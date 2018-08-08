#!/usr/bin/env python3

import sys
import getopt
# import serial


def parse_args():
    """Parse command line arguments and set global variables."""

    optlist, args = getopt.gnu_getopt(sys.argv[1:], 'abc:d:', '--verbose')

    print("optlist: " + str(optlist))
    print("args: " + str(args))

    # TODO parse arguments...


def setup_serial():
    # TODO ...
    pass


def main():
    """Main function. Does the thing."""

    # TODO testing...
    print("Meow :3")
    parse_args()


# Run program
main()
