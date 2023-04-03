//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_internal_types.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef PSDSPECTRUM_INTERNAL_TYPES_H
#define PSDSPECTRUM_INTERNAL_TYPES_H

// Include Files
#include "psdSpectrum_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

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

struct cell_28 {
  double f1;
  double f2;
  char f3[8];
};

struct b_struct_T {
  double DataLength;
  double NumChannels;
  double TimeAxisLength;
  boolean_T IsSingle;
  char TimeMode[2];
  double EffectiveFs;
  boolean_T IsNormalizedFreq;
  coder::array<double, 1U> Window;
  double WindowLength;
  double OverlapLength;
  double FFTLength;
  char FreqRange[8];
  boolean_T ConjugateSymmetric;
  char TimeDimension[13];
  double NumFreqSamples;
};

#endif
//
// File trailer for psdSpectrum_internal_types.h
//
// [EOF]
//
