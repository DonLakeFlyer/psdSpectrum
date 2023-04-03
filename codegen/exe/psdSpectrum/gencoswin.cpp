//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: gencoswin.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "gencoswin.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double m
//                double n
//                ::coder::array<double, 1U> &w
// Return Type  : void
//
namespace coder {
void calc_window(double m, double n, ::coder::array<double, 1U> &w)
{
  array<double, 2U> y;
  int nx;
  if (std::isnan(m - 1.0)) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else if (m - 1.0 < 0.0) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, static_cast<int>(m - 1.0) + 1);
    nx = static_cast<int>(m - 1.0);
    for (int k{0}; k <= nx; k++) {
      y[k] = k;
    }
  }
  w.set_size(y.size(1));
  nx = y.size(1);
  for (int k{0}; k < nx; k++) {
    w[k] = 6.2831853071795862 * (y[k] / (n - 1.0));
  }
  nx = w.size(0);
  if (w.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nx; k++) {
    w[k] = std::cos(w[k]);
  }
  nx = w.size(0);
  for (int k{0}; k < nx; k++) {
    w[k] = 0.54 - 0.46 * w[k];
  }
}

} // namespace coder

//
// File trailer for gencoswin.cpp
//
// [EOF]
//
