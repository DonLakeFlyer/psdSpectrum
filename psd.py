import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal
import math
import argparse
import os

from scipy.signal import medfilt

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
print(f"Average Noise Floor: {avg_noise_floor:.2f} dB")

# Calculate spectral flatness (geometric mean / arithmetic mean)
# Convert from dB to linear scale for geometric/arithmetic mean calculation
Pxxf_linear = 10**(Pxxf_dB / 10)
geometric_mean = np.exp(np.mean(np.log(Pxxf_linear + 1e-10)))  # add small value to avoid log(0)
arithmetic_mean = np.mean(Pxxf_linear)
flatness = 10 * np.log10(geometric_mean / arithmetic_mean)  # in dB
print(f"Spectral Flatness: {flatness:.2f} dB- higher values indicate a flatter spectrum")

# Calculate spikiness as peak-to-baseline ratio (how much peaks stand out)
baseline = medfilt(Pxxf_dB, kernel_size=101)   # smooth baseline
peak_deviation = Pxxf_dB - baseline
spikiness = np.max(peak_deviation)  # maximum deviation from baseline
print(f"Spikiness: {spikiness:.2f} dB - higher values indicate more pronounced peaks")

# Set y-axis limits based on noise floor
y_min = avg_noise_floor - 2
y_max = y_min + 20

plt.plot(f / 1e6, Pxxf_dB, '-', linewidth=1)
filename = os.path.basename(args.file)
plt.title(f'{filename}\nNoise Floor: {avg_noise_floor:.2f} dB | Flatness: {flatness:.2f} dB | Spikiness: {spikiness:.2f} dB')

plt.xlabel('Frequency (MHz)')
# Format x-axis ticks to show 3 decimal places (MHz)
plt.gca().xaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'{x:.3f}'))

plt.ylim(y_min, y_max)
plt.grid()
plt.show()
