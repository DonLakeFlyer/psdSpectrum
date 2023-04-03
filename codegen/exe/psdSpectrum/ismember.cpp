//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ismember.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "ismember.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

// Function Declarations
namespace coder {
static int bsearchni();

}

// Function Definitions
//
// Arguments    : void
// Return Type  : int
//
namespace coder {
static int bsearchni()
{
  return 0;
}

//
// Arguments    : const int a_size[2]
//                boolean_T tf_data[]
//                int tf_size[2]
// Return Type  : void
//
void isMember(const int a_size[2], boolean_T tf_data[], int tf_size[2])
{
  int loop_ub;
  int n;
  tf_size[0] = 1;
  tf_size[1] = static_cast<signed char>(a_size[1]);
  loop_ub = static_cast<signed char>(a_size[1]);
  if (loop_ub - 1 >= 0) {
    tf_data[0] = false;
  }
  loop_ub = a_size[1] - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(n)

  for (int k = 0; k <= loop_ub; k++) {
    n = bsearchni();
    if (n > 0) {
      tf_data[0] = true;
    }
  }
}

} // namespace coder

//
// File trailer for ismember.cpp
//
// [EOF]
//
