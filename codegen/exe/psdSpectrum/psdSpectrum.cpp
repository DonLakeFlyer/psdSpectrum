//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "psdSpectrum.h"
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "fileManager.h"
#include "fread.h"
#include "log10.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_initialize.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "readairspybinfile.h"
#include "rt_nonfinite.h"
#include "stft.h"
#include "welch.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>

// Function Declarations
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

static void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Order must be greater than or equal to zero.";
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
static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Order, ") << r) << ", must be finite.";
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
static void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "fopen(\'all\') is not supported for code generation.";
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
// Arguments    : double Fs
//                double centerFreqMHz
//                const coder::array<char, 2U> &file
// Return Type  : void
//
void psdSpectrum(double Fs, double, const coder::array<char, 2U> &file)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                                            // iFirst
      -1,                                            // iLast
      14,                                            // lineNo
      15,                                            // colNo
      "dataRaw",                                     // aName
      "readairspybinfile",                           // fName
      "H:\\repos\\psdSpectrum\\readairspybinfile.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                                            // iFirst
      -1,                                            // iLast
      19,                                            // lineNo
      23,                                            // colNo
      "dataRaw",                                     // aName
      "readairspybinfile",                           // fName
      "H:\\repos\\psdSpectrum\\readairspybinfile.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                                            // iFirst
      -1,                                            // iLast
      19,                                            // lineNo
      45,                                            // colNo
      "dataRaw",                                     // aName
      "readairspybinfile",                           // fName
      "H:\\repos\\psdSpectrum\\readairspybinfile.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,                                            // iFirst
      -1,                                            // iLast
      14,                                            // lineNo
      13,                                            // colNo
      "dataRaw",                                     // aName
      "readairspybinfile",                           // fName
      "H:\\repos\\psdSpectrum\\readairspybinfile.m", // pName
      0                                              // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      2,                                            // nDims
      19,                                           // lineNo
      15,                                           // colNo
      "readairspybinfile",                          // fName
      "H:\\repos\\psdSpectrum\\readairspybinfile.m" // pName
  };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      37,     // lineNo
      "fopen" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      18,           // lineNo
      "check_order" // fName
  };
  static rtRunTimeErrorInfo m_emlrtRTEI{
      22,           // lineNo
      "check_order" // fName
  };
  static const char b_cv[3]{'a', 'l', 'l'};
  coder::array<creal_T, 2U> data;
  coder::array<creal_T, 2U> dataFFT;
  coder::array<creal_T, 2U> s;
  coder::array<creal_T, 1U> b_data;
  coder::array<creal_T, 1U> yCol;
  coder::array<double, 2U> costab;
  coder::array<double, 2U> dataRaw;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 2U> sintab;
  coder::array<double, 2U> sintabinv;
  coder::array<double, 2U> welchOut_f1;
  coder::array<double, 1U> fStft;
  coder::array<double, 1U> rectWind;
  coder::array<double, 1U> tStft;
  coder::array<boolean_T, 2U> x;
  double apnd;
  double b;
  double xtmp_im;
  int fid;
  int i;
  int k;
  int lowerDim;
  boolean_T useRadix2;
  if (!isInitialized_psdSpectrum) {
    psdSpectrum_initialize();
  }
  // UNTITLED6 Summary of this function goes here
  //    Detailed explanation goes here
  printf("Loading data...\n");
  fflush(stdout);
  useRadix2 = false;
  if (file.size(1) == 3) {
    lowerDim = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (lowerDim < 3) {
        if (file[lowerDim] != b_cv[lowerDim]) {
          exitg1 = 1;
        } else {
          lowerDim++;
        }
      } else {
        useRadix2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (useRadix2) {
    rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  } else {
    signed char fileid;
    fileid = coder::cfopen(file);
    fid = fileid;
  }
  if (fid != -1) {
    coder::b_fread(static_cast<double>(fid), dataRaw);
    printf("Done.\n");
    fflush(stdout);
  } else {
    printf("UAV-RT: Error opening file at path provided.\n");
    fflush(stdout);
    dataRaw.set_size(0, 0);
  }
  r.set_size(dataRaw.size(0), dataRaw.size(1));
  lowerDim = dataRaw.size(0) * dataRaw.size(1);
  for (i = 0; i < lowerDim; i++) {
    apnd = dataRaw[i];
    if (std::isnan(apnd) || std::isinf(apnd)) {
      xtmp_im = rtNaN;
    } else if (apnd == 0.0) {
      xtmp_im = 0.0;
    } else {
      xtmp_im = std::fmod(apnd, 2.0);
      if (xtmp_im == 0.0) {
        xtmp_im = 0.0;
      } else if (apnd < 0.0) {
        xtmp_im += 2.0;
      }
    }
    r[i] = xtmp_im;
  }
  x.set_size(r.size(0), r.size(1));
  lowerDim = r.size(0) * r.size(1);
  for (i = 0; i < lowerDim; i++) {
    x[i] = (r[i] != 0.0);
  }
  useRadix2 = ((x.size(0) != 0) && (x.size(1) != 0));
  if (useRadix2) {
    boolean_T exitg2;
    lowerDim = x.size(0) * x.size(1);
    if (lowerDim > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k <= lowerDim - 1)) {
      if (!x[k]) {
        useRadix2 = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
  }
  if (useRadix2) {
    if (dataRaw.size(0) < 2) {
      rtDynamicBoundsError(2, 1, dataRaw.size(0), &emlrtBCI);
    }
    if (dataRaw.size(1) < 1) {
      rtDynamicBoundsError(dataRaw.size(1), 1, dataRaw.size(1), &b_emlrtBCI);
    }
    dataRaw[dataRaw.size(0) * (dataRaw.size(1) - 1) + 1] = 0.0;
  }
  coder::cfclose(static_cast<double>(fid));
  if (dataRaw.size(0) < 1) {
    rtDynamicBoundsError(1, 1, dataRaw.size(0), &c_emlrtBCI);
  }
  if (dataRaw.size(0) < 2) {
    rtDynamicBoundsError(2, 1, dataRaw.size(0), &d_emlrtBCI);
  }
  lowerDim = dataRaw.size(1);
  data.set_size(1, dataRaw.size(1));
  for (i = 0; i < lowerDim; i++) {
    data[i].re = dataRaw[dataRaw.size(0) * i + 1] * 0.0;
    data[i].im = dataRaw[dataRaw.size(0) * i + 1];
  }
  if ((dataRaw.size(1) != data.size(1)) &&
      ((dataRaw.size(1) != 1) && (data.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(dataRaw.size(1), data.size(1), &b_emlrtECI);
  }
  if (dataRaw.size(1) == data.size(1)) {
    lowerDim = dataRaw.size(1);
    data.set_size(1, dataRaw.size(1));
    for (i = 0; i < lowerDim; i++) {
      data[i].re = dataRaw[dataRaw.size(0) * i] + data[i].re;
    }
  } else {
    binary_expand_op(data, dataRaw);
  }
  xtmp_im = 1.0 / Fs;
  b = (static_cast<double>(data.size(1)) - 1.0) / Fs;
  if ((!std::isnan(xtmp_im)) && (!std::isnan(b)) && (!(xtmp_im == 0.0)) &&
      ((!(b > 0.0)) || (!(xtmp_im < 0.0))) &&
      ((!(b < 0.0)) || (!(xtmp_im > 0.0))) &&
      ((!std::isinf(b)) || (!std::isinf(xtmp_im))) && (!std::isinf(xtmp_im)) &&
      (!(std::floor(xtmp_im) == xtmp_im))) {
    double ndbl;
    ndbl = std::floor(b / xtmp_im + 0.5);
    apnd = ndbl * xtmp_im;
    if (xtmp_im > 0.0) {
      apnd -= b;
    } else {
      apnd = b - apnd;
    }
    if (std::abs(apnd) < 4.4408920985006262E-16 * std::fmax(0.0, std::abs(b))) {
      ndbl++;
    } else if (!(apnd > 0.0)) {
      ndbl++;
    }
    if (ndbl > 2.147483647E+9) {
      c_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
    }
  }
  // UNTITLED9 Summary of this function goes here
  //    Detailed explanation goes here
  if (data.size(1) == 0) {
    dataFFT.set_size(1, 0);
  } else {
    useRadix2 = ((data.size(1) & (data.size(1) - 1)) == 0);
    coder::internal::FFTImplementationCallback::get_algo_sizes(
        data.size(1), useRadix2, &fid, &lowerDim);
    coder::internal::FFTImplementationCallback::generate_twiddle_tables(
        lowerDim, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      lowerDim = data.size(1);
      b_data = data.reshape(lowerDim);
      coder::internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          b_data, data.size(1), costab, sintab, yCol);
    } else {
      lowerDim = data.size(1);
      b_data = data.reshape(lowerDim);
      coder::internal::FFTImplementationCallback::dobluesteinfft(
          b_data, fid, data.size(1), costab, sintab, sintabinv, yCol);
    }
    dataFFT.set_size(1, data.size(1));
    lowerDim = data.size(1);
    for (i = 0; i < lowerDim; i++) {
      dataFFT[i] = yCol[i];
    }
  }
  for (int dim{0}; dim < 2; dim++) {
    i = dataFFT.size(dim);
    if (dataFFT.size(dim) > 1) {
      int npages;
      int vlend2;
      vlend2 = dataFFT.size(dim) / 2 - 1;
      npages = 1;
      lowerDim = dim + 2;
      for (k = lowerDim; k < 3; k++) {
        npages *= dataFFT.size(1);
      }
      if ((vlend2 + 1) << 1 == dataFFT.size(dim)) {
        lowerDim = 0;
        if (npages > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < npages; b_i++) {
          int i1;
          int ib;
          i1 = lowerDim;
          lowerDim = (lowerDim + i) - 1;
          i1++;
          lowerDim++;
          ib = i1 + vlend2;
          for (k = 0; k <= vlend2; k++) {
            int dataFFT_tmp;
            fid = (i1 + k) - 1;
            apnd = dataFFT[fid].re;
            xtmp_im = dataFFT[fid].im;
            dataFFT_tmp = ib + k;
            dataFFT[fid] = dataFFT[dataFFT_tmp];
            dataFFT[dataFFT_tmp].re = apnd;
            dataFFT[dataFFT_tmp].im = xtmp_im;
          }
        }
      } else {
        lowerDim = 0;
        if (npages > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < npages; b_i++) {
          int i1;
          int ib;
          i1 = lowerDim;
          lowerDim = (lowerDim + i) - 1;
          i1++;
          lowerDim++;
          ib = i1 + vlend2;
          apnd = dataFFT[ib].re;
          xtmp_im = dataFFT[ib].im;
          for (k = 0; k <= vlend2; k++) {
            int dataFFT_tmp;
            dataFFT_tmp = ib + k;
            fid = (i1 + k) - 1;
            dataFFT[dataFFT_tmp] = dataFFT[fid];
            dataFFT[fid] = dataFFT[dataFFT_tmp + 1];
          }
          ib = (ib + vlend2) + 1;
          dataFFT[ib].re = apnd;
          dataFFT[ib].im = xtmp_im;
        }
      }
    }
  }
  apnd = Fs * 0.02;
  if (std::isinf(apnd) || std::isnan(apnd)) {
    rtErrorWithMessageID("N", l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  if (!(apnd >= 0.0)) {
    d_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
  if (apnd == std::floor(apnd)) {
    lowerDim = static_cast<int>(apnd);
  } else {
    lowerDim = static_cast<int>(std::round(apnd));
  }
  rectWind.set_size(lowerDim);
  for (i = 0; i < lowerDim; i++) {
    rectWind[i] = 1.0;
  }
  xtmp_im = std::floor(0.5 * apnd);
  coder::stft(data, Fs, rectWind, xtmp_im, apnd, s, fStft, tStft);
  coder::welch(data, rectWind, xtmp_im, apnd, Fs, welchOut_f1, fStft);
  r1.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  lowerDim = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < lowerDim; i++) {
    r1[i] = welchOut_f1[i];
  }
  coder::b_log10(r1);
  r1.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  lowerDim = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < lowerDim; i++) {
    r1[i] = welchOut_f1[i];
  }
  coder::b_log10(r1);
  // legend('Location','best')
  r1.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  lowerDim = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < lowerDim; i++) {
    r1[i] = welchOut_f1[i];
  }
  coder::b_log10(r1);
  r1.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  lowerDim = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < lowerDim; i++) {
    r1[i] = welchOut_f1[i];
  }
  coder::b_log10(r1);
  // legend('Location','best')
}

//
// File trailer for psdSpectrum.cpp
//
// [EOF]
//
