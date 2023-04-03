all:
	rm -f psdSpectrum
	rm -f *.o
	rm -f codegen/exe/psdSpectrum/*.o
	make -f matlab-coder-utils/Makefile PRODUCT_NAME=psdSpectrum -j4
