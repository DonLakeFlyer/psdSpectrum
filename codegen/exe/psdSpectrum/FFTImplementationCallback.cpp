//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 1U> &x
//                int n2blue
//                int nfft
//                const ::coder::array<double, 2U> &costab
//                const ::coder::array<double, 2U> &sintab
//                const ::coder::array<double, 2U> &sintabinv
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
namespace coder {
namespace internal {
namespace fft {
void FFTImplementationCallback::dobluesteinfft(
    const ::coder::array<creal_T, 1U> &x, int n2blue, int nfft,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab,
    const ::coder::array<double, 2U> &sintabinv, ::coder::array<creal_T, 1U> &y)
{
  static rtDoubleCheckInfo
      emlrtDCI{
          33,                     // lineNo
          28,                     // colNo
          "bluestein_setup_impl", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\bluesteinSetup."
          "m", // pName
          4    // checkKind
      };
  array<creal_T, 1U> fv;
  array<creal_T, 1U> fy;
  array<creal_T, 1U> wwc;
  double b_nt_re_tmp;
  double nt_im;
  double nt_re;
  double re_tmp;
  double twid_im;
  double twid_re;
  int i;
  int iy;
  int ju;
  int k;
  int nInt2;
  int nInt2m1;
  int nRowsD2;
  int nt_re_tmp;
  int rt;
  nInt2m1 = (nfft + nfft) - 1;
  if (nInt2m1 < 0) {
    rtNonNegativeError(static_cast<double>(nInt2m1), &emlrtDCI);
  }
  wwc.set_size(nInt2m1);
  rt = 0;
  wwc[nfft - 1].re = 1.0;
  wwc[nfft - 1].im = 0.0;
  nInt2 = nfft << 1;
  if (nfft - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k <= nfft - 2; k++) {
    iy = ((k + 1) << 1) - 1;
    if (nInt2 - rt <= iy) {
      rt += iy - nInt2;
    } else {
      rt += iy;
    }
    nt_im = -3.1415926535897931 * static_cast<double>(rt) /
            static_cast<double>(nfft);
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }
    ju = (nfft - k) - 2;
    wwc[ju].re = nt_re;
    wwc[ju].im = -nt_im;
  }
  ju = nInt2m1 - 1;
  for (k = ju; k >= nfft; k--) {
    wwc[k] = wwc[(nInt2m1 - k) - 1];
  }
  y.set_size(nfft);
  if (nfft > x.size(0)) {
    y.set_size(nfft);
    for (ju = 0; ju < nfft; ju++) {
      y[ju].re = 0.0;
      y[ju].im = 0.0;
    }
  }
  nInt2m1 = x.size(0);
  if (nfft <= nInt2m1) {
    nInt2m1 = nfft;
  }
  if (nInt2m1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nInt2m1; k++) {
    nt_re_tmp = (nfft + k) - 1;
    nt_re = wwc[nt_re_tmp].re;
    nt_im = wwc[nt_re_tmp].im;
    twid_im = x[k].im;
    re_tmp = x[k].re;
    y[k].re = nt_re * re_tmp + nt_im * twid_im;
    y[k].im = nt_re * twid_im - nt_im * re_tmp;
  }
  iy = nInt2m1 + 1;
  if ((nInt2m1 + 1 <= nfft) && (nfft > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (k = iy; k <= nfft; k++) {
    y[k - 1].re = 0.0;
    y[k - 1].im = 0.0;
  }
  fy.set_size(n2blue);
  if (n2blue > y.size(0)) {
    fy.set_size(n2blue);
    for (ju = 0; ju < n2blue; ju++) {
      fy[ju].re = 0.0;
      fy[ju].im = 0.0;
    }
  }
  rt = y.size(0);
  if (rt > n2blue) {
    rt = n2blue;
  }
  nInt2 = n2blue - 2;
  nRowsD2 = n2blue / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  if (rt - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= rt - 2; i++) {
    boolean_T tst;
    fy[iy] = y[i];
    nInt2m1 = n2blue;
    tst = true;
    while (tst) {
      nInt2m1 >>= 1;
      ju ^= nInt2m1;
      tst = ((ju & nInt2m1) == 0);
    }
    iy = ju;
  }
  fy[iy] = y[rt - 1];
  if (n2blue > 1) {
    for (i = 0; i <= nInt2; i += 2) {
      b_nt_re_tmp = fy[i + 1].re;
      nt_im = fy[i + 1].im;
      re_tmp = fy[i].re;
      twid_re = fy[i].im;
      fy[i + 1].re = re_tmp - b_nt_re_tmp;
      fy[i + 1].im = twid_re - nt_im;
      fy[i].re = re_tmp + b_nt_re_tmp;
      fy[i].im = twid_re + nt_im;
    }
  }
  nInt2m1 = 2;
  rt = 4;
  nInt2 = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < nInt2; i += rt) {
      nt_re_tmp = i + nInt2m1;
      nt_re = fy[nt_re_tmp].re;
      nt_im = fy[nt_re_tmp].im;
      fy[nt_re_tmp].re = fy[i].re - nt_re;
      fy[nt_re_tmp].im = fy[i].im - nt_im;
      fy[i].re = fy[i].re + nt_re;
      fy[i].im = fy[i].im + nt_im;
    }
    iy = 1;
    for (ju = k; ju < nRowsD2; ju += k) {
      int ihi;
      twid_re = costab[ju];
      twid_im = sintab[ju];
      i = iy;
      ihi = iy + nInt2;
      while (i < ihi) {
        nt_re_tmp = i + nInt2m1;
        b_nt_re_tmp = fy[nt_re_tmp].im;
        nt_im = fy[nt_re_tmp].re;
        nt_re = twid_re * nt_im - twid_im * b_nt_re_tmp;
        nt_im = twid_re * b_nt_re_tmp + twid_im * nt_im;
        fy[nt_re_tmp].re = fy[i].re - nt_re;
        fy[nt_re_tmp].im = fy[i].im - nt_im;
        fy[i].re = fy[i].re + nt_re;
        fy[i].im = fy[i].im + nt_im;
        i += rt;
      }
      iy++;
    }
    k /= 2;
    nInt2m1 = rt;
    rt += rt;
    nInt2 -= nInt2m1;
  }
  FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab, sintab,
                                                  fv);
  iy = fy.size(0);
  for (ju = 0; ju < iy; ju++) {
    re_tmp = fy[ju].re;
    nt_im = fv[ju].im;
    twid_re = fy[ju].im;
    twid_im = fv[ju].re;
    fy[ju].re = re_tmp * twid_im - twid_re * nt_im;
    fy[ju].im = re_tmp * nt_im + twid_re * twid_im;
  }
  FFTImplementationCallback::r2br_r2dit_trig_impl(fy, n2blue, costab, sintabinv,
                                                  fv);
  if (fv.size(0) > 1) {
    nt_im = 1.0 / static_cast<double>(fv.size(0));
    iy = fv.size(0);
    for (ju = 0; ju < iy; ju++) {
      fv[ju].re = nt_im * fv[ju].re;
      fv[ju].im = nt_im * fv[ju].im;
    }
  }
  iy = wwc.size(0);
  if ((nfft <= wwc.size(0)) && (wwc.size(0) > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (k = nfft; k <= iy; k++) {
    twid_im = wwc[k - 1].re;
    re_tmp = fv[k - 1].im;
    nt_im = wwc[k - 1].im;
    twid_re = fv[k - 1].re;
    ju = k - nfft;
    y[ju].re = twid_im * twid_re + nt_im * re_tmp;
    y[ju].im = twid_im * re_tmp - nt_im * twid_re;
  }
}

//
// Arguments    : const ::coder::array<creal_T, 1U> &x
//                int unsigned_nRows
//                const ::coder::array<double, 2U> &costab
//                const ::coder::array<double, 2U> &sintab
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig_impl(
    const ::coder::array<creal_T, 1U> &x, int unsigned_nRows,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab, ::coder::array<creal_T, 1U> &y)
{
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_re;
  int i;
  int iDelta2;
  int iheight;
  int iy;
  int ju;
  int k;
  int nRowsD2;
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y[iy].re = 0.0;
      y[iy].im = 0.0;
    }
  }
  iDelta2 = x.size(0);
  if (iDelta2 > unsigned_nRows) {
    iDelta2 = unsigned_nRows;
  }
  iheight = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  if (iDelta2 - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= iDelta2 - 2; i++) {
    boolean_T tst;
    y[iy] = x[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  y[iy] = x[iDelta2 - 1];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re_tmp = y[i + 1].re;
      temp_im = y[i + 1].im;
      temp_re = y[i].re;
      twid_re = y[i].im;
      y[i + 1].re = temp_re - temp_re_tmp;
      y[i + 1].im = twid_re - temp_im;
      y[i].re = temp_re + temp_re_tmp;
      y[i].im = twid_re + temp_im;
    }
  }
  iy = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    int b_temp_re_tmp;
    for (i = 0; i < iheight; i += iDelta2) {
      b_temp_re_tmp = i + iy;
      temp_re = y[b_temp_re_tmp].re;
      temp_im = y[b_temp_re_tmp].im;
      y[b_temp_re_tmp].re = y[i].re - temp_re;
      y[b_temp_re_tmp].im = y[i].im - temp_im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }
    ju = 1;
    for (int j{k}; j < nRowsD2; j += k) {
      double twid_im;
      int ihi;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = ju;
      ihi = ju + iheight;
      while (i < ihi) {
        b_temp_re_tmp = i + iy;
        temp_re_tmp = y[b_temp_re_tmp].im;
        temp_im = y[b_temp_re_tmp].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y[b_temp_re_tmp].re = y[i].re - temp_re;
        y[b_temp_re_tmp].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += iDelta2;
      }
      ju++;
    }
    k /= 2;
    iy = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iy;
  }
}

} // namespace fft
} // namespace internal
} // namespace coder

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
