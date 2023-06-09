//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_psdSpectrum_mex.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

#ifndef _CODER_PSDSPECTRUM_MEX_H
#define _CODER_PSDSPECTRUM_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void psdSpectrum_mexFunction(int32_T nlhs, int32_T nrhs,
                             const mxArray *prhs[3]);

#endif
//
// File trailer for _coder_psdSpectrum_mex.h
//
// [EOF]
//
