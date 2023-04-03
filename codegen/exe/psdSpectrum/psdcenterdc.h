//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdcenterdc.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef PSDCENTERDC_H
#define PSDCENTERDC_H

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
void psdcenterdc(::coder::array<double, 2U> &Pxx,
                 const ::coder::array<double, 1U> &F,
                 ::coder::array<double, 2U> &Pxxc, const struct_T b_psdoptions,
                 ::coder::array<double, 2U> &Pxx1,
                 ::coder::array<double, 1U> &F1,
                 ::coder::array<double, 2U> &Pxxc1);

}
} // namespace internal
} // namespace signal
} // namespace coder

#endif
//
// File trailer for psdcenterdc.h
//
// [EOF]
//
