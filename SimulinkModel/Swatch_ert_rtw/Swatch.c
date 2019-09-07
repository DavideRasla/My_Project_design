/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Swatch.c
 *
 * Code generated for Simulink model 'Swatch'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sat Sep  7 16:37:39 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Swatch.h"
#include "Swatch_private.h"

/* Named constants for Chart: '<S1>/StopWatch2018' */
#define Swatch_IN_Alarm                ((uint8_T)1U)
#define Swatch_IN_Buzzer_ON            ((uint8_T)1U)
#define Swatch_IN_Checking             ((uint8_T)2U)
#define Swatch_IN_Count                ((uint8_T)1U)
#define Swatch_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Swatch_IN_S_Count              ((uint8_T)1U)
#define Swatch_IN_S_Pause_With_Update  ((uint8_T)1U)
#define Swatch_IN_S_Start              ((uint8_T)2U)
#define Swatch_IN_Set_H                ((uint8_T)1U)
#define Swatch_IN_Set_M                ((uint8_T)2U)
#define Swatch_IN_StopWatch            ((uint8_T)2U)
#define Swatch_IN_Stop_WithOut_Update  ((uint8_T)2U)
#define Swatch_IN_TimeDisplay          ((uint8_T)3U)
#define Swatch_IN_TimeSetting          ((uint8_T)4U)
#define Swatch_IN_Wait_SWatch          ((uint8_T)3U)
#define Swatch_event_StopW_Start       (0)
#define Swatch_event_StopW_Stop        (1)
#define Swatch_event_Tick              (2)
#define Swatch_event_alarmmode         (7)
#define Swatch_event_minusbutton       (4)
#define Swatch_event_plusbutton        (3)
#define Swatch_event_swatchmode        (8)
#define Swatch_event_timemode          (5)
#define Swatch_event_timesetmode       (6)

/* Forward declaration for local functions */
static void Swatch_exit_internal_interface(DW_Swatch_T *Swatch_DW);
static void Swatch_interface(uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes,
  uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode,
  DW_Swatch_T *Swatch_DW);
static void Swatch_c3_Swatch(uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes,
  uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode,
  DW_Swatch_T *Swatch_DW);
static void Swatch_chartstep_c3_Swatch(uint8_T *Swatch_Y_hours, uint8_T
  *Swatch_Y_minutes, uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths,
  uint8_T *Swatch_Y_mode, DW_Swatch_T *Swatch_DW);

/* Function for Chart: '<S1>/StopWatch2018' */
static void Swatch_exit_internal_interface(DW_Swatch_T *Swatch_DW)
{
  /* Exit Internal 'interface': '<S2>:28' */
  /* Exit Internal 'Alarm': '<S2>:33' */
  Swatch_DW->is_Alarm = Swatch_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'StopWatch': '<S2>:34' */
  Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'TimeSetting': '<S2>:32' */
  Swatch_DW->is_TimeSetting = Swatch_IN_NO_ACTIVE_CHILD;
  Swatch_DW->is_interface = Swatch_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S1>/StopWatch2018' */
static void Swatch_interface(uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes,
  uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode,
  DW_Swatch_T *Swatch_DW)
{
  int32_T b_previousEvent;
  uint32_T qY;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;

  /* During 'interface': '<S2>:28' */
  /* '<S2>:40:1' sf_internal_predicateOutput = timemode; */
  if (Swatch_DW->sfEvent == Swatch_event_timemode) {
    /* Transition: '<S2>:40' */
    Swatch_exit_internal_interface(Swatch_DW);
    Swatch_DW->is_interface = Swatch_IN_TimeDisplay;

    /* Outport: '<Root>/mode' */
    /* Entry 'TimeDisplay': '<S2>:31' */
    /* '<S2>:31:1' mode = uint8(0) */
    *Swatch_Y_mode = 0U;
  } else {
    /* '<S2>:42:1' sf_internal_predicateOutput = swatchmode; */
    if (Swatch_DW->sfEvent == Swatch_event_swatchmode) {
      /* Transition: '<S2>:42' */
      Swatch_exit_internal_interface(Swatch_DW);
      Swatch_DW->is_interface = Swatch_IN_StopWatch;

      /* Outport: '<Root>/mode' */
      /* Entry 'StopWatch': '<S2>:34' */
      /* '<S2>:34:1' mode = uint8(3); */
      *Swatch_Y_mode = 3U;

      /* '<S2>:34:1' Shours = uint8(0); */
      Swatch_DW->Shours = 0U;

      /* '<S2>:34:2' Sminutes = uint8(0); */
      Swatch_DW->Sminutes = 0U;

      /* '<S2>:34:3' Sseconds = uint8(0); */
      Swatch_DW->Sseconds = 0U;

      /* '<S2>:34:4' Stenths = uint8(0); */
      Swatch_DW->Stenths = 0U;

      /* Outport: '<Root>/hours' */
      /* '<S2>:34:5' Dhours = uint8(0); */
      *Swatch_Y_hours = 0U;

      /* Outport: '<Root>/minutes' */
      /* '<S2>:34:6' Dminutes =uint8(0); */
      *Swatch_Y_minutes = 0U;

      /* Outport: '<Root>/seconds' */
      /* '<S2>:34:7' Dseconds = uint8(0); */
      *Swatch_Y_seconds = 0U;

      /* Outport: '<Root>/tenths' */
      /* '<S2>:34:8' Dtenths = uint8(0) */
      *Swatch_Y_tenths = 0U;

      /* Entry Internal 'StopWatch': '<S2>:34' */
      /* Transition: '<S2>:177' */
      Swatch_DW->is_StopWatch = Swatch_IN_Wait_SWatch;

      /* Entry 'Wait_SWatch': '<S2>:176' */
    } else {
      guard1 = false;
      guard2 = false;
      guard3 = false;
      guard4 = false;
      guard5 = false;
      guard6 = false;
      switch (Swatch_DW->is_interface) {
       case Swatch_IN_Alarm:
        /* Outport: '<Root>/mode' */
        *Swatch_Y_mode = 2U;

        /* During 'Alarm': '<S2>:33' */
        /* '<S2>:103:1' sf_internal_predicateOutput = timesetmode; */
        if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
          /* Transition: '<S2>:103' */
          /* Exit Internal 'Alarm': '<S2>:33' */
          Swatch_DW->is_Alarm = Swatch_IN_NO_ACTIVE_CHILD;
          Swatch_DW->is_interface = Swatch_IN_TimeSetting;

          /* Outport: '<Root>/mode' */
          /* Entry 'TimeSetting': '<S2>:32' */
          /* '<S2>:32:1' mode = uint8(1) */
          *Swatch_Y_mode = 1U;

          /* Entry Internal 'TimeSetting': '<S2>:32' */
          /* Transition: '<S2>:165' */
          Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

          /* Outport: '<Root>/hours' */
          /* Entry 'Set_H': '<S2>:168' */
          /* '<S2>:168:1' Dhours = hours; */
          *Swatch_Y_hours = Swatch_DW->hours;
        } else {
          switch (Swatch_DW->is_Alarm) {
           case Swatch_IN_Set_H:
            /* During 'Set_H': '<S2>:132' */
            /* '<S2>:130:1' sf_internal_predicateOutput = plusbutton; */
            if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
              /* Transition: '<S2>:130' */
              /* '<S2>:140:1' sf_internal_predicateOutput = Ahours < 23; */
              if (Swatch_DW->Ahours < 23) {
                /* Transition: '<S2>:140' */
                /* '<S2>:140:1' Ahours = Ahours +1; */
                b_previousEvent = (int32_T)(Swatch_DW->Ahours + 1U);
                if ((uint32_T)b_previousEvent > 255U) {
                  b_previousEvent = 255;
                }

                Swatch_DW->Ahours = (uint8_T)b_previousEvent;
                guard1 = true;
              } else {
                /* '<S2>:142:1' sf_internal_predicateOutput = Ahours == 23; */
                if (Swatch_DW->Ahours == 23) {
                  /* Transition: '<S2>:142' */
                  /* '<S2>:142:1' Ahours = uint8(0); */
                  Swatch_DW->Ahours = 0U;
                  guard1 = true;
                } else {
                  guard5 = true;
                }
              }
            } else {
              guard5 = true;
            }
            break;

           case Swatch_IN_Set_M:
            /* During 'Set_M': '<S2>:133' */
            /* '<S2>:149:1' sf_internal_predicateOutput = plusbutton; */
            if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
              /* Transition: '<S2>:149' */
              /* '<S2>:150:1' sf_internal_predicateOutput = Aminutes == 59; */
              if (Swatch_DW->Aminutes == 59) {
                /* Transition: '<S2>:150' */
                /* '<S2>:150:1' Aminutes = uint8(0); */
                Swatch_DW->Aminutes = 0U;
              } else {
                /* Transition: '<S2>:148' */
                /* '<S2>:148:1' Aminutes = Aminutes +1; */
                b_previousEvent = (int32_T)(Swatch_DW->Aminutes + 1U);
                if ((uint32_T)b_previousEvent > 255U) {
                  b_previousEvent = 255;
                }

                Swatch_DW->Aminutes = (uint8_T)b_previousEvent;
              }

              guard2 = true;
            } else {
              /* '<S2>:153:1' sf_internal_predicateOutput = minusbutton; */
              if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
                /* Transition: '<S2>:153' */
                /* '<S2>:154:1' sf_internal_predicateOutput = Aminutes ==0; */
                if (Swatch_DW->Aminutes == 0) {
                  /* Transition: '<S2>:154' */
                  /* '<S2>:154:1' Aminutes = 59; */
                  Swatch_DW->Aminutes = 59U;
                } else {
                  /* Transition: '<S2>:152' */
                  /* '<S2>:152:1' Aminutes = Aminutes -1; */
                  qY = Swatch_DW->Aminutes - 1U;
                  if (qY > Swatch_DW->Aminutes) {
                    qY = 0U;
                  }

                  Swatch_DW->Aminutes = (uint8_T)qY;
                }

                guard2 = true;
              } else {
                /* '<S2>:129:1' sf_internal_predicateOutput = alarmmode; */
                if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
                  /* Transition: '<S2>:129' */
                  Swatch_DW->is_Alarm = Swatch_IN_Set_H;

                  /* Outport: '<Root>/hours' */
                  /* Entry 'Set_H': '<S2>:132' */
                  /* '<S2>:132:1' Dhours = Ahours; */
                  *Swatch_Y_hours = Swatch_DW->Ahours;
                } else {
                  /* Outport: '<Root>/minutes' */
                  /* '<S2>:133:1' Dminutes = Aminutes */
                  *Swatch_Y_minutes = Swatch_DW->Aminutes;
                }
              }
            }
            break;

           default:
            /* Unreachable state, for coverage only */
            Swatch_DW->is_Alarm = Swatch_IN_NO_ACTIVE_CHILD;
            break;
          }
        }
        break;

       case Swatch_IN_StopWatch:
        /* Outport: '<Root>/mode' */
        *Swatch_Y_mode = 3U;

        /* During 'StopWatch': '<S2>:34' */
        /* '<S2>:99:1' sf_internal_predicateOutput = alarmmode; */
        if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
          /* Transition: '<S2>:99' */
          /* Exit Internal 'StopWatch': '<S2>:34' */
          Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
          Swatch_DW->is_interface = Swatch_IN_Alarm;

          /* Outport: '<Root>/mode' */
          /* Entry 'Alarm': '<S2>:33' */
          /* '<S2>:33:1' mode = uint8(2) */
          *Swatch_Y_mode = 2U;

          /* Entry Internal 'Alarm': '<S2>:33' */
          /* Transition: '<S2>:136' */
          Swatch_DW->is_Alarm = Swatch_IN_Set_H;

          /* Outport: '<Root>/hours' */
          /* Entry 'Set_H': '<S2>:132' */
          /* '<S2>:132:1' Dhours = Ahours; */
          *Swatch_Y_hours = Swatch_DW->Ahours;
        } else {
          /* '<S2>:113:1' sf_internal_predicateOutput = timesetmode; */
          if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
            /* Transition: '<S2>:113' */
            /* Exit Internal 'StopWatch': '<S2>:34' */
            Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
            Swatch_DW->is_interface = Swatch_IN_TimeSetting;

            /* Outport: '<Root>/mode' */
            /* Entry 'TimeSetting': '<S2>:32' */
            /* '<S2>:32:1' mode = uint8(1) */
            *Swatch_Y_mode = 1U;

            /* Entry Internal 'TimeSetting': '<S2>:32' */
            /* Transition: '<S2>:165' */
            Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

            /* Outport: '<Root>/hours' */
            /* Entry 'Set_H': '<S2>:168' */
            /* '<S2>:168:1' Dhours = hours; */
            *Swatch_Y_hours = Swatch_DW->hours;
          } else {
            switch (Swatch_DW->is_StopWatch) {
             case Swatch_IN_S_Pause_With_Update:
              /* During 'S_Pause_With_Update': '<S2>:231' */
              /* '<S2>:233:1' sf_internal_predicateOutput = minusbutton; */
              if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
                /* Transition: '<S2>:233' */
                Swatch_DW->is_StopWatch = Swatch_IN_S_Start;

                /* Outport: '<Root>/hours' */
                /* Entry 'S_Start': '<S2>:226' */
                /* '<S2>:226:1' Dhours = Shours; */
                *Swatch_Y_hours = Swatch_DW->Shours;

                /* Outport: '<Root>/minutes' */
                /* '<S2>:226:1' Dminutes =Sminutes; */
                *Swatch_Y_minutes = Swatch_DW->Sminutes;

                /* Outport: '<Root>/seconds' */
                /* '<S2>:226:1' Dseconds = Sseconds; */
                *Swatch_Y_seconds = Swatch_DW->Sseconds;

                /* Outport: '<Root>/tenths' */
                /* '<S2>:226:3' Dtenths = Stenths */
                *Swatch_Y_tenths = Swatch_DW->Stenths;
              }
              break;

             case Swatch_IN_S_Start:
              /* During 'S_Start': '<S2>:226' */
              /* '<S2>:227:1' sf_internal_predicateOutput = plusbutton; */
              if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
                /* Transition: '<S2>:227' */
                /* '<S2>:227:1' StopW_Stop */
                /* Event: '<S2>:9' */
                b_previousEvent = Swatch_DW->sfEvent;
                Swatch_DW->sfEvent = Swatch_event_StopW_Stop;

                /* Chart: '<S1>/StopWatch2018' */
                Swatch_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
                                 Swatch_Y_seconds, Swatch_Y_tenths,
                                 Swatch_Y_mode, Swatch_DW);
                Swatch_DW->sfEvent = b_previousEvent;
                if (Swatch_DW->is_StopWatch == Swatch_IN_S_Start) {
                  Swatch_DW->is_StopWatch = Swatch_IN_Wait_SWatch;

                  /* Entry 'Wait_SWatch': '<S2>:176' */
                }
              } else {
                /* '<S2>:232:1' sf_internal_predicateOutput = minusbutton; */
                if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
                  /* Transition: '<S2>:232' */
                  Swatch_DW->is_StopWatch = Swatch_IN_S_Pause_With_Update;
                } else {
                  /* Outport: '<Root>/hours' */
                  /* '<S2>:226:1' Dhours = Shours; */
                  *Swatch_Y_hours = Swatch_DW->Shours;

                  /* Outport: '<Root>/minutes' */
                  /* '<S2>:226:1' Dminutes =Sminutes; */
                  *Swatch_Y_minutes = Swatch_DW->Sminutes;

                  /* Outport: '<Root>/seconds' */
                  /* '<S2>:226:1' Dseconds = Sseconds; */
                  *Swatch_Y_seconds = Swatch_DW->Sseconds;

                  /* Outport: '<Root>/tenths' */
                  /* '<S2>:226:2' Dtenths = Stenths */
                  *Swatch_Y_tenths = Swatch_DW->Stenths;
                }
              }
              break;

             case Swatch_IN_Wait_SWatch:
              /* During 'Wait_SWatch': '<S2>:176' */
              /* '<S2>:196:1' sf_internal_predicateOutput = plusbutton; */
              if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
                /* Transition: '<S2>:196' */
                /* '<S2>:196:1' StopW_Start */
                /* Event: '<S2>:8' */
                b_previousEvent = Swatch_DW->sfEvent;
                Swatch_DW->sfEvent = Swatch_event_StopW_Start;

                /* Chart: '<S1>/StopWatch2018' */
                Swatch_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
                                 Swatch_Y_seconds, Swatch_Y_tenths,
                                 Swatch_Y_mode, Swatch_DW);
                Swatch_DW->sfEvent = b_previousEvent;
                if (Swatch_DW->is_StopWatch == Swatch_IN_Wait_SWatch) {
                  Swatch_DW->is_StopWatch = Swatch_IN_S_Start;

                  /* Outport: '<Root>/hours' */
                  /* Entry 'S_Start': '<S2>:226' */
                  /* '<S2>:226:1' Dhours = Shours; */
                  *Swatch_Y_hours = Swatch_DW->Shours;

                  /* Outport: '<Root>/minutes' */
                  /* '<S2>:226:1' Dminutes =Sminutes; */
                  *Swatch_Y_minutes = Swatch_DW->Sminutes;

                  /* Outport: '<Root>/seconds' */
                  /* '<S2>:226:1' Dseconds = Sseconds; */
                  *Swatch_Y_seconds = Swatch_DW->Sseconds;

                  /* Outport: '<Root>/tenths' */
                  /* '<S2>:226:3' Dtenths = Stenths */
                  *Swatch_Y_tenths = Swatch_DW->Stenths;
                }
              } else {
                /* '<S2>:208:1' sf_internal_predicateOutput = swatchmode; */
                if (Swatch_DW->sfEvent == Swatch_event_swatchmode) {
                  /* Transition: '<S2>:208' */
                  /* '<S2>:208:1' Shours = uint8(0); */
                  Swatch_DW->Shours = 0U;

                  /* '<S2>:208:1' Sminutes = uint8(0); */
                  Swatch_DW->Sminutes = 0U;

                  /* '<S2>:208:3' Sseconds = uint8(0); */
                  Swatch_DW->Sseconds = 0U;

                  /* '<S2>:208:4' Stenths = uint8(0); */
                  Swatch_DW->Stenths = 0U;

                  /* Outport: '<Root>/hours' */
                  /* '<S2>:208:5' Dhours = uint8(0); */
                  *Swatch_Y_hours = 0U;

                  /* Outport: '<Root>/minutes' */
                  /* '<S2>:208:6' Dminutes =uint8(0); */
                  *Swatch_Y_minutes = 0U;

                  /* Outport: '<Root>/seconds' */
                  /* '<S2>:208:7' Dseconds = uint8(0); */
                  *Swatch_Y_seconds = 0U;

                  /* Outport: '<Root>/tenths' */
                  /* '<S2>:208:8' Dtenths = uint8(0) */
                  *Swatch_Y_tenths = 0U;
                  Swatch_DW->is_StopWatch = Swatch_IN_Wait_SWatch;

                  /* Entry 'Wait_SWatch': '<S2>:176' */
                }
              }
              break;

             default:
              /* Unreachable state, for coverage only */
              Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
              break;
            }
          }
        }
        break;

       case Swatch_IN_TimeDisplay:
        /* Outport: '<Root>/mode' */
        *Swatch_Y_mode = 0U;

        /* During 'TimeDisplay': '<S2>:31' */
        /* '<S2>:100:1' sf_internal_predicateOutput = alarmmode; */
        if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
          /* Transition: '<S2>:100' */
          Swatch_DW->is_interface = Swatch_IN_Alarm;

          /* Outport: '<Root>/mode' */
          /* Entry 'Alarm': '<S2>:33' */
          /* '<S2>:33:1' mode = uint8(2) */
          *Swatch_Y_mode = 2U;

          /* Entry Internal 'Alarm': '<S2>:33' */
          /* Transition: '<S2>:136' */
          Swatch_DW->is_Alarm = Swatch_IN_Set_H;

          /* Outport: '<Root>/hours' */
          /* Entry 'Set_H': '<S2>:132' */
          /* '<S2>:132:1' Dhours = Ahours; */
          *Swatch_Y_hours = Swatch_DW->Ahours;
        } else {
          /* '<S2>:112:1' sf_internal_predicateOutput = timesetmode; */
          if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
            /* Transition: '<S2>:112' */
            Swatch_DW->is_interface = Swatch_IN_TimeSetting;

            /* Outport: '<Root>/mode' */
            /* Entry 'TimeSetting': '<S2>:32' */
            /* '<S2>:32:1' mode = uint8(1) */
            *Swatch_Y_mode = 1U;

            /* Entry Internal 'TimeSetting': '<S2>:32' */
            /* Transition: '<S2>:165' */
            Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

            /* Outport: '<Root>/hours' */
            /* Entry 'Set_H': '<S2>:168' */
            /* '<S2>:168:1' Dhours = hours; */
            *Swatch_Y_hours = Swatch_DW->hours;
          } else {
            /* Outport: '<Root>/hours' */
            /* '<S2>:31:1' Dhours = hours; */
            *Swatch_Y_hours = Swatch_DW->hours;

            /* Outport: '<Root>/minutes' */
            /* '<S2>:31:1' Dminutes = minutes; */
            *Swatch_Y_minutes = Swatch_DW->minutes;

            /* Outport: '<Root>/tenths' */
            /* '<S2>:31:3' Dtenths = tenths; */
            *Swatch_Y_tenths = Swatch_DW->tenths;

            /* Outport: '<Root>/seconds' */
            /* '<S2>:31:3' Dseconds = seconds */
            *Swatch_Y_seconds = Swatch_DW->seconds;
          }
        }
        break;

       case Swatch_IN_TimeSetting:
        /* Outport: '<Root>/mode' */
        *Swatch_Y_mode = 1U;

        /* During 'TimeSetting': '<S2>:32' */
        /* '<S2>:104:1' sf_internal_predicateOutput = alarmmode; */
        if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
          /* Transition: '<S2>:104' */
          /* Exit Internal 'TimeSetting': '<S2>:32' */
          Swatch_DW->is_TimeSetting = Swatch_IN_NO_ACTIVE_CHILD;
          Swatch_DW->is_interface = Swatch_IN_Alarm;

          /* Outport: '<Root>/mode' */
          /* Entry 'Alarm': '<S2>:33' */
          /* '<S2>:33:1' mode = uint8(2) */
          *Swatch_Y_mode = 2U;

          /* Entry Internal 'Alarm': '<S2>:33' */
          /* Transition: '<S2>:136' */
          Swatch_DW->is_Alarm = Swatch_IN_Set_H;

          /* Outport: '<Root>/hours' */
          /* Entry 'Set_H': '<S2>:132' */
          /* '<S2>:132:1' Dhours = Ahours; */
          *Swatch_Y_hours = Swatch_DW->Ahours;
        } else {
          switch (Swatch_DW->is_TimeSetting) {
           case Swatch_IN_Set_H:
            /* During 'Set_H': '<S2>:168' */
            /* '<S2>:171:1' sf_internal_predicateOutput = timesetmode; */
            if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
              /* Transition: '<S2>:171' */
              Swatch_DW->is_TimeSetting = Swatch_IN_Set_M;

              /* Outport: '<Root>/minutes' */
              /* Entry 'Set_M': '<S2>:169' */
              /* '<S2>:169:1' Dminutes = minutes */
              *Swatch_Y_minutes = Swatch_DW->minutes;
            } else {
              /* '<S2>:167:1' sf_internal_predicateOutput = plusbutton; */
              if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
                /* Transition: '<S2>:167' */
                /* '<S2>:159:1' sf_internal_predicateOutput = hours < 23; */
                if (Swatch_DW->hours < 23) {
                  /* Transition: '<S2>:159' */
                  /* '<S2>:159:1' hours = hours +1; */
                  b_previousEvent = (int32_T)(Swatch_DW->hours + 1U);
                  if ((uint32_T)b_previousEvent > 255U) {
                    b_previousEvent = 255;
                  }

                  Swatch_DW->hours = (uint8_T)b_previousEvent;
                  guard3 = true;
                } else {
                  /* '<S2>:166:1' sf_internal_predicateOutput = hours == 23; */
                  if (Swatch_DW->hours == 23) {
                    /* Transition: '<S2>:166' */
                    /* '<S2>:166:1' hours = uint8(0); */
                    Swatch_DW->hours = 0U;
                    guard3 = true;
                  } else {
                    guard6 = true;
                  }
                }
              } else {
                guard6 = true;
              }
            }
            break;

           case Swatch_IN_Set_M:
            /* During 'Set_M': '<S2>:169' */
            /* '<S2>:175:1' sf_internal_predicateOutput = plusbutton; */
            if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
              /* Transition: '<S2>:175' */
              /* '<S2>:172:1' sf_internal_predicateOutput = minutes == 59; */
              if (Swatch_DW->minutes == 59) {
                /* Transition: '<S2>:172' */
                /* '<S2>:172:1' minutes = uint8(0); */
                Swatch_DW->minutes = 0U;
              } else {
                /* Transition: '<S2>:173' */
                /* '<S2>:173:1' minutes = minutes +1; */
                b_previousEvent = (int32_T)(Swatch_DW->minutes + 1U);
                if ((uint32_T)b_previousEvent > 255U) {
                  b_previousEvent = 255;
                }

                Swatch_DW->minutes = (uint8_T)b_previousEvent;
              }

              guard4 = true;
            } else {
              /* '<S2>:155:1' sf_internal_predicateOutput = minusbutton; */
              if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
                /* Transition: '<S2>:155' */
                /* '<S2>:158:1' sf_internal_predicateOutput = minutes ==0; */
                if (Swatch_DW->minutes == 0) {
                  /* Transition: '<S2>:158' */
                  /* '<S2>:158:1' minutes = 59; */
                  Swatch_DW->minutes = 59U;
                } else {
                  /* Transition: '<S2>:157' */
                  /* '<S2>:157:1' minutes = minutes -1; */
                  qY = Swatch_DW->minutes - 1U;
                  if (qY > Swatch_DW->minutes) {
                    qY = 0U;
                  }

                  Swatch_DW->minutes = (uint8_T)qY;
                }

                guard4 = true;
              } else {
                /* '<S2>:170:1' sf_internal_predicateOutput = timesetmode; */
                if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
                  /* Transition: '<S2>:170' */
                  Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

                  /* Outport: '<Root>/hours' */
                  /* Entry 'Set_H': '<S2>:168' */
                  /* '<S2>:168:1' Dhours = hours; */
                  *Swatch_Y_hours = Swatch_DW->hours;
                } else {
                  /* Outport: '<Root>/minutes' */
                  /* '<S2>:169:1' Dminutes = minutes */
                  *Swatch_Y_minutes = Swatch_DW->minutes;
                }
              }
            }
            break;

           default:
            /* Unreachable state, for coverage only */
            Swatch_DW->is_TimeSetting = Swatch_IN_NO_ACTIVE_CHILD;
            break;
          }
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        Swatch_DW->is_interface = Swatch_IN_NO_ACTIVE_CHILD;
        break;
      }

      if (guard6) {
        /* '<S2>:162:1' sf_internal_predicateOutput = minusbutton; */
        if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
          /* Transition: '<S2>:162' */
          /* '<S2>:163:1' sf_internal_predicateOutput = hours ==0; */
          if (Swatch_DW->hours == 0) {
            /* Transition: '<S2>:163' */
            /* '<S2>:163:1' hours = 23; */
            Swatch_DW->hours = 23U;
          } else {
            /* Transition: '<S2>:161' */
            /* '<S2>:161:1' hours = hours -1; */
            qY = Swatch_DW->hours - 1U;
            if (qY > Swatch_DW->hours) {
              qY = 0U;
            }

            Swatch_DW->hours = (uint8_T)qY;
          }

          guard3 = true;
        } else {
          /* Outport: '<Root>/hours' */
          /* '<S2>:168:1' Dhours = hours; */
          *Swatch_Y_hours = Swatch_DW->hours;
        }
      }

      if (guard5) {
        /* '<S2>:146:1' sf_internal_predicateOutput = minusbutton; */
        if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
          /* Transition: '<S2>:146' */
          /* '<S2>:145:1' sf_internal_predicateOutput = Ahours ==0; */
          if (Swatch_DW->Ahours == 0) {
            /* Transition: '<S2>:145' */
            /* '<S2>:145:1' Ahours = 23; */
            Swatch_DW->Ahours = 23U;
          } else {
            /* Transition: '<S2>:143' */
            /* '<S2>:143:1' Ahours = Ahours -1; */
            qY = Swatch_DW->Ahours - 1U;
            if (qY > Swatch_DW->Ahours) {
              qY = 0U;
            }

            Swatch_DW->Ahours = (uint8_T)qY;
          }

          guard1 = true;
        } else {
          /* '<S2>:128:1' sf_internal_predicateOutput = alarmmode; */
          if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
            /* Transition: '<S2>:128' */
            Swatch_DW->is_Alarm = Swatch_IN_Set_M;

            /* Outport: '<Root>/minutes' */
            /* Entry 'Set_M': '<S2>:133' */
            /* '<S2>:133:1' Dminutes = Aminutes */
            *Swatch_Y_minutes = Swatch_DW->Aminutes;
          } else {
            /* Outport: '<Root>/hours' */
            /* '<S2>:132:1' Dhours = Ahours; */
            *Swatch_Y_hours = Swatch_DW->Ahours;
          }
        }
      }

      if (guard4) {
        Swatch_DW->is_TimeSetting = Swatch_IN_Set_M;

        /* Outport: '<Root>/minutes' */
        /* Entry 'Set_M': '<S2>:169' */
        /* '<S2>:169:1' Dminutes = minutes */
        *Swatch_Y_minutes = Swatch_DW->minutes;
      }

      if (guard3) {
        Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S2>:168' */
        /* '<S2>:168:1' Dhours = hours; */
        *Swatch_Y_hours = Swatch_DW->hours;
      }

      if (guard2) {
        Swatch_DW->is_Alarm = Swatch_IN_Set_M;

        /* Outport: '<Root>/minutes' */
        /* Entry 'Set_M': '<S2>:133' */
        /* '<S2>:133:1' Dminutes = Aminutes */
        *Swatch_Y_minutes = Swatch_DW->Aminutes;
      }

      if (guard1) {
        Swatch_DW->is_Alarm = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S2>:132' */
        /* '<S2>:132:1' Dhours = Ahours; */
        *Swatch_Y_hours = Swatch_DW->Ahours;
      }
    }
  }
}

/* Function for Chart: '<S1>/StopWatch2018' */
static void Swatch_c3_Swatch(uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes,
  uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode,
  DW_Swatch_T *Swatch_DW)
{
  int32_T tmp;

  /* Chart: '<S1>/StopWatch2018' */
  /* During: Swatch/StopWatch2018 */
  if (Swatch_DW->is_active_c3_Swatch == 0U) {
    /* Entry: Swatch/StopWatch2018 */
    Swatch_DW->is_active_c3_Swatch = 1U;

    /* Entry Internal: Swatch/StopWatch2018 */
    /* Transition: '<S2>:45' */
    Swatch_DW->is_active_AlarmManagement = 1U;

    /* Entry Internal 'AlarmManagement': '<S2>:29' */
    /* Transition: '<S2>:75' */
    Swatch_DW->is_AlarmManagement = Swatch_IN_Checking;
    Swatch_DW->is_active_TimeCount = 1U;

    /* Outport: '<Root>/tenths' */
    /* Entry 'TimeCount': '<S2>:25' */
    /* Entry Internal 'TimeCount': '<S2>:25' */
    /* Transition: '<S2>:48' */
    /* '<S2>:48:1' Dtenths = uint8(0); */
    *Swatch_Y_tenths = 0U;

    /* '<S2>:48:1' tenths = uint8(0); */
    Swatch_DW->is_TimeCount = Swatch_IN_Count;

    /* Entry 'Count': '<S2>:47' */
    Swatch_DW->is_active_TimeCountStopWatch = 1U;

    /* Entry 'TimeCountStopWatch': '<S2>:27' */
    /* Entry Internal 'TimeCountStopWatch': '<S2>:27' */
    /* Transition: '<S2>:219' */
    Swatch_DW->is_TimeCountStopWatch = Swatch_IN_S_Count;

    /* Entry 'S_Count': '<S2>:190' */
    Swatch_DW->is_active_interface = 1U;

    /* Entry 'interface': '<S2>:28' */
    /* Entry Internal 'interface': '<S2>:28' */
    /* Transition: '<S2>:38' */
    /* '<S2>:38:1' hours = uint8(1); */
    Swatch_DW->hours = 1U;

    /* '<S2>:38:1' minutes = uint8(0); */
    Swatch_DW->minutes = 0U;

    /* '<S2>:38:1' seconds = uint8(45); */
    Swatch_DW->seconds = 45U;

    /* '<S2>:38:2' tenths = uint8(0); */
    Swatch_DW->tenths = 0U;

    /* '<S2>:38:3' Aminutes = uint8(1); */
    Swatch_DW->Aminutes = 1U;

    /* '<S2>:38:4' Ahours = uint8(1); */
    Swatch_DW->Ahours = 1U;

    /* '<S2>:38:5' Shours = uint8(0); */
    Swatch_DW->Shours = 0U;

    /* '<S2>:38:6' Sminutes = uint8(0); */
    Swatch_DW->Sminutes = 0U;

    /* '<S2>:38:7' Sseconds = uint8(0); */
    Swatch_DW->Sseconds = 0U;

    /* '<S2>:38:9' Stenths = uint8(0) */
    Swatch_DW->Stenths = 0U;
    Swatch_DW->is_interface = Swatch_IN_TimeDisplay;

    /* Outport: '<Root>/mode' */
    /* Entry 'TimeDisplay': '<S2>:31' */
    /* '<S2>:31:1' mode = uint8(0) */
    *Swatch_Y_mode = 0U;
  } else {
    if (Swatch_DW->is_active_AlarmManagement != 0U) {
      /* During 'AlarmManagement': '<S2>:29' */
      switch (Swatch_DW->is_AlarmManagement) {
       case Swatch_IN_Buzzer_ON:
        /* During 'Buzzer_ON': '<S2>:76' */
        /* '<S2>:72:1' sf_internal_predicateOutput = Ahours ~= hours || Aminutes ~= minutes; */
        if ((Swatch_DW->Ahours != Swatch_DW->hours) || (Swatch_DW->Aminutes !=
             Swatch_DW->minutes)) {
          /* Transition: '<S2>:72' */
          Swatch_DW->is_AlarmManagement = Swatch_IN_Checking;
        }
        break;

       case Swatch_IN_Checking:
        /* During 'Checking': '<S2>:74' */
        /* '<S2>:71:1' sf_internal_predicateOutput = Ahours == hours && Aminutes == minutes; */
        if ((Swatch_DW->Ahours == Swatch_DW->hours) && (Swatch_DW->Aminutes ==
             Swatch_DW->minutes)) {
          /* Transition: '<S2>:71' */
          Swatch_DW->is_AlarmManagement = Swatch_IN_Buzzer_ON;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        Swatch_DW->is_AlarmManagement = Swatch_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if ((Swatch_DW->is_active_TimeCount != 0U) && (Swatch_DW->is_TimeCount ==
         Swatch_IN_Count) && (Swatch_DW->sfEvent == Swatch_event_Tick)) {
      /* During 'TimeCount': '<S2>:25' */
      /* During 'Count': '<S2>:47' */
      /* '<S2>:56:1' sf_internal_predicateOutput = Tick; */
      /* Transition: '<S2>:56' */
      /* '<S2>:53:1' sf_internal_predicateOutput = tenths == 9; */
      if (Swatch_DW->tenths == 9) {
        /* Transition: '<S2>:53' */
        /* '<S2>:53:1' tenths = uint8(0); */
        Swatch_DW->tenths = 0U;

        /* '<S2>:54:1' sf_internal_predicateOutput = seconds == 59; */
        if (Swatch_DW->seconds == 59) {
          /* Transition: '<S2>:54' */
          /* '<S2>:54:1' seconds = uint8(0); */
          Swatch_DW->seconds = 0U;

          /* '<S2>:55:1' sf_internal_predicateOutput = minutes == 59; */
          if (Swatch_DW->minutes == 59) {
            /* Transition: '<S2>:55' */
            /* '<S2>:55:1' minutes = uint8(0); */
            Swatch_DW->minutes = 0U;

            /* Transition: '<S2>:60' */
            /* '<S2>:60:1' hours = hours +1 */
            tmp = (int32_T)(Swatch_DW->hours + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Swatch_DW->hours = (uint8_T)tmp;
          } else {
            /* Transition: '<S2>:59' */
            /* '<S2>:59:1' minutes = minutes +1; */
            tmp = (int32_T)(Swatch_DW->minutes + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Swatch_DW->minutes = (uint8_T)tmp;
          }
        } else {
          /* Transition: '<S2>:58' */
          /* '<S2>:58:1' seconds = seconds + 1; */
          tmp = (int32_T)(Swatch_DW->seconds + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Swatch_DW->seconds = (uint8_T)tmp;
        }
      } else {
        /* Transition: '<S2>:57' */
        /* '<S2>:57:1' tenths = tenths +1; */
        tmp = (int32_T)(Swatch_DW->tenths + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Swatch_DW->tenths = (uint8_T)tmp;
      }

      Swatch_DW->is_TimeCount = Swatch_IN_Count;

      /* Entry 'Count': '<S2>:47' */
    }

    if (Swatch_DW->is_active_TimeCountStopWatch != 0U) {
      /* During 'TimeCountStopWatch': '<S2>:27' */
      /* '<S2>:223:1' sf_internal_predicateOutput = StopW_Start; */
      if (Swatch_DW->sfEvent == Swatch_event_StopW_Start) {
        /* Transition: '<S2>:223' */
        /* Exit Internal 'TimeCountStopWatch': '<S2>:27' */
        Swatch_DW->is_TimeCountStopWatch = Swatch_IN_S_Count;

        /* Entry 'S_Count': '<S2>:190' */
      } else {
        switch (Swatch_DW->is_TimeCountStopWatch) {
         case Swatch_IN_S_Count:
          /* During 'S_Count': '<S2>:190' */
          /* '<S2>:221:1' sf_internal_predicateOutput = Tick; */
          if (Swatch_DW->sfEvent == Swatch_event_Tick) {
            /* Transition: '<S2>:221' */
            /* '<S2>:182:1' sf_internal_predicateOutput = Stenths == 9; */
            if (Swatch_DW->Stenths == 9) {
              /* Transition: '<S2>:182' */
              /* '<S2>:182:1' Stenths = uint8(0); */
              Swatch_DW->Stenths = 0U;

              /* '<S2>:189:1' sf_internal_predicateOutput = Sseconds == 59; */
              if (Swatch_DW->Sseconds == 59) {
                /* Transition: '<S2>:189' */
                /* '<S2>:189:1' Sseconds = uint8(0); */
                Swatch_DW->Sseconds = 0U;

                /* '<S2>:191:1' sf_internal_predicateOutput = Sminutes == 59; */
                if (Swatch_DW->Sminutes == 59) {
                  /* Transition: '<S2>:191' */
                  /* '<S2>:191:1' Sminutes = uint8(0); */
                  Swatch_DW->Sminutes = 0U;

                  /* '<S2>:183:1' sf_internal_predicateOutput = Shours == 24; */
                  if (Swatch_DW->Shours == 24) {
                    /* Transition: '<S2>:183' */
                    /* '<S2>:183:1' Shours = uint8(0) */
                    Swatch_DW->Shours = 0U;

                    /* Transition: '<S2>:181' */
                  } else {
                    /* Transition: '<S2>:193' */
                    /* '<S2>:193:1' Shours = hours +1 */
                    tmp = (int32_T)(Swatch_DW->hours + 1U);
                    if ((uint32_T)tmp > 255U) {
                      tmp = 255;
                    }

                    Swatch_DW->Shours = (uint8_T)tmp;
                  }
                } else {
                  /* Transition: '<S2>:184' */
                  /* '<S2>:184:1' Sminutes = Sminutes +1; */
                  tmp = (int32_T)(Swatch_DW->Sminutes + 1U);
                  if ((uint32_T)tmp > 255U) {
                    tmp = 255;
                  }

                  Swatch_DW->Sminutes = (uint8_T)tmp;
                }
              } else {
                /* Transition: '<S2>:186' */
                /* '<S2>:186:1' Sseconds = Sseconds + 1; */
                tmp = (int32_T)(Swatch_DW->Sseconds + 1U);
                if ((uint32_T)tmp > 255U) {
                  tmp = 255;
                }

                Swatch_DW->Sseconds = (uint8_T)tmp;
              }
            } else {
              /* Transition: '<S2>:178' */
              /* '<S2>:178:1' Stenths = Stenths +1; */
              tmp = (int32_T)(Swatch_DW->Stenths + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              Swatch_DW->Stenths = (uint8_T)tmp;
            }

            Swatch_DW->is_TimeCountStopWatch = Swatch_IN_S_Count;

            /* Entry 'S_Count': '<S2>:190' */
          } else {
            /* '<S2>:230:1' sf_internal_predicateOutput = plusbutton; */
            if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
              /* Transition: '<S2>:230' */
              Swatch_DW->is_TimeCountStopWatch = Swatch_IN_Stop_WithOut_Update;
            }
          }
          break;

         case Swatch_IN_Stop_WithOut_Update:
          break;

         default:
          /* Unreachable state, for coverage only */
          Swatch_DW->is_TimeCountStopWatch = Swatch_IN_NO_ACTIVE_CHILD;
          break;
        }
      }
    }

    if (Swatch_DW->is_active_interface != 0U) {
      Swatch_interface(Swatch_Y_hours, Swatch_Y_minutes, Swatch_Y_seconds,
                       Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }
  }

  /* End of Chart: '<S1>/StopWatch2018' */
}

/* Function for Chart: '<S1>/StopWatch2018' */
static void Swatch_chartstep_c3_Swatch(uint8_T *Swatch_Y_hours, uint8_T
  *Swatch_Y_minutes, uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths,
  uint8_T *Swatch_Y_mode, DW_Swatch_T *Swatch_DW)
{
  Swatch_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes, Swatch_Y_seconds,
                   Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
}

/* Model step function */
void Swatch_step(RT_MODEL_Swatch_T *const Swatch_M, boolean_T Swatch_U_Tick,
                 boolean_T Swatch_U_plusbutton, boolean_T Swatch_U_minusbutton,
                 boolean_T Swatch_U_timemode, boolean_T Swatch_U_timesetmode,
                 boolean_T Swatch_U_alarmmode, boolean_T Swatch_U_swatchmode,
                 uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes, uint8_T
                 *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T
                 *Swatch_Y_mode)
{
  DW_Swatch_T *Swatch_DW = ((DW_Swatch_T *) Swatch_M->dwork);
  PrevZCX_Swatch_T *Swatch_PrevZCX = ((PrevZCX_Swatch_T *)
    Swatch_M->prevZCSigState);
  boolean_T zcEvent[7];
  int8_T rtb_inputevents[7];
  int32_T i;
  boolean_T zcEvent_0;

  /* Chart: '<S1>/StopWatch2018' incorporates:
   *  TriggerPort: '<S2>/input events'
   */
  /* Inport: '<Root>/Tick ' */
  zcEvent[0] = (Swatch_U_Tick && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[0] !=
    POS_ZCSIG));

  /* Inport: '<Root>/plusbutton' */
  zcEvent[1] = (Swatch_U_plusbutton && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[1]
    != POS_ZCSIG));

  /* Inport: '<Root>/minusbutton' */
  zcEvent[2] = (Swatch_U_minusbutton && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE
    [2] != POS_ZCSIG));

  /* Inport: '<Root>/timemode' */
  zcEvent[3] = (Swatch_U_timemode && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[3]
    != POS_ZCSIG));

  /* Inport: '<Root>/timesetmode' */
  zcEvent[4] = (Swatch_U_timesetmode && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE
    [4] != POS_ZCSIG));

  /* Inport: '<Root>/alarmmode' */
  zcEvent[5] = (Swatch_U_alarmmode && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[5]
    != POS_ZCSIG));

  /* Inport: '<Root>/swatchmode' */
  zcEvent[6] = (Swatch_U_swatchmode && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[6]
    != POS_ZCSIG));
  zcEvent_0 = false;
  for (i = 0; i < 7; i++) {
    zcEvent_0 = (zcEvent_0 || zcEvent[i]);
  }

  if (zcEvent_0) {
    for (i = 0; i < 7; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    /* Gateway: Swatch/StopWatch2018 */
    if (rtb_inputevents[0U] == 1) {
      /* Event: '<S2>:2' */
      Swatch_DW->sfEvent = Swatch_event_Tick;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[1U] == 1) {
      /* Event: '<S2>:1' */
      Swatch_DW->sfEvent = Swatch_event_plusbutton;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[2U] == 1) {
      /* Event: '<S2>:3' */
      Swatch_DW->sfEvent = Swatch_event_minusbutton;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[3U] == 1) {
      /* Event: '<S2>:4' */
      Swatch_DW->sfEvent = Swatch_event_timemode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[4U] == 1) {
      /* Event: '<S2>:5' */
      Swatch_DW->sfEvent = Swatch_event_timesetmode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[5U] == 1) {
      /* Event: '<S2>:6' */
      Swatch_DW->sfEvent = Swatch_event_alarmmode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[6U] == 1) {
      /* Event: '<S2>:7' */
      Swatch_DW->sfEvent = Swatch_event_swatchmode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }
  }

  /* Inport: '<Root>/Tick ' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[0] = Swatch_U_Tick;

  /* Inport: '<Root>/plusbutton' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[1] = Swatch_U_plusbutton;

  /* Inport: '<Root>/minusbutton' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[2] = Swatch_U_minusbutton;

  /* Inport: '<Root>/timemode' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[3] = Swatch_U_timemode;

  /* Inport: '<Root>/timesetmode' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[4] = Swatch_U_timesetmode;

  /* Inport: '<Root>/alarmmode' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[5] = Swatch_U_alarmmode;

  /* Inport: '<Root>/swatchmode' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[6] = Swatch_U_swatchmode;
}

/* Model initialize function */
void Swatch_initialize(RT_MODEL_Swatch_T *const Swatch_M, boolean_T
  *Swatch_U_Tick, boolean_T *Swatch_U_plusbutton, boolean_T
  *Swatch_U_minusbutton, boolean_T *Swatch_U_timemode, boolean_T
  *Swatch_U_timesetmode, boolean_T *Swatch_U_alarmmode, boolean_T
  *Swatch_U_swatchmode, uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes,
  uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode)
{
  DW_Swatch_T *Swatch_DW = ((DW_Swatch_T *) Swatch_M->dwork);
  PrevZCX_Swatch_T *Swatch_PrevZCX = ((PrevZCX_Swatch_T *)
    Swatch_M->prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)Swatch_DW, 0,
                sizeof(DW_Swatch_T));

  /* external inputs */
  *Swatch_U_Tick = false;
  *Swatch_U_plusbutton = false;
  *Swatch_U_minusbutton = false;
  *Swatch_U_timemode = false;
  *Swatch_U_timesetmode = false;
  *Swatch_U_alarmmode = false;
  *Swatch_U_swatchmode = false;

  /* external outputs */
  (*Swatch_Y_hours) = 0U;
  (*Swatch_Y_minutes) = 0U;
  (*Swatch_Y_seconds) = 0U;
  (*Swatch_Y_tenths) = 0U;
  (*Swatch_Y_mode) = 0U;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      Swatch_PrevZCX->StopWatch2018_Trig_ZCE[i] = POS_ZCSIG;
    }

    /* SystemInitialize for Chart: '<S1>/StopWatch2018' */
    Swatch_DW->is_active_AlarmManagement = 0U;
    Swatch_DW->is_AlarmManagement = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_active_TimeCount = 0U;
    Swatch_DW->is_TimeCount = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_active_TimeCountStopWatch = 0U;
    Swatch_DW->is_TimeCountStopWatch = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_active_interface = 0U;
    Swatch_DW->is_interface = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_Alarm = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_TimeSetting = Swatch_IN_NO_ACTIVE_CHILD;
    Swatch_DW->is_active_c3_Swatch = 0U;
  }
}

/* Model terminate function */
void Swatch_terminate(RT_MODEL_Swatch_T *const Swatch_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(Swatch_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
