#!/usr/bin/python3
"""
Module: 0-stats
Script that reads stdin line by line and computes metrics.
"""

import sys
from collections import defaultdict


def parse_line(line):
    """
    Parse a log line to extract IP address, status code, and file size.

    Args:
        line (str): A log line in the specified format.

    Returns:
        tuple: A tuple containing IP address, status code, and file size.
               Returns None if the line format is incorrect.
    """
    # Split the line into components
    parts = line.split()
    if len(parts) < 10:
        return None
    ip_address = parts[0]
    status_code = parts[-2]
    file_size = int(parts[-1])
    return ip_address, status_code, file_size


def print_statistics(total_size, status_counts):
    """
    Print accumulated statistics.

    Args:
        total_size (int): Total file size.
        status_counts (dict): Dictionary containing status code counts.
    """
    print("File size:", total_size)
    for status_code in sorted(status_counts.keys()):
        print(status_code + ":", status_counts[status_code])


def main():
    """
    Main function to process log lines from stdin and compute statistics.
    """
    total_size = 0
    status_counts = defaultdict(int)
    lines_processed = 0

    try:
        for line in sys.stdin:
            # Parse each line
            parsed = parse_line(line.strip())
            if parsed is None:
                continue

            # Update total file size
            total_size += parsed[2]

            # Update status code counts
            status_counts[parsed[1]] += 1

            # Increment lines processed
            lines_processed += 1

            # Print statistics every 10 lines
            if lines_processed % 10 == 0:
                print_statistics(total_size, status_counts)
    except KeyboardInterrupt:
        # Handle keyboard interruption
        print_statistics(total_size, status_counts)
        sys.exit(0)


if __name__ == "__main__":
    main()
