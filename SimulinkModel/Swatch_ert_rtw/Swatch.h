/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Swatch.h
 *
 * Code generated for Simulink model 'Swatch'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Aug 22 17:37:15 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Swatch_h_
#define RTW_HEADER_Swatch_h_
#include <string.h>
#ifndef Swatch_COMMON_INCLUDES_
# define Swatch_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Swatch_COMMON_INCLUDES_ */

#include "Swatch_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<S1>/StopWatch2018' */
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
  uint8_T is_active_c3_Swatch;         /* '<S1>/StopWatch2018' */
  uint8_T is_AlarmManagement;          /* '<S1>/StopWatch2018' */
  uint8_T is_active_AlarmManagement;   /* '<S1>/StopWatch2018' */
  uint8_T is_TimeCount;                /* '<S1>/StopWatch2018' */
  uint8_T is_active_TimeCount;         /* '<S1>/StopWatch2018' */
  uint8_T is_TimeCountStopWatch;       /* '<S1>/StopWatch2018' */
  uint8_T is_active_TimeCountStopWatch;/* '<S1>/StopWatch2018' */
  uint8_T is_interface;                /* '<S1>/StopWatch2018' */
  uint8_T is_active_interface;         /* '<S1>/StopWatch2018' */
  uint8_T is_TimeSetting;              /* '<S1>/StopWatch2018' */
  uint8_T is_Alarm;                    /* '<S1>/StopWatch2018' */
  uint8_T is_StopWatch;                /* '<S1>/StopWatch2018' */
  uint8_T Ahours;                      /* '<S1>/StopWatch2018' */
  uint8_T Aminutes;                    /* '<S1>/StopWatch2018' */
  uint8_T hours;                       /* '<S1>/StopWatch2018' */
  uint8_T seconds;                     /* '<S1>/StopWatch2018' */
  uint8_T tenths;                      /* '<S1>/StopWatch2018' */
  uint8_T Shours;                      /* '<S1>/StopWatch2018' */
  uint8_T Sminutes;                    /* '<S1>/StopWatch2018' */
  uint8_T Stenths;                     /* '<S1>/StopWatch2018' */
  uint8_T Sseconds;                    /* '<S1>/StopWatch2018' */
  uint8_T minutes;                     /* '<S1>/StopWatch2018' */
} DW_Swatch_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StopWatch2018_Trig_ZCE[7];/* '<S1>/StopWatch2018' */
} PrevZCX_Swatch_T;

/* Real-time Model Data Structure */
struct tag_RTM_Swatch_T {
  const char_T *errorStatus;
  PrevZCX_Swatch_T *prevZCSigState;
  DW_Swatch_T *dwork;
};

/* Model entry point functions */
extern void Swatch_initialize(RT_MODEL_Swatch_T *const Swatch_M, boolean_T
  *Swatch_U_Bplus, boolean_T *Swatch_U_Bminus, boolean_T *Swatch_U_Btime,
  boolean_T *Swatch_U_Btimeset, boolean_T *Swatch_U_Balarm, boolean_T
  *Swatch_U_Bswatch, uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes, uint8_T
  *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode);
extern void Swatch_step(RT_MODEL_Swatch_T *const Swatch_M, boolean_T
  Swatch_U_Bplus, boolean_T Swatch_U_Bminus, boolean_T Swatch_U_Btime, boolean_T
  Swatch_U_Btimeset, boolean_T Swatch_U_Balarm, boolean_T Swatch_U_Bswatch,
  uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes, uint8_T *Swatch_Y_seconds,
  uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Stop_Generated/Swatch  ')    - opens subsystem Stop_Generated/Swatch
 * hilite_system('Stop_Generated/Swatch  /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Stop_Generated'
 * '<S1>'   : 'Stop_Generated/Swatch  '
 * '<S2>'   : 'Stop_Generated/Swatch  /Counter Limited'
 * '<S3>'   : 'Stop_Generated/Swatch  /StopWatch2018'
 * '<S4>'   : 'Stop_Generated/Swatch  /Counter Limited/Increment Real World'
 * '<S5>'   : 'Stop_Generated/Swatch  /Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Swatch_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
