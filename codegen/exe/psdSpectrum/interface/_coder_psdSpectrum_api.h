//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_psdSpectrum_api.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef _CODER_PSDSPECTRUM_API_H
#define _CODER_PSDSPECTRUM_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void psdSpectrum(real_T Fs, real_T centerFreqMHz,
                 coder::array<char_T, 2U> *file);

void psdSpectrum_api(const mxArray *const prhs[3]);

void psdSpectrum_atexit();

void psdSpectrum_initialize();

void psdSpectrum_terminate();

void psdSpectrum_xil_shutdown();

void psdSpectrum_xil_terminate();

#endif
//
// File trailer for _coder_psdSpectrum_api.h
//
// [EOF]
//
