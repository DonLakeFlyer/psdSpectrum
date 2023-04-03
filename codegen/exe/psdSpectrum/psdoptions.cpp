//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdoptions.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "psdoptions.h"
#include "ifWhileCond.h"
#include "ismember.h"
#include "psdSpectrum_data.h"
#include "psdSpectrum_internal_types.h"
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "validatestring.h"
#include "omp.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Type Definitions
struct emxArray_char_T_1x15 {
  char data[15];
  int size[2];
};

struct cell_wrap_34 {
  emxArray_char_T_1x15 f1;
};

// Function Declarations
static void b_rtErrorWithMessageID(const char *r, const char *r1,
                                   const std::string r2, const char *aFcnName,
                                   int aLineNum);

namespace coder {
static void checkUniqueOpts(const double arg_data[], const int arg_size[2],
                            boolean_T *err, double visitedOpts[16],
                            double *b_index);

}
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const char *r, const char *r1,
                                 const std::string r2, const char *aFcnName,
                                 int aLineNum);

static void rtErrorWithMessageID(const std::string r, const std::string r1,
                                 const char *aFcnName, int aLineNum);

static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void t_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *r
//                const char *r1
//                const std::string r2
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *r, const char *r1,
                                   const std::string r2, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((((outStream << "Expected ") << r) << " to match one of these strings: ")
     << r1)
    << ". The input")
   << r2)
      << " matched more than one valid string.";
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
// Arguments    : const double arg_data[]
//                const int arg_size[2]
//                boolean_T *err
//                double visitedOpts[16]
//                double *b_index
// Return Type  : void
//
namespace coder {
static void checkUniqueOpts(const double arg_data[], const int arg_size[2],
                            boolean_T *err, double visitedOpts[16],
                            double *b_index)
{
  static rtEqualityCheckInfo b_emlrtECI{
      -1,                // nDims
      420,               // lineNo
      9,                 // colNo
      "checkUniqueOpts", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\psdoptions.m" // pName
  };
  int x_size[2];
  int k;
  boolean_T exitg1;
  boolean_T x_data;
  boolean_T y;
  *b_index = 1.0;
  std::memset(&visitedOpts[0], 0, 16U * sizeof(double));
  isMember(arg_size, (boolean_T *)&x_data, x_size);
  y = (x_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        k = 1;
      }
    }
  }
  if (y) {
    *err = true;
  } else {
    boolean_T guard1{false};
    boolean_T guard2{false};
    x_size[1] = arg_size[1];
    k = arg_size[1];
    for (int i{0}; i < k; i++) {
      x_data = (arg_data[0] == 1.0);
    }
    y = (arg_size[1] != 0);
    if (y) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size[1] - 1)) {
        if (!x_data) {
          y = false;
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
    guard1 = false;
    guard2 = false;
    if (y) {
      guard2 = true;
    } else {
      int loop_ub_tmp;
      loop_ub_tmp = arg_size[1] - 1;
      for (int i{0}; i <= loop_ub_tmp; i++) {
        x_data = (x_data || (arg_data[0] == 2.0));
      }
      y = (arg_size[1] != 0);
      if (y) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= x_size[1] - 1)) {
          if (!x_data) {
            y = false;
            exitg1 = true;
          } else {
            k = 1;
          }
        }
      }
      if (y) {
        guard2 = true;
      } else {
        x_size[1] = arg_size[1];
        k = arg_size[1];
        for (int i{0}; i < k; i++) {
          x_data = (arg_data[0] == 3.0);
        }
        y = (arg_size[1] != 0);
        if (y) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= x_size[1] - 1)) {
            if (!x_data) {
              y = false;
              exitg1 = true;
            } else {
              k = 1;
            }
          }
        }
        if (y) {
          guard2 = true;
        } else {
          x_size[1] = arg_size[1];
          k = arg_size[1];
          for (int i{0}; i < k; i++) {
            x_data = (arg_data[0] == 4.0);
          }
          y = (arg_size[1] != 0);
          if (y) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= x_size[1] - 1)) {
              if (!x_data) {
                y = false;
                exitg1 = true;
              } else {
                k = 1;
              }
            }
          }
          if (y) {
            guard2 = true;
          } else {
            x_size[1] = arg_size[1];
            k = arg_size[1];
            for (int i{0}; i < k; i++) {
              x_data = (arg_data[0] == 5.0);
            }
            y = (arg_size[1] != 0);
            if (y) {
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k <= x_size[1] - 1)) {
                if (!x_data) {
                  y = false;
                  exitg1 = true;
                } else {
                  k = 1;
                }
              }
            }
            if (y) {
              guard1 = true;
            } else {
              for (int i{0}; i <= loop_ub_tmp; i++) {
                x_data = (x_data || (arg_data[0] == 6.0));
              }
              y = (arg_size[1] != 0);
              if (y) {
                k = 0;
                exitg1 = false;
                while ((!exitg1) && (k <= x_size[1] - 1)) {
                  if (!x_data) {
                    y = false;
                    exitg1 = true;
                  } else {
                    k = 1;
                  }
                }
              }
              if (y) {
                guard1 = true;
              } else {
                x_size[1] = arg_size[1];
                k = arg_size[1];
                for (int i{0}; i < k; i++) {
                  x_data = (arg_data[0] == 7.0);
                }
                y = (arg_size[1] != 0);
                if (y) {
                  k = 0;
                  exitg1 = false;
                  while ((!exitg1) && (k <= x_size[1] - 1)) {
                    if (!x_data) {
                      y = false;
                      exitg1 = true;
                    } else {
                      k = 1;
                    }
                  }
                }
                if (y) {
                  guard1 = true;
                } else {
                  if (arg_size[1] != 1) {
                    rtSizeEq1DError(1, 0, &b_emlrtECI);
                  }
                  visitedOpts[0] = arg_data[0];
                  *b_index = 2.0;
                }
              }
            }
          }
        }
      }
    }
    if (guard2) {
      visitedOpts[0] = 1.0;
      visitedOpts[1] = 2.0;
      visitedOpts[2] = 3.0;
      visitedOpts[3] = 4.0;
      *b_index = 4.0;
    }
    if (guard1) {
      visitedOpts[0] = 5.0;
      visitedOpts[1] = 6.0;
      visitedOpts[2] = 7.0;
      *b_index = 3.0;
    }
    *err = false;
  }
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
} // namespace coder
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "A \'onesided\' PSD cannot be computed for a complex signal.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Two or more values specified for a single parameter.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "The confidence level value is missing";
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
// Arguments    : const char *r
//                const char *r1
//                const std::string r2
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *r1,
                                 const std::string r2, const char *aFcnName,
                                 int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((((outStream << "Expected ") << r) << " to match one of these strings: ")
     << r1)
    << ". The input")
   << r2)
      << " did not match any of the valid strings.";
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
// Arguments    : const std::string r
//                const std::string r1
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const std::string r, const std::string r1,
                                 const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((outStream << "The \'") << r) << "\' and \'") << r1)
      << "\' options cannot be specified together.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Unrecognized character vector specified.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void t_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Option index out of bounds.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Ambiguous or invalid character vector option specified.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "SWITCH expression must be a scalar or a character vector.";
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
// Arguments    : char options_range[8]
//                double varargin_1
//                double varargin_2
//                const char varargin_3[8]
//                double *options1_nfft
//                double *options1_Fs
//                boolean_T *options1_maxhold
//                boolean_T *options1_minhold
//                boolean_T *options1_centerdc
//                char options1_range[8]
// Return Type  : void
//
namespace coder {
void psdoptions(char options_range[8], double varargin_1, double varargin_2,
                const char varargin_3[8], double *options1_nfft,
                double *options1_Fs, boolean_T *options1_maxhold,
                boolean_T *options1_minhold, boolean_T *options1_centerdc,
                char options1_range[8])
{
  static rtRunTimeErrorInfo k_emlrtRTEI{
      131,                 // lineNo
      "fullValidatestring" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      366,                // lineNo
      "ConstructErrorObj" // fName
  };
  static rtRunTimeErrorInfo m_emlrtRTEI{
      87,                       // lineNo
      "check_switch_expression" // fName
  };
  static rtRunTimeErrorInfo n_emlrtRTEI{
      139,                 // lineNo
      "fullValidatestring" // fName
  };
  static const char b[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  static const char b_cv1[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  static const char b_cv2[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  static const char strOpts_f10[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const signed char varargin_6[8]{11, 12, 13, 14, 16, 17, 18, 19};
  static const char b_cv[5]{'w', 'h', 'o', 'l', 'e'};
  static const char strOpts_f5[5]{'a', 'd', 'a', 'p', 't'};
  static const char strOpts_f6[5]{'u', 'n', 'i', 't', 'y'};
  static const char strOpts_f7[5]{'e', 'i', 'g', 'e', 'n'};
  static const char b_b[3]{'o', 'n', 'e'};
  static const char c_b[3]{'t', 'w', 'o'};
  cell_28 inputArgs;
  cell_wrap_34 exclusiveOpts[14];
  cell_wrap_34 rv[14];
  cell_wrap_34 r;
  cell_wrap_34 r1;
  cell_wrap_34 r10;
  cell_wrap_34 r11;
  cell_wrap_34 r12;
  cell_wrap_34 r13;
  cell_wrap_34 r2;
  cell_wrap_34 r3;
  cell_wrap_34 r4;
  cell_wrap_34 r5;
  cell_wrap_34 r6;
  cell_wrap_34 r7;
  cell_wrap_34 r8;
  cell_wrap_34 r9;
  double b_index;
  int arg2_size[2];
  int arg_size[2];
  int b_i_size[2];
  int i_size[2];
  int ret;
  char arg_data[15];
  char partial_match_data[15];
  char tmp_data[13];
  char arg2_data[8];
  char c;
  boolean_T b_guard1{false};
  boolean_T guard1{false};
  boolean_T i_data;
  boolean_T options_centerdc;
  inputArgs.f1 = varargin_1;
  inputArgs.f2 = varargin_2;
  options_centerdc = false;
  r.f1.size[0] = 1;
  r.f1.size[1] = 4;
  r.f1.data[0] = 'h';
  r.f1.data[1] = 'a';
  r.f1.data[2] = 'l';
  r.f1.data[3] = 'f';
  r1.f1.size[0] = 1;
  r1.f1.size[1] = 8;
  for (ret = 0; ret < 8; ret++) {
    inputArgs.f3[ret] = varargin_3[ret];
    r1.f1.data[ret] = b[ret];
  }
  r2.f1.size[0] = 1;
  r2.f1.size[1] = 5;
  r3.f1.size[0] = 1;
  r3.f1.size[1] = 5;
  r4.f1.size[0] = 1;
  r4.f1.size[1] = 5;
  for (ret = 0; ret < 5; ret++) {
    c = strOpts_f5[ret];
    r2.f1.data[ret] = c;
    r3.f1.data[ret] = c;
    r4.f1.data[ret] = strOpts_f6[ret];
  }
  r5.f1.size[0] = 1;
  r5.f1.size[1] = 4;
  r5.f1.data[0] = 'h';
  r5.f1.data[1] = 'a';
  r5.f1.data[2] = 'l';
  r5.f1.data[3] = 'f';
  r6.f1.size[0] = 1;
  r6.f1.size[1] = 8;
  for (ret = 0; ret < 8; ret++) {
    r6.f1.data[ret] = b[ret];
  }
  r7.f1.size[0] = 1;
  r7.f1.size[1] = 5;
  for (ret = 0; ret < 5; ret++) {
    r7.f1.data[ret] = b_cv[ret];
  }
  r8.f1.size[0] = 1;
  r8.f1.size[1] = 8;
  for (ret = 0; ret < 8; ret++) {
    r8.f1.data[ret] = b_cv1[ret];
  }
  r9.f1.size[0] = 1;
  r9.f1.size[1] = 5;
  r10.f1.size[0] = 1;
  r10.f1.size[1] = 5;
  r11.f1.size[0] = 1;
  r11.f1.size[1] = 5;
  for (ret = 0; ret < 5; ret++) {
    r9.f1.data[ret] = strOpts_f6[ret];
    c = strOpts_f7[ret];
    r10.f1.data[ret] = c;
    r11.f1.data[ret] = c;
  }
  r12.f1.size[0] = 1;
  r12.f1.size[1] = 8;
  r13.f1.size[0] = 1;
  r13.f1.size[1] = 8;
  for (ret = 0; ret < 8; ret++) {
    c = strOpts_f10[ret];
    r12.f1.data[ret] = c;
    r13.f1.data[ret] = c;
  }
  rv[0] = r;
  rv[1] = r1;
  rv[2] = r2;
  rv[3] = r3;
  rv[4] = r4;
  rv[5] = r5;
  rv[6] = r6;
  rv[7] = r7;
  rv[8] = r8;
  rv[9] = r9;
  rv[10] = r10;
  rv[11] = r11;
  rv[12] = r12;
  rv[13] = r13;
  std::copy(&rv[0], &rv[14], &exclusiveOpts[0]);
  ret = 0;
  guard1 = false;
  int exitg1;
  do {
    exitg1 = 0;
    if (ret < 7) {
      int k;
      boolean_T bv[3];
      boolean_T x_data[3];
      boolean_T exitg2;
      internal::b_strcmp(exclusiveOpts[ret].f1.data, exclusiveOpts[ret].f1.size,
                         inputArgs, bv);
      x_data[0] = bv[0];
      x_data[1] = bv[1];
      x_data[2] = bv[2];
      i_data = false;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k <= 2)) {
        if (x_data[k]) {
          i_data = true;
          exitg2 = true;
        } else {
          k++;
        }
      }
      if (i_data) {
        internal::b_strcmp(exclusiveOpts[ret + 7].f1.data,
                           exclusiveOpts[ret + 7].f1.size, inputArgs, bv);
        x_data[0] = bv[0];
        x_data[1] = bv[1];
        x_data[2] = bv[2];
        i_data = false;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= 2)) {
          if (x_data[k]) {
            i_data = true;
            exitg2 = true;
          } else {
            k++;
          }
        }
        if (i_data) {
          rtErrorWithMessageID(std::string(&exclusiveOpts[ret].f1.data[0],
                                           exclusiveOpts[ret].f1.size[1]),
                               std::string(&exclusiveOpts[ret + 7].f1.data[0],
                                           exclusiveOpts[ret + 7].f1.size[1]),
                               l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }
      if (b_guard1) {
        ret++;
        guard1 = false;
      }
    } else {
      double c_i_data[19];
      int partial_match_size[2];
      int k;
      signed char b_i_data[19];
      char b_y1[8];
      boolean_T x[19];
      boolean_T exitg2;
      boolean_T guard2{false};
      if (varargin_2 <= 0.0) {
        g_rtErrorWithMessageID("fs", j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      }
      for (k = 0; k < 8; k++) {
        b_y1[k] = cv[static_cast<int>(varargin_3[k])];
      }
      ret = memcmp(&b_y1[0], &b_b[0], 3);
      guard2 = false;
      if (ret != 0) {
        ret = memcmp(&b_y1[0], &c_b[0], 3);
        if (ret != 0) {
          arg2_size[0] = 1;
          arg2_size[1] = 8;
          for (ret = 0; ret < 8; ret++) {
            arg2_data[ret] = b_y1[ret];
          }
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
      if (guard2) {
        if ((b_y1[3] == ' ') || (b_y1[3] == '-')) {
          arg2_size[0] = 1;
          arg2_size[1] = 7;
          arg2_data[0] = b_y1[0];
          arg2_data[1] = b_y1[1];
          arg2_data[2] = b_y1[2];
          arg2_data[3] = b_y1[4];
          arg2_data[4] = b_y1[5];
          arg2_data[5] = b_y1[6];
          arg2_data[6] = b_y1[7];
        } else {
          arg2_size[0] = 1;
          arg2_size[1] = 8;
          for (ret = 0; ret < 8; ret++) {
            arg2_data[ret] = b_y1[ret];
          }
        }
      }
      get_match(arg2_data, arg2_size, partial_match_data, partial_match_size,
                &ret);
      if (ret == 0) {
        tmp_data[0] = ',';
        tmp_data[1] = ' ';
        tmp_data[2] = '\'';
        ret = arg2_size[1];
        std::copy(&arg2_data[0], &arg2_data[ret], &tmp_data[3]);
        tmp_data[arg2_size[1] + 3] = '\'';
        tmp_data[arg2_size[1] + 4] = ',';
        rtErrorWithMessageID(
            "input",
            "\'half\', \'onesided\', \'whole\', \'twosided\', \'adapt\', "
            "\'unity\', \'eigen\', \'corr\', \'ev\', \'centered\', \'power\', "
            "\'psd\', \'ms\', \'reassigned\'"
            ", \'confidencelevel\', \'mean\', \'maxhold\', \'minhold\', "
            "\'mimo\'",
            std::string(&tmp_data[0], arg2_size[1] + 5), k_emlrtRTEI.fName,
            k_emlrtRTEI.lineNo);
      } else if (ret > 1) {
        tmp_data[0] = ',';
        tmp_data[1] = ' ';
        tmp_data[2] = '\'';
        ret = arg2_size[1];
        std::copy(&arg2_data[0], &arg2_data[ret], &tmp_data[3]);
        tmp_data[arg2_size[1] + 3] = '\'';
        tmp_data[arg2_size[1] + 4] = ',';
        b_rtErrorWithMessageID(
            "input",
            "\'half\', \'onesided\', \'whole\', \'twosided\', \'adapt\', "
            "\'unity\', \'eigen\', \'corr\', \'ev\', \'centered\', \'power\', "
            "\'psd\', \'ms\', \'reassigned\'"
            ", \'confidencelevel\', \'mean\', \'maxhold\', \'minhold\', "
            "\'mimo\'",
            std::string(&tmp_data[0], arg2_size[1] + 5), n_emlrtRTEI.fName,
            n_emlrtRTEI.lineNo);
      } else {
        arg_size[0] = 1;
        arg_size[1] = partial_match_size[1];
        ret = partial_match_size[1];
        if (ret - 1 >= 0) {
          std::copy(&partial_match_data[0], &partial_match_data[ret],
                    &arg_data[0]);
        }
      }
      internal::c_strcmp(arg_data, arg_size, x);
      ret = 0;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k < 19)) {
        if (x[k]) {
          ret++;
          b_i_data[ret - 1] = static_cast<signed char>(k + 1);
          if (ret >= 19) {
            exitg2 = true;
          } else {
            k++;
          }
        } else {
          k++;
        }
      }
      if (ret < 1) {
        k = 0;
      } else {
        k = ret;
      }
      i_size[0] = 1;
      i_size[1] = k;
      for (ret = 0; ret < k; ret++) {
        c_i_data[ret] = b_i_data[ret];
      }
      if (k > 1) {
        u_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
      } else {
        int exitg3;
        int exitg5;
        if (k != 1) {
          v_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
        }
        ret = 0;
        do {
          exitg5 = 0;
          if (ret < 4) {
            b_i_size[0] = 1;
            b_i_size[1] = 1;
            i_data = (ret + 1 == static_cast<int>(c_i_data[0]));
            if (internal::ifWhileCond((const boolean_T *)&i_data, b_i_size)) {
              ret = 0;
              exitg5 = 1;
            } else {
              ret++;
            }
          } else {
            ret = 0;
            exitg5 = 2;
          }
        } while (exitg5 == 0);
        if (exitg5 != 1) {
          int exitg4;
          do {
            exitg4 = 0;
            if (ret < 3) {
              b_i_size[0] = 1;
              b_i_size[1] = 1;
              i_data = (ret + 5 == static_cast<int>(c_i_data[0]));
              if (internal::ifWhileCond((const boolean_T *)&i_data, b_i_size)) {
                ret = 1;
                exitg4 = 1;
              } else {
                ret++;
              }
            } else {
              b_i_size[0] = 1;
              b_i_size[1] = 1;
              i_data = (c_i_data[0] == 8.0);
              exitg4 = 2;
            }
          } while (exitg4 == 0);
          if (exitg4 != 1) {
            if (internal::ifWhileCond((const boolean_T *)&i_data, b_i_size)) {
              ret = 2;
            } else {
              b_i_size[0] = 1;
              b_i_size[1] = 1;
              i_data = (c_i_data[0] == 9.0);
              if (internal::ifWhileCond((const boolean_T *)&i_data, b_i_size)) {
                ret = 3;
              } else {
                b_i_size[0] = 1;
                b_i_size[1] = 1;
                i_data = (c_i_data[0] == 10.0);
                if (internal::ifWhileCond((const boolean_T *)&i_data,
                                          b_i_size)) {
                  ret = 4;
                } else {
                  ret = 0;
                  do {
                    exitg3 = 0;
                    if (ret < 8) {
                      b_i_size[0] = 1;
                      b_i_size[1] = 1;
                      i_data =
                          (varargin_6[ret] == static_cast<int>(c_i_data[0]));
                      if (internal::ifWhileCond((const boolean_T *)&i_data,
                                                b_i_size)) {
                        ret = 5;
                        exitg3 = 1;
                      } else {
                        ret++;
                      }
                    } else {
                      b_i_size[0] = 1;
                      b_i_size[1] = 1;
                      i_data = (c_i_data[0] == 15.0);
                      if (internal::ifWhileCond((const boolean_T *)&i_data,
                                                b_i_size)) {
                        ret = 6;
                      } else {
                        ret = -1;
                      }
                      exitg3 = 1;
                    }
                  } while (exitg3 == 0);
                }
              }
            }
          }
        }
        switch (ret) {
        case 0: {
          double visitedOpts[16];
          checkUniqueOpts(c_i_data, i_size, &i_data, visitedOpts, &b_index);
          if (i_data) {
            q_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          } else {
            b_i_size[0] = 1;
            b_i_size[1] = 1;
            i_data = (c_i_data[0] == 1.0);
            guard2 = false;
            if (internal::ifWhileCond((const boolean_T *)&i_data, b_i_size)) {
              guard2 = true;
            } else {
              i_data = (i_data || (c_i_data[0] == 2.0));
              b_i_size[0] = 1;
              b_i_size[1] = 1;
              if (internal::ifWhileCond((const boolean_T *)&i_data, b_i_size)) {
                guard2 = true;
              } else {
                for (ret = 0; ret < 8; ret++) {
                  options_range[ret] = b_cv1[ret];
                }
              }
            }
            if (guard2) {
              for (ret = 0; ret < 8; ret++) {
                options_range[ret] = b[ret];
              }
            }
            i_data = false;
            ret = 0;
            do {
              exitg3 = 0;
              if (ret < 8) {
                if (cv[static_cast<int>(options_range[ret])] !=
                    cv[static_cast<int>(b_cv2[ret])]) {
                  exitg3 = 1;
                } else {
                  ret++;
                }
              } else {
                i_data = true;
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            if (i_data) {
              p_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
            } else {
              guard1 = true;
            }
          }
        } break;
        case 1:
          s_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          break;
        case 2:
          s_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          break;
        case 3:
          s_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          break;
        case 4: {
          double visitedOpts[16];
          checkUniqueOpts(c_i_data, i_size, &i_data, visitedOpts, &b_index);
          if (i_data) {
            q_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          } else {
            options_centerdc = true;
            guard1 = true;
          }
        } break;
        case 5:
          guard1 = true;
          break;
        case 6: {
          double visitedOpts[16];
          checkUniqueOpts(c_i_data, i_size, &i_data, visitedOpts, &b_index);
          if (i_data) {
            q_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          } else {
            r_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          }
        } break;
        default:
          t_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
          break;
        }
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (guard1) {
    *options1_nfft = varargin_1;
    *options1_Fs = varargin_2;
    *options1_maxhold = false;
    *options1_minhold = false;
    *options1_centerdc = options_centerdc;
    for (ret = 0; ret < 8; ret++) {
      options1_range[ret] = options_range[ret];
    }
  }
}

} // namespace coder

//
// File trailer for psdoptions.cpp
//
// [EOF]
//
