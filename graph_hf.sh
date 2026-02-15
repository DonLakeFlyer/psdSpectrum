#!/bin/bash

# Script to analyze and graph IQ samples from Airspy HF+

if [[ $# -eq 0 ]]; then
    echo "Usage: $0 <iq_file>"
    echo ""
    echo "Arguments:"
    echo "  iq_file    Path to IQ file to analyze"
    echo ""
    echo "Example:"
    echo "  $0 capture.iq"
    exit 1
fi

IQ_FILE="$1"

# Check if file exists
if [[ ! -f "$IQ_FILE" ]]; then
    echo "Error: File '$IQ_FILE' not found"
    exit 1
fi

# Run psd analysis
python psd.py -sdr hf -file "$IQ_FILE"
