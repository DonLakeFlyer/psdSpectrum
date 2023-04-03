function psdSpectrum(Fs, centerFreqMHz, file)

    data = readairspybinfile(file);
    t = 0:1/Fs:(numel(data)-1)/Fs;

    [dataFFT, fftFreqs] = centered_fft(Fs, data);

    windTime = 0.02;
    nWind = Fs * windTime;
    stftFreqRes = 1/nWind * Fs;

    rectWind            = rectwin(nWind);
    nOverlap            = floor(0.5 * nWind);
    [ s, fStft, tStft ] = stft(data,Fs,Window=rectWind,OverlapLength=nOverlap,FFTLength=nWind);
    [ pxx, f ]          = pwelch(data,rectWind,nOverlap,nWind,Fs,'centered');

    figure;
    subplot(2,1,1)
    plot(f/1e6,10*log10(pxx),'DisplayName',file);hold on
    plot(f/1e6,10*log10(pxx),'--','DisplayName',file);
    dcmObj1 = datacursormode;  % Turn on data cursors and return the data cursor mode object
    set(dcmObj1, 'UpdateFcn', @updateFcn);  % Set the data cursor mode object update function so it uses updateFcn.m
    legend('Location','best')
    xlabel('Frequency (MHz relative to Fc)')
    ylabel('PSD (dB)');

    subplot(2,1,2)
    plot((f+centerFreqMHz*6)/1e6,10*log10(pxx),'DisplayName',file);hold on
    plot((f+centerFreqMHz*6)/1e6,10*log10(pxx),'--','DisplayName',file);
    dcmObj2 = datacursormode;  % Turn on data cursors and return the data cursor mode object
    set(dcmObj2, 'UpdateFcn', @updateFcn);  % Set the data cursor mode object update function so it uses updateFcn.m
    legend('Location','best')
    xlabel('Frequency (MHz Absolute)')
    ylabel('PSD (dB)');

end