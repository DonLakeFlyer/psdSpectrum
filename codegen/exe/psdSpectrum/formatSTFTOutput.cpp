//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: formatSTFTOutput.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "formatSTFTOutput.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "iseven.h"
#include "psdSpectrum_internal_types.h"
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
static void ab_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void b_rtDivisionByZeroErrorN();

static int div_s32_sat(int numerator, int denominator);

static void rtErrorWithMessageID(const char *r, const char *r1,
                                 const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void ab_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Divide by zero.";
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
// Arguments    : void
// Return Type  : void
//
static void b_rtDivisionByZeroErrorN()
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Division by zero detected.\nEarly termination due to division "
               "by zero.";
  outStream << "\n";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32_sat(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    b_rtDivisionByZeroErrorN();
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    boolean_T quotientNeedsNegation;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((!quotientNeedsNegation) && (b_numerator >= 2147483647U)) {
      quotient = MAX_int32_T;
    } else if (quotientNeedsNegation && (b_numerator > 2147483647U)) {
      quotient = MIN_int32_T;
    } else if (quotientNeedsNegation) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : const char *r
//                const char *r1
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *r1,
                                 const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((outStream << "Invalid shift argument: must be a finite, real, integer "
                   "vector with entries between -intmax(\'")
     << r)
    << "\') and intmax(\'")
   << r1)
      << "\').";
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
// Arguments    : ::coder::array<creal_T, 2U> &S
//                ::coder::array<double, 1U> &F
//                const b_struct_T *opts
// Return Type  : void
//
namespace coder {
namespace signal {
namespace internal {
namespace stft {
void formatSTFTOutput(::coder::array<creal_T, 2U> &S,
                      ::coder::array<double, 1U> &F, const b_struct_T *opts)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      16,           // lineNo
      13,           // colNo
      "",           // aName
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      23,                 // lineNo
      22,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      23,                 // lineNo
      24,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      18,                 // lineNo
      22,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      13,           // lineNo
      13,           // colNo
      "",           // aName
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      18,                 // lineNo
      24,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      13,           // lineNo
      13,           // colNo
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      16,           // lineNo
      13,           // colNo
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      23,                 // lineNo
      24,                 // colNo
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      1                           // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      18,                 // lineNo
      24,                 // colNo
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      1                           // checkKind
  };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      132,          // lineNo
      "eml_idivide" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      31,         // lineNo
      "circshift" // fName
  };
  static const char b[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const char b_b[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  array<creal_T, 2U> buffer;
  int ret;
  ret = memcmp(&opts->FreqRange[0], &b[0], 8);
  if (ret == 0) {
    ret = 0;
  } else {
    ret = memcmp(&opts->FreqRange[0], &b_b[0], 8);
    if (ret == 0) {
      ret = 1;
    } else {
      ret = -1;
    }
  }
  switch (ret) {
  case 0: {
    double xtmp_re;
    int i;
    if (signalwavelet::internal::iseven(static_cast<double>(S.size(0)))) {
      int vspread;
      xtmp_re = static_cast<double>(S.size(0)) / 2.0 - 1.0;
      vspread = 1;
      if (S.size(0) != 1) {
        vspread = 0;
      }
      if (static_cast<int>(xtmp_re) != xtmp_re) {
        rtErrorWithMessageID("int32", "int32", l_emlrtRTEI.fName,
                             l_emlrtRTEI.lineNo);
      }
      if ((S.size(0) != 0) && (S.size(1) != 0) &&
          ((S.size(0) != 1) || (S.size(1) != 1))) {
        int i2;
        int ib;
        int npages;
        int ns;
        int vlend2;
        boolean_T shiftright;
        if (xtmp_re < 0.0) {
          ns = 1;
          shiftright = false;
        } else {
          ns = static_cast<int>(xtmp_re);
          shiftright = true;
        }
        if (ns > S.size(vspread)) {
          if (S.size(vspread) == 0) {
            ab_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
          }
          ns -= div_s32_sat(ns, S.size(vspread)) * S.size(vspread);
        }
        if (ns > (S.size(vspread) >> 1)) {
          ns = S.size(vspread) - ns;
          shiftright = !shiftright;
        }
        if ((S.size(0) == 0) || (S.size(1) == 0)) {
          vlend2 = 0;
        } else {
          ret = S.size(0);
          vlend2 = S.size(1);
          if (ret >= vlend2) {
            vlend2 = ret;
          }
        }
        ret = static_cast<int>(std::floor(static_cast<double>(vlend2) / 2.0));
        buffer.set_size(1, ret);
        for (i = 0; i < ret; i++) {
          buffer[i].re = 0.0;
          buffer[i].im = 0.0;
        }
        i = S.size(vspread);
        i2 = S.size(vspread);
        ib = 1;
        for (int k{0}; k < vspread; k++) {
          ib *= S.size(0);
        }
        npages = 1;
        ret = vspread + 2;
        for (int k{ret}; k < 3; k++) {
          npages *= S.size(1);
        }
        vlend2 = ib * S.size(vspread);
        if ((S.size(vspread) > 1) && (ns > 0)) {
          if (npages > 2147483646) {
            check_forloop_overflow_error();
          }
          for (int b_i{0}; b_i < npages; b_i++) {
            ret = b_i * vlend2;
            if (ib > 2147483646) {
              check_forloop_overflow_error();
            }
            for (vspread = 0; vspread < ib; vspread++) {
              int b_i1;
              b_i1 = ret + vspread;
              if (shiftright) {
                int i1;
                for (int k{0}; k < ns; k++) {
                  buffer[k] = S[b_i1 + ((k + i) - ns) * ib];
                }
                i1 = ns + 1;
                for (int k{i2}; k >= i1; k--) {
                  S[b_i1 + (k - 1) * ib] = S[b_i1 + ((k - ns) - 1) * ib];
                }
                for (int k{0}; k < ns; k++) {
                  S[b_i1 + k * ib] = buffer[k];
                }
              } else {
                int i1;
                for (int k{0}; k < ns; k++) {
                  buffer[k] = S[b_i1 + k * ib];
                }
                i1 = (i - ns) - 1;
                for (int k{0}; k <= i1; k++) {
                  S[b_i1 + k * ib] = S[b_i1 + (k + ns) * ib];
                }
                for (int k{0}; k < ns; k++) {
                  S[b_i1 + ((k + i) - ns) * ib] = buffer[k];
                }
              }
            }
          }
        }
      }
    } else if (S.size(0) > 1) {
      int npages;
      int vlend2;
      int vspread;
      vlend2 = S.size(0) / 2 - 1;
      npages = S.size(1) - 1;
      vspread = S.size(0);
      if ((vlend2 + 1) << 1 == S.size(0)) {
        int i2;
        i2 = 1;
        if (S.size(1) > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i <= npages; b_i++) {
          int b_i1;
          int ib;
          b_i1 = i2;
          i2 += vspread;
          ib = b_i1 + vlend2;
          for (int k{0}; k <= vlend2; k++) {
            double xtmp_im;
            ret = (b_i1 + k) - 1;
            xtmp_re = S[ret].re;
            xtmp_im = S[ret].im;
            i = ib + k;
            S[ret] = S[i];
            S[i].re = xtmp_re;
            S[i].im = xtmp_im;
          }
        }
      } else {
        int i2;
        i2 = 1;
        if (S.size(1) > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i <= npages; b_i++) {
          double xtmp_im;
          int b_i1;
          int ib;
          b_i1 = i2;
          i2 += vspread;
          ib = b_i1 + vlend2;
          xtmp_re = S[ib].re;
          xtmp_im = S[ib].im;
          for (int k{0}; k <= vlend2; k++) {
            int i1;
            i = ib + k;
            i1 = (b_i1 + k) - 1;
            S[i] = S[i1];
            S[i1] = S[i + 1];
          }
          ib = (ib + vlend2) + 1;
          S[ib].re = xtmp_re;
          S[ib].im = xtmp_im;
        }
      }
    }
    if (signalwavelet::internal::iseven(static_cast<double>(F.size(0)))) {
      i = F.size(0);
      xtmp_re = static_cast<double>(F.size(0)) / 2.0;
      if (xtmp_re != std::floor(xtmp_re)) {
        rtIntegerError(xtmp_re, &c_emlrtDCI);
      }
      if ((static_cast<int>(xtmp_re) < 1) || (static_cast<int>(xtmp_re) > i)) {
        rtDynamicBoundsError(static_cast<int>(xtmp_re), 1, i, &emlrtBCI);
      }
      xtmp_re = F[static_cast<int>(xtmp_re) - 1];
      ret = F.size(0);
      for (i = 0; i < ret; i++) {
        F[i] = F[i] - xtmp_re;
      }
    } else {
      i = F.size(0);
      xtmp_re = (static_cast<double>(F.size(0)) + 1.0) / 2.0;
      if (xtmp_re != std::floor(xtmp_re)) {
        rtIntegerError(xtmp_re, &d_emlrtDCI);
      }
      if ((static_cast<int>(xtmp_re) < 1) || (static_cast<int>(xtmp_re) > i)) {
        rtDynamicBoundsError(static_cast<int>(xtmp_re), 1, i, &b_emlrtBCI);
      }
      xtmp_re = F[static_cast<int>(xtmp_re) - 1];
      ret = F.size(0);
      for (i = 0; i < ret; i++) {
        F[i] = F[i] - xtmp_re;
      }
    }
  } break;
  case 1:
    break;
  default: {
    int i;
    if (S.size(0) != opts->NumFreqSamples) {
      int vlend2;
      if (opts->NumFreqSamples < 1.0) {
        ret = 0;
      } else {
        i = S.size(0);
        if (i < 1) {
          rtDynamicBoundsError(1, 1, i, &e_emlrtBCI);
        }
        i = S.size(0);
        if (opts->NumFreqSamples !=
            static_cast<int>(std::floor(opts->NumFreqSamples))) {
          rtIntegerError(opts->NumFreqSamples, &f_emlrtDCI);
        }
        if ((static_cast<int>(opts->NumFreqSamples) < 1) ||
            (static_cast<int>(opts->NumFreqSamples) > i)) {
          rtDynamicBoundsError(static_cast<int>(opts->NumFreqSamples), 1, i,
                               &f_emlrtBCI);
        }
        ret = static_cast<int>(opts->NumFreqSamples);
      }
      vlend2 = S.size(1) - 1;
      for (i = 0; i <= vlend2; i++) {
        for (int i1{0}; i1 < ret; i1++) {
          S[i1 + ret * i] = S[i1 + S.size(0) * i];
        }
      }
      S.set_size(ret, vlend2 + 1);
    }
    if (F.size(0) != opts->NumFreqSamples) {
      int iv[2];
      if (opts->NumFreqSamples < 1.0) {
        i = 0;
      } else {
        i = F.size(0);
        if (i < 1) {
          rtDynamicBoundsError(1, 1, i, &c_emlrtBCI);
        }
        i = F.size(0);
        if (opts->NumFreqSamples !=
            static_cast<int>(std::floor(opts->NumFreqSamples))) {
          rtIntegerError(opts->NumFreqSamples, &e_emlrtDCI);
        }
        if ((static_cast<int>(opts->NumFreqSamples) < 1) ||
            (static_cast<int>(opts->NumFreqSamples) > i)) {
          rtDynamicBoundsError(static_cast<int>(opts->NumFreqSamples), 1, i,
                               &d_emlrtBCI);
        }
        i = static_cast<int>(opts->NumFreqSamples);
      }
      iv[0] = 1;
      iv[1] = i;
      ::coder::internal::indexShapeCheck(F.size(0), iv);
      F.set_size(i);
    }
  } break;
  }
}

} // namespace stft
} // namespace internal
} // namespace signal
} // namespace coder

//
// File trailer for formatSTFTOutput.cpp
//
// [EOF]
//
