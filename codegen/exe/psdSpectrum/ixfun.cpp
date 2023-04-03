//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixfun.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "ixfun.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void x_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void x_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Arrays have incompatible sizes for this operation.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void expand_max(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c)
{
  static rtRunTimeErrorInfo k_emlrtRTEI{
      160,         // lineNo
      "expand_max" // fName
  };
  int csz_idx_0;
  int u0;
  if (b.size(0) == 1) {
    csz_idx_0 = a.size(0);
  } else if (a.size(0) == 1) {
    csz_idx_0 = b.size(0);
  } else {
    u0 = a.size(0);
    csz_idx_0 = b.size(0);
    if (u0 <= csz_idx_0) {
      csz_idx_0 = u0;
    }
    if (a.size(0) != b.size(0)) {
      x_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
    }
  }
  c.set_size(csz_idx_0, a.size(1));
  if ((csz_idx_0 != 0) && (a.size(1) != 0)) {
    int acoef;
    int bcoef;
    acoef = (a.size(0) != 1);
    bcoef = (b.size(0) != 1);
    u0 = csz_idx_0 - 1;
    for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
      c[csz_idx_0] = std::fmax(a[acoef * csz_idx_0], b[bcoef * csz_idx_0]);
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void expand_min(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c)
{
  static rtRunTimeErrorInfo k_emlrtRTEI{
      160,         // lineNo
      "expand_min" // fName
  };
  int csz_idx_0;
  int u0;
  if (b.size(0) == 1) {
    csz_idx_0 = a.size(0);
  } else if (a.size(0) == 1) {
    csz_idx_0 = b.size(0);
  } else {
    u0 = a.size(0);
    csz_idx_0 = b.size(0);
    if (u0 <= csz_idx_0) {
      csz_idx_0 = u0;
    }
    if (a.size(0) != b.size(0)) {
      x_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
    }
  }
  c.set_size(csz_idx_0, a.size(1));
  if ((csz_idx_0 != 0) && (a.size(1) != 0)) {
    int acoef;
    int bcoef;
    acoef = (a.size(0) != 1);
    bcoef = (b.size(0) != 1);
    u0 = csz_idx_0 - 1;
    for (csz_idx_0 = 0; csz_idx_0 <= u0; csz_idx_0++) {
      c[csz_idx_0] = std::fmin(a[acoef * csz_idx_0], b[bcoef * csz_idx_0]);
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for ixfun.cpp
//
// [EOF]
//
