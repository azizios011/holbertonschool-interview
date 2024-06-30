#!/usr/bin/env python3
import sys
import re

# Regular expression to match the log line format
log_pattern = re.compile(r'^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[(.*?)\] "GET /projects/260 HTTP/1.1" (\d{3}) (\d+)')

# Initialize metrics variables
total_file_size = 0
status_code_counts = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
line_count = 0

try:
    for line in sys.stdin:
        line_count += 1
        line = line.strip()
        match = log_pattern.match(line)
        
        if not match:
            continue
        
        ip_address, date, status_code_str, file_size_str = match.groups()
        
        try:
            status_code = int(status_code_str)
            file_size = int(file_size_str)
        except ValueError:
            continue
        
        total_file_size += file_size
        
        if status_code in status_code_counts:
            status_code_counts[status_code] += 1
        
        # Print metrics after every 10 lines
        if line_count % 10 == 0:
            print(f"File size: {total_file_size}")
            for code in sorted(status_code_counts):
                if status_code_counts[code] > 0:
                    print(f"{code}: {status_code_counts[code]}")
            print()
except KeyboardInterrupt:
    # Handle keyboard interruption
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")
    sys.exit(0)
