#!/usr/bin/python3

import sys
import signal

# Global variables to store metrics
file_sizes = []
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0


def signal_handler(sig, frame):
    print_statistics()
    sys.exit(0)


def print_statistics():
    global file_sizes, status_codes
    total_size = sum(file_sizes)
    print(f"File size: {total_size}")
    for code, count in sorted(status_codes.items()):
        if count > 0:
            print(f"{code}: {count}")


def parse_line(line):
    global file_sizes, status_codes, line_count
    parts = line.split()
    if len(parts) != 7:
        return
    status_code = int(parts[-2])
    if status_code in status_codes:
        status_codes[status_code] += 1
        file_sizes.append(int(parts[-1]))
    line_count += 1
    if line_count % 10 == 0:
        print_statistics()


def main():
    signal.signal(signal.SIGINT, signal_handler)
    for line in sys.stdin:
        parse_line(line.strip())


if __name__ == "__main__":
    main()
