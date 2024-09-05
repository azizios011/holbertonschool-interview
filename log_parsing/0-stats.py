#!/usr/bin/python3

"""
Reads stdin line by line and computes metrics.
"""
import sys

if __name__ == "__main__":

    status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                    403: 0, 404: 0, 405: 0, 500: 0}
    file_size = [0]
    count = 1

    def print_stats():
        """
        Prints file size
        """
        print('File size: {}'.format(file_size[0]))

        for code in sorted(status_codes.keys()):
            if status_codes[code] != 0:
                print('{}: {}'.format(code, status_codes[code]))

    def parse_stdin(line):
        """
        Checks the stdin for matches
        """
        try:
            line = line[:-1]
            word = line.split(' ')

            file_size[0] += int(word[-1])

            status_code = int(word[-2])

            if status_code in status_codes:
                status_codes[status_code] += 1
        except BaseException:
            pass

    try:
        for line in sys.stdin:
            parse_stdin(line)

            if count % 10 == 0:
                print_stats()
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
