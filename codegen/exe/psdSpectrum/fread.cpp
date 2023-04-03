//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fread.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "fread.h"
#include "eml_int_forloop_overflow_check.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
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
static void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
// Arguments    : double fileID
//                ::coder::array<double, 2U> &A
// Return Type  : void
//
namespace coder {
void b_fread(double fileID, ::coder::array<double, 2U> &A)
{
  static rtDoubleCheckInfo
      c_emlrtDCI{
          329,         // lineNo
          60,          // colNo
          "fullFread", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\eml\\lib\\matlab\\iofun\\fread.m", // pName
          4 // checkKind
      };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      72,     // lineNo
      "fread" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      559,          // lineNo
      "getFileStar" // fName
  };
  FILE *filestar;
  size_t nBytes;
  array<double, 1U> At;
  int bytesOut;
  int c;
  int k;
  int numRead;
  signed char fileid;
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    e_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  nBytes = sizeof(float);
  if (fileID < 0.0) {
    f_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  fileid = static_cast<signed char>(std::round(fileID));
  if (fileID != fileid) {
    f_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(fileID) != fileid) {
    fileid = -1;
  }
  if (fileid >= 3) {
    filestar = eml_openfiles[fileid - 3];
    if (eml_openfiles[fileid - 3] == NULL) {
      g_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
    }
  } else if (fileid == 0) {
    filestar = stdin;
  } else if (fileid == 1) {
    filestar = stdout;
  } else if (fileid == 2) {
    filestar = stderr;
  } else {
    filestar = NULL;
  }
  if (filestar == NULL) {
    f_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
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
      k = At.size(0);
      At.set_size(At.size(0) + numRead);
      for (int i{0}; i < numRead; i++) {
        At[k + i] = tbuf[i];
      }
      bytesOut += c;
    }
  }
  if (At.size(0) >= 2) {
    A.set_size(2, A.size(1));
    k = (bytesOut >> 1) + ((bytesOut & 1) != 0);
    if (k < 0) {
      rtNonNegativeError(static_cast<double>(k), &c_emlrtDCI);
    }
    A.set_size(A.size(0), k);
    if (bytesOut > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < bytesOut; k++) {
      A[k] = At[k];
    }
    numRead = bytesOut + 1;
    c = A.size(1) << 1;
    if ((bytesOut + 1 <= c) && (c > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (k = numRead; k <= c; k++) {
      A[k - 1] = 0.0;
    }
  } else {
    A.set_size(At.size(0), 1);
    numRead = At.size(0);
    for (k = 0; k < numRead; k++) {
      A[0] = At[0];
    }
  }
}

} // namespace coder

//
// File trailer for fread.cpp
//
// [EOF]
//
