import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal
import math
import argparse

parser = argparse.ArgumentParser("psdSpectrum.py")
parser.add_argument("-fs",   help="Sample rate.", type=float, required=True)
parser.add_argument("-file", help="IQ file.", required=True)
args = parser.parse_args()

windTime    = 0.02
nWind       = args.fs * windTime;
rectWindow  = signal.windows.boxcar(math.floor(nWind))
nOverlap    = math.floor(0.5 * nWind);
samples     = np.fromfile(args.file, np.complex64)

f, Pxxf = signal.welch(samples, args.fs, window=rectWindow, noverlap=nOverlap, return_onesided=False)

plt.semilogy(f, Pxxf, '-', linewidth=1)

plt.grid()
plt.show()