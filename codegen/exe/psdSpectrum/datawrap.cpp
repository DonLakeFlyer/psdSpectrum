//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: datawrap.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "datawrap.h"
#include "eml_int_forloop_overflow_check.h"
#include "psdSpectrum_rtwutil.h"
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
static void fb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void fb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((outStream << "Size argument must be an integer in the range: ") << 1)
    << " to ")
   << MAX_int32_T)
      << ".";
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
// Arguments    : const ::coder::array<creal_T, 1U> &x
//                double nfft
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
namespace coder {
void datawrap(const ::coder::array<creal_T, 1U> &x, double nfft,
              ::coder::array<creal_T, 2U> &y)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      35,                                                            // lineNo
      14,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      39,                                                            // lineNo
      7,                                                             // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      11,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      18,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      35,                                                            // lineNo
      7,                                                             // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      25,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      12,        // lineNo
      "datawrap" // fName
  };
  int b_remainder;
  int i;
  int i1;
  int nFullPasses;
  int ny_tmp_tmp;
  int offset;
  if ((!(nfft >= 1.0)) || (!(std::floor(nfft) == nfft))) {
    fb_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  ny_tmp_tmp = static_cast<int>(nfft);
  if (x.size(0) == 1) {
    y.set_size(1, ny_tmp_tmp);
    for (i = 0; i < ny_tmp_tmp; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  } else {
    y.set_size(ny_tmp_tmp, 1);
    for (i = 0; i < ny_tmp_tmp; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  nFullPasses = div_s32(x.size(0), static_cast<int>(nfft));
  offset = nFullPasses * static_cast<int>(nfft);
  b_remainder = x.size(0) - offset;
  if (b_remainder > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < b_remainder; k++) {
    i = y.size(0) * y.size(1);
    if ((k + 1 < 1) || (k + 1 > i)) {
      rtDynamicBoundsError(k + 1, 1, i, &emlrtBCI);
    }
    i = (offset + k) + 1;
    if ((i < 1) || (i > x.size(0))) {
      rtDynamicBoundsError(i, 1, x.size(0), &b_emlrtBCI);
    }
    y[k].re = x[i - 1].re;
    if ((i < 1) || (i > x.size(0))) {
      rtDynamicBoundsError(i, 1, x.size(0), &b_emlrtBCI);
    }
    i1 = y.size(0) * y.size(1);
    if (k + 1 > i1) {
      rtDynamicBoundsError(k + 1, 1, i1, &emlrtBCI);
    }
    y[k].im = x[i - 1].im;
  }
  offset = b_remainder + 1;
  if ((b_remainder + 1 <= static_cast<int>(nfft)) &&
      (static_cast<int>(nfft) > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{offset}; k <= ny_tmp_tmp; k++) {
    i = y.size(0) * y.size(1);
    if ((k < 1) || (k > i)) {
      rtDynamicBoundsError(k, 1, i, &c_emlrtBCI);
    }
    y[k - 1].re = 0.0;
    i = y.size(0) * y.size(1);
    if (k > i) {
      rtDynamicBoundsError(k, 1, i, &c_emlrtBCI);
    }
    y[k - 1].im = 0.0;
  }
  if (nFullPasses > 2147483646) {
    check_forloop_overflow_error();
  }
  for (b_remainder = 0; b_remainder < nFullPasses; b_remainder++) {
    offset = b_remainder * static_cast<int>(nfft);
    if (static_cast<int>(nfft) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < ny_tmp_tmp; k++) {
      i = y.size(0) * y.size(1);
      if ((k + 1 < 1) || (k + 1 > i)) {
        rtDynamicBoundsError(k + 1, 1, i, &d_emlrtBCI);
      }
      i = y.size(0) * y.size(1);
      if (k + 1 > i) {
        rtDynamicBoundsError(k + 1, 1, i, &e_emlrtBCI);
      }
      i = (offset + k) + 1;
      if ((i < 1) || (i > x.size(0))) {
        rtDynamicBoundsError(i, 1, x.size(0), &f_emlrtBCI);
      }
      y[k].re = y[k].re + x[i - 1].re;
      i1 = y.size(0) * y.size(1);
      if (k + 1 > i1) {
        rtDynamicBoundsError(k + 1, 1, i1, &e_emlrtBCI);
      }
      if (i > x.size(0)) {
        rtDynamicBoundsError(i, 1, x.size(0), &f_emlrtBCI);
      }
      i1 = y.size(0) * y.size(1);
      if (k + 1 > i1) {
        rtDynamicBoundsError(k + 1, 1, i1, &d_emlrtBCI);
      }
      y[k].im = y[k].im + x[i - 1].im;
    }
  }
}

} // namespace coder

//
// File trailer for datawrap.cpp
//
// [EOF]
//
