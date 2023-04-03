//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdcenterdc.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "psdcenterdc.h"
#include "colon.h"
#include "indexShapeCheck.h"
#include "iseven.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_internal_types.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &Pxx
//                const ::coder::array<double, 1U> &F
//                ::coder::array<double, 2U> &Pxxc
//                const struct_T b_psdoptions
//                ::coder::array<double, 2U> &Pxx1
//                ::coder::array<double, 1U> &F1
//                ::coder::array<double, 2U> &Pxxc1
// Return Type  : void
//
namespace coder {
namespace signal {
namespace internal {
namespace spectral {
void psdcenterdc(::coder::array<double, 2U> &Pxx,
                 const ::coder::array<double, 1U> &F,
                 ::coder::array<double, 2U> &Pxxc, const struct_T b_psdoptions,
                 ::coder::array<double, 2U> &Pxx1,
                 ::coder::array<double, 1U> &F1,
                 ::coder::array<double, 2U> &Pxxc1)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      56,            // lineNo
      8,             // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      58,            // lineNo
      16,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      72,            // lineNo
      9,             // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      72,            // lineNo
      30,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      55,            // lineNo
      12,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      74,            // lineNo
      8,             // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      74,            // lineNo
      26,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      76,            // lineNo
      8,             // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      76,            // lineNo
      28,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      33,            // lineNo
      14,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      33,            // lineNo
      16,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      33,            // lineNo
      32,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      33,            // lineNo
      34,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      31,            // lineNo
      11,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      31,            // lineNo
      13,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      31,            // lineNo
      28,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo q_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      31,            // lineNo
      30,            // colNo
      "",            // aName
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      0                          // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      74,            // lineNo
      8,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      1                          // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      74,            // lineNo
      26,            // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      1                          // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      76,            // lineNo
      8,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      1                          // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      76,            // lineNo
      28,            // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      1                          // checkKind
  };
  static rtDoubleCheckInfo emlrtDCI{
      55,            // lineNo
      12,            // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m", // pName
      1                          // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      -1,            // nDims
      33,            // lineNo
      9,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static rtEqualityCheckInfo c_emlrtECI{
      -1,            // nDims
      72,            // lineNo
      3,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      -1,            // nDims
      74,            // lineNo
      3,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      -1,            // nDims
      76,            // lineNo
      3,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,            // nDims
      31,            // lineNo
      7,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static rtEqualityCheckInfo f_emlrtECI{
      -1,            // nDims
      40,            // lineNo
      7,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static rtEqualityCheckInfo g_emlrtECI{
      -1,            // nDims
      42,            // lineNo
      9,             // colNo
      "psdcenterdc", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\psdcenterdc.m" // pName
  };
  static const char b_cv[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  array<double, 2U> idx;
  array<double, 2U> r;
  array<double, 2U> r1;
  array<double, 2U> y;
  array<double, 1U> Pxx1_tmp;
  int iv[2];
  if (F.size(0) == 0) {
    int kstr;
    Pxx1.set_size(Pxx.size(0), Pxx.size(1));
    kstr = Pxx.size(0) * Pxx.size(1);
    for (int i{0}; i < kstr; i++) {
      Pxx1[i] = Pxx[i];
    }
    F1.set_size(0);
    Pxxc1.set_size(Pxxc.size(0), Pxxc.size(1));
    kstr = Pxxc.size(0) * Pxxc.size(1);
    for (int i{0}; i < kstr; i++) {
      Pxxc1[i] = Pxxc[i];
    }
  } else {
    double Fs;
    double a;
    int i;
    int i1;
    int i2;
    int kstr;
    int loop_ub;
    boolean_T even_nfft;
    boolean_T isonesided;
    even_nfft = signalwavelet::internal::iseven(b_psdoptions.nfft);
    isonesided = false;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (cv[static_cast<int>(b_psdoptions.range[kstr])] !=
            cv[static_cast<int>(b_cv[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        isonesided = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (isonesided) {
      if (even_nfft) {
        int i3;
        if (Pxx.size(0) - 1 < 2) {
          i = 0;
          i1 = 0;
        } else {
          if (Pxx.size(0) < 2) {
            rtDynamicBoundsError(2, 1, Pxx.size(0), &p_emlrtBCI);
          }
          i = 1;
          if ((Pxx.size(0) - 1 < 1) || (Pxx.size(0) - 1 > Pxx.size(0))) {
            rtDynamicBoundsError(Pxx.size(0) - 1, 1, Pxx.size(0), &q_emlrtBCI);
          }
          i1 = Pxx.size(0) - 1;
        }
        if (Pxx.size(0) - 1 < 2) {
          i2 = 0;
          i3 = 0;
        } else {
          if (Pxx.size(0) < 2) {
            rtDynamicBoundsError(2, 1, Pxx.size(0), &n_emlrtBCI);
          }
          i2 = 1;
          if ((Pxx.size(0) - 1 < 1) || (Pxx.size(0) - 1 > Pxx.size(0))) {
            rtDynamicBoundsError(Pxx.size(0) - 1, 1, Pxx.size(0), &o_emlrtBCI);
          }
          i3 = Pxx.size(0) - 1;
        }
        kstr = Pxx.size(1);
        loop_ub = i1 - i;
        r.set_size(loop_ub, Pxx.size(1));
        for (i1 = 0; i1 < kstr; i1++) {
          for (int i4{0}; i4 < loop_ub; i4++) {
            r[i4] = Pxx[i + i4] / 2.0;
          }
        }
        iv[0] = i3 - i2;
        iv[1] = Pxx.size(1);
        rtSubAssignSizeCheck(&iv[0], 2, r.size(), 2, &emlrtECI);
        kstr = r.size(1);
        for (i = 0; i < kstr; i++) {
          loop_ub = r.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            Pxx[i2 + i1] = r[i1];
          }
        }
        if ((Pxxc.size(0) != 0) && (Pxxc.size(1) != 0)) {
          if (Pxxc.size(0) - 1 < 2) {
            i = 0;
            i1 = 0;
          } else {
            if (Pxxc.size(0) < 2) {
              rtDynamicBoundsError(2, 1, Pxxc.size(0), &l_emlrtBCI);
            }
            i = 1;
            if ((Pxxc.size(0) - 1 < 1) || (Pxxc.size(0) - 1 > Pxxc.size(0))) {
              rtDynamicBoundsError(Pxxc.size(0) - 1, 1, Pxxc.size(0),
                                   &m_emlrtBCI);
            }
            i1 = Pxxc.size(0) - 1;
          }
          if (Pxxc.size(0) - 1 < 2) {
            i2 = 0;
            i3 = 0;
          } else {
            if (Pxxc.size(0) < 2) {
              rtDynamicBoundsError(2, 1, Pxxc.size(0), &j_emlrtBCI);
            }
            i2 = 1;
            if ((Pxxc.size(0) - 1 < 1) || (Pxxc.size(0) - 1 > Pxxc.size(0))) {
              rtDynamicBoundsError(Pxxc.size(0) - 1, 1, Pxxc.size(0),
                                   &k_emlrtBCI);
            }
            i3 = Pxxc.size(0) - 1;
          }
          kstr = Pxxc.size(1);
          loop_ub = i1 - i;
          r.set_size(loop_ub, Pxxc.size(1));
          for (i1 = 0; i1 < kstr; i1++) {
            for (int i4{0}; i4 < loop_ub; i4++) {
              r[i4 + r.size(0) * i1] = Pxxc[(i + i4) + Pxxc.size(0) * i1] / 2.0;
            }
          }
          iv[0] = i3 - i2;
          iv[1] = Pxxc.size(1);
          rtSubAssignSizeCheck(&iv[0], 2, r.size(), 2, &b_emlrtECI);
          kstr = r.size(1);
          loop_ub = r.size(0);
          for (i = 0; i < kstr; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              Pxxc[(i2 + i1) + Pxxc.size(0) * i] = r[i1 + r.size(0) * i];
            }
          }
        }
        if (F.size(0) - 1 < 2) {
          y.set_size(1, 0);
        } else {
          y.set_size(1, F.size(0) - 2);
          kstr = F.size(0) - 3;
          for (i = 0; i <= kstr; i++) {
            y[i] =
                (static_cast<double>(F.size(0)) - 1.0) - static_cast<double>(i);
          }
        }
        idx.set_size(1, F.size(0) + y.size(1));
        kstr = y.size(1);
        for (i = 0; i < kstr; i++) {
          idx[i] = y[i];
        }
        kstr = F.size(0) - 1;
        for (i = 0; i <= kstr; i++) {
          idx[i + y.size(1)] = static_cast<double>(i) + 1.0;
        }
      } else {
        int i3;
        if (Pxx.size(0) < 2) {
          i = 0;
          i1 = 0;
          i2 = 0;
          i3 = 0;
        } else {
          i = 1;
          i1 = Pxx.size(0);
          i2 = 1;
          i3 = Pxx.size(0);
        }
        kstr = Pxx.size(1);
        loop_ub = i1 - i;
        r.set_size(loop_ub, Pxx.size(1));
        for (i1 = 0; i1 < kstr; i1++) {
          for (int i4{0}; i4 < loop_ub; i4++) {
            r[i4] = Pxx[i + i4] / 2.0;
          }
        }
        iv[0] = i3 - i2;
        iv[1] = Pxx.size(1);
        rtSubAssignSizeCheck(&iv[0], 2, r.size(), 2, &f_emlrtECI);
        kstr = r.size(1);
        for (i = 0; i < kstr; i++) {
          loop_ub = r.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            Pxx[i2 + i1] = r[i1];
          }
        }
        if ((Pxxc.size(0) != 0) && (Pxxc.size(1) != 0)) {
          if (Pxxc.size(0) < 2) {
            i = 0;
            i1 = 0;
            i2 = 0;
            i3 = 0;
          } else {
            i = 1;
            i1 = Pxxc.size(0);
            i2 = 1;
            i3 = Pxxc.size(0);
          }
          kstr = Pxxc.size(1);
          loop_ub = i1 - i;
          r1.set_size(loop_ub, Pxxc.size(1));
          for (i1 = 0; i1 < kstr; i1++) {
            for (int i4{0}; i4 < loop_ub; i4++) {
              r1[i4 + r1.size(0) * i1] =
                  Pxxc[(i + i4) + Pxxc.size(0) * i1] / 2.0;
            }
          }
          iv[0] = i3 - i2;
          iv[1] = Pxxc.size(1);
          rtSubAssignSizeCheck(&iv[0], 2, r1.size(), 2, &g_emlrtECI);
          kstr = r1.size(1);
          loop_ub = r1.size(0);
          for (i = 0; i < kstr; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              Pxxc[(i2 + i1) + Pxxc.size(0) * i] = r1[i1 + r1.size(0) * i];
            }
          }
        }
        if (F.size(0) < 2) {
          y.set_size(1, 0);
        } else {
          y.set_size(1, F.size(0) - 1);
          kstr = F.size(0) - 2;
          for (i = 0; i <= kstr; i++) {
            y[i] = static_cast<double>(F.size(0)) - static_cast<double>(i);
          }
        }
        idx.set_size(1, F.size(0) + y.size(1));
        kstr = y.size(1);
        for (i = 0; i < kstr; i++) {
          idx[i] = y[i];
        }
        kstr = F.size(0) - 1;
        for (i = 0; i <= kstr; i++) {
          idx[i + y.size(1)] = static_cast<double>(i) + 1.0;
        }
      }
    } else if (even_nfft) {
      a = static_cast<double>(F.size(0)) / 2.0 + 2.0;
      if (F.size(0) < a) {
        y.set_size(1, 0);
      } else if (std::floor(a) == a) {
        y.set_size(1, (F.size(0) - static_cast<int>(a)) + 1);
        kstr = F.size(0) - static_cast<int>(a);
        for (i = 0; i <= kstr; i++) {
          y[i] = a + static_cast<double>(i);
        }
      } else {
        eml_float_colon(a, static_cast<double>(F.size(0)), y);
      }
      a = static_cast<double>(F.size(0)) / 2.0 + 1.0;
      idx.set_size(1, (y.size(1) + static_cast<int>(a - 1.0)) + 1);
      kstr = y.size(1);
      for (i = 0; i < kstr; i++) {
        idx[i] = y[i];
      }
      kstr = static_cast<int>(a - 1.0);
      for (i = 0; i <= kstr; i++) {
        idx[i + y.size(1)] = static_cast<double>(i) + 1.0;
      }
    } else {
      a = (static_cast<double>(F.size(0)) + 1.0) / 2.0 + 1.0;
      if (F.size(0) < a) {
        y.set_size(1, 0);
      } else if (std::floor(a) == a) {
        y.set_size(1, (F.size(0) - static_cast<int>(a)) + 1);
        kstr = F.size(0) - static_cast<int>(a);
        for (i = 0; i <= kstr; i++) {
          y[i] = a + static_cast<double>(i);
        }
      } else {
        eml_float_colon(a, static_cast<double>(F.size(0)), y);
      }
      a = (static_cast<double>(F.size(0)) + 1.0) / 2.0;
      idx.set_size(1, (y.size(1) + static_cast<int>(a - 1.0)) + 1);
      kstr = y.size(1);
      for (i = 0; i < kstr; i++) {
        idx[i] = y[i];
      }
      kstr = static_cast<int>(a - 1.0);
      for (i = 0; i <= kstr; i++) {
        idx[i + y.size(1)] = static_cast<double>(i) + 1.0;
      }
    }
    Pxx1_tmp.set_size(idx.size(1));
    kstr = idx.size(1);
    for (i = 0; i < kstr; i++) {
      Pxx1_tmp[i] = idx[i];
    }
    kstr = Pxx.size(1);
    Pxx1.set_size(Pxx1_tmp.size(0), Pxx.size(1));
    for (i = 0; i < kstr; i++) {
      loop_ub = Pxx1_tmp.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        if (Pxx1_tmp[i1] != static_cast<int>(std::floor(Pxx1_tmp[i1]))) {
          rtIntegerError(Pxx1_tmp[i1], &emlrtDCI);
        }
        i2 = static_cast<int>(Pxx1_tmp[i1]);
        if ((i2 < 1) || (i2 > Pxx.size(0))) {
          rtDynamicBoundsError(i2, 1, Pxx.size(0), &emlrtBCI);
        }
        Pxx1[i1] = Pxx[i2 - 1];
      }
    }
    iv[0] = (*(int(*)[2])idx.size())[0];
    iv[1] = (*(int(*)[2])idx.size())[1];
    ::coder::internal::indexShapeCheck(F.size(0), iv);
    F1.set_size(idx.size(1));
    kstr = idx.size(1);
    for (i = 0; i < kstr; i++) {
      i1 = static_cast<int>(idx[i]);
      if ((i1 < 1) || (i1 > F.size(0))) {
        rtDynamicBoundsError(i1, 1, F.size(0), &b_emlrtBCI);
      }
      F1[i] = F[i1 - 1];
    }
    if ((Pxxc.size(0) != 0) && (Pxxc.size(1) != 0)) {
      kstr = Pxxc.size(1);
      Pxxc1.set_size(Pxx1_tmp.size(0), Pxxc.size(1));
      loop_ub = Pxx1_tmp.size(0);
      for (i = 0; i < kstr; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          i2 = static_cast<int>(Pxx1_tmp[i1]);
          if ((i2 < 1) || (i2 > Pxxc.size(0))) {
            rtDynamicBoundsError(static_cast<int>(Pxx1_tmp[i1]), 1,
                                 Pxxc.size(0), &c_emlrtBCI);
          }
          Pxxc1[i1 + Pxxc1.size(0) * i] = Pxxc[(i2 + Pxxc.size(0) * i) - 1];
        }
      }
    } else {
      Pxxc1.set_size(Pxxc.size(0), Pxxc.size(1));
      kstr = Pxxc.size(0) * Pxxc.size(1);
      for (i = 0; i < kstr; i++) {
        Pxxc1[i] = Pxxc[i];
      }
    }
    if (std::isnan(b_psdoptions.Fs)) {
      Fs = 6.2831853071795862;
    } else {
      Fs = b_psdoptions.Fs;
    }
    if (isonesided) {
      kstr = idx.size(1) - F.size(0);
      if (kstr < 1) {
        kstr = 0;
      } else if (kstr > idx.size(1)) {
        rtDynamicBoundsError(kstr, 1, idx.size(1), &e_emlrtBCI);
      }
      iv[0] = 1;
      iv[1] = kstr;
      ::coder::internal::indexShapeCheck(idx.size(1), iv);
      loop_ub = idx.size(1) - F.size(0);
      if (loop_ub < 1) {
        loop_ub = 0;
      } else if (loop_ub > idx.size(1)) {
        rtDynamicBoundsError(loop_ub, 1, idx.size(1), &d_emlrtBCI);
      }
      Pxx1_tmp.set_size(kstr);
      for (i = 0; i < kstr; i++) {
        Pxx1_tmp[i] = -F1[i];
      }
      if (loop_ub != Pxx1_tmp.size(0)) {
        rtSizeEq1DError(loop_ub, Pxx1_tmp.size(0), &c_emlrtECI);
      }
      for (i = 0; i < loop_ub; i++) {
        F1[i] = Pxx1_tmp[i];
      }
    } else if (even_nfft) {
      a = static_cast<double>(F.size(0)) / 2.0 - 1.0;
      if (a < 1.0) {
        i = 0;
      } else {
        if (a != std::floor(a)) {
          rtIntegerError(a, &c_emlrtDCI);
        }
        if (static_cast<int>(a) > idx.size(1)) {
          rtDynamicBoundsError(static_cast<int>(a), 1, idx.size(1),
                               &g_emlrtBCI);
        }
        i = static_cast<int>(a);
      }
      iv[0] = 1;
      iv[1] = i;
      ::coder::internal::indexShapeCheck(idx.size(1), iv);
      a = static_cast<double>(F.size(0)) / 2.0 - 1.0;
      if (a < 1.0) {
        kstr = 0;
      } else {
        if (a != std::floor(a)) {
          rtIntegerError(a, &b_emlrtDCI);
        }
        if (static_cast<int>(a) > idx.size(1)) {
          rtDynamicBoundsError(static_cast<int>(a), 1, idx.size(1),
                               &f_emlrtBCI);
        }
        kstr = static_cast<int>(a);
      }
      if (kstr != i) {
        rtSizeEq1DError(kstr, i, &d_emlrtECI);
      }
      y.set_size(1, kstr);
      for (i = 0; i < kstr; i++) {
        y[i] = F1[i] - Fs;
      }
      kstr = y.size(1);
      for (i = 0; i < kstr; i++) {
        F1[i] = y[i];
      }
    } else {
      a = (static_cast<double>(F.size(0)) - 1.0) / 2.0;
      if (a < 1.0) {
        i = 0;
      } else {
        if (a != std::floor(a)) {
          rtIntegerError(a, &e_emlrtDCI);
        }
        if (static_cast<int>(a) > idx.size(1)) {
          rtDynamicBoundsError(static_cast<int>(a), 1, idx.size(1),
                               &i_emlrtBCI);
        }
        i = static_cast<int>(a);
      }
      iv[0] = 1;
      iv[1] = i;
      ::coder::internal::indexShapeCheck(idx.size(1), iv);
      a = (static_cast<double>(F.size(0)) - 1.0) / 2.0;
      if (a < 1.0) {
        kstr = 0;
      } else {
        if (a != std::floor(a)) {
          rtIntegerError(a, &d_emlrtDCI);
        }
        if (static_cast<int>(a) > idx.size(1)) {
          rtDynamicBoundsError(static_cast<int>(a), 1, idx.size(1),
                               &h_emlrtBCI);
        }
        kstr = static_cast<int>(a);
      }
      if (kstr != i) {
        rtSizeEq1DError(kstr, i, &e_emlrtECI);
      }
      y.set_size(1, kstr);
      for (i = 0; i < kstr; i++) {
        y[i] = F1[i] - Fs;
      }
      kstr = y.size(1);
      for (i = 0; i < kstr; i++) {
        F1[i] = y[i];
      }
    }
  }
}

} // namespace spectral
} // namespace internal
} // namespace signal
} // namespace coder

//
// File trailer for psdcenterdc.cpp
//
// [EOF]
//
