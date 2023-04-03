//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: iseven.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "iseven.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double x
// Return Type  : boolean_T
//
namespace coder {
namespace signalwavelet {
namespace internal {
boolean_T iseven(double x)
{
  static rtRunTimeErrorInfo k_emlrtRTEI{
      12,      // lineNo
      "iseven" // fName
  };
  double r;
  if (x - std::trunc(x) != 0.0) {
    m_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if (std::isnan(x) || std::isinf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = std::fmod(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 2.0;
    }
  }
  return r == 0.0;
}

} // namespace internal
} // namespace signalwavelet
} // namespace coder

//
// File trailer for iseven.cpp
//
// [EOF]
//
