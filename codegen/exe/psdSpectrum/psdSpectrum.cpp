//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "psdSpectrum.h"
#include "eml_int_forloop_overflow_check.h"
#include "fileManager.h"
#include "log10.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_initialize.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "readairspybinfile.h"
#include "rt_nonfinite.h"
#include "welch.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>

// Function Declarations
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Operation is not implemented for requested file identifier.";
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
  static rtDoubleCheckInfo
      emlrtDCI{
          329,         // lineNo
          60,          // colNo
          "fullFread", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\eml\\lib\\matlab\\iofun\\fread.m", // pName
          4 // checkKind
      };
  static rtEqualityCheckInfo emlrtECI{
      2,                                            // nDims
      19,                                           // lineNo
      15,                                           // colNo
      "readairspybinfile",                          // fName
      "H:\\repos\\psdSpectrum\\readairspybinfile.m" // pName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      37,     // lineNo
      "fopen" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      72,     // lineNo
      "fread" // fName
  };
  static rtRunTimeErrorInfo h_emlrtRTEI{
      559,          // lineNo
      "getFileStar" // fName
  };
  static rtRunTimeErrorInfo i_emlrtRTEI{
      18,           // lineNo
      "check_order" // fName
  };
  static rtRunTimeErrorInfo j_emlrtRTEI{
      22,           // lineNo
      "check_order" // fName
  };
  static const char b_cv[3]{'a', 'l', 'l'};
  coder::array<creal_T, 2U> data;
  coder::array<double, 2U> dataRaw;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r2;
  coder::array<double, 2U> welchOut_f1;
  coder::array<double, 1U> At;
  coder::array<double, 1U> r1;
  coder::array<boolean_T, 2U> x;
  double apnd;
  double b;
  double varargout_1;
  int c;
  int fid;
  int i;
  int k;
  int numRead;
  boolean_T b_bool;
  if (!isInitialized_psdSpectrum) {
    psdSpectrum_initialize();
  }
  // UNTITLED6 Summary of this function goes here
  //    Detailed explanation goes here
  printf("Loading data...\n");
  fflush(stdout);
  b_bool = false;
  if (file.size(1) == 3) {
    numRead = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (numRead < 3) {
        if (file[numRead] != b_cv[numRead]) {
          exitg1 = 1;
        } else {
          numRead++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    c_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  } else {
    signed char fileid;
    fileid = coder::cfopen(file);
    fid = fileid;
  }
  if (fid != -1) {
    FILE *filestar;
    size_t nBytes;
    int bytesOut;
    if ((fid == 0) || (fid == 1) || (fid == 2)) {
      d_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
    }
    nBytes = sizeof(float);
    if (fid < 0) {
      e_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
    }
    if (fid >= 3) {
      filestar = eml_openfiles[fid - 3];
      if (eml_openfiles[fid - 3] == NULL) {
        f_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
      }
    } else if (fid == 0) {
      filestar = stdin;
    } else if (fid == 1) {
      filestar = stdout;
    } else if (fid == 2) {
      filestar = stderr;
    } else {
      filestar = NULL;
    }
    if (filestar == NULL) {
      e_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
    }
    if ((fid == 0) || (fid == 1) || (fid == 2)) {
      filestar = NULL;
    }
    At.set_size(0);
    if (filestar == NULL) {
      bytesOut = 0;
    } else {
      c = 1;
      bytesOut = 0;
      while (c > 0) {
        float tbuf[1024];
        c = 0;
        numRead = 1;
        while ((c < 1024) && (numRead > 0)) {
          size_t numReadSizeT;
          numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c), filestar);
          numRead = (int)numReadSizeT;
          c += (int)numReadSizeT;
        }
        if (c < 1) {
          numRead = 0;
        } else {
          numRead = c;
        }
        i = At.size(0);
        At.set_size(At.size(0) + numRead);
        for (k = 0; k < numRead; k++) {
          At[i + k] = tbuf[k];
        }
        bytesOut += c;
      }
    }
    if (At.size(0) >= 2) {
      dataRaw.set_size(2, dataRaw.size(1));
      i = (bytesOut >> 1) + ((bytesOut & 1) != 0);
      if (i < 0) {
        rtNonNegativeError(static_cast<double>(i), &emlrtDCI);
      }
      dataRaw.set_size(dataRaw.size(0), i);
      if (bytesOut > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k < bytesOut; k++) {
        dataRaw[k] = At[k];
      }
      numRead = bytesOut + 1;
      c = dataRaw.size(1) << 1;
      if ((bytesOut + 1 <= c) && (c > 2147483646)) {
        coder::check_forloop_overflow_error();
      }
      for (k = numRead; k <= c; k++) {
        dataRaw[k - 1] = 0.0;
      }
    } else {
      dataRaw.set_size(At.size(0), 1);
      numRead = At.size(0);
      for (i = 0; i < numRead; i++) {
        dataRaw[0] = At[0];
      }
    }
    printf("Done.\n");
    fflush(stdout);
  } else {
    printf("UAV-RT: Error opening file at path provided.\n");
    fflush(stdout);
    dataRaw.set_size(0, 0);
  }
  r.set_size(dataRaw.size(0), dataRaw.size(1));
  numRead = dataRaw.size(0) * dataRaw.size(1);
  for (i = 0; i < numRead; i++) {
    apnd = dataRaw[i];
    if (std::isnan(apnd) || std::isinf(apnd)) {
      varargout_1 = rtNaN;
    } else if (apnd == 0.0) {
      varargout_1 = 0.0;
    } else {
      varargout_1 = std::fmod(apnd, 2.0);
      if (varargout_1 == 0.0) {
        varargout_1 = 0.0;
      } else if (apnd < 0.0) {
        varargout_1 += 2.0;
      }
    }
    r[i] = varargout_1;
  }
  x.set_size(r.size(0), r.size(1));
  numRead = r.size(0) * r.size(1);
  for (i = 0; i < numRead; i++) {
    x[i] = (r[i] != 0.0);
  }
  b_bool = ((x.size(0) != 0) && (x.size(1) != 0));
  if (b_bool) {
    boolean_T exitg2;
    c = x.size(0) * x.size(1);
    if (c > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k <= c - 1)) {
      if (!x[k]) {
        b_bool = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
  }
  if (b_bool) {
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
  numRead = dataRaw.size(1);
  data.set_size(1, dataRaw.size(1));
  for (i = 0; i < numRead; i++) {
    data[i].re = dataRaw[dataRaw.size(0) * i + 1] * 0.0;
    data[i].im = dataRaw[dataRaw.size(0) * i + 1];
  }
  if ((dataRaw.size(1) != data.size(1)) &&
      ((dataRaw.size(1) != 1) && (data.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(dataRaw.size(1), data.size(1), &emlrtECI);
  }
  if (dataRaw.size(1) == data.size(1)) {
    numRead = dataRaw.size(1);
    data.set_size(1, dataRaw.size(1));
    for (i = 0; i < numRead; i++) {
      data[i].re = dataRaw[dataRaw.size(0) * i] + data[i].re;
    }
  } else {
    binary_expand_op(data, dataRaw);
  }
  varargout_1 = 1.0 / Fs;
  b = (static_cast<double>(data.size(1)) - 1.0) / Fs;
  if ((!std::isnan(varargout_1)) && (!std::isnan(b)) &&
      (!(varargout_1 == 0.0)) && ((!(b > 0.0)) || (!(varargout_1 < 0.0))) &&
      ((!(b < 0.0)) || (!(varargout_1 > 0.0))) &&
      ((!std::isinf(b)) || (!std::isinf(varargout_1))) &&
      (!std::isinf(varargout_1)) &&
      (!(std::floor(varargout_1) == varargout_1))) {
    double ndbl;
    ndbl = std::floor(b / varargout_1 + 0.5);
    apnd = ndbl * varargout_1;
    if (varargout_1 > 0.0) {
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
      rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    }
  }
  apnd = Fs * 0.02;
  if (std::isinf(apnd) || std::isnan(apnd)) {
    rtErrorWithMessageID("N", i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if (!(apnd >= 0.0)) {
    b_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  if (apnd == std::floor(apnd)) {
    numRead = static_cast<int>(apnd);
  } else {
    numRead = static_cast<int>(std::round(apnd));
  }
  // [ s, fStft, tStft ] =
  // stft(data,Fs,Window=rectWind,OverlapLength=nOverlap,FFTLength=nWind);
  r1.set_size(numRead);
  for (i = 0; i < numRead; i++) {
    r1[i] = 1.0;
  }
  coder::welch(data, r1, std::floor(0.5 * apnd), apnd, Fs, welchOut_f1, At);
  r2.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  numRead = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < numRead; i++) {
    r2[i] = welchOut_f1[i];
  }
  coder::b_log10(r2);
  r2.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  numRead = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < numRead; i++) {
    r2[i] = welchOut_f1[i];
  }
  coder::b_log10(r2);
  // legend('Location','best')
  r2.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  numRead = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < numRead; i++) {
    r2[i] = welchOut_f1[i];
  }
  coder::b_log10(r2);
  r2.set_size(welchOut_f1.size(0), welchOut_f1.size(1));
  numRead = welchOut_f1.size(0) * welchOut_f1.size(1);
  for (i = 0; i < numRead; i++) {
    r2[i] = welchOut_f1[i];
  }
  coder::b_log10(r2);
  // legend('Location','best')
}

//
// File trailer for psdSpectrum.cpp
//
// [EOF]
//
