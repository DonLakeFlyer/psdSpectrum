//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_data.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "psdSpectrum_data.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
FILE *eml_openfiles[20];

omp_nest_lock_t psdSpectrum_nestLockGlobal;

rtRunTimeErrorInfo emlrtRTEI{
    37,   // lineNo
    "fft" // fName
};

rtRunTimeErrorInfo b_emlrtRTEI{
    419,              // lineNo
    "assert_pmaxsize" // fName
};

rtRunTimeErrorInfo c_emlrtRTEI{
    144,          // lineNo
    "getfilestar" // fName
};

rtRunTimeErrorInfo d_emlrtRTEI{
    292,                    // lineNo
    "cast_and_validate_fid" // fName
};

rtRunTimeErrorInfo e_emlrtRTEI{
    288,                    // lineNo
    "cast_and_validate_fid" // fName
};

rtEqualityCheckInfo
    emlrtECI{
        -1,                 // nDims
        85,                 // lineNo
        9,                  // colNo
        "computeDFTviaFFT", // fName
        "C:\\Program "
        "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m" // pName
    };

rtRunTimeErrorInfo f_emlrtRTEI{
    53,      // lineNo
    "bsxfun" // fName
};

rtDoubleCheckInfo
    b_emlrtDCI{
        81,                 // lineNo
        1,                  // colNo
        "computeDFTviaFFT", // fName
        "C:\\Program "
        "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
        1 // checkKind
    };

rtRunTimeErrorInfo g_emlrtRTEI{
    14,                   // lineNo
    "validatenonnegative" // fName
};

rtRunTimeErrorInfo h_emlrtRTEI{
    14,              // lineNo
    "validatenonnan" // fName
};

rtRunTimeErrorInfo i_emlrtRTEI{
    14,              // lineNo
    "validatefinite" // fName
};

rtRunTimeErrorInfo j_emlrtRTEI{
    14,                // lineNo
    "validatepositive" // fName
};

const char cv[128]{
    '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '	',  '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

const char cv1[10]{'r', 'e', 'a', 's', 's', 'i', 'g', 'n', 'e', 'd'};

const char cv2[15]{'c', 'o', 'n', 'f', 'i', 'd', 'e', 'n',
                   'c', 'e', 'l', 'e', 'v', 'e', 'l'};

boolean_T isInitialized_psdSpectrum{false};

//
// File trailer for psdSpectrum_data.cpp
//
// [EOF]
//
