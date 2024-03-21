#!/usr/bin/python3
"""a script that reads 'stdin' line by line and computes metrics"""

import sys
import re
from collections import defaultdict

"""Regular expression pattern to match the log format"""

LOG_PATTERN = re.compile(
    r'^(\d+\.\d+\.\d+\.\d+) '
    r'\[(.*?)\] "GET /projects/260 HTTP/1\.1" '
    r'(\d+) (\d+)$'
)


def print_statistics(total_size, status_counts):
    """Function to print statistics"""
    print(f"File size: {total_size}")
    for status_code in sorted(status_counts.keys()):
        print(f"{status_code}: {status_counts[status_code]}")


def main():
    """Extract information from the log line and
    Print statistics after every 10 lines"""
    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    try:
        for line in sys.stdin:
            match = re.match(LOG_PATTERN, line.strip())
            if match:

                ip_address, _, status_code, file_size = match.groups()
                total_size += int(file_size)
                status_counts[status_code] += 1
                line_count += 1

                if line_count % 10 == 0:
                    print_statistics(total_size, status_counts)

    except KeyboardInterrupt:
        pass

    print_statistics(total_size, status_counts)


if __name__ == "__main__":
    main()
