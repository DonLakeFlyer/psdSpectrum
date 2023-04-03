//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixfun.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

#ifndef IXFUN_H
#define IXFUN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void expand_max(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c);

void expand_min(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for ixfun.h
//
// [EOF]
//
