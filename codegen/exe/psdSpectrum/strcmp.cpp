//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: strcmp.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "strcmp.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const char a_data[]
//                const int a_size[2]
//                const cell_28 b
//                boolean_T b_bool[3]
// Return Type  : void
//
namespace coder {
namespace internal {
void b_strcmp(const char a_data[], const int a_size[2], const cell_28 b,
              boolean_T b_bool[3])
{
  b_bool[0] = false;
  b_bool[1] = false;
  b_bool[2] = false;
  if (a_size[1] == 8) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (cv[static_cast<int>(a_data[kstr])] !=
            cv[static_cast<int>(b.f3[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[2] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : const char a_data[]
//                const int a_size[2]
//                boolean_T b_bool[19]
// Return Type  : void
//
void c_strcmp(const char a_data[], const int a_size[2], boolean_T b_bool[19])
{
  static const char b_cv1[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  static const char cv3[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  static const char cv9[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const char cv14[7]{'m', 'a', 'x', 'h', 'o', 'l', 'd'};
  static const char cv15[7]{'m', 'i', 'n', 'h', 'o', 'l', 'd'};
  static const char b_cv2[5]{'w', 'h', 'o', 'l', 'e'};
  static const char cv10[5]{'p', 'o', 'w', 'e', 'r'};
  static const char cv4[5]{'a', 'd', 'a', 'p', 't'};
  static const char cv5[5]{'u', 'n', 'i', 't', 'y'};
  static const char cv6[5]{'e', 'i', 'g', 'e', 'n'};
  static const char b_cv[4]{'h', 'a', 'l', 'f'};
  static const char cv13[4]{'m', 'e', 'a', 'n'};
  static const char cv16[4]{'m', 'i', 'm', 'o'};
  static const char cv7[4]{'c', 'o', 'r', 'r'};
  static const char cv11[3]{'p', 's', 'd'};
  static const char cv12[2]{'m', 's'};
  static const char cv8[2]{'e', 'v'};
  int exitg1;
  int kstr;
  b_bool[0] = false;
  if (a_size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a_data[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[0] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[1] = false;
  if (a_size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (a_data[kstr] != b_cv1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[1] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[2] = false;
  if (a_size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a_data[kstr] != b_cv2[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[2] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[3] = false;
  if (a_size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (a_data[kstr] != cv3[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[3] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[4] = false;
  if (a_size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a_data[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[4] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[5] = false;
  if (a_size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a_data[kstr] != cv5[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[5] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[6] = false;
  if (a_size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a_data[kstr] != cv6[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[6] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[7] = false;
  if (a_size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a_data[kstr] != cv7[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[7] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[8] = false;
  if (a_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a_data[kstr] != cv8[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[8] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[9] = false;
  if (a_size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (a_data[kstr] != cv9[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[9] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[10] = false;
  if (a_size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a_data[kstr] != cv10[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[10] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[11] = false;
  if (a_size[1] == 3) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (a_data[kstr] != cv11[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[11] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[12] = false;
  if (a_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a_data[kstr] != cv12[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[12] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[13] = false;
  if (a_size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (a_data[kstr] != cv1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[13] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[14] = false;
  if (a_size[1] == 15) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (a_data[kstr] != cv2[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[14] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[15] = false;
  if (a_size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a_data[kstr] != cv13[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[15] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[16] = false;
  if (a_size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (a_data[kstr] != cv14[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[16] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[17] = false;
  if (a_size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (a_data[kstr] != cv15[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[17] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_bool[18] = false;
  if (a_size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a_data[kstr] != cv16[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool[18] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for strcmp.cpp
//
// [EOF]
//
