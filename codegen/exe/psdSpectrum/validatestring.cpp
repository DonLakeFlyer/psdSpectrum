//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: validatestring.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "validatestring.h"
#include "psdSpectrum_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const char str_data[]
//                const int str_size[2]
//                char match_data[]
//                int match_size[2]
//                int *nmatched
// Return Type  : void
//
namespace coder {
void get_match(const char str_data[], const int str_size[2], char match_data[],
               int match_size[2], int *nmatched)
{
  static const char b_cv[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  static const char b_cv2[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  static const char b_vstr[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  static const char c_vstr[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const char cv3[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const char vstr[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  static const char b_cv1[7]{'m', 'i', 'n', 'h', 'o', 'l', 'd'};
  static const char cv4[7]{'m', 'a', 'x', 'h', 'o', 'l', 'd'};
  static const char d_vstr[7]{'m', 'i', 'n', 'h', 'o', 'l', 'd'};
  static const char e_vstr[7]{'m', 'a', 'x', 'h', 'o', 'l', 'd'};
  int exitg1;
  int kstr;
  int lenstr;
  int minnanb;
  boolean_T b_bool;
  boolean_T b_guard1{false};
  boolean_T guard1{false};
  boolean_T guard2{false};
  boolean_T guard3{false};
  boolean_T guard4{false};
  boolean_T guard5{false};
  boolean_T matched;
  match_size[0] = 1;
  match_size[1] = 4;
  match_data[0] = ' ';
  match_data[1] = ' ';
  match_data[2] = ' ';
  match_data[3] = ' ';
  lenstr = str_size[1];
  *nmatched = 0;
  matched = false;
  b_bool = false;
  minnanb = str_size[1];
  guard1 = false;
  if (lenstr <= minnanb) {
    if (minnanb < lenstr) {
      minnanb = 7;
    } else {
      minnanb = lenstr;
    }
    guard1 = true;
  } else if (str_size[1] == 8) {
    minnanb = 8;
    guard1 = true;
  }
  if (guard1) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr <= minnanb - 1) {
        if (cv[static_cast<int>(str_data[kstr])] !=
            cv[static_cast<int>(b_cv[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  b_guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  if (b_bool) {
    if (str_size[1] == 8) {
      *nmatched = 1;
      match_size[0] = 1;
      match_size[1] = 8;
      for (minnanb = 0; minnanb < 8; minnanb++) {
        match_data[minnanb] = vstr[minnanb];
      }
    } else {
      match_size[0] = 1;
      match_size[1] = 8;
      for (minnanb = 0; minnanb < 8; minnanb++) {
        match_data[minnanb] = vstr[minnanb];
      }
      matched = true;
      *nmatched = 1;
      guard5 = true;
    }
  } else {
    guard5 = true;
  }
  if (guard5) {
    b_bool = false;
    minnanb = str_size[1];
    guard1 = false;
    if (lenstr <= minnanb) {
      if (minnanb < lenstr) {
        minnanb = 7;
      } else {
        minnanb = lenstr;
      }
      guard1 = true;
    } else if (str_size[1] == 8) {
      minnanb = 8;
      guard1 = true;
    }
    if (guard1) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr <= minnanb - 1) {
          if (cv[static_cast<int>(str_data[kstr])] !=
              cv[static_cast<int>(b_cv2[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      if (str_size[1] == 8) {
        *nmatched = 1;
        match_size[0] = 1;
        match_size[1] = 8;
        for (minnanb = 0; minnanb < 8; minnanb++) {
          match_data[minnanb] = b_vstr[minnanb];
        }
      } else {
        if (!matched) {
          match_size[0] = 1;
          match_size[1] = 8;
          for (minnanb = 0; minnanb < 8; minnanb++) {
            match_data[minnanb] = b_vstr[minnanb];
          }
        }
        matched = true;
        (*nmatched)++;
        guard4 = true;
      }
    } else {
      guard4 = true;
    }
  }
  if (guard4) {
    b_bool = false;
    minnanb = str_size[1];
    guard1 = false;
    if (lenstr <= minnanb) {
      if (minnanb < lenstr) {
        minnanb = 7;
      } else {
        minnanb = lenstr;
      }
      guard1 = true;
    } else if (str_size[1] == 8) {
      minnanb = 8;
      guard1 = true;
    }
    if (guard1) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr <= minnanb - 1) {
          if (cv[static_cast<int>(str_data[kstr])] !=
              cv[static_cast<int>(cv3[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      if (str_size[1] == 8) {
        *nmatched = 1;
        match_size[0] = 1;
        match_size[1] = 8;
        for (minnanb = 0; minnanb < 8; minnanb++) {
          match_data[minnanb] = c_vstr[minnanb];
        }
      } else {
        if (!matched) {
          match_size[0] = 1;
          match_size[1] = 8;
          for (minnanb = 0; minnanb < 8; minnanb++) {
            match_data[minnanb] = c_vstr[minnanb];
          }
        }
        matched = true;
        (*nmatched)++;
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }
  if (guard3) {
    int b_minnanb;
    b_bool = false;
    minnanb = str_size[1];
    if (lenstr <= minnanb) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (minnanb < lenstr) {
          b_minnanb = 7;
        } else {
          b_minnanb = lenstr;
        }
        if (kstr <= b_minnanb - 1) {
          if (cv[static_cast<int>(str_data[kstr])] !=
              cv[static_cast<int>(cv1[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      if (!matched) {
        match_size[0] = 1;
        match_size[1] = 10;
        for (minnanb = 0; minnanb < 10; minnanb++) {
          match_data[minnanb] = cv1[minnanb];
        }
      }
      matched = true;
      (*nmatched)++;
    }
    b_bool = false;
    minnanb = str_size[1];
    if (lenstr <= minnanb) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (minnanb < lenstr) {
          b_minnanb = 7;
        } else {
          b_minnanb = lenstr;
        }
        if (kstr <= b_minnanb - 1) {
          if (cv[static_cast<int>(str_data[kstr])] !=
              cv[static_cast<int>(cv2[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      if (!matched) {
        match_size[0] = 1;
        match_size[1] = 15;
        for (minnanb = 0; minnanb < 15; minnanb++) {
          match_data[minnanb] = cv2[minnanb];
        }
      }
      (*nmatched)++;
    }
    if (str_size[1] <= 7) {
      b_bool = false;
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 7) {
          if (cv[static_cast<int>(str_data[kstr])] !=
              cv[static_cast<int>(cv4[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (b_bool) {
        *nmatched = 1;
        match_size[0] = 1;
        match_size[1] = 7;
        for (minnanb = 0; minnanb < 7; minnanb++) {
          match_data[minnanb] = e_vstr[minnanb];
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
  }
  if (guard2) {
    if (str_size[1] <= 7) {
      b_bool = false;
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 7) {
          if (cv[static_cast<int>(str_data[kstr])] !=
              cv[static_cast<int>(b_cv1[kstr])]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (b_bool) {
        *nmatched = 1;
        match_size[0] = 1;
        match_size[1] = 7;
        for (minnanb = 0; minnanb < 7; minnanb++) {
          match_data[minnanb] = d_vstr[minnanb];
        }
      } else {
        b_guard1 = true;
      }
    } else {
      b_guard1 = true;
    }
  }
  if (b_guard1 && (*nmatched == 0)) {
    match_size[0] = 1;
    match_size[1] = 4;
    match_data[0] = ' ';
    match_data[1] = ' ';
    match_data[2] = ' ';
    match_data[3] = ' ';
  }
}

} // namespace coder

//
// File trailer for validatestring.cpp
//
// [EOF]
//
