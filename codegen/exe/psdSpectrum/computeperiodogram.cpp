//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeperiodogram.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "computeperiodogram.h"
#include "FFTImplementationCallback.h"
#include "datawrap.h"
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
static void h_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void w_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void h_rtErrorWithMessageID(const char *r, const char *aFcnName,
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
static void w_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
  static rtDoubleCheckInfo c_emlrtDCI{
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
  static rtRunTimeErrorInfo k_emlrtRTEI{
      193,             // lineNo
      "validateinputs" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      196,             // lineNo
      "validateinputs" // fName
  };
  array<creal_T, 2U> wrappedData;
  array<creal_T, 1U> Xx;
  array<creal_T, 1U> b_xw;
  array<creal_T, 1U> xw;
  array<double, 2U> costab;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  double b_win;
  int bcoef;
  int csz_idx_0;
  int i;
  int k;
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
    f_rtErrorWithMessageID("x", i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
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
    e_rtErrorWithMessageID("x", h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  if (x.size(0) != win.size(0)) {
    h_rtErrorWithMessageID("window", k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if (x.size(0) < 2) {
    w_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  if (win.size(0) == 1) {
    csz_idx_0 = x.size(0);
  } else if (x.size(0) == win.size(0)) {
    csz_idx_0 = x.size(0);
  } else {
    j_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  xw.set_size(csz_idx_0);
  if (csz_idx_0 != 0) {
    bcoef = (win.size(0) != 1);
    i = csz_idx_0 - 1;
    for (k = 0; k <= i; k++) {
      b_win = win[bcoef * k];
      xw[k].re = b_win * x[k].re;
      xw[k].im = b_win * x[k].im;
    }
  }
  if (!(nfft >= 0.0)) {
    rtNonNegativeError(nfft, &c_emlrtDCI);
  }
  i = static_cast<int>(std::floor(nfft));
  if (nfft != i) {
    rtIntegerError(nfft, &b_emlrtDCI);
  }
  k = static_cast<int>(nfft);
  b_xw.set_size(k);
  if (k != i) {
    rtIntegerError(nfft, &b_emlrtDCI);
  }
  for (i = 0; i < k; i++) {
    b_xw[i].re = 0.0;
    b_xw[i].im = 0.0;
  }
  if (xw.size(0) > k) {
    datawrap(xw, nfft, wrappedData);
    csz_idx_0 = wrappedData.size(0) * wrappedData.size(1);
    rtSubAssignSizeCheck(&k, 1, &csz_idx_0, 1, &emlrtECI);
    csz_idx_0 = wrappedData.size(0) * wrappedData.size(1);
    for (i = 0; i < csz_idx_0; i++) {
      b_xw[i] = wrappedData[i];
    }
  } else {
    b_xw.set_size(xw.size(0));
    bcoef = xw.size(0);
    for (i = 0; i < bcoef; i++) {
      b_xw[i] = xw[i];
    }
  }
  if (b_xw.size(0) == 1) {
    b_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if ((b_xw.size(0) == 0) || (nfft == 0.0)) {
    Xx.set_size(k);
    for (i = 0; i < k; i++) {
      Xx[i].re = 0.0;
      Xx[i].im = 0.0;
    }
  } else {
    useRadix2 = ((k & (k - 1)) == 0);
    internal::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(nfft), useRadix2, &csz_idx_0, &bcoef);
    internal::FFTImplementationCallback::generate_twiddle_tables(
        bcoef, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          b_xw, static_cast<int>(nfft), costab, sintab, Xx);
    } else {
      internal::FFTImplementationCallback::dobluesteinfft(
          b_xw, csz_idx_0, static_cast<int>(nfft), costab, sintab, sintabinv,
          Xx);
    }
  }
  psdfreqvec(nfft, Fs, F);
  b_win = 0.0;
  bcoef = win.size(0);
  for (i = 0; i < bcoef; i++) {
    b_win += win[i] * win[i];
  }
  xw.set_size(Xx.size(0));
  bcoef = Xx.size(0);
  for (i = 0; i < bcoef; i++) {
    xw[i].re = Xx[i].re;
    xw[i].im = -Xx[i].im;
  }
  if (Xx.size(0) != xw.size(0)) {
    rtSizeEq1DError(Xx.size(0), xw.size(0), &b_emlrtECI);
  }
  Pxx.set_size(Xx.size(0));
  bcoef = Xx.size(0);
  for (i = 0; i < bcoef; i++) {
    double Xx_re;
    double Xx_re_tmp;
    double b_Xx_re_tmp;
    double c_Xx_re_tmp;
    double d_Xx_re_tmp;
    Xx_re_tmp = Xx[i].re;
    b_Xx_re_tmp = xw[i].im;
    c_Xx_re_tmp = Xx[i].im;
    d_Xx_re_tmp = xw[i].re;
    Xx_re = Xx_re_tmp * d_Xx_re_tmp - c_Xx_re_tmp * b_Xx_re_tmp;
    if (Xx_re_tmp * b_Xx_re_tmp + c_Xx_re_tmp * d_Xx_re_tmp == 0.0) {
      Xx_re /= b_win;
    } else if (Xx_re == 0.0) {
      Xx_re = 0.0;
    } else {
      Xx_re /= b_win;
    }
    Pxx[i] = Xx_re;
  }
}

} // namespace coder

//
// File trailer for computeperiodogram.cpp
//
// [EOF]
//
