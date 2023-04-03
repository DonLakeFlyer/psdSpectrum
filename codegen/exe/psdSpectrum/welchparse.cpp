//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: welchparse.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "welchparse.h"
#include "hamming.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_internal_types.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "psdoptions.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void cb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void db_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void eb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void j_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Window size must be larger than 1 sample.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void cb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream
      << "To RESHAPE the number of elements must not change, and if the input "
         "is empty, the maximum dimension length cannot be increased u"
         "nless the output size is fixed.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void db_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "The number of samples to overlap must be less than the length "
               "of the segments.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void eb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "The length of the segments cannot be greater than the length "
               "of the input signal.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void j_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "The ") << r) << " argument must be a vector or a scalar.";
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
// Arguments    : const ::coder::array<creal_T, 2U> &x1
//                ::coder::array<double, 1U> &varargin_1
//                double varargin_2
//                double varargin_3
//                double varargin_4
//                const char varargin_5[8]
//                ::coder::array<creal_T, 1U> &x
//                double *M
//                char winName_data[]
//                int winName_size[2]
//                char winParam_data[]
//                int winParam_size[2]
//                double *noverlap
//                double *k
//                double *L
//                struct_T *options
// Return Type  : void
//
namespace coder {
namespace signal {
namespace internal {
namespace spectral {
void welchparse(const ::coder::array<creal_T, 2U> &x1,
                ::coder::array<double, 1U> &varargin_1, double varargin_2,
                double varargin_3, double varargin_4, const char varargin_5[8],
                ::coder::array<creal_T, 1U> &x, double *M, char winName_data[],
                int winName_size[2], char winParam_data[], int winParam_size[2],
                double *noverlap, double *k, double *L, struct_T *options)
{
  static rtRunTimeErrorInfo k_emlrtRTEI{
      52,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      183,           // lineNo
      "parse_inputs" // fName
  };
  static rtRunTimeErrorInfo m_emlrtRTEI{
      275,           // lineNo
      "segment_info" // fName
  };
  static rtRunTimeErrorInfo n_emlrtRTEI{
      276,           // lineNo
      "segment_info" // fName
  };
  static rtRunTimeErrorInfo o_emlrtRTEI{
      251,           // lineNo
      "segment_info" // fName
  };
  static const char b_cv[12]{'U', 's', 'e', 'r', ' ', 'D',
                             'e', 'f', 'i', 'n', 'e', 'd'};
  static const char b_cv2[9]{'s', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c'};
  static const char b_options_range[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  static const char b_cv1[7]{'h', 'a', 'm', 'm', 'i', 'n', 'g'};
  double absn;
  int b_k;
  int eint;
  int u0;
  char options_range[8];
  boolean_T exitg1;
  boolean_T p;
  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= x1.size(1) - 1)) {
    if ((!std::isinf(x1[b_k].re)) && (!std::isinf(x1[b_k].im)) &&
        ((!std::isnan(x1[b_k].re)) && (!std::isnan(x1[b_k].im)))) {
      b_k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    f_rtErrorWithMessageID("x", i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= x1.size(1) - 1)) {
    if ((!std::isnan(x1[b_k].re)) && (!std::isnan(x1[b_k].im))) {
      b_k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    e_rtErrorWithMessageID("x", h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  b_k = 1;
  if (x1.size(1) > 1) {
    b_k = x1.size(1);
  }
  u0 = x1.size(1);
  if (u0 >= b_k) {
    b_k = u0;
  }
  if (x1.size(1) > b_k) {
    cb_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  x.set_size(x1.size(1));
  b_k = x1.size(1);
  for (u0 = 0; u0 < b_k; u0++) {
    x[u0] = x1[u0];
  }
  if (varargin_1.size(0) == 1) {
    bb_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  if ((varargin_1.size(0) == 0) || (varargin_1.size(0) == 1)) {
    winName_size[0] = 1;
    winName_size[1] = 7;
    for (u0 = 0; u0 < 7; u0++) {
      winName_data[u0] = b_cv1[u0];
    }
    winParam_size[0] = 1;
    winParam_size[1] = 9;
    for (u0 = 0; u0 < 9; u0++) {
      winParam_data[u0] = b_cv2[u0];
    }
  } else {
    winName_size[0] = 1;
    winName_size[1] = 12;
    for (u0 = 0; u0 < 12; u0++) {
      winName_data[u0] = b_cv[u0];
    }
    winParam_size[0] = 1;
    winParam_size[1] = 0;
  }
  u0 = x1.size(1);
  if (varargin_1.size(0) == 0) {
    *L = std::trunc((static_cast<double>(x1.size(1)) + 7.0 * varargin_2) / 8.0);
    hamming(*L, varargin_1);
  } else {
    boolean_T x_data[3];
    x_data[0] = (varargin_1.size(0) <= 1);
    x_data[1] = true;
    p = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= 1)) {
      if (x_data[b_k]) {
        p = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (!p) {
      j_rtErrorWithMessageID("WINDOW", o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
    }
    if (varargin_1.size(0) > 1) {
      *L = varargin_1.size(0);
    } else {
      hamming(1.0, varargin_1);
      *L = varargin_1.size(0);
    }
  }
  if (*L > x1.size(1)) {
    eb_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
  if (varargin_2 >= *L) {
    db_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
  }
  absn = std::abs(*L);
  if ((!std::isinf(absn)) && (!std::isnan(absn))) {
    frexp(absn, &eint);
  }
  for (int i{0}; i < 8; i++) {
    options_range[i] = b_options_range[i];
  }
  psdoptions(options_range, varargin_3, varargin_4, varargin_5, &options->nfft,
             &options->Fs, &options->maxhold, &options->minhold,
             &options->centerdc, options->range);
  *k = std::trunc((static_cast<double>(x1.size(1)) - varargin_2) /
                  (*L - varargin_2));
  *M = u0;
  *noverlap = varargin_2;
}

} // namespace spectral
} // namespace internal
} // namespace signal
} // namespace coder

//
// File trailer for welchparse.cpp
//
// [EOF]
//
