//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_internal_types.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

#ifndef PSDSPECTRUM_INTERNAL_TYPES_H
#define PSDSPECTRUM_INTERNAL_TYPES_H

// Include Files
#include "psdSpectrum_types.h"
#include "rtwtypes.h"

// Type Definitions
struct struct_T {
  double nfft;
  double Fs;
  double conflevel;
  boolean_T average;
  boolean_T maxhold;
  boolean_T minhold;
  boolean_T MIMO;
  boolean_T isNFFTSingle;
  boolean_T centerdc;
  char range[8];
};

struct cell_9 {
  double f1;
  double f2;
  char f3[8];
};

#endif
//
// File trailer for psdSpectrum_internal_types.h
//
// [EOF]
//
