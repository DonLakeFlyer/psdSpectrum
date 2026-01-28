#!/bin/bash

# Script to capture IQ samples using Airspy

# Default values
FREQUENCY=146.5
DURATION_MS=10000
OUTPUT_FILE=""

# Parse command line arguments
# First positional argument is the output file
if [[ $# -gt 0 && ! "$1" =~ ^- ]]; then
    OUTPUT_FILE="$1"
    shift
fi

while [[ $# -gt 0 ]]; do
    case $1 in
        -f|--frequency)
            FREQUENCY="$2"
            shift 2
            ;;
        -d|--duration)
            DURATION_MS="$2"
            shift 2
            ;;
        -o|--output)
            OUTPUT_FILE="$2"
            shift 2
            ;;
        -h|--help)
            echo "Usage: $0 <output_file> [-f <frequency>] [-d <duration_ms>]"
            echo "   or: $0 -o <output_file> [options]"
            echo ""
            echo "Arguments:"
            echo "  output_file               Output IQ file (required, can be first arg or use -o)"
            echo ""
            echo "Options:"
            echo "  -f, --frequency <freq>    Frequency in MHz (default: 146.5)"
            echo "  -d, --duration <ms>       Duration in milliseconds (default: 10000)"
            echo "  -o, --output <file>       Output IQ file (alternative to positional arg)"
            echo "  -h, --help                Show this help message"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            echo "Use -h or --help for usage information"
            exit 1
            ;;
    esac
done

# Validate required arguments
if [ -z "$OUTPUT_FILE" ]; then
    echo "Error: Output file is required (-o or --output)"
    exit 1
fi

# Convert duration from milliseconds to number of samples (3000000 Hz sample rate for Airspy Mini)
SAMPLE_RATE=3000000
NUM_SAMPLES=$((DURATION_MS * SAMPLE_RATE / 1000))

# Build airspy_rx command
CMD="airspy_rx -f $FREQUENCY -a 3000000 -h 21 -t 0 -n $NUM_SAMPLES -r $OUTPUT_FILE"

# Run the command
echo "Running: $CMD"
eval "$CMD"
