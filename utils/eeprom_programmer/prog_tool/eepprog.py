#!/usr/bin/env python3

import sys
import getopt
import serial

# Global variables for program parameters
verbose = False
serial_device = "/dev/ttyUSB0"
serial_baudrate = 9600
command = ""

# Valid commands
valid_commands = ("test")


def usage():
    """Prints help text."""

    print(f"""
Usage: {sys.argv[0]} [OPTIONS] COMMAND [ARGS]

Commands:
  test                            first test command...

Options:
  -h, --help                      show this help message and exit
  -v, --verbose                   be verbose
  -d DEVICE, --device=DEVICE      use DEVICE as serial device
                                  (default: /dev/ttyUSB0)
"""[1:-1])


def parse_args():
    """Parse command line arguments and set global variables."""

    # Global variables for program options (yes, yes, I know...)
    global verbose, serial_device, serial_baudrate, command

    try:
        # Try to parse argument strings
        optlist, args = getopt.gnu_getopt(
            sys.argv[1:],
            "hvd:",
            ["help", "verbose", "device="]
        )
    except getopt.GetoptError as err:
        # Invalid option, print help and exit
        print(err, "\n")
        usage()
        sys.exit(2)

    # Parse all the options
    for opt, val in optlist:
        if opt == "-h" or opt == "--help":
            # Print help
            usage()
            sys.exit()

        elif opt == "-v" or opt == "--verbose":
            # Verbose
            verbose = True

        elif opt == "-d" or opt == "--device":
            # Set device filename
            serial_device = val

        else:
            assert False, "unhandled option"

    # Parse command argument
    if len(args) == 0:
        print("missing command\n")
        usage()
        sys.exit(2)
    else:
        # Get command and remove argument
        command = args.pop(0)

        # Check if command is valid
        if command not in valid_commands:
            print("invalid command '" + command + "'\n")
            usage()
            sys.exit(2)

        # Check if command has valid arguments
        # TODO


def setup_serial():
    """Setup serial device."""

    if verbose:
        print(f"setting up serial device '{serial_device}' with baudrate "
              f"{serial_baudrate}")

    # Setup serial device
    ser = serial.Serial(serial_device, serial_baudrate)
    return ser


def command_test(ser):
    """Command 'test': Does some testing."""

    if verbose:
        print("running command 'test' ...")

    # Write a test command
    # TODO do a HELLO first
    ser.write(b"TESTREAD\n")

    # Just read some stuff
    while True:
        print("read: ", ser.readline(80))


def main():
    """Main function. Does the thing."""

    # Parse program arguments
    parse_args()

    # Setup serial device
    ser = setup_serial()

    # Run command
    if command == "test":
        command_test(ser)
    else:
        assert False, "unhandled command"

    # Close serial device
    ser.close()


# Run program
main()
