#!/bin/bash

# Script to capture IQ samples using Airspy HF+

# Default values
FREQUENCY=146.5
DURATION_MS=10000
OUTPUT_FILE=""
AGC="off"
ATTENUATOR=0
LNA="on"

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
        -a|--agc)
            AGC="$2"
            shift 2
            ;;
        -att|--attenuator)
            ATTENUATOR="$2"
            shift 2
            ;;
        -m|--lna)
            LNA="$2"
            shift 2
            ;;
        -h|--help)
            echo "Usage: $0 <output_file> [-f <frequency>] [-d <duration_ms>] [-a <on|off>] [-att <level>] [-m <on|off>]"
            echo "   or: $0 -o <output_file> [options]"
            echo ""
            echo "Arguments:"
            echo "  output_file               Output IQ file (required, can be first arg or use -o)"
            echo ""
            echo "Options:"
            echo "  -f, --frequency <freq>    Frequency in MHz (default: 146.5)"
            echo "  -d, --duration <ms>       Duration in milliseconds (default: 10000)"
            echo "  -o, --output <file>       Output IQ file (alternative to positional arg)"
            echo "  -a, --agc <on|off>        AGC on/off (default: off)"
            echo "  -att, --attenuator <lvl>  Attenuator level (default: 0)"
            echo "  -m, --lna <on|off>        LNA on/off (default: on)"
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

# Convert duration from milliseconds to number of samples (768000 Hz sample rate for HF)
SAMPLE_RATE=768000
NUM_SAMPLES=$((DURATION_MS * SAMPLE_RATE / 1000))

# Build airspyhf_rx command
CMD="airspyhf_rx -f $FREQUENCY -n $NUM_SAMPLES -r $OUTPUT_FILE"

# Add optional parameters
CMD="$CMD -g $AGC"
CMD="$CMD -t $ATTENUATOR"
CMD="$CMD -m $LNA"

# Run the command
echo "Running: $CMD"
eval "$CMD"
