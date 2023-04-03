//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: welch.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "welch.h"
#include "computeperiodogram.h"
#include "computepsd.h"
#include "ixfun.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_internal_types.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "psdcenterdc.h"
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include "welchparse.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2);

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2)
{
  coder::array<double, 2U> b_in1;
  int b_in2_idx_0;
  int b_loop_ub;
  int in2_idx_0;
  int loop_ub;
  int stride_1_0;
  in2_idx_0 = in2.size(0);
  if (in2_idx_0 == 1) {
    b_in2_idx_0 = in1.size(0);
  } else {
    b_in2_idx_0 = in2_idx_0;
  }
  b_in1.set_size(b_in2_idx_0, in1.size(1));
  b_in2_idx_0 = (in1.size(0) != 1);
  stride_1_0 = (in2_idx_0 != 1);
  loop_ub = in1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    if (in2_idx_0 == 1) {
      b_loop_ub = in1.size(0);
    } else {
      b_loop_ub = in2_idx_0;
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_in1[i1] = in1[i1 * b_in2_idx_0] + in2[i1 * stride_1_0];
    }
  }
  in1.set_size(b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1] = b_in1[i1];
    }
  }
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &x
//                const ::coder::array<double, 1U> &varargin_1
//                double varargin_2
//                double varargin_3
//                double varargin_4
//                ::coder::array<double, 2U> &varargout_1
//                ::coder::array<double, 1U> &varargout_2
// Return Type  : void
//
namespace coder {
void welch(const ::coder::array<creal_T, 2U> &x,
           const ::coder::array<double, 1U> &varargin_1, double varargin_2,
           double varargin_3, double varargin_4,
           ::coder::array<double, 2U> &varargout_1,
           ::coder::array<double, 1U> &varargout_2)
{
  static rtBoundsCheckInfo
      b_emlrtBCI{
          -1,                    // iFirst
          -1,                    // iLast
          397,                   // lineNo
          58,                    // colNo
          "",                    // aName
          "localComputeSpectra", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m", // pName
          0 // checkKind
      };
  static rtBoundsCheckInfo
      c_emlrtBCI{
          -1,                    // iFirst
          -1,                    // iLast
          397,                   // lineNo
          42,                    // colNo
          "",                    // aName
          "localComputeSpectra", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m", // pName
          0 // checkKind
      };
  static rtBoundsCheckInfo
      d_emlrtBCI{
          -1,                    // iFirst
          -1,                    // iLast
          397,                   // lineNo
          53,                    // colNo
          "",                    // aName
          "localComputeSpectra", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m", // pName
          0 // checkKind
      };
  static rtBoundsCheckInfo
      emlrtBCI{
          -1,                    // iFirst
          -1,                    // iLast
          397,                   // lineNo
          49,                    // colNo
          "",                    // aName
          "localComputeSpectra", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m", // pName
          0 // checkKind
      };
  static rtDoubleCheckInfo
      b_emlrtDCI{
          397,                   // lineNo
          53,                    // colNo
          "localComputeSpectra", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m", // pName
          1 // checkKind
      };
  static rtDoubleCheckInfo
      emlrtDCI{
          397,                   // lineNo
          42,                    // colNo
          "localComputeSpectra", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m", // pName
          1 // checkKind
      };
  static rtEqualityCheckInfo emlrtECI{
      1,                     // nDims
      404,                   // lineNo
      22,                    // colNo
      "localComputeSpectra", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\private\\welch.m" // pName
  };
  static const char varargin_5[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  array<creal_T, 1U> b_x1;
  array<creal_T, 1U> x1;
  array<double, 2U> Pxxc1;
  array<double, 2U> Sxx1;
  array<double, 2U> b_Sxx1;
  array<double, 2U> r;
  array<double, 2U> xEnd;
  array<double, 2U> xStart;
  array<double, 1U> Sxxk;
  array<double, 1U> w;
  array<double, 1U> win1;
  struct_T options;
  double L;
  double LminusOverlap;
  double k1;
  double ndbl;
  double noverlap;
  int winName_size[2];
  int winParam_size[2];
  int k;
  int loop_ub;
  int nm1d2;
  char winName_data[12];
  char units_data[10];
  char winParam_data[9];
  win1.set_size(varargin_1.size(0));
  loop_ub = varargin_1.size(0);
  for (k = 0; k < loop_ub; k++) {
    win1[k] = varargin_1[k];
  }
  signal::internal::spectral::welchparse(
      x, win1, varargin_2, varargin_3, varargin_4, varargin_5, x1, &ndbl,
      winName_data, winName_size, winParam_data, winParam_size, &noverlap, &k1,
      &L, &options);
  LminusOverlap = L - noverlap;
  noverlap = k1 * LminusOverlap;
  if (std::isnan(LminusOverlap) || std::isnan(noverlap)) {
    xStart.set_size(1, 1);
    xStart[0] = rtNaN;
  } else if ((LminusOverlap == 0.0) ||
             ((noverlap > 1.0) && (LminusOverlap < 0.0)) ||
             ((noverlap < 1.0) && (LminusOverlap > 0.0))) {
    xStart.set_size(1, 0);
  } else if (std::isinf(noverlap) && std::isinf(LminusOverlap)) {
    xStart.set_size(1, 1);
    xStart[0] = rtNaN;
  } else if (std::isinf(LminusOverlap)) {
    xStart.set_size(1, 1);
    xStart[0] = 1.0;
  } else if (std::floor(LminusOverlap) == LminusOverlap) {
    loop_ub = static_cast<int>((noverlap - 1.0) / LminusOverlap);
    xStart.set_size(1, loop_ub + 1);
    for (k = 0; k <= loop_ub; k++) {
      xStart[k] = LminusOverlap * static_cast<double>(k) + 1.0;
    }
  } else {
    double apnd;
    double cdiff;
    ndbl = std::floor((noverlap - 1.0) / LminusOverlap + 0.5);
    apnd = ndbl * LminusOverlap + 1.0;
    if (LminusOverlap > 0.0) {
      cdiff = apnd - noverlap;
    } else {
      cdiff = noverlap - apnd;
    }
    if (std::abs(cdiff) <
        4.4408920985006262E-16 * std::fmax(1.0, std::abs(noverlap))) {
      ndbl++;
      apnd = noverlap;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * LminusOverlap + 1.0;
    } else {
      ndbl++;
    }
    if (ndbl >= 0.0) {
      loop_ub = static_cast<int>(ndbl);
    } else {
      loop_ub = 0;
    }
    if (ndbl > 2.147483647E+9) {
      rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    }
    xStart.set_size(1, loop_ub);
    if (loop_ub > 0) {
      xStart[0] = 1.0;
      if (loop_ub > 1) {
        xStart[loop_ub - 1] = apnd;
        nm1d2 = (loop_ub - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          ndbl = (static_cast<double>(k) + 1.0) * LminusOverlap;
          xStart[k + 1] = ndbl + 1.0;
          xStart[(loop_ub - k) - 2] = apnd - ndbl;
        }
        if (nm1d2 << 1 == loop_ub - 1) {
          xStart[nm1d2] = (apnd + 1.0) / 2.0;
        } else {
          ndbl = static_cast<double>(nm1d2) * LminusOverlap;
          xStart[nm1d2] = ndbl + 1.0;
          xStart[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }
  }
  xEnd.set_size(1, xStart.size(1));
  loop_ub = xStart.size(1);
  for (k = 0; k < loop_ub; k++) {
    xEnd[k] = (xStart[k] + L) - 1.0;
  }
  if (options.maxhold) {
    Sxx1.set_size(0, 0);
    k = static_cast<int>(k1);
    for (int ii{0}; ii < k; ii++) {
      int i;
      int i1;
      if ((ii + 1 < 1) || (ii + 1 > xStart.size(1))) {
        rtDynamicBoundsError(ii + 1, 1, xStart.size(1), &emlrtBCI);
      }
      if ((ii + 1 < 1) || (ii + 1 > xEnd.size(1))) {
        rtDynamicBoundsError(ii + 1, 1, xEnd.size(1), &b_emlrtBCI);
      }
      if (xStart[ii] > xEnd[ii]) {
        i = 0;
        i1 = 0;
      } else {
        if (xStart[ii] != static_cast<int>(std::floor(xStart[ii]))) {
          rtIntegerError(xStart[ii], &emlrtDCI);
        }
        i = static_cast<int>(xStart[ii]);
        if ((i < 1) || (i > x1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(xStart[ii]), 1, x1.size(0),
                               &c_emlrtBCI);
        }
        i--;
        if (xEnd[ii] != static_cast<int>(std::floor(xEnd[ii]))) {
          rtIntegerError(xEnd[ii], &b_emlrtDCI);
        }
        i1 = static_cast<int>(xEnd[ii]);
        if ((i1 < 1) || (i1 > x1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(xEnd[ii]), 1, x1.size(0),
                               &d_emlrtBCI);
        }
      }
      loop_ub = i1 - i;
      b_x1.set_size(loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x1[i1] = x1[i + i1];
      }
      computeperiodogram(b_x1, win1, options.nfft, options.Fs, Sxxk, w);
      if (ii + 1U == 1U) {
        loop_ub = Sxxk.size(0);
        for (i = 0; i < loop_ub; i++) {
          noverlap = k1 * Sxxk[i];
          Sxxk[i] = std::fmax(rtMinusInf, noverlap);
        }
        loop_ub = Sxxk.size(0);
        Sxx1.set_size(Sxxk.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          Sxx1[i] = Sxxk[i];
        }
      } else {
        loop_ub = Sxxk.size(0);
        for (i = 0; i < loop_ub; i++) {
          Sxxk[i] = k1 * Sxxk[i];
        }
        loop_ub = Sxx1.size(0);
        if ((Sxx1.size(0) == Sxxk.size(0)) && (Sxx1.size(1) == 1)) {
          Sxxk.set_size(Sxx1.size(0));
          for (i = 0; i < loop_ub; i++) {
            ndbl = Sxx1[i];
            noverlap = Sxxk[i];
            Sxxk[i] = std::fmax(ndbl, noverlap);
          }
          loop_ub = Sxxk.size(0);
          Sxx1.set_size(Sxxk.size(0), 1);
          for (i = 0; i < loop_ub; i++) {
            Sxx1[i] = Sxxk[i];
          }
        } else {
          b_Sxx1.set_size(Sxx1.size(0), Sxx1.size(1));
          loop_ub = Sxx1.size(0) * Sxx1.size(1) - 1;
          for (i = 0; i <= loop_ub; i++) {
            b_Sxx1[i] = Sxx1[i];
          }
          internal::expand_max(b_Sxx1, Sxxk, Sxx1);
        }
      }
    }
    loop_ub = Sxx1.size(0) * Sxx1.size(1);
    for (k = 0; k < loop_ub; k++) {
      Sxx1[k] = Sxx1[k] / k1;
    }
    psdfreqvec(options.nfft, options.Fs, w);
    loop_ub = w.size(0);
    xStart = w.reshape(loop_ub, 1);
    computepsd(Sxx1, xStart, options.range, options.nfft, options.Fs,
               varargout_1, varargout_2, units_data, winName_size);
  } else if (options.minhold) {
    Sxx1.set_size(0, 0);
    k = static_cast<int>(k1);
    for (int ii{0}; ii < k; ii++) {
      int i;
      int i1;
      if ((ii + 1 < 1) || (ii + 1 > xStart.size(1))) {
        rtDynamicBoundsError(ii + 1, 1, xStart.size(1), &emlrtBCI);
      }
      if ((ii + 1 < 1) || (ii + 1 > xEnd.size(1))) {
        rtDynamicBoundsError(ii + 1, 1, xEnd.size(1), &b_emlrtBCI);
      }
      if (xStart[ii] > xEnd[ii]) {
        i = 0;
        i1 = 0;
      } else {
        if (xStart[ii] != static_cast<int>(std::floor(xStart[ii]))) {
          rtIntegerError(xStart[ii], &emlrtDCI);
        }
        i = static_cast<int>(xStart[ii]);
        if ((i < 1) || (i > x1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(xStart[ii]), 1, x1.size(0),
                               &c_emlrtBCI);
        }
        i--;
        if (xEnd[ii] != static_cast<int>(std::floor(xEnd[ii]))) {
          rtIntegerError(xEnd[ii], &b_emlrtDCI);
        }
        i1 = static_cast<int>(xEnd[ii]);
        if ((i1 < 1) || (i1 > x1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(xEnd[ii]), 1, x1.size(0),
                               &d_emlrtBCI);
        }
      }
      loop_ub = i1 - i;
      b_x1.set_size(loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x1[i1] = x1[i + i1];
      }
      computeperiodogram(b_x1, win1, options.nfft, options.Fs, Sxxk, w);
      if (ii + 1U == 1U) {
        loop_ub = Sxxk.size(0);
        for (i = 0; i < loop_ub; i++) {
          noverlap = k1 * Sxxk[i];
          Sxxk[i] = std::fmin(rtInf, noverlap);
        }
        loop_ub = Sxxk.size(0);
        Sxx1.set_size(Sxxk.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          Sxx1[i] = Sxxk[i];
        }
      } else {
        loop_ub = Sxxk.size(0);
        for (i = 0; i < loop_ub; i++) {
          Sxxk[i] = k1 * Sxxk[i];
        }
        loop_ub = Sxx1.size(0);
        if ((Sxx1.size(0) == Sxxk.size(0)) && (Sxx1.size(1) == 1)) {
          Sxxk.set_size(Sxx1.size(0));
          for (i = 0; i < loop_ub; i++) {
            ndbl = Sxx1[i];
            noverlap = Sxxk[i];
            Sxxk[i] = std::fmin(ndbl, noverlap);
          }
          loop_ub = Sxxk.size(0);
          Sxx1.set_size(Sxxk.size(0), 1);
          for (i = 0; i < loop_ub; i++) {
            Sxx1[i] = Sxxk[i];
          }
        } else {
          b_Sxx1.set_size(Sxx1.size(0), Sxx1.size(1));
          loop_ub = Sxx1.size(0) * Sxx1.size(1) - 1;
          for (i = 0; i <= loop_ub; i++) {
            b_Sxx1[i] = Sxx1[i];
          }
          internal::expand_min(b_Sxx1, Sxxk, Sxx1);
        }
      }
    }
    loop_ub = Sxx1.size(0) * Sxx1.size(1);
    for (k = 0; k < loop_ub; k++) {
      Sxx1[k] = Sxx1[k] / k1;
    }
    psdfreqvec(options.nfft, options.Fs, w);
    loop_ub = w.size(0);
    xStart = w.reshape(loop_ub, 1);
    computepsd(Sxx1, xStart, options.range, options.nfft, options.Fs,
               varargout_1, varargout_2, units_data, winName_size);
  } else {
    Sxx1.set_size(0, 0);
    k = static_cast<int>(k1);
    for (int ii{0}; ii < k; ii++) {
      int i;
      int i1;
      if ((ii + 1 < 1) || (ii + 1 > xStart.size(1))) {
        rtDynamicBoundsError(ii + 1, 1, xStart.size(1), &emlrtBCI);
      }
      if ((ii + 1 < 1) || (ii + 1 > xEnd.size(1))) {
        rtDynamicBoundsError(ii + 1, 1, xEnd.size(1), &b_emlrtBCI);
      }
      if (xStart[ii] > xEnd[ii]) {
        i = 0;
        i1 = 0;
      } else {
        if (xStart[ii] != static_cast<int>(std::floor(xStart[ii]))) {
          rtIntegerError(xStart[ii], &emlrtDCI);
        }
        i = static_cast<int>(xStart[ii]);
        if ((i < 1) || (i > x1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(xStart[ii]), 1, x1.size(0),
                               &c_emlrtBCI);
        }
        i--;
        if (xEnd[ii] != static_cast<int>(std::floor(xEnd[ii]))) {
          rtIntegerError(xEnd[ii], &b_emlrtDCI);
        }
        i1 = static_cast<int>(xEnd[ii]);
        if ((i1 < 1) || (i1 > x1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(xEnd[ii]), 1, x1.size(0),
                               &d_emlrtBCI);
        }
      }
      loop_ub = i1 - i;
      b_x1.set_size(loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x1[i1] = x1[i + i1];
      }
      computeperiodogram(b_x1, win1, options.nfft, options.Fs, Sxxk, w);
      if (ii + 1U == 1U) {
        loop_ub = Sxxk.size(0);
        Sxx1.set_size(Sxxk.size(0), 1);
        for (i = 0; i < loop_ub; i++) {
          Sxx1[i] = Sxxk[i];
        }
      } else {
        if ((Sxx1.size(0) != Sxxk.size(0)) &&
            ((Sxx1.size(0) != 1) && (Sxxk.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(Sxx1.size(0), Sxxk.size(0), &emlrtECI);
        }
        if (Sxx1.size(0) == Sxxk.size(0)) {
          loop_ub = Sxx1.size(1);
          b_Sxx1.set_size(Sxx1.size(0), Sxx1.size(1));
          for (i = 0; i < loop_ub; i++) {
            nm1d2 = Sxx1.size(0);
            for (i1 = 0; i1 < nm1d2; i1++) {
              b_Sxx1[i1] = Sxx1[i1] + Sxxk[i1];
            }
          }
          Sxx1.set_size(b_Sxx1.size(0), b_Sxx1.size(1));
          loop_ub = b_Sxx1.size(0) * b_Sxx1.size(1);
          for (i = 0; i < loop_ub; i++) {
            Sxx1[i] = b_Sxx1[i];
          }
        } else {
          binary_expand_op(Sxx1, Sxxk);
        }
      }
    }
    loop_ub = Sxx1.size(0) * Sxx1.size(1);
    for (k = 0; k < loop_ub; k++) {
      Sxx1[k] = Sxx1[k] / k1;
    }
    psdfreqvec(options.nfft, options.Fs, w);
    loop_ub = w.size(0);
    xStart = w.reshape(loop_ub, 1);
    computepsd(Sxx1, xStart, options.range, options.nfft, options.Fs,
               varargout_1, varargout_2, units_data, winName_size);
  }
  if (options.centerdc) {
    b_Sxx1.set_size(varargout_1.size(0), varargout_1.size(1));
    loop_ub = varargout_1.size(0) * varargout_1.size(1) - 1;
    for (k = 0; k <= loop_ub; k++) {
      b_Sxx1[k] = varargout_1[k];
    }
    r.set_size(0, 0);
    win1.set_size(varargout_2.size(0));
    loop_ub = varargout_2.size(0) - 1;
    for (k = 0; k <= loop_ub; k++) {
      win1[k] = varargout_2[k];
    }
    signal::internal::spectral::psdcenterdc(b_Sxx1, win1, r, options,
                                            varargout_1, varargout_2, Pxxc1);
  }
}

} // namespace coder

//
// File trailer for welch.cpp
//
// [EOF]
//
