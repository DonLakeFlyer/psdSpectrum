//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hamming.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "hamming.h"
#include "gencoswin.h"
#include "indexShapeCheck.h"
#include "iseven.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double varargin_1
//                ::coder::array<double, 1U> &w
// Return Type  : void
//
namespace coder {
void hamming(double varargin_1, ::coder::array<double, 1U> &w)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      62,           // lineNo
      24,           // colNo
      "",           // aName
      "sym_window", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\gencoswin.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      62,           // lineNo
      15,           // colNo
      "",           // aName
      "sym_window", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\gencoswin.m", // pName
      0 // checkKind
  };
  array<double, 1U> b_w;
  double L;
  int i;
  int trivialwin;
  int w_size;
  signed char w_data;
  if (std::isinf(varargin_1) || std::isnan(varargin_1)) {
    f_rtErrorWithMessageID("input number 1, N,", i_emlrtRTEI.fName,
                           i_emlrtRTEI.lineNo);
  }
  w_size = 1;
  w_data = 0;
  trivialwin = 0;
  if (varargin_1 < 0.0) {
    d_rtErrorWithMessageID("N", g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (varargin_1 == std::floor(varargin_1)) {
    L = varargin_1;
  } else {
    L = std::round(varargin_1);
  }
  if (L == 0.0) {
    w_size = 0;
    trivialwin = 1;
  } else if (L == 1.0) {
    w_data = 1;
    trivialwin = 1;
  }
  w.set_size(w_size);
  for (i = 0; i < w_size; i++) {
    w[0] = w_data;
  }
  if (trivialwin == 0) {
    boolean_T tf;
    tf = signalwavelet::internal::iseven(L);
    if (tf) {
      int iv[2];
      int i1;
      int loop_ub;
      calc_window(L / 2.0, L, w);
      if (w.size(0) < 1) {
        i = 0;
        w_size = 1;
        i1 = -1;
      } else {
        i = w.size(0) - 1;
        w_size = -1;
        i1 = 0;
      }
      iv[0] = 1;
      trivialwin = div_s32(i1 - i, w_size);
      iv[1] = trivialwin + 1;
      internal::indexShapeCheck(w.size(0), iv);
      b_w.set_size((w.size(0) + trivialwin) + 1);
      loop_ub = w.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_w[i1] = w[i1];
      }
      for (i1 = 0; i1 <= trivialwin; i1++) {
        b_w[i1 + w.size(0)] = w[i + w_size * i1];
      }
      w.set_size(b_w.size(0));
      trivialwin = b_w.size(0);
      for (i = 0; i < trivialwin; i++) {
        w[i] = b_w[i];
      }
    } else {
      int iv[2];
      int i1;
      int loop_ub;
      calc_window((L + 1.0) / 2.0, L, w);
      if (w.size(0) - 1 < 1) {
        i = 0;
        w_size = 1;
        i1 = -1;
      } else {
        if ((w.size(0) - 1 < 1) || (w.size(0) - 1 > w.size(0))) {
          rtDynamicBoundsError(w.size(0) - 1, 1, w.size(0), &emlrtBCI);
        }
        i = w.size(0) - 2;
        w_size = -1;
        if (w.size(0) < 1) {
          rtDynamicBoundsError(1, 1, w.size(0), &b_emlrtBCI);
        }
        i1 = 0;
      }
      iv[0] = 1;
      trivialwin = div_s32(i1 - i, w_size);
      iv[1] = trivialwin + 1;
      internal::indexShapeCheck(w.size(0), iv);
      b_w.set_size((w.size(0) + trivialwin) + 1);
      loop_ub = w.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_w[i1] = w[i1];
      }
      for (i1 = 0; i1 <= trivialwin; i1++) {
        b_w[i1 + w.size(0)] = w[i + w_size * i1];
      }
      w.set_size(b_w.size(0));
      trivialwin = b_w.size(0);
      for (i = 0; i < trivialwin; i++) {
        w[i] = b_w[i];
      }
    }
  }
}

} // namespace coder

//
// File trailer for hamming.cpp
//
// [EOF]
//
