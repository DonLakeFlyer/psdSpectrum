//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_terminate.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 13:38:12
//

// Include Files
#include "psdSpectrum_terminate.h"
#include "psdSpectrum_data.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void psdSpectrum_terminate()
{
  omp_destroy_nest_lock(&psdSpectrum_nestLockGlobal);
  isInitialized_psdSpectrum = false;
}

//
// File trailer for psdSpectrum_terminate.cpp
//
// [EOF]
//
