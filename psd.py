import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal
import math
import argparse
import os
from matplotlib.ticker import FuncFormatter

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
nperseg     = math.floor(nWind)
nOverlap    = math.floor(0.5 * nWind);
samples     = np.fromfile(args.file, np.complex64)

# Decimate Airspy samples to match HF sample rate
if args.sdr == "mini":
    decimation_factor = 4  # 3000000 / 768000 ≈ 3.90625, use 4 for integer decimation
    samples = signal.decimate(samples, decimation_factor, ftype='iir')
    fs = fs // decimation_factor  # Update sample rate after decimation

f, Pxxf = signal.welch(samples, fs, window="hann", nperseg=nperseg, noverlap=nOverlap, return_onesided=False)

# Convert Welch density to true dBFS/Hz via bin bandwidth:
# 1) PSD density [FS^2/Hz] -> per-bin power [FS^2/bin] by multiplying by delta_f
# 2) Per-bin dBFS -> normalize back to dBFS/Hz by subtracting 10*log10(delta_f)
delta_f = fs / nperseg
eps = np.finfo(float).tiny
Pxxf_per_bin = np.maximum(Pxxf * delta_f, eps)
Pxxf_dBFS_bin = 10 * np.log10(Pxxf_per_bin)
Pxxf_dBFS_Hz = Pxxf_dBFS_bin - 10 * np.log10(delta_f)

avg_noise_floor = np.mean(Pxxf_dBFS_Hz)
print(f"Average Noise Floor: {avg_noise_floor:.2f} dBFS/Hz")
print(f"Bin Bandwidth (Δf): {delta_f:.2f} Hz")

# Calculate spectral flatness (geometric mean / arithmetic mean)
# Convert from dB to linear scale for geometric/arithmetic mean calculation
Pxxf_linear = 10**(Pxxf_dBFS_Hz / 10)
geometric_mean = np.exp(np.mean(np.log(Pxxf_linear + 1e-10)))  # add small value to avoid log(0)
arithmetic_mean = np.mean(Pxxf_linear)
flatness = 10 * np.log10(geometric_mean / arithmetic_mean)  # in dB
print(f"Spectral Flatness: {flatness:.2f} dB- higher values indicate a flatter spectrum")

# Calculate spikiness as peak-to-baseline ratio (how much peaks stand out)
baseline = medfilt(Pxxf_dBFS_Hz, kernel_size=101)   # smooth baseline
peak_deviation = Pxxf_dBFS_Hz - baseline
spikiness = np.max(peak_deviation)  # maximum deviation from baseline
print(f"Spikiness: {spikiness:.2f} dB - higher values indicate more pronounced peaks")

# Set y-axis limits based on noise floor
y_min = avg_noise_floor - 2
y_max = y_min + 20

plt.plot(f / 1e6, Pxxf_dBFS_Hz, '-', linewidth=1)
filename = os.path.basename(args.file)
plt.title(f'{filename}\nNoise Floor: {avg_noise_floor:.2f} dBFS/Hz | Flatness: {flatness:.2f} dB | Spikiness: {spikiness:.2f} dB')

plt.xlabel('Frequency (MHz)')
plt.ylabel('PSD (dBFS/Hz)')
# Format x-axis ticks to show 3 decimal places (MHz)
plt.gca().xaxis.set_major_formatter(FuncFormatter(lambda x, _: f'{x:.3f}'))

plt.ylim(y_min, y_max)
plt.grid()
plt.show()
