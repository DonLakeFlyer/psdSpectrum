//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeperiodogram.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

#ifndef COMPUTEPERIODOGRAM_H
#define COMPUTEPERIODOGRAM_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void computeperiodogram(const ::coder::array<creal_T, 1U> &x,
                        const ::coder::array<double, 1U> &win, double nfft,
                        double Fs, ::coder::array<double, 1U> &Pxx,
                        ::coder::array<double, 1U> &F);

}

#endif
//
// File trailer for computeperiodogram.h
//
// [EOF]
//
