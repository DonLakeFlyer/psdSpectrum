//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computepsd.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "computepsd.h"
#include "indexShapeCheck.h"
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
static void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Dimensions of arrays being concatenated are not consistent.";
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
// Arguments    : const ::coder::array<double, 2U> &Sxx1
//                const ::coder::array<double, 2U> &w2
//                const char range[8]
//                double nfft
//                double Fs
//                ::coder::array<double, 2U> &varargout_1
//                ::coder::array<double, 1U> &varargout_2
//                char varargout_3_data[]
//                int varargout_3_size[2]
// Return Type  : void
//
namespace coder {
void computepsd(const ::coder::array<double, 2U> &Sxx1,
                const ::coder::array<double, 2U> &w2, const char range[8],
                double nfft, double Fs, ::coder::array<double, 2U> &varargout_1,
                ::coder::array<double, 1U> &varargout_2,
                char varargout_3_data[], int varargout_3_size[2])
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      41,           // lineNo
      27,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      47,           // lineNo
      11,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      44,           // lineNo
      27,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      45,           // lineNo
      27,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      40,           // lineNo
      27,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      45,           // lineNo
      73,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      45,           // lineNo
      48,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      45,           // lineNo
      50,           // colNo
      "",           // aName
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      0 // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      44,           // lineNo
      27,           // colNo
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo emlrtDCI{
      40,           // lineNo
      27,           // colNo
      "computepsd", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\computepsd.m", // pName
      1 // checkKind
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      12,     // lineNo
      "isodd" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      275,                  // lineNo
      "check_non_axis_size" // fName
  };
  static const char b_cv[10]{'r', 'a', 'd', '/', 's', 'a', 'm', 'p', 'l', 'e'};
  static const char b[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  array<double, 2U> Sxx;
  array<double, 2U> b_select;
  array<double, 2U> y;
  int i;
  int loop_ub;
  int ret;
  ret = memcmp(&range[0], &b[0], 8);
  if (ret == 0) {
    double r;
    int iv[2];
    int i1;
    if (nfft - std::trunc(nfft) != 0.0) {
      g_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
    }
    if (std::isnan(nfft) || std::isinf(nfft)) {
      r = rtNaN;
    } else if (nfft == 0.0) {
      r = 0.0;
    } else {
      r = std::fmod(nfft, 2.0);
      if (r == 0.0) {
        r = 0.0;
      } else if (nfft < 0.0) {
        r += 2.0;
      }
    }
    if (r == 1.0) {
      int b_loop_ub;
      int sizes_idx_0;
      signed char b_input_sizes_idx_0;
      boolean_T empty_non_axis_sizes;
      r = (nfft + 1.0) / 2.0;
      if (std::isnan(r)) {
        b_select.set_size(1, 1);
        b_select[0] = rtNaN;
      } else if (r < 1.0) {
        b_select.set_size(1, 0);
      } else {
        b_select.set_size(1, static_cast<int>(r - 1.0) + 1);
        loop_ub = static_cast<int>(r - 1.0);
        for (i = 0; i <= loop_ub; i++) {
          b_select[i] = static_cast<double>(i) + 1.0;
        }
      }
      loop_ub = Sxx1.size(1);
      Sxx.set_size(b_select.size(1), Sxx1.size(1));
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = b_select.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          ret = static_cast<int>(b_select[i1]);
          if (b_select[i1] != ret) {
            rtIntegerError(b_select[i1], &emlrtDCI);
          }
          if ((ret < 1) || (ret > Sxx1.size(0))) {
            rtDynamicBoundsError(ret, 1, Sxx1.size(0), &emlrtBCI);
          }
          Sxx[i1] = Sxx1[ret - 1];
        }
      }
      if (b_select.size(1) < 2) {
        i = 0;
        i1 = 0;
      } else {
        i = 1;
        i1 = b_select.size(1);
      }
      if (b_select.size(1) < 1) {
        rtDynamicBoundsError(1, 1, b_select.size(1), &b_emlrtBCI);
      }
      loop_ub = Sxx1.size(1) - 1;
      b_loop_ub = i1 - i;
      y.set_size(b_loop_ub, Sxx1.size(1));
      for (i1 = 0; i1 <= loop_ub; i1++) {
        for (ret = 0; ret < b_loop_ub; ret++) {
          y[ret] = 2.0 * Sxx[i + ret];
        }
      }
      if (Sxx1.size(1) != 0) {
        ret = 1;
      } else {
        boolean_T guard1{false};
        guard1 = false;
        if ((y.size(0) != 0) && (y.size(1) != 0)) {
          ret = 1;
          guard1 = true;
        } else {
          ret = 0;
          if (y.size(1) > 0) {
            ret = 1;
            guard1 = true;
          }
        }
        if (guard1 && (Sxx1.size(1) != 0)) {
          v_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
        }
      }
      if ((y.size(1) != ret) && ((y.size(0) != 0) && (y.size(1) != 0))) {
        v_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
      }
      empty_non_axis_sizes = (ret == 0);
      if (empty_non_axis_sizes || (Sxx1.size(1) != 0)) {
        b_input_sizes_idx_0 = 1;
      } else {
        b_input_sizes_idx_0 = 0;
      }
      if (empty_non_axis_sizes || ((y.size(0) != 0) && (y.size(1) != 0))) {
        sizes_idx_0 = y.size(0);
      } else {
        sizes_idx_0 = 0;
      }
      loop_ub = Sxx1.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        r = Sxx[0];
      }
      Sxx.set_size(b_input_sizes_idx_0 + sizes_idx_0, ret);
      for (i = 0; i < ret; i++) {
        loop_ub = b_input_sizes_idx_0;
        for (i1 = 0; i1 < loop_ub; i1++) {
          Sxx[0] = r;
        }
      }
      for (i = 0; i < ret; i++) {
        for (i1 = 0; i1 < sizes_idx_0; i1++) {
          Sxx[i1 + b_input_sizes_idx_0] = y[i1];
        }
      }
    } else {
      double Sxx_unscaled_data;
      int b_loop_ub;
      int input_sizes_idx_0;
      int sizes_idx_0;
      signed char b_input_sizes_idx_0;
      boolean_T empty_non_axis_sizes;
      r = nfft / 2.0 + 1.0;
      if (std::isnan(r)) {
        b_select.set_size(1, 1);
        b_select[0] = rtNaN;
      } else if (r < 1.0) {
        b_select.set_size(1, 0);
      } else {
        b_select.set_size(1, static_cast<int>(r - 1.0) + 1);
        loop_ub = static_cast<int>(r - 1.0);
        for (i = 0; i <= loop_ub; i++) {
          b_select[i] = static_cast<double>(i) + 1.0;
        }
      }
      loop_ub = Sxx1.size(1);
      Sxx.set_size(b_select.size(1), Sxx1.size(1));
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = b_select.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          ret = static_cast<int>(b_select[i1]);
          if (b_select[i1] != ret) {
            rtIntegerError(b_select[i1], &b_emlrtDCI);
          }
          if ((ret < 1) || (ret > Sxx1.size(0))) {
            rtDynamicBoundsError(ret, 1, Sxx1.size(0), &d_emlrtBCI);
          }
          Sxx[i1] = Sxx1[ret - 1];
        }
      }
      if (b_select.size(1) - 1 < 2) {
        i = -1;
        i1 = -1;
      } else {
        if (b_select.size(1) < 2) {
          rtDynamicBoundsError(2, 1, b_select.size(1), &g_emlrtBCI);
        }
        i = 0;
        if ((b_select.size(1) - 1 < 1) ||
            (b_select.size(1) - 1 > b_select.size(1))) {
          rtDynamicBoundsError(b_select.size(1) - 1, 1, b_select.size(1),
                               &h_emlrtBCI);
        }
        i1 = b_select.size(1) - 2;
      }
      if (b_select.size(1) < 1) {
        rtDynamicBoundsError(1, 1, b_select.size(1), &e_emlrtBCI);
      }
      loop_ub = Sxx1.size(1) - 1;
      input_sizes_idx_0 = i1 - i;
      y.set_size(input_sizes_idx_0, Sxx1.size(1));
      for (i1 = 0; i1 <= loop_ub; i1++) {
        for (ret = 0; ret < input_sizes_idx_0; ret++) {
          y[ret] = 2.0 * Sxx[(i + ret) + 1];
        }
      }
      if (b_select.size(1) < 1) {
        rtDynamicBoundsError(b_select.size(1), 1, b_select.size(1),
                             &f_emlrtBCI);
      }
      if (Sxx1.size(1) != 0) {
        ret = 1;
      } else if ((input_sizes_idx_0 != 0) && (Sxx1.size(1) != 0)) {
        ret = y.size(1);
      } else {
        ret = 0;
        if (y.size(1) > 0) {
          ret = 1;
        }
      }
      if ((Sxx1.size(1) != ret) && (Sxx1.size(1) != 0)) {
        v_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
      }
      if ((y.size(1) != ret) &&
          ((input_sizes_idx_0 != 0) && (Sxx1.size(1) != 0))) {
        v_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
      }
      if ((Sxx1.size(1) != ret) && (Sxx1.size(1) != 0)) {
        v_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
      }
      empty_non_axis_sizes = (ret == 0);
      if (empty_non_axis_sizes || (Sxx1.size(1) != 0)) {
        b_input_sizes_idx_0 = 1;
      } else {
        b_input_sizes_idx_0 = 0;
      }
      if ((!empty_non_axis_sizes) &&
          ((input_sizes_idx_0 == 0) || (Sxx1.size(1) == 0))) {
        input_sizes_idx_0 = 0;
      }
      if (empty_non_axis_sizes || (Sxx1.size(1) != 0)) {
        sizes_idx_0 = 1;
      } else {
        sizes_idx_0 = 0;
      }
      loop_ub = Sxx1.size(1) - 1;
      b_loop_ub = Sxx1.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        r = Sxx[0];
      }
      for (i = 0; i <= b_loop_ub; i++) {
        Sxx_unscaled_data = Sxx[b_select.size(1) - 1];
      }
      Sxx.set_size((b_input_sizes_idx_0 + input_sizes_idx_0) + sizes_idx_0,
                   ret);
      for (i = 0; i < ret; i++) {
        loop_ub = b_input_sizes_idx_0;
        for (i1 = 0; i1 < loop_ub; i1++) {
          Sxx[0] = r;
        }
      }
      for (i = 0; i < ret; i++) {
        for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
          Sxx[i1 + b_input_sizes_idx_0] = y[i1];
        }
      }
      for (i = 0; i < ret; i++) {
        for (i1 = 0; i1 < sizes_idx_0; i1++) {
          Sxx[b_input_sizes_idx_0 + input_sizes_idx_0] = Sxx_unscaled_data;
        }
      }
    }
    iv[0] = (*(int(*)[2])b_select.size())[0];
    iv[1] = (*(int(*)[2])b_select.size())[1];
    internal::indexShapeCheck(w2.size(0), iv);
    varargout_2.set_size(b_select.size(1));
    loop_ub = b_select.size(1);
    for (i = 0; i < loop_ub; i++) {
      i1 = static_cast<int>(b_select[i]);
      if ((i1 < 1) || (i1 > w2.size(0))) {
        rtDynamicBoundsError(i1, 1, w2.size(0), &c_emlrtBCI);
      }
      varargout_2[i] = w2[i1 - 1];
    }
  } else {
    Sxx.set_size(Sxx1.size(0), Sxx1.size(1));
    loop_ub = Sxx1.size(0) * Sxx1.size(1);
    for (i = 0; i < loop_ub; i++) {
      Sxx[i] = Sxx1[i];
    }
    varargout_2.set_size(w2.size(0));
    loop_ub = w2.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargout_2[i] = w2[i];
    }
  }
  if (!std::isnan(Fs)) {
    varargout_1.set_size(Sxx.size(0), Sxx.size(1));
    loop_ub = Sxx.size(0) * Sxx.size(1);
    for (i = 0; i < loop_ub; i++) {
      varargout_1[i] = Sxx[i] / Fs;
    }
    varargout_3_size[0] = 1;
    varargout_3_size[1] = 2;
    varargout_3_data[0] = 'H';
    varargout_3_data[1] = 'z';
  } else {
    varargout_1.set_size(Sxx.size(0), Sxx.size(1));
    loop_ub = Sxx.size(0) * Sxx.size(1);
    for (i = 0; i < loop_ub; i++) {
      varargout_1[i] = Sxx[i] / 6.2831853071795862;
    }
    varargout_3_size[0] = 1;
    varargout_3_size[1] = 10;
    for (i = 0; i < 10; i++) {
      varargout_3_data[i] = b_cv[i];
    }
  }
}

} // namespace coder

//
// File trailer for computepsd.cpp
//
// [EOF]
//
