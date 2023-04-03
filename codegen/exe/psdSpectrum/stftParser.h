//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: stftParser.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef STFTPARSER_H
#define STFTPARSER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct b_struct_T;

// Function Declarations
namespace coder {
namespace signal {
namespace internal {
namespace stft {
void stftParser(const ::coder::array<creal_T, 2U> &x, double varargin_1,
                const ::coder::array<double, 1U> &varargin_3, double varargin_5,
                double varargin_7, ::coder::array<creal_T, 1U> &varargout_1,
                b_struct_T *varargout_2);

}
} // namespace internal
} // namespace signal
} // namespace coder

#endif
//
// File trailer for stftParser.h
//
// [EOF]
//
