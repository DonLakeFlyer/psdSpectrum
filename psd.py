import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal
import math
import argparse

parser = argparse.ArgumentParser("psdSpectrum.py")
parser.add_argument("-sdr", help="SDR type.", choices=["mini", "hf"], required=True)
parser.add_argument("-file", help="IQ file.", required=True)
args = parser.parse_args()

# Map SDR type to sample rate
sdr_sample_rates = {
    "mini": 3000000,
    "hf": 768000
}
fs = sdr_sample_rates[args.sdr]

windTime    = 0.02
nWind       = fs * windTime;
rectWindow  = signal.windows.hann(math.floor(nWind))
nOverlap    = math.floor(0.5 * nWind);
samples     = np.fromfile(args.file, np.complex64)

# Decimate Airspy samples to match HF sample rate
if args.sdr == "mini":
    decimation_factor = 4  # 3000000 / 768000 ≈ 3.90625, use 4 for integer decimation
    samples = signal.decimate(samples, decimation_factor, ftype='iir')
    fs = fs // decimation_factor  # Update sample rate after decimation

f, Pxxf = signal.welch(samples, fs, window=rectWindow, noverlap=nOverlap, return_onesided=False)

# Convert to dB and compute average noise floor
Pxxf_dB = 10*np.log10(Pxxf)
avg_noise_floor = np.mean(Pxxf_dB)

# Set y-axis limits based on noise floor
y_min = avg_noise_floor - 2
y_max = y_min + 20

plt.plot(f / 1e6, Pxxf_dB, '-', linewidth=1)
plt.title(args.file)

plt.xlabel('Frequency (MHz)')
# Format x-axis ticks to show 3 decimal places (MHz)
plt.gca().xaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'{x:.3f}'))

plt.ylim(y_min, y_max)
plt.grid()
plt.show()
