function [dataFFTShift,fftFreqs] = centered_fft(Fs, data)
%UNTITLED9 Summary of this function goes here
%   Detailed explanation goes here

dataFFT      = fft(data);
dataFFTShift = fftshift(dataFFT);
nFFT         = length(dataFFT);
fftFreqs     = (-nFFT/2:nFFT/2-1)/nFFT*Fs;

end