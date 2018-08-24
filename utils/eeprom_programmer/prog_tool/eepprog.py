#!/usr/bin/env python3

import sys
import getopt
# import serial

# Global variables for program parameters
verbose = False
serial_device = "/dev/ttyUSB0"
serial_baudrate = 9600


def usage():
    """Prints help text."""

    print(f"""
Usage: {sys.argv[0]} [options]

Options:
  -h, --help                      show this help message and exit
  -v, --verbose                   be verbose
  -d DEVICE, --device=DEVICE      use DEVICE as serial device
                                  (default: /dev/ttyUSB0)
"""[1:-1])


def parse_args():
    """Parse command line arguments and set global variables."""

    # Global variables for program options (yes, yes, I know...)
    global verbose, serial_device, serial_baudrate

    try:
        # Try to parse argument strings
        optlist, args = getopt.gnu_getopt(
            sys.argv[1:],
            "hvd:",
            ["help", "verbose", "device"]
        )
    except getopt.GetoptError as err:
        # Invalid option, print help and exit
        print(err, "\n")
        usage()
        sys.exit(2)

    # Parse all the arguments
    for opt, val in optlist:
        if opt == "-h" or opt == "--help":
            # Print help
            usage()
            sys.exit()

        elif opt == "-v" or opt == "--verbose":
            # Verbose
            print("verbose!")
            verbose = True

        elif opt == "-d" or opt == "--device":
            # Set device filename
            print("device: " + val)
            serial_device = val

        else:
            assert False, "unhandled option"


def setup_serial():
    """Setup serial device."""

    # TODO ...
    pass


def main():
    """Main function. Does the thing."""

    # Parse program arguments
    parse_args()


# Run program
main()
