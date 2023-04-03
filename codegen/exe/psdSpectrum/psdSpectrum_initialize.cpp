//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: psdSpectrum_initialize.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 03-Apr-2023 14:44:32
//

// Include Files
#include "psdSpectrum_initialize.h"
#include "fileManager.h"
#include "psdSpectrum_data.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void psdSpectrum_initialize()
{
  omp_init_nest_lock(&psdSpectrum_nestLockGlobal);
  filedata_init();
  isInitialized_psdSpectrum = true;
}

//
// File trailer for psdSpectrum_initialize.cpp
//
// [EOF]
//
