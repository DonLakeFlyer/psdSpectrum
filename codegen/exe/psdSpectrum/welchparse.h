//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: welchparse.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef WELCHPARSE_H
#define WELCHPARSE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

// Function Declarations
namespace coder {
namespace signal {
namespace internal {
namespace spectral {
void welchparse(const ::coder::array<creal_T, 2U> &x1,
                ::coder::array<double, 1U> &varargin_1, double varargin_2,
                double varargin_3, double varargin_4, const char varargin_5[8],
                ::coder::array<creal_T, 1U> &x, double *M, char winName_data[],
                int winName_size[2], char winParam_data[], int winParam_size[2],
                double *noverlap, double *k, double *L, struct_T *options);

}
} // namespace internal
} // namespace signal
} // namespace coder

#endif
//
// File trailer for welchparse.h
//
// [EOF]
//
