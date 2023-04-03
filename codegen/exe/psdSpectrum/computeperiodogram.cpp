//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeperiodogram.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "computeperiodogram.h"
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "psdfreqvec.h"
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
static void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "The ") << r)
      << " must be a vector of the same length as the signal.";
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
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Non-singleton dimensions of the two input arrays must match "
               "each other.";
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
static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "The input must be either a vector or two-dimensional matrix.";
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
static void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Assertion failed.";
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
static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream
      << "The dimension to operate along was selected automatically, is "
         "variable-length, and has length 1 at run time. This is not support"
         "ed. Manually select the dimension to operate along by supplying the "
         "DIM argument.";
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
//                const ::coder::array<double, 1U> &win
//                double nfft
//                double Fs
//                ::coder::array<double, 1U> &Pxx
//                ::coder::array<double, 1U> &F
// Return Type  : void
//
namespace coder {
void computeperiodogram(const ::coder::array<creal_T, 1U> &x,
                        const ::coder::array<double, 1U> &win, double nfft,
                        double Fs, ::coder::array<double, 1U> &Pxx,
                        ::coder::array<double, 1U> &F)
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
  static rtDoubleCheckInfo b_emlrtDCI{
      81,                 // lineNo
      1,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo emlrtDCI{
      81,                 // lineNo
      1,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      4 // checkKind
  };
  static rtEqualityCheckInfo
      b_emlrtECI{
          -1,                   // nDims
          130,                  // lineNo
          14,                   // colNo
          "computeperiodogram", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeperiodogram."
          "m" // pName
      };
  static rtEqualityCheckInfo emlrtECI{
      -1,                 // nDims
      85,                 // lineNo
      9,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m" // pName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      193,             // lineNo
      "validateinputs" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      196,             // lineNo
      "validateinputs" // fName
  };
  static rtRunTimeErrorInfo h_emlrtRTEI{
      12,        // lineNo
      "datawrap" // fName
  };
  static rtRunTimeErrorInfo i_emlrtRTEI{
      37,   // lineNo
      "fft" // fName
  };
  static rtRunTimeErrorInfo j_emlrtRTEI{
      417,                                       // lineNo
      "FFTImplementationCallback/get_algo_sizes" // fName
  };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      53,      // lineNo
      "bsxfun" // fName
  };
  array<creal_T, 2U> wrappedData;
  array<creal_T, 1U> b_x;
  array<creal_T, 1U> b_xw;
  array<creal_T, 1U> xw;
  array<double, 2U> costab;
  array<double, 2U> costab1q;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  double e;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int k;
  int loop_ub_tmp;
  int nFullPasses;
  boolean_T exitg1;
  boolean_T useRadix2;
  if (std::isnan(Fs)) {
    Fs = 6.2831853071795862;
  }
  useRadix2 = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x.size(0) - 1)) {
    if ((!std::isinf(x[k].re)) && (!std::isinf(x[k].im)) &&
        ((!std::isnan(x[k].re)) && (!std::isnan(x[k].im)))) {
      k++;
    } else {
      useRadix2 = false;
      exitg1 = true;
    }
  }
  if (!useRadix2) {
    c_rtErrorWithMessageID("x", d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  useRadix2 = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x.size(0) - 1)) {
    if ((!std::isnan(x[k].re)) && (!std::isnan(x[k].im))) {
      k++;
    } else {
      useRadix2 = false;
      exitg1 = true;
    }
  }
  if (!useRadix2) {
    e_rtErrorWithMessageID("x", e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  if (x.size(0) != win.size(0)) {
    f_rtErrorWithMessageID("window", f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  if (x.size(0) < 2) {
    q_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (win.size(0) == 1) {
    csz_idx_0 = x.size(0);
  } else if (x.size(0) == win.size(0)) {
    csz_idx_0 = x.size(0);
  } else {
    p_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  xw.set_size(csz_idx_0);
  if (csz_idx_0 != 0) {
    bcoef = (win.size(0) != 1);
    i = csz_idx_0 - 1;
    for (k = 0; k <= i; k++) {
      e = win[bcoef * k];
      xw[k].re = e * x[k].re;
      xw[k].im = e * x[k].im;
    }
  }
  if (!(nfft >= 0.0)) {
    rtNonNegativeError(nfft, &emlrtDCI);
  }
  i = static_cast<int>(std::floor(nfft));
  if (nfft != i) {
    rtIntegerError(nfft, &b_emlrtDCI);
  }
  loop_ub_tmp = static_cast<int>(nfft);
  b_xw.set_size(loop_ub_tmp);
  if (loop_ub_tmp != i) {
    rtIntegerError(nfft, &b_emlrtDCI);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    b_xw[i].re = 0.0;
    b_xw[i].im = 0.0;
  }
  if (xw.size(0) > loop_ub_tmp) {
    csz_idx_0 = xw.size(0);
    b_x.set_size(xw.size(0));
    for (i = 0; i < csz_idx_0; i++) {
      b_x[i] = xw[i];
    }
    if (!(nfft >= 1.0)) {
      bb_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
    }
    if (xw.size(0) == 1) {
      wrappedData.set_size(1, loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        wrappedData[i].re = 0.0;
        wrappedData[i].im = 0.0;
      }
    } else {
      wrappedData.set_size(loop_ub_tmp, 1);
      for (i = 0; i < loop_ub_tmp; i++) {
        wrappedData[i].re = 0.0;
        wrappedData[i].im = 0.0;
      }
    }
    nFullPasses = div_s32(xw.size(0), loop_ub_tmp);
    csz_idx_0 = nFullPasses * loop_ub_tmp;
    bcoef = xw.size(0) - csz_idx_0;
    if (bcoef > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < bcoef; k++) {
      i = wrappedData.size(0) * wrappedData.size(1);
      if ((k + 1 < 1) || (k + 1 > i)) {
        rtDynamicBoundsError(k + 1, 1, i, &emlrtBCI);
      }
      i = (csz_idx_0 + k) + 1;
      if ((i < 1) || (i > xw.size(0))) {
        rtDynamicBoundsError(i, 1, xw.size(0), &b_emlrtBCI);
      }
      wrappedData[k].re = b_x[i - 1].re;
      i1 = wrappedData.size(0) * wrappedData.size(1);
      if (k + 1 > i1) {
        rtDynamicBoundsError(k + 1, 1, i1, &emlrtBCI);
      }
      if (i > xw.size(0)) {
        rtDynamicBoundsError(i, 1, xw.size(0), &b_emlrtBCI);
      }
      wrappedData[k].im = b_x[i - 1].im;
    }
    i = bcoef + 1;
    for (k = i; k <= loop_ub_tmp; k++) {
      i1 = wrappedData.size(0) * wrappedData.size(1);
      if ((k < 1) || (k > i1)) {
        rtDynamicBoundsError(k, 1, i1, &c_emlrtBCI);
      }
      wrappedData[k - 1].re = 0.0;
      i1 = wrappedData.size(0) * wrappedData.size(1);
      if (k > i1) {
        rtDynamicBoundsError(k, 1, i1, &c_emlrtBCI);
      }
      wrappedData[k - 1].im = 0.0;
    }
    if (nFullPasses > 2147483646) {
      check_forloop_overflow_error();
    }
    for (bcoef = 0; bcoef < nFullPasses; bcoef++) {
      csz_idx_0 = bcoef * loop_ub_tmp;
      for (k = 0; k < loop_ub_tmp; k++) {
        i = wrappedData.size(0) * wrappedData.size(1);
        if (k + 1 > i) {
          rtDynamicBoundsError(k + 1, 1, i, &d_emlrtBCI);
        }
        i = wrappedData.size(0) * wrappedData.size(1);
        if (k + 1 > i) {
          rtDynamicBoundsError(k + 1, 1, i, &e_emlrtBCI);
        }
        i = (csz_idx_0 + k) + 1;
        if ((i < 1) || (i > xw.size(0))) {
          rtDynamicBoundsError(i, 1, xw.size(0), &f_emlrtBCI);
        }
        wrappedData[k].re = wrappedData[k].re + b_x[i - 1].re;
        i1 = wrappedData.size(0) * wrappedData.size(1);
        if (k + 1 > i1) {
          rtDynamicBoundsError(k + 1, 1, i1, &d_emlrtBCI);
        }
        if (i > xw.size(0)) {
          rtDynamicBoundsError(i, 1, xw.size(0), &f_emlrtBCI);
        }
        i1 = wrappedData.size(0) * wrappedData.size(1);
        if (k + 1 > i1) {
          rtDynamicBoundsError(k + 1, 1, i1, &e_emlrtBCI);
        }
        wrappedData[k].im = wrappedData[k].im + b_x[i - 1].im;
      }
    }
    csz_idx_0 = wrappedData.size(0) * wrappedData.size(1);
    rtSubAssignSizeCheck(&loop_ub_tmp, 1, &csz_idx_0, 1, &emlrtECI);
    csz_idx_0 = wrappedData.size(0) * wrappedData.size(1);
    for (i = 0; i < csz_idx_0; i++) {
      b_xw[i] = wrappedData[i];
    }
  } else {
    b_xw.set_size(xw.size(0));
    csz_idx_0 = xw.size(0);
    for (i = 0; i < csz_idx_0; i++) {
      b_xw[i] = xw[i];
    }
  }
  if (b_xw.size(0) == 1) {
    s_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if ((b_xw.size(0) == 0) || (nfft == 0.0)) {
    b_x.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_x[i].re = 0.0;
      b_x[i].im = 0.0;
    }
  } else {
    int n;
    useRadix2 = ((loop_ub_tmp & (loop_ub_tmp - 1)) == 0);
    bcoef = 1;
    if (!useRadix2) {
      n = (loop_ub_tmp + loop_ub_tmp) - 1;
      csz_idx_0 = 31;
      if (n <= 1) {
        csz_idx_0 = 0;
      } else {
        bcoef = 0;
        exitg1 = false;
        while ((!exitg1) && (csz_idx_0 - bcoef > 1)) {
          k = (bcoef + csz_idx_0) >> 1;
          nFullPasses = 1 << k;
          if (nFullPasses == n) {
            csz_idx_0 = k;
            exitg1 = true;
          } else if (nFullPasses > n) {
            csz_idx_0 = k;
          } else {
            bcoef = k;
          }
        }
      }
      bcoef = 1 << csz_idx_0;
      csz_idx_0 = loop_ub_tmp << 2;
      if (csz_idx_0 < 1) {
        csz_idx_0 = 1;
      }
      if (bcoef > csz_idx_0) {
        r_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      }
      loop_ub_tmp = bcoef;
    }
    e = 6.2831853071795862 / static_cast<double>(loop_ub_tmp);
    n = loop_ub_tmp / 2 / 2;
    costab1q.set_size(1, n + 1);
    costab1q[0] = 1.0;
    csz_idx_0 = n / 2 - 1;
    for (k = 0; k <= csz_idx_0; k++) {
      costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
    }
    i = csz_idx_0 + 2;
    i1 = n - 1;
    for (k = i; k <= i1; k++) {
      costab1q[k] = std::sin(e * static_cast<double>(n - k));
    }
    costab1q[n] = 0.0;
    if (!useRadix2) {
      n = costab1q.size(1) - 1;
      csz_idx_0 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, csz_idx_0 + 1);
      sintab.set_size(1, csz_idx_0 + 1);
      costab[0] = 1.0;
      sintab[0] = 0.0;
      sintabinv.set_size(1, csz_idx_0 + 1);
      for (k = 0; k < n; k++) {
        sintabinv[k + 1] = costab1q[(n - k) - 1];
      }
      i = costab1q.size(1);
      for (k = i; k <= csz_idx_0; k++) {
        sintabinv[k] = costab1q[k - n];
      }
      for (k = 0; k < n; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(n - k) - 1];
      }
      i = costab1q.size(1);
      for (k = i; k <= csz_idx_0; k++) {
        costab[k] = -costab1q[csz_idx_0 - k];
        sintab[k] = -costab1q[k - n];
      }
    } else {
      n = costab1q.size(1) - 1;
      csz_idx_0 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, csz_idx_0 + 1);
      sintab.set_size(1, csz_idx_0 + 1);
      costab[0] = 1.0;
      sintab[0] = 0.0;
      for (k = 0; k < n; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(n - k) - 1];
      }
      i = costab1q.size(1);
      for (k = i; k <= csz_idx_0; k++) {
        costab[k] = -costab1q[csz_idx_0 - k];
        sintab[k] = -costab1q[k - n];
      }
      sintabinv.set_size(1, 0);
    }
    if (useRadix2) {
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          b_xw, static_cast<int>(nfft), costab, sintab, b_x);
    } else {
      internal::fft::FFTImplementationCallback::dobluesteinfft(
          b_xw, bcoef, static_cast<int>(nfft), costab, sintab, sintabinv, b_x);
    }
  }
  psdfreqvec(nfft, Fs, F);
  e = 0.0;
  csz_idx_0 = win.size(0);
  for (i = 0; i < csz_idx_0; i++) {
    e += win[i] * win[i];
  }
  xw.set_size(b_x.size(0));
  csz_idx_0 = b_x.size(0);
  for (i = 0; i < csz_idx_0; i++) {
    xw[i].re = b_x[i].re;
    xw[i].im = -b_x[i].im;
  }
  if (b_x.size(0) != xw.size(0)) {
    rtSizeEq1DError(b_x.size(0), xw.size(0), &b_emlrtECI);
  }
  Pxx.set_size(b_x.size(0));
  csz_idx_0 = b_x.size(0);
  for (i = 0; i < csz_idx_0; i++) {
    double b_x_re_tmp;
    double c_x_re_tmp;
    double d_x_re_tmp;
    double x_re;
    double x_re_tmp;
    x_re_tmp = b_x[i].re;
    b_x_re_tmp = xw[i].im;
    c_x_re_tmp = b_x[i].im;
    d_x_re_tmp = xw[i].re;
    x_re = x_re_tmp * d_x_re_tmp - c_x_re_tmp * b_x_re_tmp;
    if (x_re_tmp * b_x_re_tmp + c_x_re_tmp * d_x_re_tmp == 0.0) {
      x_re /= e;
    } else if (x_re == 0.0) {
      x_re = 0.0;
    } else {
      x_re /= e;
    }
    Pxx[i] = x_re;
  }
}

} // namespace coder

//
// File trailer for computeperiodogram.cpp
//
// [EOF]
//
