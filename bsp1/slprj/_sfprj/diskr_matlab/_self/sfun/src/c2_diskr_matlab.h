#ifndef __c2_diskr_matlab_h__
#define __c2_diskr_matlab_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c2_ResolvedFunctionInfo;

typedef struct {
  real_T c2_X_data[1801];
  real_T c2_a[3];
  real_T c2_b[3];
  real_T c2_steps;
  SimStruct *S;
  int32_T c2_X_sizes[2];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_X_not_empty;
  boolean_T c2_doneDoubleBufferReInit;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_diskr_matlab;
  ChartInfoStruct chartInfo;
} SFc2_diskr_matlabInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_diskr_matlab_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_diskr_matlab_get_check_sum(mxArray *plhs[]);
extern void c2_diskr_matlab_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
