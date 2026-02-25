#!/bin/bash

# Script to analyze and graph IQ samples for any supported SDR type

usage() {
    echo "Usage: $0 -sdr <mini|hf|uavrt_hf|uavrt_mini> <iq_file>"
    echo ""
    echo "Arguments:"
    echo "  -sdr     SDR type (mini, hf, uavrt_hf, uavrt_mini)"
    echo "  iq_file  Path to IQ file to analyze (positional)"
    echo ""
    echo "Optional:"
    echo "  -file    Path to IQ file to analyze (legacy flag form)"
    echo ""
    echo "Example:"
    echo "  $0 -sdr hf capture.iq"
    exit 1
}

SDR_TYPE=""
IQ_FILE=""

while [[ $# -gt 0 ]]; do
    case "$1" in
        -sdr)
            if [[ -z "$2" ]]; then
                echo "Error: -sdr requires a value"
                usage
            fi
            SDR_TYPE="$2"
            shift 2
            ;;
        -file)
            if [[ -z "$2" ]]; then
                echo "Error: -file requires a value"
                usage
            fi
            IQ_FILE="$2"
            shift 2
            ;;
        -h|--help)
            usage
            ;;
        *)
            # Treat non-flag args as IQ file; last one wins
            IQ_FILE="$1"
            shift
            ;;
    esac
done

if [[ -z "$SDR_TYPE" || -z "$IQ_FILE" ]]; then
    usage
fi

case "$SDR_TYPE" in
    mini|hf|uavrt_hf|uavrt_mini)
        ;;
    *)
        echo "Error: Invalid SDR type '$SDR_TYPE'"
        usage
        ;;
esac

if [[ ! -f "$IQ_FILE" ]]; then
    echo "Error: File '$IQ_FILE' not found"
    exit 1
fi

python psd.py -sdr "$SDR_TYPE" -file "$IQ_FILE"
