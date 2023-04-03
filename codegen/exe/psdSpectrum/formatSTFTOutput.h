//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: formatSTFTOutput.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef FORMATSTFTOUTPUT_H
#define FORMATSTFTOUTPUT_H

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
void formatSTFTOutput(::coder::array<creal_T, 2U> &S,
                      ::coder::array<double, 1U> &F, const b_struct_T *opts);

}
} // namespace internal
} // namespace signal
} // namespace coder

#endif
//
// File trailer for formatSTFTOutput.h
//
// [EOF]
//
