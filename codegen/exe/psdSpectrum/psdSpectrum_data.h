//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_data.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

#ifndef PSDSPECTRUM_DATA_H
#define PSDSPECTRUM_DATA_H

// Include Files
#include "psdSpectrum_types.h"
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>
#include <stdio.h>

// Variable Declarations
extern FILE *eml_openfiles[20];
extern omp_nest_lock_t psdSpectrum_nestLockGlobal;
extern rtRunTimeErrorInfo emlrtRTEI;
extern rtRunTimeErrorInfo b_emlrtRTEI;
extern rtRunTimeErrorInfo c_emlrtRTEI;
extern rtRunTimeErrorInfo d_emlrtRTEI;
extern rtRunTimeErrorInfo e_emlrtRTEI;
extern const char cv[128];
extern const char cv1[10];
extern const char cv2[15];
extern boolean_T isInitialized_psdSpectrum;

#endif
//
// File trailer for psdSpectrum_data.h
//
// [EOF]
//
