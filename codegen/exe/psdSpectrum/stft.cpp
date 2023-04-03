//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: stft.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "stft.h"
#include "FFTImplementationCallback.h"
#include "datawrap.h"
#include "formatSTFTOutput.h"
#include "indexShapeCheck.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_internal_types.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include "stftParser.h"
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
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Requested array exceeds the maximum possible variable size.";
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
// Arguments    : const ::coder::array<creal_T, 2U> &x
//                double varargin_1
//                const ::coder::array<double, 1U> &varargin_3
//                double varargin_5
//                double varargin_7
//                ::coder::array<creal_T, 2U> &varargout_1
//                ::coder::array<double, 1U> &varargout_2
//                ::coder::array<double, 1U> &varargout_3
// Return Type  : void
//
namespace coder {
void stft(const ::coder::array<creal_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal_T, 2U> &varargout_1,
          ::coder::array<double, 1U> &varargout_2,
          ::coder::array<double, 1U> &varargout_3)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      23,               // lineNo
      23,               // colNo
      "",               // aName
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      23,               // lineNo
      42,               // colNo
      "",               // aName
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      84,                 // lineNo
      38,                 // colNo
      "",                 // aName
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      85,                 // lineNo
      14,                 // colNo
      "",                 // aName
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      23,               // lineNo
      11,               // colNo
      "",               // aName
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      279,                                                          // lineNo
      12,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      279,                                                          // lineNo
      14,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      278,                                                          // lineNo
      12,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      278,                                                          // lineNo
      14,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      14,               // lineNo
      30,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      14,               // lineNo
      30,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      4                         // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      14,               // lineNo
      5,                // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      23,               // lineNo
      23,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      23,               // lineNo
      42,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo h_emlrtDCI{
      81,                 // lineNo
      12,                 // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      4 // checkKind
  };
  static rtDoubleCheckInfo i_emlrtDCI{
      81,                 // lineNo
      12,                 // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      1 // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      -1,               // nDims
      23,               // lineNo
      5,                // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m" // pName
  };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      52,   // lineNo
      "fft" // fName
  };
  array<creal_T, 2U> c;
  array<creal_T, 2U> wrappedData;
  array<creal_T, 2U> xin;
  array<creal_T, 2U> xw;
  array<creal_T, 1U> data;
  array<double, 2U> costab;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  array<double, 2U> y;
  array<double, 1U> f;
  b_struct_T opts;
  double hopSize;
  double nCol;
  int iv[2];
  int b_bcoef;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int k;
  signal::internal::stft::stftParser(x, varargin_1, varargin_3, varargin_5,
                                     varargin_7, data, &opts);
  hopSize = opts.WindowLength - opts.OverlapLength;
  nCol = std::trunc((opts.DataLength - opts.OverlapLength) / hopSize);
  xin.set_size(static_cast<int>(opts.WindowLength), xin.size(1));
  if (!(nCol >= 0.0)) {
    rtNonNegativeError(nCol, &d_emlrtDCI);
  }
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, &c_emlrtDCI);
  }
  xin.set_size(xin.size(0), static_cast<int>(nCol));
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, &e_emlrtDCI);
  }
  bcoef = static_cast<int>(opts.WindowLength) * static_cast<int>(nCol);
  for (i = 0; i < bcoef; i++) {
    xin[i].re = 0.0;
    xin[i].im = 0.0;
  }
  if (nCol - 1.0 < 0.0) {
    y.set_size(y.size(0), 0);
  } else {
    y.set_size(1, static_cast<int>(nCol - 1.0) + 1);
    bcoef = static_cast<int>(nCol - 1.0);
    for (i = 0; i <= bcoef; i++) {
      y[i] = i;
    }
  }
  i = static_cast<int>(nCol);
  for (bcoef = 0; bcoef < i; bcoef++) {
    double d;
    nCol = hopSize * ((static_cast<double>(bcoef) + 1.0) - 1.0);
    d = opts.WindowLength + nCol;
    if (nCol + 1.0 > d) {
      i1 = 0;
      k = 0;
    } else {
      if (nCol + 1.0 != static_cast<int>(std::floor(nCol + 1.0))) {
        rtIntegerError(nCol + 1.0, &f_emlrtDCI);
      }
      if ((static_cast<int>(nCol + 1.0) < 1) ||
          (static_cast<int>(nCol + 1.0) > data.size(0))) {
        rtDynamicBoundsError(static_cast<int>(nCol + 1.0), 1, data.size(0),
                             &b_emlrtBCI);
      }
      i1 = static_cast<int>(nCol + 1.0) - 1;
      if (d != static_cast<int>(std::floor(d))) {
        rtIntegerError(d, &g_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) || (static_cast<int>(d) > data.size(0))) {
        rtDynamicBoundsError(static_cast<int>(d), 1, data.size(0), &c_emlrtBCI);
      }
      k = static_cast<int>(d);
    }
    if ((bcoef + 1 < 1) || (bcoef + 1 > xin.size(1))) {
      rtDynamicBoundsError(bcoef + 1, 1, xin.size(1), &emlrtBCI);
    }
    b_bcoef = k - i1;
    rtSubAssignSizeCheck(xin.size(), 1, &b_bcoef, 1, &b_emlrtECI);
    for (k = 0; k < b_bcoef; k++) {
      xin[k + xin.size(0) * bcoef] = data[i1 + k];
    }
  }
  y.set_size(1, y.size(1));
  nCol = opts.WindowLength / 2.0;
  bcoef = y.size(1) - 1;
  for (i = 0; i <= bcoef; i++) {
    y[i] = (y[i] * hopSize + nCol) / opts.EffectiveFs;
  }
  if (xin.size(0) == 1) {
    csz_idx_0 = opts.Window.size(0);
  } else if (opts.Window.size(0) == 1) {
    csz_idx_0 = xin.size(0);
  } else if (opts.Window.size(0) == xin.size(0)) {
    csz_idx_0 = opts.Window.size(0);
  } else {
    j_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  c.set_size(csz_idx_0, xin.size(1));
  if ((csz_idx_0 != 0) && (xin.size(1) != 0)) {
    b_bcoef = (xin.size(1) != 1);
    i = xin.size(1) - 1;
    bcoef = (xin.size(0) != 1);
    for (k = 0; k <= i; k++) {
      csz_idx_0 = b_bcoef * k;
      i1 = c.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        c[b_k + c.size(0) * k] = xin[bcoef * b_k + xin.size(0) * csz_idx_0];
      }
    }
  }
  if (!(opts.FFTLength >= 0.0)) {
    rtNonNegativeError(opts.FFTLength, &h_emlrtDCI);
  }
  nCol = static_cast<int>(std::floor(opts.FFTLength));
  if (opts.FFTLength != nCol) {
    rtIntegerError(opts.FFTLength, &i_emlrtDCI);
  }
  xw.set_size(static_cast<int>(opts.FFTLength), c.size(1));
  if (opts.FFTLength != nCol) {
    rtIntegerError(opts.FFTLength, &b_emlrtDCI);
  }
  bcoef = static_cast<int>(opts.FFTLength) * c.size(1);
  for (i = 0; i < bcoef; i++) {
    xw[i].re = 0.0;
    xw[i].im = 0.0;
  }
  if (c.size(0) > opts.FFTLength) {
    i = c.size(1);
    for (csz_idx_0 = 0; csz_idx_0 < i; csz_idx_0++) {
      if (csz_idx_0 + 1 > c.size(1)) {
        rtDynamicBoundsError(csz_idx_0 + 1, 1, c.size(1), &d_emlrtBCI);
      }
      bcoef = c.size(0);
      data.set_size(c.size(0));
      for (i1 = 0; i1 < bcoef; i1++) {
        data[i1] = c[i1 + c.size(0) * csz_idx_0];
      }
      datawrap(data, opts.FFTLength, wrappedData);
      if (csz_idx_0 + 1 > xw.size(1)) {
        rtDynamicBoundsError(csz_idx_0 + 1, 1, xw.size(1), &e_emlrtBCI);
      }
      b_bcoef = wrappedData.size(0) * wrappedData.size(1);
      rtSubAssignSizeCheck(xw.size(), 1, &b_bcoef, 1, &emlrtECI);
      b_bcoef = wrappedData.size(0) * wrappedData.size(1);
      for (i1 = 0; i1 < b_bcoef; i1++) {
        xw[i1 + xw.size(0) * csz_idx_0] = wrappedData[i1];
      }
    }
  } else {
    xw.set_size(c.size(0), c.size(1));
    bcoef = c.size(0) * c.size(1);
    for (i = 0; i < bcoef; i++) {
      xw[i] = c[i];
    }
  }
  if (xw.size(0) == 1) {
    b_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (!(opts.FFTLength <= 2.147483647E+9)) {
    i_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if ((xw.size(0) == 0) || (xw.size(1) == 0) ||
      (static_cast<int>(opts.FFTLength) == 0)) {
    varargout_1.set_size(static_cast<int>(opts.FFTLength), xw.size(1));
    bcoef = static_cast<int>(opts.FFTLength) * xw.size(1);
    for (i = 0; i < bcoef; i++) {
      varargout_1[i].re = 0.0;
      varargout_1[i].im = 0.0;
    }
  } else {
    boolean_T useRadix2;
    useRadix2 = ((static_cast<int>(opts.FFTLength) > 0) &&
                 ((static_cast<int>(opts.FFTLength) &
                   (static_cast<int>(opts.FFTLength) - 1)) == 0));
    internal::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(opts.FFTLength), useRadix2, &b_bcoef, &bcoef);
    internal::FFTImplementationCallback::generate_twiddle_tables(
        bcoef, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      internal::FFTImplementationCallback::r2br_r2dit_trig(
          xw, static_cast<int>(opts.FFTLength), costab, sintab, varargout_1);
    } else {
      internal::FFTImplementationCallback::dobluesteinfft(
          xw, b_bcoef, static_cast<int>(opts.FFTLength), costab, sintab,
          sintabinv, varargout_1);
    }
  }
  psdfreqvec(opts.FFTLength, opts.EffectiveFs, f);
  signal::internal::stft::formatSTFTOutput(varargout_1, f, &opts);
  if (varargout_1.size(0) < 1) {
    bcoef = 0;
  } else {
    if (f.size(0) < 1) {
      rtDynamicBoundsError(1, 1, f.size(0), &h_emlrtBCI);
    }
    if (varargout_1.size(0) > f.size(0)) {
      rtDynamicBoundsError(varargout_1.size(0), 1, f.size(0), &i_emlrtBCI);
    }
    bcoef = varargout_1.size(0);
  }
  iv[0] = 1;
  iv[1] = bcoef;
  internal::indexShapeCheck(f.size(0), iv);
  varargout_2.set_size(bcoef);
  for (i = 0; i < bcoef; i++) {
    varargout_2[i] = f[i];
  }
  if (varargout_1.size(1) < 1) {
    bcoef = 0;
  } else {
    if (y.size(1) < 1) {
      rtDynamicBoundsError(1, 1, y.size(1), &f_emlrtBCI);
    }
    if (varargout_1.size(1) > y.size(1)) {
      rtDynamicBoundsError(varargout_1.size(1), 1, y.size(1), &g_emlrtBCI);
    }
    bcoef = varargout_1.size(1);
  }
  varargout_3.set_size(bcoef);
  for (i = 0; i < bcoef; i++) {
    varargout_3[i] = y[i];
  }
}

} // namespace coder

//
// File trailer for stft.cpp
//
// [EOF]
//
