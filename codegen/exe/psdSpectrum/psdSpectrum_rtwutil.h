//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_rtwutil.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

#ifndef PSDSPECTRUM_RTWUTIL_H
#define PSDSPECTRUM_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>
#include <string>

// Type Declarations
struct rtBoundsCheckInfo;

struct rtEqualityCheckInfo;

struct rtDoubleCheckInfo;

// Function Declarations
extern void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void d_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern int div_s32(int numerator, int denominator);

extern void e_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo *aInfo);

extern void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void g_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtDivisionByZeroErrorN();

extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo *aInfo);

extern std::string rtGenSizeString(const int aNDims, const int *aDims);

extern void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo *aInfo);

extern boolean_T rtIsNullOrEmptyString(const char *aString);

extern void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo *aInfo);

extern void rtSizeEq1DError(const int aDim1, const int aDim2,
                            const rtEqualityCheckInfo *aInfo);

extern void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                                 const int *aDims2, const int aNDims2,
                                 const rtEqualityCheckInfo *aInfo);

#endif
//
// File trailer for psdSpectrum_rtwutil.h
//
// [EOF]
//
