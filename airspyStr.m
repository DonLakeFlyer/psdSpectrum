function [fullStr] = airspyStr(theFreqMHz,timeDurSec, sampleRate, theFilename)
% airspy_rx v1.0.5 23 April 2016
% Usage:
% -r <filename>: Receive data into file
% -w Receive data into file with WAV header and automatic name
%  This is for SDR# compatibility and may not work with other software
% [-s serial_number_64bits]: Open device with specified 64bits serial number
% [-p packing]: Set packing for samples, 
%  1=enabled(12bits packed), 0=disabled(default 16bits not packed)
% [-f frequency_MHz]: Set frequency in MHz between [24, 1900] (default 900MHz)
% [-a sample_rate]: Set sample rate
% [-t sample_type]: Set sample type, 
%  0=FLOAT32_IQ, 1=FLOAT32_REAL, 2=INT16_IQ(default), 3=INT16_REAL, 4=U16_REAL, 5=RAW
% [-b biast]: Set Bias Tee, 1=enabled, 0=disabled(default)
% [-v vga_gain]: Set VGA/IF gain, 0-15 (default 5)
% [-m mixer_gain]: Set Mixer gain, 0-15 (default 5)
% [-l lna_gain]: Set LNA gain, 0-14 (default 1)
% [-g linearity_gain]: Set linearity simplified gain, 0-21
% [-h sensivity_gain]: Set sensitivity simplified gain, 0-21
% [-n num_samples]: Number of samples to transfer (default is unlimited)
% [-d]: Verbose mode

if ~any(sampleRate == 1e6*[3,6,10])
    fprintf('UAV-RT Error: Sample Rate must be 3e6, 6e6, or 10e6. ')
    return
end

Fs = sampleRate;
nSamps = timeDurSec*Fs;

frequency   = ['-f ',num2str(theFreqMHz), ' '];
filename    = ['-r ', theFilename, ' '];
sampleRate  = ['-a ', num2str(Fs), ' '];
sampleType  = '-t 0 ';
verboseMode = '-d ';
numSamps   = ['-n ',num2str(nSamps), ' '];

fullStr = ['airspy_rx ',frequency,filename,sampleRate,sampleType,numSamps, verboseMode];

end




