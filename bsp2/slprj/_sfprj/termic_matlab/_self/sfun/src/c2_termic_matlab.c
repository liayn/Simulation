/* Include files */

#include "blascompat32.h"
#include "termic_matlab_sfun.h"
#include "c2_termic_matlab.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "termic_matlab_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_b_T                         (800.0)
#define c2_b_step                      (0.1)

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[7] = { "T", "step", "nargin", "nargout",
  "wert", "tmp", "X" };

/* Function Declarations */
static void initialize_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance);
static void initialize_params_c2_termic_matlab(SFc2_termic_matlabInstanceStruct *
  chartInstance);
static void enable_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance);
static void disable_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_termic_matlab
  (SFc2_termic_matlabInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_termic_matlab
  (SFc2_termic_matlabInstanceStruct *chartInstance);
static void set_sim_state_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance);
static void sf_c2_termic_matlab(SFc2_termic_matlabInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c2_termic_matlab
  (SFc2_termic_matlabInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[17]);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_tmp, const char_T *c2_name);
static real_T c2_b_emlrt_marshallIn(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_b_X, const char_T *c2_name);
static uint8_T c2_c_emlrt_marshallIn(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_termic_matlab, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_termic_matlabInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_X_not_empty = FALSE;
  chartInstance->c2_is_active_c2_termic_matlab = 0U;
}

static void initialize_params_c2_termic_matlab(SFc2_termic_matlabInstanceStruct *
  chartInstance)
{
  real_T c2_d0;
  real_T c2_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'T' in the parent workspace.\n");
  sf_mex_import("T", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c2_d0, 0, 0,
                0U, 0, 0U, 0);
  chartInstance->c2_T = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'step' in the parent workspace.\n");
  sf_mex_import("step", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c2_d1, 0,
                0, 0U, 0, 0U, 0);
  chartInstance->c2_step = c2_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_termic_matlab
  (SFc2_termic_matlabInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_termic_matlab
  (SFc2_termic_matlabInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_tmp;
  c2_tmp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  c2_hoistedGlobal = *c2_tmp;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_X;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  if (!chartInstance->c2_X_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_termic_matlab;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_tmp;
  c2_tmp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_tmp = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "tmp");
  chartInstance->c2_X = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "X");
  chartInstance->c2_is_active_c2_termic_matlab = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_termic_matlab");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_termic_matlab(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_termic_matlab(SFc2_termic_matlabInstanceStruct
  *chartInstance)
{
}

static void sf_c2_termic_matlab(SFc2_termic_matlabInstanceStruct *chartInstance)
{
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_wert;
  uint32_T c2_debug_family_var_map[7];
  real_T c2_c_T = c2_b_T;
  real_T c2_c_step = c2_b_step;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_tmp;
  real_T c2_b_hoistedGlobal;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_y;
  real_T c2_a;
  real_T c2_b_y;
  real_T *c2_b_wert;
  real_T *c2_b_tmp;
  c2_b_tmp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_wert = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  _SFD_DATA_RANGE_CHECK(*c2_b_wert, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_tmp, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_T, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_step, 3U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  c2_hoistedGlobal = *c2_b_wert;
  c2_wert = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_c_T, c2_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_c_step, c2_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_wert, c2_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_tmp, c2_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_X, c2_sf_marshall, 6U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  if (CV_EML_IF(0, 0, !chartInstance->c2_X_not_empty)) {
    _SFD_EML_CALL(0, 5);
    chartInstance->c2_X = 0.0;
    chartInstance->c2_X_not_empty = TRUE;
  }

  _SFD_EML_CALL(0, 8);
  c2_b_hoistedGlobal = chartInstance->c2_X;
  c2_A = c2_wert;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_y = c2_c_x / c2_b_T;
  c2_a = c2_y;
  c2_b_y = c2_a * c2_b_step;
  chartInstance->c2_X = c2_b_hoistedGlobal + c2_b_y;
  _SFD_EML_CALL(0, 9);
  c2_tmp = chartInstance->c2_X;

  /* function tmp = PI(wert,K,step) %#eml */
  /* persistent X */
  /* eml.varsize('X',[1 (7000/0.1+100)]); */
  /* if isempty(X) */
  /*     X = wert; */
  /* else */
  /*     X = [X wert]; */
  /* end; */
  /* res = filter([6.25e-005 6.25e-005],[1 -1],X); */
  /* tmp = res(end); */
  _SFD_EML_CALL(0, -9);
  sf_debug_symbol_scope_pop();
  *c2_b_tmp = c2_tmp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_termic_matlabMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c2_termic_matlab
  (SFc2_termic_matlabInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_termic_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_termic_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  if (!chartInstance->c2_X_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_termic_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_termic_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_termic_matlab_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[17];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17));
  for (c2_i0 = 0; c2_i0 < 17; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[17])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileLength = 432U;
  c2_info[0].fileTime1 = 1277748222U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "nargin";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[B]nargin";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[2].name = "ge";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]ge";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[3].name = "isscalar";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]isscalar";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[4].name = "rdivide";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[4].fileLength = 403U;
  c2_info[4].fileTime1 = 1245102420U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[5].name = "gt";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]gt";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].name = "isa";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]isa";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_div";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[7].fileLength = 4918U;
  c2_info[7].fileTime1 = 1267063410U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[8].name = "isinteger";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isinteger";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[9].name = "isreal";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]isreal";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "";
  c2_info[10].name = "mtimes";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].fileLength = 3425U;
  c2_info[10].fileTime1 = 1251031872U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "strcmp";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved = "[B]strcmp";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].name = "size";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]size";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].name = "eq";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]eq";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].name = "class";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]class";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].name = "not";
  c2_info[15].dominantType = "logical";
  c2_info[15].resolved = "[B]not";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "plus";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]plus";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_termic_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_termic_matlabInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_tmp, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_name, sf_mex_dup(c2_tmp), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_tmp);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_b_X, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d3;
  if (mxIsEmpty(c2_b_X)) {
    chartInstance->c2_X_not_empty = FALSE;
  } else {
    chartInstance->c2_X_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_X), &c2_d3, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d3;
  }

  sf_mex_destroy(&c2_b_X);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_termic_matlabInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_termic_matlab
  , const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_termic_matlab), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_termic_matlab);
  return c2_y;
}

static void init_dsm_address_info(SFc2_termic_matlabInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_termic_matlab_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3132933051U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2145188577U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3452651336U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3418597592U);
}

mxArray *sf_c2_termic_matlab_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1656445235U);
    pr[1] = (double)(264186708U);
    pr[2] = (double)(3325021488U);
    pr[3] = (double)(3679624119U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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

static mxArray *sf_get_sim_state_info_c2_termic_matlab(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"tmp\",},{M[4],M[0],T\"X\",S'l','i','p'{{M1x2[46 47],M[0],}}},{M[8],M[0],T\"is_active_c2_termic_matlab\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_termic_matlab_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_termic_matlabInstanceStruct *chartInstance;
    chartInstance = (SFc2_termic_matlabInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_termic_matlabMachineNumber_,
           2,
           1,
           1,
           4,
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
          init_script_number_translation(_termic_matlabMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_termic_matlabMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_termic_matlabMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"wert");
          _SFD_SET_DATA_PROPS(1,2,0,1,"tmp");
          _SFD_SET_DATA_PROPS(2,10,0,0,"T");
          _SFD_SET_DATA_PROPS(3,10,0,0,"step");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,397);
        _SFD_CV_INIT_EML_IF(0,0,57,70,-1,93);
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
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);

        {
          real_T *c2_wert;
          real_T *c2_tmp;
          c2_tmp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_wert = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_wert);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_tmp);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c2_T);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_step);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_termic_matlabMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_termic_matlab(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_termic_matlabInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*)
    chartInstanceVar);
  initialize_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_termic_matlab(void *chartInstanceVar)
{
  enable_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_termic_matlab(void *chartInstanceVar)
{
  disable_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_termic_matlab(void *chartInstanceVar)
{
  sf_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_termic_matlab(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_termic_matlab
    ((SFc2_termic_matlabInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_termic_matlab();/* state var info */
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

static void sf_internal_set_sim_state_c2_termic_matlab(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_termic_matlab();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_termic_matlab(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_termic_matlab(S);
}

static void sf_opaque_set_sim_state_c2_termic_matlab(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_termic_matlab(S, st);
}

static void sf_opaque_terminate_c2_termic_matlab(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_termic_matlabInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_termic_matlab
    ((SFc2_termic_matlabInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_termic_matlab(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_termic_matlab((SFc2_termic_matlabInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_termic_matlab(SimStruct *S)
{
  /* Actual parameters from chart:
     T step
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for T*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for step*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"termic_matlab","termic_matlab",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"termic_matlab","termic_matlab",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"termic_matlab",
      "termic_matlab",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"termic_matlab","termic_matlab",2,1);
      sf_mark_chart_reusable_outputs(S,"termic_matlab","termic_matlab",2,1);
    }

    sf_set_rtw_dwork_info(S,"termic_matlab","termic_matlab",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2331712678U));
  ssSetChecksum1(S,(2191271063U));
  ssSetChecksum2(S,(1845656865U));
  ssSetChecksum3(S,(3509084537U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_termic_matlab(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "termic_matlab", "termic_matlab",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_termic_matlab(SimStruct *S)
{
  SFc2_termic_matlabInstanceStruct *chartInstance;
  chartInstance = (SFc2_termic_matlabInstanceStruct *)malloc(sizeof
    (SFc2_termic_matlabInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_termic_matlabInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_termic_matlab;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_termic_matlab;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_termic_matlab;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_termic_matlab;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_termic_matlab;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_termic_matlab;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_termic_matlab;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_termic_matlab;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_termic_matlab;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_termic_matlab;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_termic_matlab;
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

void c2_termic_matlab_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_termic_matlab(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_termic_matlab(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_termic_matlab(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_termic_matlab_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
