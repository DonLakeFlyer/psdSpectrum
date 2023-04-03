function [dataComplex] = readairspybinfile(filePath)
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here
fprintf('Loading data...\n')
fid = fopen(filePath);
if fid ~= -1
    dataRaw = fread(fid,[2 inf],'single');
    fprintf('Done.\n')
else
    fprintf('UAV-RT: Error opening file at path provided.\n')
    dataRaw = [];
end
if mod(dataRaw,2)~=0
    dataRaw(2,end) = 0;
end

fclose(fid);

dataComplex = dataRaw(1, :) + (1i * dataRaw(2, :));

end