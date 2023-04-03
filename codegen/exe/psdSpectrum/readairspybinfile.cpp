//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readairspybinfile.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "readairspybinfile.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 2U> &in1,
                      const coder::array<double, 2U> &in2)
{
  coder::array<creal_T, 2U> b_in2;
  int i;
  int i1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  i = in2.size(1);
  if (in1.size(1) == 1) {
    i1 = i;
  } else {
    i1 = in1.size(1);
  }
  b_in2.set_size(1, i1);
  stride_0_1 = (i != 1);
  stride_1_1 = (in1.size(1) != 1);
  if (in1.size(1) == 1) {
    loop_ub = i;
  } else {
    loop_ub = in1.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    b_in2[i].re = in2[in2.size(0) * (i * stride_0_1)] + in1[i1].re;
    b_in2[i].im = in1[i1].im;
  }
  in1.set_size(1, b_in2.size(1));
  loop_ub = b_in2.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// File trailer for readairspybinfile.cpp
//
// [EOF]
//
