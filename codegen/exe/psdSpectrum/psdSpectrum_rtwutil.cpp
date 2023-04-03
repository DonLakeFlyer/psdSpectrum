//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_rtwutil.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "psdSpectrum_rtwutil.h"
#include "psdSpectrum_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream
      << "The dimension to operate along was selected automatically, is "
         "variable-length, and has length 1 at run time. This is not support"
         "ed. Manually select the dimension to operate along by supplying the "
         "DIM argument.";
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
void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Maximum variable size allowed by the program is exceeded.";
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
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void d_rtErrorWithMessageID(const char *r, const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be nonnegative.";
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
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    rtDivisionByZeroErrorN();
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void e_rtErrorWithMessageID(const char *r, const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be non-NaN.";
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
// Arguments    : const int aDim1
//                const int aDim2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                 const rtEqualityCheckInfo *aInfo)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((((outStream << "Size mismatch error on dimension ") << aInfo->nDims)
      << ": expected ")
     << aDim1)
    << " or a singleton, but actual size is ")
   << aDim2)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
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
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void f_rtErrorWithMessageID(const char *r, const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be finite.";
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
void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Invalid file identifier. Use fopen to generate a valid file "
               "identifier.";
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
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void g_rtErrorWithMessageID(const char *r, const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be positive.";
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
void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Invalid file identifier.  Use fopen to generate a valid file "
               "identifier.";
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
void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Non-singleton dimensions of the two input arrays must match "
               "each other.";
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
void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Argument must be integer-valued.";
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
// Arguments    : void
// Return Type  : void
//
void rtDivisionByZeroErrorN()
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Division by zero detected.\nEarly termination due to division "
               "by zero.";
  outStream << "\n";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : int aIndexValue
//                int aLoBound
//                int aHiBound
//                const rtBoundsCheckInfo *aInfo
// Return Type  : void
//
void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                          const rtBoundsCheckInfo *aInfo)
{
  std::string b_errMsg;
  std::string errMsg;
  std::stringstream b_outStream;
  std::stringstream outStream;
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }
  if (rtIsNullOrEmptyString(aInfo->aName)) {
    ((((((b_outStream << "Index exceeds array dimensions. Index value ")
         << aIndexValue)
        << " exceeds valid range [")
       << aLoBound)
      << "-")
     << aHiBound)
        << "].";
    b_outStream << "\n";
    ((((b_outStream << "Error in ") << aInfo->fName) << " (line ")
     << aInfo->lineNo)
        << ")";
    if (omp_in_parallel()) {
      b_errMsg = b_outStream.str();
      std::fprintf(stderr, "%s", b_errMsg.c_str());
      std::abort();
    } else {
      throw std::runtime_error(b_outStream.str());
    }
  } else {
    ((((((((outStream << "Index exceeds array dimensions. Index value ")
           << aIndexValue)
          << " exceeds valid range [")
         << aLoBound)
        << "-")
       << aHiBound)
      << "] for array \'")
     << aInfo->aName)
        << "\'.";
    outStream << "\n";
    ((((outStream << "Error in ") << aInfo->fName) << " (line ")
     << aInfo->lineNo)
        << ")";
    if (omp_in_parallel()) {
      errMsg = outStream.str();
      std::fprintf(stderr, "%s", errMsg.c_str());
      std::abort();
    } else {
      throw std::runtime_error(outStream.str());
    }
  }
}

//
// Arguments    : const int aNDims
//                const int *aDims
// Return Type  : std::string
//
std::string rtGenSizeString(const int aNDims, const int *aDims)
{
  std::stringstream outStream;
  for (int i{0}; i < aNDims; i++) {
    outStream << "[";
    outStream << aDims[i];
    outStream << "]";
  }
  return outStream.str();
}

//
// Arguments    : const double aInteger
//                const rtDoubleCheckInfo *aInfo
// Return Type  : void
//
void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected a value representable in the C type \'int\'. Found ")
   << aInteger)
      << " instead.";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const char *aString
// Return Type  : boolean_T
//
boolean_T rtIsNullOrEmptyString(const char *aString)
{
  return (aString == nullptr) || (*aString == '\x00');
}

//
// Arguments    : const double aPositive
//                const rtDoubleCheckInfo *aInfo
// Return Type  : void
//
void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo *aInfo)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Value ") << aPositive)
      << " is not greater than or equal to zero.\nExiting to prevent memory "
         "corruption.";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const int aDim1
//                const int aDim2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
void rtSizeEq1DError(const int aDim1, const int aDim2,
                     const rtEqualityCheckInfo *aInfo)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((outStream << "Sizes mismatch: ") << aDim1) << " ~= ") << aDim2) << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const int *aDims1
//                const int aNDims1
//                const int *aDims2
//                const int aNDims2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                          const int *aDims2, const int aNDims2,
                          const rtEqualityCheckInfo *aInfo)
{
  std::string errMsg;
  std::stringstream outStream;
  int i;
  int j;
  i = 0;
  j = 0;
  while ((i < aNDims1) && (j < aNDims2)) {
    while ((i < aNDims1) && (aDims1[i] == 1)) {
      i++;
    }
    while ((j < aNDims2) && (aDims2[j] == 1)) {
      j++;
    }
    if (((i < aNDims1) || (j < aNDims2)) &&
        ((i == aNDims1) || ((j == aNDims2) || ((aDims1[i] != -1) &&
                                               ((aDims2[j] != -1) &&
                                                (aDims1[i] != aDims2[j])))))) {
      std::string dims1Str;
      std::string dims2Str;
      dims1Str = rtGenSizeString(aNDims1, aDims1);
      dims2Str = rtGenSizeString(aNDims1, aDims2);
      ((((outStream << "Subscripted assignment dimension mismatch: ")
         << dims1Str)
        << " ~= ")
       << dims2Str)
          << ".";
      outStream << "\n";
      ((((outStream << "Error in ") << aInfo->fName) << " (line ")
       << aInfo->lineNo)
          << ")";
      if (omp_in_parallel()) {
        errMsg = outStream.str();
        std::fprintf(stderr, "%s", errMsg.c_str());
        std::abort();
      } else {
        throw std::runtime_error(outStream.str());
      }
    }
    i++;
    j++;
  }
}

//
// File trailer for psdSpectrum_rtwutil.cpp
//
// [EOF]
//
