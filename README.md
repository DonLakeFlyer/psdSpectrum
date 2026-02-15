# PSD Spectrum Analysis

A Python-based tool for analyzing power spectral density (PSD) of IQ samples captured from Airspy SDR devices. Computes spectral flatness and spikiness metrics to characterize noise floor characteristics.

## Overview

This project consists of:
- **capture_hf.sh** - Capture IQ samples using Airspy HF+
- **capture_mini.sh** - Capture IQ samples using Airspy Mini
- **psd.py** - Analyze captured IQ samples and compute PSD metrics

## Prerequisites

- Python 3.x with numpy, matplotlib, scipy
- Airspy device (HF+ or Mini) with airspyhf_rx or airspy_rx installed

### Setup

**Create and activate virtual environment:**

```bash
source setup_venv.sh
```

**Important:** You must **source** the script (not bash it) for the virtual environment activation to take effect in your current shell.

Alternatively, if you run it with `bash setup_venv.sh`, manually activate afterward:

```bash
source venv/bin/activate
```

This creates a Python virtual environment with required dependencies (numpy, matplotlib, scipy).

## Capturing IQ Samples

### Using Airspy HF+

```bash
./capture_hf.sh <output_file> [options]
```

**Options:**
- `-f, --frequency <freq>` - Frequency in MHz (default: 146.5)
- `-d, --duration <ms>` - Duration in milliseconds (default: 10000)
- `-a, --agc <on|off>` - AGC on/off (default: off)
- `-att, --attenuator <lvl>` - Attenuator level (default: 0)
- `-m, --lna <on|off>` - LNA on/off (default: on)

**Example:**
```bash
./capture_hf.sh output.iq -f 146.5 -d 5000 -att 10
```

Sample rate: **768,000 Hz**

### Using Airspy Mini

```bash
./capture_mini.sh <output_file> [options]
```

**Options:**
- `-f, --frequency <freq>` - Frequency in MHz (default: 146.5)
- `-d, --duration <ms>` - Duration in milliseconds (default: 10000)

**Example:**
```bash
./capture_mini.sh output.iq -f 146.5 -d 5000
```

Sample rate: **3,000,000 Hz** (automatically decimated to 768,000 Hz in psd.py for consistency)

## Analyzing Captured Samples

### Using Python Directly

```bash
python psd.py -sdr <mini|hf> -file <iq_file>
```

**Arguments:**
- `-sdr` - SDR type: `mini` or `hf` (required)
- `-file` - Path to IQ file (required)

**Example:**
```bash
python psd.py -sdr hf -file output.iq
python psd.py -sdr mini -file output.iq
```

### Using Graph Scripts (Recommended)

Convenience wrapper scripts that automatically call `psd.py` with the correct SDR type:

```bash
./graph_hf.sh <iq_file>
./graph_mini.sh <iq_file>
```

**Example:**
```bash
./graph_hf.sh output.iq
./graph_mini.sh output.iq
```

These scripts include file existence validation and usage help.

## Output

The script generates:
1. **Console output** showing metrics:
   - Spectral Flatness (dB)
   - Spikiness (dB)

2. **Interactive plot** displaying:
   - Power spectral density across frequency
   - Title with filename and metrics on two lines
   - Frequency in MHz on x-axis
   - Power in dB on y-axis

## Metrics

### Spectral Flatness
- Computes the ratio of geometric mean to arithmetic mean of the spectrum
- **Higher values (closer to 0 dB)** = flatter noise floor
- **More negative values** = bumpier spectrum with peaks and dips
- Standard measure of spectral uniformity in signal processing

### Spikiness
- Measures the maximum deviation of spectrum peaks from a smooth baseline
- **Higher dB values** = more pronounced peaks above the baseline
- **Lower dB values** = smoother spectrum
- Quantifies how much interference or signals stand out from the noise floor

## Workflow Example

```bash
# Capture 5 seconds at 146.5 MHz using HF+
./capture_hf.sh test.iq -f 146.5 -d 5000

# Analyze and graph the capture
./graph_hf.sh test.iq
```

Or using Python directly:
```bash
python psd.py -sdr hf -file test.iq
```

## Notes

- **Airspy Mini samples** are decimated from 3,000,000 Hz to 768,000 Hz for consistency with HF+ sample rate
- The spectral analysis uses a Hann window with 50% overlap for Welch periodogram
- Y-axis limits are automatically set relative to the noise floor (±2 dB, 20 dB span)
