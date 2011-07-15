/* Include files */

#include "blascompat32.h"
#include "diskr_matlab_sfun.h"
#include "c2_diskr_matlab.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "diskr_matlab_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_b_steps                     (1800.0)

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[11] = { "diff", "res", "b", "a",
  "steps", "nargin", "nargout", "ist", "soll", "stell", "X" };

/* Function Declarations */
static void initialize_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance);
static void initialize_params_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance);
static void enable_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance);
static void disable_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_diskr_matlab
  (SFc2_diskr_matlabInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_diskr_matlab
  (SFc2_diskr_matlabInstanceStruct *chartInstance);
static void set_sim_state_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance);
static void sf_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct *chartInstance);
static void c2_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c2_diskr_matlab
  (SFc2_diskr_matlabInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance);
static void c2_filter(SFc2_diskr_matlabInstanceStruct *chartInstance, real_T
                      c2_x_data[1801], int32_T c2_x_sizes[2], real_T c2_y_data
                      [1801], int32_T c2_y_sizes[2]);
static void c2_b_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance);
static void c2_c_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance);
static void c2_eml_prodsize_except_dim(SFc2_diskr_matlabInstanceStruct
  *chartInstance, real_T c2_x_data[1801], int32_T c2_x_sizes[2]);
static void c2_d_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance);
static real_T c2_min(SFc2_diskr_matlabInstanceStruct *chartInstance, real_T
                     c2_varargin_1, real_T c2_varargin_2);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, real_T c2_u_data
  [1801], int32_T c2_u_sizes[2]);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, real_T
  c2_u_data[1801], int32_T c2_u_sizes[2]);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[46]);
static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_diskr_matlabInstanceStruct *chartInstance,
  const mxArray *c2_stell, const char_T *c2_name);
static void c2_b_emlrt_marshallIn(SFc2_diskr_matlabInstanceStruct *chartInstance,
  const mxArray *c2_X, const char_T *c2_name, real_T c2_y_data[1801], int32_T
  c2_y_sizes[2]);
static uint8_T c2_c_emlrt_marshallIn(SFc2_diskr_matlabInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_diskr_matlab, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_diskr_matlabInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_X_not_empty = FALSE;
  chartInstance->c2_is_active_c2_diskr_matlab = 0U;
}

static void initialize_params_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance)
{
  real_T c2_dv0[3];
  int32_T c2_i0;
  real_T c2_dv1[3];
  int32_T c2_i1;
  real_T c2_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'b' in the parent workspace.\n");
  sf_mex_import("b", sf_mex_get_sfun_param(chartInstance->S, 1, 0), c2_dv0, 0, 0,
                0U, 1, 0U, 2, 1, 3);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0 = c2_i0 + 1) {
    chartInstance->c2_b[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'a' in the parent workspace.\n");
  sf_mex_import("a", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c2_dv1, 0, 0,
                0U, 1, 0U, 2, 1, 3);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    chartInstance->c2_a[c2_i1] = c2_dv1[c2_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'steps' in the parent workspace.\n");
  sf_mex_import("steps", sf_mex_get_sfun_param(chartInstance->S, 2, 0), &c2_d0,
                0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_steps = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_diskr_matlab
  (SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_diskr_matlab
  (SFc2_diskr_matlabInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_hoistedGlobal_sizes[2];
  int32_T c2_b_hoistedGlobal;
  int32_T c2_c_hoistedGlobal;
  int32_T c2_loop_ub;
  int32_T c2_i2;
  real_T c2_hoistedGlobal_data[1801];
  int32_T c2_u_sizes[2];
  int32_T c2_b_u;
  int32_T c2_c_u;
  int32_T c2_b_loop_ub;
  int32_T c2_i3;
  real_T c2_u_data[1801];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_stell;
  c2_stell = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  c2_hoistedGlobal = *c2_stell;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal_sizes[0] = 1;
  c2_hoistedGlobal_sizes[1] = chartInstance->c2_X_sizes[1];
  c2_b_hoistedGlobal = c2_hoistedGlobal_sizes[0];
  c2_c_hoistedGlobal = c2_hoistedGlobal_sizes[1];
  c2_loop_ub = chartInstance->c2_X_sizes[0] * chartInstance->c2_X_sizes[1] - 1;
  for (c2_i2 = 0; c2_i2 <= c2_loop_ub; c2_i2 = c2_i2 + 1) {
    c2_hoistedGlobal_data[c2_i2] = chartInstance->c2_X_data[c2_i2];
  }

  c2_u_sizes[0] = 1;
  c2_u_sizes[1] = c2_hoistedGlobal_sizes[1];
  c2_b_u = c2_u_sizes[0];
  c2_c_u = c2_u_sizes[1];
  c2_b_loop_ub = c2_hoistedGlobal_sizes[0] * c2_hoistedGlobal_sizes[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3 = c2_i3 + 1) {
    c2_u_data[c2_i3] = c2_hoistedGlobal_data[c2_i3];
  }

  c2_c_y = NULL;
  if (!chartInstance->c2_X_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_u_data, 0, 0U, 1U, 0U, 2,
      c2_u_sizes[0], c2_u_sizes[1]));
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_diskr_matlab;
  c2_d_u = c2_d_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  int32_T c2_tmp_sizes[2];
  real_T c2_tmp_data[1801];
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_loop_ub;
  int32_T c2_i6;
  real_T *c2_stell;
  c2_stell = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_stell = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "stell");
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "X",
                        c2_tmp_data, c2_tmp_sizes);
  chartInstance->c2_X_sizes[0] = 1;
  chartInstance->c2_X_sizes[1] = c2_tmp_sizes[1];
  c2_i4 = chartInstance->c2_X_sizes[0];
  c2_i5 = chartInstance->c2_X_sizes[1];
  c2_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
  for (c2_i6 = 0; c2_i6 <= c2_loop_ub; c2_i6 = c2_i6 + 1) {
    chartInstance->c2_X_data[c2_i6] = c2_tmp_data[c2_i6];
  }

  chartInstance->c2_is_active_c2_diskr_matlab = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_diskr_matlab");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_diskr_matlab(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct
  *chartInstance)
{
}

static void sf_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_previousEvent;
  real_T *c2_ist;
  real_T *c2_soll;
  real_T *c2_stell;
  c2_stell = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_soll = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_ist = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  _SFD_DATA_RANGE_CHECK(*c2_ist, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_soll, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_stell, 2U);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7 = c2_i7 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_b[c2_i7], 3U);
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_a[c2_i8], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_steps, 5U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_diskr_matlab(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_diskr_matlabMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_c2_diskr_matlab(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_ist;
  real_T c2_soll;
  uint32_T c2_debug_family_var_map[11];
  static const char *c2_sv0[11] = { "diff", "res", "b", "a", "steps", "nargin",
    "nargout", "ist", "soll", "stell", "X" };

  real_T c2_diff;
  int32_T c2_res_sizes[2];
  real_T c2_res_data[1801];
  real_T c2_c_b[3] = { 54.299790062732114, -104.45418715255416,
    50.18678297242289 };

  real_T c2_c_a[3] = { 1.0, -1.1773985819381527, 0.17739858193815267 };

  real_T c2_c_steps = c2_b_steps;
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 1.0;
  real_T c2_stell;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_tmp_sizes[2];
  int32_T c2_loop_ub;
  int32_T c2_i11;
  real_T c2_tmp_data[1802];
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_b_loop_ub;
  int32_T c2_i14;
  int32_T c2_b_tmp_sizes[2];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_c_loop_ub;
  int32_T c2_i17;
  real_T c2_b_tmp_data[1801];
  int32_T c2_c_tmp_sizes[2];
  real_T c2_c_tmp_data[1801];
  int32_T c2_res;
  int32_T c2_b_res;
  int32_T c2_d_loop_ub;
  int32_T c2_i18;
  real_T *c2_b_stell;
  real_T *c2_b_ist;
  real_T *c2_b_soll;
  c2_b_stell = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_soll = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_ist = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  c2_hoistedGlobal = *c2_b_ist;
  c2_b_hoistedGlobal = *c2_b_soll;
  c2_ist = c2_hoistedGlobal;
  c2_soll = c2_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c2_sv0, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_diff, c2_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml_dyn(c2_res_data, (const int32_T *)&c2_res_sizes,
    NULL, 0, (void *)c2_d_sf_marshall, 1);
  sf_debug_symbol_scope_add_eml(c2_c_b, c2_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c2_c_a, c2_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_c_steps, c2_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_ist, c2_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c2_soll, c2_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c2_stell, c2_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml_dyn(chartInstance->c2_X_data, (const int32_T *)
    &chartInstance->c2_X_sizes, NULL, 1, (void *)
    c2_sf_marshall, 10);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  _SFD_EML_CALL(0, 6);
  c2_diff = c2_soll - c2_ist;
  _SFD_EML_CALL(0, 7);
  c2_A = c2_diff;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_diff = c2_c_x / 0.0338;
  _SFD_EML_CALL(0, 9);
  if (CV_EML_IF(0, 0, !chartInstance->c2_X_not_empty)) {
    _SFD_EML_CALL(0, 10);
    chartInstance->c2_X_sizes[0] = 1;
    chartInstance->c2_X_sizes[1] = 1;
    c2_i9 = chartInstance->c2_X_sizes[0];
    c2_i10 = chartInstance->c2_X_sizes[1];
    chartInstance->c2_X_data[0] = c2_diff;
    chartInstance->c2_X_not_empty = TRUE;
  } else {
    _SFD_EML_CALL(0, 12);
    c2_tmp_sizes[0] = 1;
    c2_tmp_sizes[1] = chartInstance->c2_X_sizes[1] + 1;
    c2_loop_ub = chartInstance->c2_X_sizes[1] - 1;
    for (c2_i11 = 0; c2_i11 <= c2_loop_ub; c2_i11 = c2_i11 + 1) {
      c2_tmp_data[c2_tmp_sizes[0] * c2_i11] = chartInstance->
        c2_X_data[chartInstance->c2_X_sizes[0] * c2_i11];
    }

    c2_tmp_data[c2_tmp_sizes[0] * chartInstance->c2_X_sizes[1]] = c2_diff;
    sf_debug_dim_size_geq_check(1801, c2_tmp_sizes[1], 2);
    chartInstance->c2_X_sizes[0] = 1;
    chartInstance->c2_X_sizes[1] = c2_tmp_sizes[1];
    c2_i12 = chartInstance->c2_X_sizes[0];
    c2_i13 = chartInstance->c2_X_sizes[1];
    c2_b_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
    for (c2_i14 = 0; c2_i14 <= c2_b_loop_ub; c2_i14 = c2_i14 + 1) {
      chartInstance->c2_X_data[c2_i14] = c2_tmp_data[c2_i14];
    }

    chartInstance->c2_X_not_empty = TRUE;
  }

  _SFD_EML_CALL(0, 15);
  c2_b_tmp_sizes[0] = 1;
  c2_b_tmp_sizes[1] = chartInstance->c2_X_sizes[1];
  c2_i15 = c2_b_tmp_sizes[0];
  c2_i16 = c2_b_tmp_sizes[1];
  c2_c_loop_ub = chartInstance->c2_X_sizes[0] * chartInstance->c2_X_sizes[1] - 1;
  for (c2_i17 = 0; c2_i17 <= c2_c_loop_ub; c2_i17 = c2_i17 + 1) {
    c2_b_tmp_data[c2_i17] = chartInstance->c2_X_data[c2_i17];
  }

  c2_filter(chartInstance, c2_b_tmp_data, c2_b_tmp_sizes, c2_c_tmp_data,
            c2_c_tmp_sizes);
  c2_res_sizes[0] = 1;
  c2_res_sizes[1] = c2_c_tmp_sizes[1];
  c2_res = c2_res_sizes[0];
  c2_b_res = c2_res_sizes[1];
  c2_d_loop_ub = c2_c_tmp_sizes[0] * c2_c_tmp_sizes[1] - 1;
  for (c2_i18 = 0; c2_i18 <= c2_d_loop_ub; c2_i18 = c2_i18 + 1) {
    c2_res_data[c2_i18] = c2_c_tmp_data[c2_i18];
  }

  _SFD_EML_CALL(0, 17);
  c2_stell = c2_min(chartInstance, c2_res_data[c2_res_sizes[1] - 1], 10.0);
  _SFD_EML_CALL(0, -17);
  sf_debug_symbol_scope_pop();
  *c2_b_stell = c2_stell;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
}

static void compInitSubchartSimstructsFcn_c2_diskr_matlab
  (SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

static void c2_filter(SFc2_diskr_matlabInstanceStruct *chartInstance, real_T
                      c2_x_data[1801], int32_T c2_x_sizes[2], real_T
                      c2_y_data[1801], int32_T c2_y_sizes[2])
{
  boolean_T c2_b0;
  boolean_T c2_b1;
  int32_T c2_i19;
  static char_T c2_cv0[44] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'f', 'i', 'l', 't', 'e', 'r'
    , ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a',
    't', 'i', 'b', 'i', 'l',
    'i', 't', 'y' };

  char_T c2_u[44];
  const mxArray *c2_y = NULL;
  int32_T c2_i20;
  static char_T c2_cv1[191] = { 'T', 'h', 'e', ' ', 'w', 'o', 'r', 'k', 'i', 'n',
    'g', ' ', 'd', 'i', 'm', 'e', 'n', 's', 'i', 'o',
    'n', ' ', 'w', 'a', 's', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ',
    'a', 'u', 't', 'o', 'm',
    'a', 't', 'i', 'c', 'a', 'l', 'l', 'y', ',', ' ', 'i', 's', ' ', 'v', 'a',
    'r', 'i', 'a', 'b', 'l',
    'e', '-', 'l', 'e', 'n', 'g', 't', 'h', ',', ' ', 'a', 'n', 'd', ' ', 'h',
    'a', 's', ' ', 'l', 'e',
    'n', 'g', 't', 'h', ' ', '1', ' ', 'a', 't', ' ', 'r', 'u', 'n', '-', 't',
    'i', 'm', 'e', '.', ' ',
    'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 's', 'u', 'p',
    'p', 'o', 'r', 't', 'e',
    'd', '.', ' ', 'M', 'a', 'n', 'u', 'a', 'l', 'l', 'y', ' ', 's', 'e', 'l',
    'e', 'c', 't', ' ', 't',
    'h', 'e', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'd', 'i', 'm', 'e',
    'n', 's', 'i', 'o', 'n',
    ' ', 'b', 'y', ' ', 's', 'u', 'p', 'p', 'l', 'y', 'i', 'n', 'g', ' ', 't',
    'h', 'e', ' ', 'D', 'I',
    'M', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', '.' };

  char_T c2_b_u[191];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i21;
  real_T c2_dv2[2];
  int32_T c2_tmp_sizes[2];
  int32_T c2_iv0[2];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_loop_ub;
  int32_T c2_i24;
  real_T c2_tmp_data[1801];
  int32_T c2_i25;
  real_T c2_nx;
  int32_T c2_b_x_sizes[2];
  int32_T c2_x;
  int32_T c2_b_x;
  int32_T c2_b_loop_ub;
  int32_T c2_i26;
  real_T c2_b_x_data[1801];
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_dbuffer[3];
  real_T c2_j;
  real_T c2_b_j;
  real_T c2_c_a;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  int32_T c2_i27;
  int32_T c2_jp;
  real_T c2_c_k;
  real_T c2_d_k;
  real_T c2_d_a;
  static real_T c2_dv3[3] = { 54.299790062732114, -104.45418715255416,
    50.18678297242289 };

  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_e_k;
  real_T c2_e_a;
  static real_T c2_dv4[3] = { 1.0, -1.1773985819381527, 0.17739858193815267 };

  real_T c2_d_b;
  real_T c2_d_y;
  c2_b0 = (c2_x_sizes[1] == 1);
  if (c2_b0) {
  } else if ((real_T)c2_x_sizes[1] != 1.0) {
  } else {
    c2_b1 = FALSE;
    goto label_1;
  }

  c2_b1 = TRUE;
 label_1:
  ;
  if (c2_b1) {
  } else {
    for (c2_i19 = 0; c2_i19 < 44; c2_i19 = c2_i19 + 1) {
      c2_u[c2_i19] = c2_cv0[c2_i19];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 44));
    for (c2_i20 = 0; c2_i20 < 191; c2_i20 = c2_i20 + 1) {
      c2_b_u[c2_i20] = c2_cv1[c2_i20];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 191));
    sf_mex_call_debug("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i21 = 0; c2_i21 < 2; c2_i21 = c2_i21 + 1) {
    c2_dv2[c2_i21] = (real_T)c2_x_sizes[c2_i21];
  }

  c2_tmp_sizes[0] = 1;
  c2_iv0[0] = 1;
  c2_iv0[1] = (int32_T)c2_dv2[1];
  c2_tmp_sizes[1] = c2_iv0[1];
  c2_i22 = c2_tmp_sizes[0];
  c2_i23 = c2_tmp_sizes[1];
  c2_loop_ub = (int32_T)c2_dv2[1] - 1;
  for (c2_i24 = 0; c2_i24 <= c2_loop_ub; c2_i24 = c2_i24 + 1) {
    c2_tmp_data[c2_i24] = 0.0;
  }

  for (c2_i25 = 0; c2_i25 < 2; c2_i25 = c2_i25 + 1) {
    c2_y_sizes[c2_i25] = c2_tmp_sizes[c2_i25];
  }

  c2_nx = (real_T)c2_x_sizes[1];
  c2_b_x_sizes[0] = 1;
  c2_b_x_sizes[1] = c2_x_sizes[1];
  c2_x = c2_b_x_sizes[0];
  c2_b_x = c2_b_x_sizes[1];
  c2_b_loop_ub = c2_x_sizes[0] * c2_x_sizes[1] - 1;
  for (c2_i26 = 0; c2_i26 <= c2_b_loop_ub; c2_i26 = c2_i26 + 1) {
    c2_b_x_data[c2_i26] = c2_x_data[c2_i26];
  }

  c2_eml_prodsize_except_dim(chartInstance, c2_b_x_data, c2_b_x_sizes);
  c2_d_eml_scalar_eg(chartInstance);
  c2_d_eml_scalar_eg(chartInstance);
  for (c2_k = 1.0; c2_k <= 2.0; c2_k = c2_k + 1.0) {
    c2_b_k = c2_k;
    c2_dbuffer[(int32_T)(c2_b_k + 1.0) - 1] = 0.0;
  }

  for (c2_j = 1.0; c2_j <= c2_nx; c2_j = c2_j + 1.0) {
    c2_b_j = c2_j;
    c2_c_a = c2_b_j;
    c2_d1 = c2_c_a;
    c2_d2 = c2_d1;
    c2_d2 = c2_d2 < 0.0 ? muDoubleScalarCeil(c2_d2 - 0.5) : muDoubleScalarFloor
      (c2_d2 + 0.5);
    c2_d3 = c2_d2;
    if (c2_d3 < 2.147483648E+9) {
      if (c2_d3 >= -2.147483648E+9) {
        c2_i27 = (int32_T)c2_d3;
      } else {
        c2_i27 = MIN_int32_T;
      }
    } else if (c2_d3 >= 2.147483648E+9) {
      c2_i27 = MAX_int32_T;
    } else {
      c2_i27 = 0;
    }

    c2_jp = c2_i27;
    for (c2_c_k = 1.0; c2_c_k <= 2.0; c2_c_k = c2_c_k + 1.0) {
      c2_b_k = c2_c_k;
      c2_dbuffer[(int32_T)c2_b_k - 1] = c2_dbuffer[(int32_T)(c2_b_k + 1.0) - 1];
    }

    c2_dbuffer[2] = 0.0;
    for (c2_d_k = 1.0; c2_d_k <= 3.0; c2_d_k = c2_d_k + 1.0) {
      c2_b_k = c2_d_k;
      c2_d_a = c2_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c2_jp, 1, c2_x_sizes[1],
        1, 0) - 1];
      c2_c_b = c2_dv3[(int32_T)c2_b_k - 1];
      c2_c_y = c2_d_a * c2_c_b;
      c2_dbuffer[(int32_T)c2_b_k - 1] = c2_dbuffer[(int32_T)c2_b_k - 1] + c2_c_y;
    }

    for (c2_e_k = 2.0; c2_e_k <= 3.0; c2_e_k = c2_e_k + 1.0) {
      c2_b_k = c2_e_k;
      c2_e_a = c2_dbuffer[0];
      c2_d_b = c2_dv4[(int32_T)c2_b_k - 1];
      c2_d_y = c2_e_a * c2_d_b;
      c2_dbuffer[(int32_T)c2_b_k - 1] = c2_dbuffer[(int32_T)c2_b_k - 1] - c2_d_y;
    }

    c2_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c2_jp, 1, c2_y_sizes[1], 1, 0) - 1]
      = c2_dbuffer[0];
  }
}

static void c2_b_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

static void c2_c_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

static void c2_eml_prodsize_except_dim(SFc2_diskr_matlabInstanceStruct
  *chartInstance, real_T c2_x_data[1801], int32_T c2_x_sizes[2]
  )
{
}

static void c2_d_eml_scalar_eg(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

static real_T c2_min(SFc2_diskr_matlabInstanceStruct *chartInstance, real_T
                     c2_varargin_1, real_T c2_varargin_2)
{
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_xk;
  real_T c2_c_x;
  c2_x = c2_varargin_1;
  c2_b_x = c2_x;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_b_x;
  c2_c_x = c2_xk;
  c2_eml_scalar_eg(chartInstance);
  return muDoubleScalarMin(c2_c_x, 10.0);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, real_T c2_u_data
  [1801], int32_T c2_u_sizes[2])
{
  const mxArray *c2_y = NULL;
  int32_T c2_b_u_sizes[2];
  int32_T c2_loop_ub;
  int32_T c2_i28;
  real_T c2_b_u_data[1801];
  int32_T c2_c_u_sizes[2];
  int32_T c2_b_loop_ub;
  int32_T c2_i29;
  real_T c2_c_u_data[1801];
  const mxArray *c2_b_y = NULL;
  SFc2_diskr_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_diskr_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u_sizes[0] = 1;
  c2_b_u_sizes[1] = c2_u_sizes[1];
  c2_loop_ub = c2_u_sizes[1] - 1;
  for (c2_i28 = 0; c2_i28 <= c2_loop_ub; c2_i28 = c2_i28 + 1) {
    c2_b_u_data[c2_b_u_sizes[0] * c2_i28] = c2_u_data[c2_u_sizes[0] * c2_i28];
  }

  c2_c_u_sizes[0] = 1;
  c2_c_u_sizes[1] = c2_b_u_sizes[1];
  c2_b_loop_ub = c2_b_u_sizes[1] - 1;
  for (c2_i29 = 0; c2_i29 <= c2_b_loop_ub; c2_i29 = c2_i29 + 1) {
    c2_c_u_data[c2_c_u_sizes[0] * c2_i29] = c2_b_u_data[c2_b_u_sizes[0] * c2_i29];
  }

  c2_b_y = NULL;
  if (!chartInstance->c2_X_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u_data, 0, 0U, 1U, 0U, 2,
      c2_c_u_sizes[0], c2_c_u_sizes[1]));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_diskr_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_diskr_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i30;
  real_T c2_b_u[3];
  int32_T c2_i31;
  real_T c2_c_u[3];
  const mxArray *c2_b_y = NULL;
  SFc2_diskr_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_diskr_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i30 = 0; c2_i30 < 3; c2_i30 = c2_i30 + 1) {
    c2_b_u[c2_i30] = (*((real_T (*)[3])c2_u))[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 3; c2_i31 = c2_i31 + 1) {
    c2_c_u[c2_i31] = c2_b_u[c2_i31];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, real_T
  c2_u_data[1801], int32_T c2_u_sizes[2])
{
  const mxArray *c2_y = NULL;
  int32_T c2_b_u_sizes[2];
  int32_T c2_loop_ub;
  int32_T c2_i32;
  real_T c2_b_u_data[1801];
  int32_T c2_c_u_sizes[2];
  int32_T c2_b_loop_ub;
  int32_T c2_i33;
  real_T c2_c_u_data[1801];
  const mxArray *c2_b_y = NULL;
  SFc2_diskr_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_diskr_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u_sizes[0] = 1;
  c2_b_u_sizes[1] = c2_u_sizes[1];
  c2_loop_ub = c2_u_sizes[1] - 1;
  for (c2_i32 = 0; c2_i32 <= c2_loop_ub; c2_i32 = c2_i32 + 1) {
    c2_b_u_data[c2_b_u_sizes[0] * c2_i32] = c2_u_data[c2_u_sizes[0] * c2_i32];
  }

  c2_c_u_sizes[0] = 1;
  c2_c_u_sizes[1] = c2_b_u_sizes[1];
  c2_b_loop_ub = c2_b_u_sizes[1] - 1;
  for (c2_i33 = 0; c2_i33 <= c2_b_loop_ub; c2_i33 = c2_i33 + 1) {
    c2_c_u_data[c2_c_u_sizes[0] * c2_i33] = c2_b_u_data[c2_b_u_sizes[0] * c2_i33];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u_data, 0, 0U, 1U, 0U, 2,
    c2_c_u_sizes[0], c2_c_u_sizes[1]));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_diskr_matlab_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[46];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i34;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 46));
  for (c2_i34 = 0; c2_i34 < 46; c2_i34 = c2_i34 + 1) {
    c2_r0 = &c2_info[c2_i34];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i34);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i34);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i34);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i34);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i34);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i34
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i34
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[46])
{
  c2_info[0].context = "";
  c2_info[0].name = "plus";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]plus";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "minus";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]minus";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "mrdivide";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[2].fileLength = 432U;
  c2_info[2].fileTime1 = 1277748222U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[3].name = "nargin";
  c2_info[3].dominantType = "";
  c2_info[3].resolved = "[B]nargin";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[4].name = "ge";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]ge";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].name = "isscalar";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isscalar";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileLength = 403U;
  c2_info[6].fileTime1 = 1245102420U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "gt";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]gt";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].name = "isa";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isa";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].name = "eml_div";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[9].fileLength = 4918U;
  c2_info[9].fileTime1 = 1267063410U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[10].name = "isinteger";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isinteger";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[11].name = "isreal";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]isreal";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "filter";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[12].fileLength = 6556U;
  c2_info[12].fileTime1 = 1240261954U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[13].name = "isvector";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]isvector";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[14].name = "isempty";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]isempty";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[15].name = "not";
  c2_info[15].dominantType = "logical";
  c2_info[15].resolved = "[B]not";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[16].name = "max";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[16].fileLength = 362U;
  c2_info[16].fileTime1 = 1245102360U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[17].name = "le";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]le";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[18].name = "nargout";
  c2_info[18].dominantType = "";
  c2_info[18].resolved = "[B]nargout";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[19].name = "eml_min_or_max";
  c2_info[19].dominantType = "char";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[19].fileLength = 9967U;
  c2_info[19].fileTime1 = 1261951870U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[20].name = "ischar";
  c2_info[20].dominantType = "char";
  c2_info[20].resolved = "[B]ischar";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[21].name = "strcmp";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved = "[B]strcmp";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[22].name = "isnumeric";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]isnumeric";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[23].name = "eq";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]eq";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[24].name = "class";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]class";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[25].name = "islogical";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[B]islogical";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[26].name = "eml_scalar_eg";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[26].fileLength = 3068U;
  c2_info[26].fileTime1 = 1240262010U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c2_info[27].name = "false";
  c2_info[27].dominantType = "";
  c2_info[27].resolved = "[B]false";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[28].name = "isstruct";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]isstruct";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c2_info[29].name = "cast";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[B]cast";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[30].name = "eml_scalexp_alloc";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[30].fileLength = 932U;
  c2_info[30].fileTime1 = 1261951870U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[31].name = "eml_index_class";
  c2_info[31].dominantType = "";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[31].fileLength = 909U;
  c2_info[31].fileTime1 = 1192466782U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[32].name = "ones";
  c2_info[32].dominantType = "char";
  c2_info[32].resolved = "[B]ones";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[33].name = "lt";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[B]lt";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[34].name = "eml_const_nonsingleton_dim";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[34].fileLength = 1473U;
  c2_info[34].fileTime1 = 1240262002U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m!local_const_nonsingleton_dim";
  c2_info[35].name = "size";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]size";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m!local_const_nonsingleton_dim";
  c2_info[36].name = "ne";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]ne";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[37].name = "zeros";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved = "[B]zeros";
  c2_info[37].fileLength = 0U;
  c2_info[37].fileTime1 = 0U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[38].name = "isfinite";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[38].fileLength = 364U;
  c2_info[38].fileTime1 = 1226577272U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[39].name = "isinf";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[39].fileLength = 541U;
  c2_info[39].fileTime1 = 1271405588U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[40].name = "isnan";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[40].fileLength = 541U;
  c2_info[40].fileTime1 = 1271405588U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[41].name = "and";
  c2_info[41].dominantType = "logical";
  c2_info[41].resolved = "[B]and";
  c2_info[41].fileLength = 0U;
  c2_info[41].fileTime1 = 0U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[42].name = "eml_prodsize_except_dim";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_prodsize_except_dim.m";
  c2_info[42].fileLength = 279U;
  c2_info[42].fileTime1 = 1234901170U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[43].name = "eml_index_plus";
  c2_info[43].dominantType = "int32";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[43].fileLength = 272U;
  c2_info[43].fileTime1 = 1192466784U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/filter.m";
  c2_info[44].name = "mtimes";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[44].fileLength = 3425U;
  c2_info[44].fileTime1 = 1251031872U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context = "";
  c2_info[45].name = "min";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[45].fileLength = 362U;
  c2_info[45].fileTime1 = 1245102364U;
  c2_info[45].fileTime2 = 0U;
}

static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_diskr_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_diskr_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_diskr_matlabInstanceStruct *chartInstance,
  const mxArray *c2_stell, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d4;
  sf_mex_import(c2_name, sf_mex_dup(c2_stell), &c2_d4, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d4;
  sf_mex_destroy(&c2_stell);
  return c2_y;
}

static void c2_b_emlrt_marshallIn(SFc2_diskr_matlabInstanceStruct *chartInstance,
  const mxArray *c2_X, const char_T *c2_name, real_T
  c2_y_data[1801], int32_T c2_y_sizes[2])
{
  int32_T c2_i35;
  uint32_T c2_uv0[2];
  int32_T c2_i36;
  static boolean_T c2_bv0[2] = { FALSE, TRUE };

  boolean_T c2_bv1[2];
  int32_T c2_tmp_sizes[2];
  real_T c2_tmp_data[1801];
  int32_T c2_y;
  int32_T c2_b_y;
  int32_T c2_loop_ub;
  int32_T c2_i37;
  for (c2_i35 = 0; c2_i35 < 2; c2_i35 = c2_i35 + 1) {
    c2_uv0[c2_i35] = 1U + 1800U * (uint32_T)c2_i35;
  }

  if (mxIsEmpty(c2_X)) {
    chartInstance->c2_X_not_empty = FALSE;
  } else {
    chartInstance->c2_X_not_empty = TRUE;
    for (c2_i36 = 0; c2_i36 < 2; c2_i36 = c2_i36 + 1) {
      c2_bv1[c2_i36] = c2_bv0[c2_i36];
    }

    sf_mex_import_vs(c2_name, sf_mex_dup(c2_X), c2_tmp_data, 1, 0, 0U, 1, 0U, 2,
                     c2_bv1, c2_uv0, c2_tmp_sizes);
    c2_y_sizes[0] = 1;
    c2_y_sizes[1] = c2_tmp_sizes[1];
    c2_y = c2_y_sizes[0];
    c2_b_y = c2_y_sizes[1];
    c2_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
    for (c2_i37 = 0; c2_i37 <= c2_loop_ub; c2_i37 = c2_i37 + 1) {
      c2_y_data[c2_i37] = c2_tmp_data[c2_i37];
    }
  }

  sf_mex_destroy(&c2_X);
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_diskr_matlabInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_diskr_matlab,
  const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_diskr_matlab), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_diskr_matlab);
  return c2_y;
}

static void init_dsm_address_info(SFc2_diskr_matlabInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_diskr_matlab_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2044882157U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1205123155U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1020629017U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(953853911U);
}

mxArray *sf_c2_diskr_matlab_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1891473060U);
    pr[1] = (double)(1684632787U);
    pr[2] = (double)(785418320U);
    pr[3] = (double)(4243659703U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_diskr_matlab(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"stell\",},{M[4],M[0],T\"X\",S'l','i','p'{{M1x2[62 63],M[0],}}},{M[8],M[0],T\"is_active_c2_diskr_matlab\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_diskr_matlab_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_diskr_matlabInstanceStruct *chartInstance;
    chartInstance = (SFc2_diskr_matlabInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_diskr_matlabMachineNumber_,
           2,
           1,
           1,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_diskr_matlabMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_diskr_matlabMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_diskr_matlabMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"ist");
          _SFD_SET_DATA_PROPS(1,1,1,0,"soll");
          _SFD_SET_DATA_PROPS(2,2,0,1,"stell");
          _SFD_SET_DATA_PROPS(3,10,0,0,"b");
          _SFD_SET_DATA_PROPS(4,10,0,0,"a");
          _SFD_SET_DATA_PROPS(5,10,0,0,"steps");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,298);
        _SFD_CV_INIT_EML_IF(0,0,162,175,198,232);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);

        {
          real_T *c2_ist;
          real_T *c2_soll;
          real_T *c2_stell;
          c2_stell = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_soll = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_ist = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_ist);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_soll);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_stell);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_b);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_a);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c2_steps);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_diskr_matlabMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_diskr_matlab(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_diskr_matlabInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*)
    chartInstanceVar);
  initialize_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_diskr_matlab(void *chartInstanceVar)
{
  enable_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_diskr_matlab(void *chartInstanceVar)
{
  disable_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_diskr_matlab(void *chartInstanceVar)
{
  sf_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_diskr_matlab(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_diskr_matlab
    ((SFc2_diskr_matlabInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_diskr_matlab();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c2_diskr_matlab(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_diskr_matlab();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_diskr_matlab(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_diskr_matlab(S);
}

static void sf_opaque_set_sim_state_c2_diskr_matlab(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_diskr_matlab(S, st);
}

static void sf_opaque_terminate_c2_diskr_matlab(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_diskr_matlabInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_diskr_matlab(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_diskr_matlab((SFc2_diskr_matlabInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_diskr_matlab(SimStruct *S)
{
  /* Actual parameters from chart:
     a b steps
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for a*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for b*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for steps*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"diskr_matlab","diskr_matlab",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"diskr_matlab","diskr_matlab",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"diskr_matlab",
      "diskr_matlab",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"diskr_matlab","diskr_matlab",2,2);
      sf_mark_chart_reusable_outputs(S,"diskr_matlab","diskr_matlab",2,1);
    }

    sf_set_rtw_dwork_info(S,"diskr_matlab","diskr_matlab",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2318725662U));
  ssSetChecksum1(S,(3463904009U));
  ssSetChecksum2(S,(1688842994U));
  ssSetChecksum3(S,(13001058U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_diskr_matlab(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "diskr_matlab", "diskr_matlab",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_diskr_matlab(SimStruct *S)
{
  SFc2_diskr_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_diskr_matlabInstanceStruct *)malloc(sizeof
    (SFc2_diskr_matlabInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_diskr_matlabInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_diskr_matlab;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_diskr_matlab;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_diskr_matlab;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_diskr_matlab;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_diskr_matlab;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_diskr_matlab;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_diskr_matlab;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_diskr_matlab;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_diskr_matlab;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_diskr_matlab;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_diskr_matlab;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_diskr_matlab_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_diskr_matlab(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_diskr_matlab(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_diskr_matlab(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_diskr_matlab_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
