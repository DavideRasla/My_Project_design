/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Swatch.c
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
  /* Exit Internal 'interface': '<S3>:28' */
  /* Exit Internal 'Alarm': '<S3>:33' */
  Swatch_DW->is_Alarm = Swatch_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'StopWatch': '<S3>:34' */
  Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;

  /* Exit Internal 'TimeSetting': '<S3>:32' */
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

  /* During 'interface': '<S3>:28' */
  if (Swatch_DW->sfEvent == Swatch_event_timemode) {
    /* Transition: '<S3>:40' */
    Swatch_exit_internal_interface(Swatch_DW);
    Swatch_DW->is_interface = Swatch_IN_TimeDisplay;

    /* Outport: '<Root>/mode' */
    /* Entry 'TimeDisplay': '<S3>:31' */
    *Swatch_Y_mode = 0U;
  } else if (Swatch_DW->sfEvent == Swatch_event_swatchmode) {
    /* Transition: '<S3>:42' */
    Swatch_exit_internal_interface(Swatch_DW);
    Swatch_DW->is_interface = Swatch_IN_StopWatch;

    /* Outport: '<Root>/mode' */
    /* Entry 'StopWatch': '<S3>:34' */
    *Swatch_Y_mode = 3U;
    Swatch_DW->Shours = 0U;
    Swatch_DW->Sminutes = 0U;
    Swatch_DW->Sseconds = 0U;
    Swatch_DW->Stenths = 0U;

    /* Outport: '<Root>/hours' */
    *Swatch_Y_hours = 0U;

    /* Outport: '<Root>/minutes' */
    *Swatch_Y_minutes = 0U;

    /* Outport: '<Root>/seconds' */
    *Swatch_Y_seconds = 0U;

    /* Outport: '<Root>/tenths' */
    *Swatch_Y_tenths = 0U;

    /* Entry Internal 'StopWatch': '<S3>:34' */
    /* Transition: '<S3>:177' */
    Swatch_DW->is_StopWatch = Swatch_IN_Wait_SWatch;

    /* Entry 'Wait_SWatch': '<S3>:176' */
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

      /* During 'Alarm': '<S3>:33' */
      if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
        /* Transition: '<S3>:103' */
        /* Exit Internal 'Alarm': '<S3>:33' */
        Swatch_DW->is_Alarm = Swatch_IN_NO_ACTIVE_CHILD;
        Swatch_DW->is_interface = Swatch_IN_TimeSetting;

        /* Outport: '<Root>/mode' */
        /* Entry 'TimeSetting': '<S3>:32' */
        *Swatch_Y_mode = 1U;

        /* Entry Internal 'TimeSetting': '<S3>:32' */
        /* Transition: '<S3>:165' */
        Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S3>:168' */
        *Swatch_Y_hours = Swatch_DW->hours;
      } else {
        switch (Swatch_DW->is_Alarm) {
         case Swatch_IN_Set_H:
          /* During 'Set_H': '<S3>:132' */
          if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
            /* Transition: '<S3>:130' */
            if (Swatch_DW->Ahours < 23) {
              /* Transition: '<S3>:140' */
              b_previousEvent = (int32_T)(Swatch_DW->Ahours + 1U);
              if ((uint32_T)b_previousEvent > 255U) {
                b_previousEvent = 255;
              }

              Swatch_DW->Ahours = (uint8_T)b_previousEvent;
              guard1 = true;
            } else if (Swatch_DW->Ahours == 23) {
              /* Transition: '<S3>:142' */
              Swatch_DW->Ahours = 0U;
              guard1 = true;
            } else {
              guard5 = true;
            }
          } else {
            guard5 = true;
          }
          break;

         case Swatch_IN_Set_M:
          /* During 'Set_M': '<S3>:133' */
          if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
            /* Transition: '<S3>:149' */
            if (Swatch_DW->Aminutes == 59) {
              /* Transition: '<S3>:150' */
              Swatch_DW->Aminutes = 0U;
            } else {
              /* Transition: '<S3>:148' */
              b_previousEvent = (int32_T)(Swatch_DW->Aminutes + 1U);
              if ((uint32_T)b_previousEvent > 255U) {
                b_previousEvent = 255;
              }

              Swatch_DW->Aminutes = (uint8_T)b_previousEvent;
            }

            guard2 = true;
          } else if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
            /* Transition: '<S3>:153' */
            if (Swatch_DW->Aminutes == 0) {
              /* Transition: '<S3>:154' */
              Swatch_DW->Aminutes = 59U;
            } else {
              /* Transition: '<S3>:152' */
              qY = Swatch_DW->Aminutes - 1U;
              if (qY > Swatch_DW->Aminutes) {
                qY = 0U;
              }

              Swatch_DW->Aminutes = (uint8_T)qY;
            }

            guard2 = true;
          } else if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
            /* Transition: '<S3>:129' */
            Swatch_DW->is_Alarm = Swatch_IN_Set_H;

            /* Outport: '<Root>/hours' */
            /* Entry 'Set_H': '<S3>:132' */
            *Swatch_Y_hours = Swatch_DW->Ahours;
          } else {
            /* Outport: '<Root>/minutes' */
            *Swatch_Y_minutes = Swatch_DW->Aminutes;
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

      /* During 'StopWatch': '<S3>:34' */
      if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
        /* Transition: '<S3>:99' */
        /* Exit Internal 'StopWatch': '<S3>:34' */
        Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
        Swatch_DW->is_interface = Swatch_IN_Alarm;

        /* Outport: '<Root>/mode' */
        /* Entry 'Alarm': '<S3>:33' */
        *Swatch_Y_mode = 2U;

        /* Entry Internal 'Alarm': '<S3>:33' */
        /* Transition: '<S3>:136' */
        Swatch_DW->is_Alarm = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S3>:132' */
        *Swatch_Y_hours = Swatch_DW->Ahours;
      } else if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
        /* Transition: '<S3>:113' */
        /* Exit Internal 'StopWatch': '<S3>:34' */
        Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
        Swatch_DW->is_interface = Swatch_IN_TimeSetting;

        /* Outport: '<Root>/mode' */
        /* Entry 'TimeSetting': '<S3>:32' */
        *Swatch_Y_mode = 1U;

        /* Entry Internal 'TimeSetting': '<S3>:32' */
        /* Transition: '<S3>:165' */
        Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S3>:168' */
        *Swatch_Y_hours = Swatch_DW->hours;
      } else {
        switch (Swatch_DW->is_StopWatch) {
         case Swatch_IN_S_Pause_With_Update:
          /* During 'S_Pause_With_Update': '<S3>:231' */
          if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
            /* Transition: '<S3>:233' */
            Swatch_DW->is_StopWatch = Swatch_IN_S_Start;

            /* Outport: '<Root>/hours' */
            /* Entry 'S_Start': '<S3>:226' */
            *Swatch_Y_hours = Swatch_DW->Shours;

            /* Outport: '<Root>/minutes' */
            *Swatch_Y_minutes = Swatch_DW->Sminutes;

            /* Outport: '<Root>/seconds' */
            *Swatch_Y_seconds = Swatch_DW->Sseconds;

            /* Outport: '<Root>/tenths' */
            *Swatch_Y_tenths = Swatch_DW->Stenths;
          }
          break;

         case Swatch_IN_S_Start:
          /* During 'S_Start': '<S3>:226' */
          if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
            /* Transition: '<S3>:227' */
            /* Event: '<S3>:9' */
            b_previousEvent = Swatch_DW->sfEvent;
            Swatch_DW->sfEvent = Swatch_event_StopW_Stop;

            /* Chart: '<S1>/StopWatch2018' */
            Swatch_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes, Swatch_Y_seconds,
                             Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
            Swatch_DW->sfEvent = b_previousEvent;
            if (Swatch_DW->is_StopWatch == Swatch_IN_S_Start) {
              Swatch_DW->is_StopWatch = Swatch_IN_Wait_SWatch;

              /* Entry 'Wait_SWatch': '<S3>:176' */
            }
          } else if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
            /* Transition: '<S3>:232' */
            Swatch_DW->is_StopWatch = Swatch_IN_S_Pause_With_Update;
          } else {
            /* Outport: '<Root>/hours' */
            *Swatch_Y_hours = Swatch_DW->Shours;

            /* Outport: '<Root>/minutes' */
            *Swatch_Y_minutes = Swatch_DW->Sminutes;

            /* Outport: '<Root>/seconds' */
            *Swatch_Y_seconds = Swatch_DW->Sseconds;

            /* Outport: '<Root>/tenths' */
            *Swatch_Y_tenths = Swatch_DW->Stenths;
          }
          break;

         case Swatch_IN_Wait_SWatch:
          /* During 'Wait_SWatch': '<S3>:176' */
          if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
            /* Transition: '<S3>:196' */
            /* Event: '<S3>:8' */
            b_previousEvent = Swatch_DW->sfEvent;
            Swatch_DW->sfEvent = Swatch_event_StopW_Start;

            /* Chart: '<S1>/StopWatch2018' */
            Swatch_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes, Swatch_Y_seconds,
                             Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
            Swatch_DW->sfEvent = b_previousEvent;
            if (Swatch_DW->is_StopWatch == Swatch_IN_Wait_SWatch) {
              Swatch_DW->is_StopWatch = Swatch_IN_S_Start;

              /* Outport: '<Root>/hours' */
              /* Entry 'S_Start': '<S3>:226' */
              *Swatch_Y_hours = Swatch_DW->Shours;

              /* Outport: '<Root>/minutes' */
              *Swatch_Y_minutes = Swatch_DW->Sminutes;

              /* Outport: '<Root>/seconds' */
              *Swatch_Y_seconds = Swatch_DW->Sseconds;

              /* Outport: '<Root>/tenths' */
              *Swatch_Y_tenths = Swatch_DW->Stenths;
            }
          } else {
            if (Swatch_DW->sfEvent == Swatch_event_swatchmode) {
              /* Transition: '<S3>:208' */
              Swatch_DW->Shours = 0U;
              Swatch_DW->Sminutes = 0U;
              Swatch_DW->Sseconds = 0U;
              Swatch_DW->Stenths = 0U;

              /* Outport: '<Root>/hours' */
              *Swatch_Y_hours = 0U;

              /* Outport: '<Root>/minutes' */
              *Swatch_Y_minutes = 0U;

              /* Outport: '<Root>/seconds' */
              *Swatch_Y_seconds = 0U;

              /* Outport: '<Root>/tenths' */
              *Swatch_Y_tenths = 0U;
              Swatch_DW->is_StopWatch = Swatch_IN_Wait_SWatch;

              /* Entry 'Wait_SWatch': '<S3>:176' */
            }
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          Swatch_DW->is_StopWatch = Swatch_IN_NO_ACTIVE_CHILD;
          break;
        }
      }
      break;

     case Swatch_IN_TimeDisplay:
      /* Outport: '<Root>/mode' */
      *Swatch_Y_mode = 0U;

      /* During 'TimeDisplay': '<S3>:31' */
      if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
        /* Transition: '<S3>:100' */
        Swatch_DW->is_interface = Swatch_IN_Alarm;

        /* Outport: '<Root>/mode' */
        /* Entry 'Alarm': '<S3>:33' */
        *Swatch_Y_mode = 2U;

        /* Entry Internal 'Alarm': '<S3>:33' */
        /* Transition: '<S3>:136' */
        Swatch_DW->is_Alarm = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S3>:132' */
        *Swatch_Y_hours = Swatch_DW->Ahours;
      } else if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
        /* Transition: '<S3>:112' */
        Swatch_DW->is_interface = Swatch_IN_TimeSetting;

        /* Outport: '<Root>/mode' */
        /* Entry 'TimeSetting': '<S3>:32' */
        *Swatch_Y_mode = 1U;

        /* Entry Internal 'TimeSetting': '<S3>:32' */
        /* Transition: '<S3>:165' */
        Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S3>:168' */
        *Swatch_Y_hours = Swatch_DW->hours;
      } else {
        /* Outport: '<Root>/hours' */
        *Swatch_Y_hours = Swatch_DW->hours;

        /* Outport: '<Root>/minutes' */
        *Swatch_Y_minutes = Swatch_DW->minutes;

        /* Outport: '<Root>/tenths' */
        *Swatch_Y_tenths = Swatch_DW->tenths;

        /* Outport: '<Root>/seconds' */
        *Swatch_Y_seconds = Swatch_DW->seconds;
      }
      break;

     case Swatch_IN_TimeSetting:
      /* Outport: '<Root>/mode' */
      *Swatch_Y_mode = 1U;

      /* During 'TimeSetting': '<S3>:32' */
      if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
        /* Transition: '<S3>:104' */
        /* Exit Internal 'TimeSetting': '<S3>:32' */
        Swatch_DW->is_TimeSetting = Swatch_IN_NO_ACTIVE_CHILD;
        Swatch_DW->is_interface = Swatch_IN_Alarm;

        /* Outport: '<Root>/mode' */
        /* Entry 'Alarm': '<S3>:33' */
        *Swatch_Y_mode = 2U;

        /* Entry Internal 'Alarm': '<S3>:33' */
        /* Transition: '<S3>:136' */
        Swatch_DW->is_Alarm = Swatch_IN_Set_H;

        /* Outport: '<Root>/hours' */
        /* Entry 'Set_H': '<S3>:132' */
        *Swatch_Y_hours = Swatch_DW->Ahours;
      } else {
        switch (Swatch_DW->is_TimeSetting) {
         case Swatch_IN_Set_H:
          /* During 'Set_H': '<S3>:168' */
          if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
            /* Transition: '<S3>:171' */
            Swatch_DW->is_TimeSetting = Swatch_IN_Set_M;

            /* Outport: '<Root>/minutes' */
            /* Entry 'Set_M': '<S3>:169' */
            *Swatch_Y_minutes = Swatch_DW->minutes;
          } else if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
            /* Transition: '<S3>:167' */
            if (Swatch_DW->hours < 23) {
              /* Transition: '<S3>:159' */
              b_previousEvent = (int32_T)(Swatch_DW->hours + 1U);
              if ((uint32_T)b_previousEvent > 255U) {
                b_previousEvent = 255;
              }

              Swatch_DW->hours = (uint8_T)b_previousEvent;
              guard3 = true;
            } else if (Swatch_DW->hours == 23) {
              /* Transition: '<S3>:166' */
              Swatch_DW->hours = 0U;
              guard3 = true;
            } else {
              guard6 = true;
            }
          } else {
            guard6 = true;
          }
          break;

         case Swatch_IN_Set_M:
          /* During 'Set_M': '<S3>:169' */
          if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
            /* Transition: '<S3>:175' */
            if (Swatch_DW->minutes == 59) {
              /* Transition: '<S3>:172' */
              Swatch_DW->minutes = 0U;
            } else {
              /* Transition: '<S3>:173' */
              b_previousEvent = (int32_T)(Swatch_DW->minutes + 1U);
              if ((uint32_T)b_previousEvent > 255U) {
                b_previousEvent = 255;
              }

              Swatch_DW->minutes = (uint8_T)b_previousEvent;
            }

            guard4 = true;
          } else if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
            /* Transition: '<S3>:155' */
            if (Swatch_DW->minutes == 0) {
              /* Transition: '<S3>:158' */
              Swatch_DW->minutes = 59U;
            } else {
              /* Transition: '<S3>:157' */
              qY = Swatch_DW->minutes - 1U;
              if (qY > Swatch_DW->minutes) {
                qY = 0U;
              }

              Swatch_DW->minutes = (uint8_T)qY;
            }

            guard4 = true;
          } else if (Swatch_DW->sfEvent == Swatch_event_timesetmode) {
            /* Transition: '<S3>:170' */
            Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

            /* Outport: '<Root>/hours' */
            /* Entry 'Set_H': '<S3>:168' */
            *Swatch_Y_hours = Swatch_DW->hours;
          } else {
            /* Outport: '<Root>/minutes' */
            *Swatch_Y_minutes = Swatch_DW->minutes;
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
      if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
        /* Transition: '<S3>:162' */
        if (Swatch_DW->hours == 0) {
          /* Transition: '<S3>:163' */
          Swatch_DW->hours = 23U;
        } else {
          /* Transition: '<S3>:161' */
          qY = Swatch_DW->hours - 1U;
          if (qY > Swatch_DW->hours) {
            qY = 0U;
          }

          Swatch_DW->hours = (uint8_T)qY;
        }

        guard3 = true;
      } else {
        /* Outport: '<Root>/hours' */
        *Swatch_Y_hours = Swatch_DW->hours;
      }
    }

    if (guard5) {
      if (Swatch_DW->sfEvent == Swatch_event_minusbutton) {
        /* Transition: '<S3>:146' */
        if (Swatch_DW->Ahours == 0) {
          /* Transition: '<S3>:145' */
          Swatch_DW->Ahours = 23U;
        } else {
          /* Transition: '<S3>:143' */
          qY = Swatch_DW->Ahours - 1U;
          if (qY > Swatch_DW->Ahours) {
            qY = 0U;
          }

          Swatch_DW->Ahours = (uint8_T)qY;
        }

        guard1 = true;
      } else if (Swatch_DW->sfEvent == Swatch_event_alarmmode) {
        /* Transition: '<S3>:128' */
        Swatch_DW->is_Alarm = Swatch_IN_Set_M;

        /* Outport: '<Root>/minutes' */
        /* Entry 'Set_M': '<S3>:133' */
        *Swatch_Y_minutes = Swatch_DW->Aminutes;
      } else {
        /* Outport: '<Root>/hours' */
        *Swatch_Y_hours = Swatch_DW->Ahours;
      }
    }

    if (guard4) {
      Swatch_DW->is_TimeSetting = Swatch_IN_Set_M;

      /* Outport: '<Root>/minutes' */
      /* Entry 'Set_M': '<S3>:169' */
      *Swatch_Y_minutes = Swatch_DW->minutes;
    }

    if (guard3) {
      Swatch_DW->is_TimeSetting = Swatch_IN_Set_H;

      /* Outport: '<Root>/hours' */
      /* Entry 'Set_H': '<S3>:168' */
      *Swatch_Y_hours = Swatch_DW->hours;
    }

    if (guard2) {
      Swatch_DW->is_Alarm = Swatch_IN_Set_M;

      /* Outport: '<Root>/minutes' */
      /* Entry 'Set_M': '<S3>:133' */
      *Swatch_Y_minutes = Swatch_DW->Aminutes;
    }

    if (guard1) {
      Swatch_DW->is_Alarm = Swatch_IN_Set_H;

      /* Outport: '<Root>/hours' */
      /* Entry 'Set_H': '<S3>:132' */
      *Swatch_Y_hours = Swatch_DW->Ahours;
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
  /* During: Swatch  /StopWatch2018 */
  if (Swatch_DW->is_active_c3_Swatch == 0U) {
    /* Entry: Swatch  /StopWatch2018 */
    Swatch_DW->is_active_c3_Swatch = 1U;

    /* Entry Internal: Swatch  /StopWatch2018 */
    /* Transition: '<S3>:45' */
    Swatch_DW->is_active_AlarmManagement = 1U;

    /* Entry Internal 'AlarmManagement': '<S3>:29' */
    /* Transition: '<S3>:75' */
    Swatch_DW->is_AlarmManagement = Swatch_IN_Checking;
    Swatch_DW->is_active_TimeCount = 1U;

    /* Outport: '<Root>/tenths' */
    /* Entry 'TimeCount': '<S3>:25' */
    /* Entry Internal 'TimeCount': '<S3>:25' */
    /* Transition: '<S3>:48' */
    *Swatch_Y_tenths = 0U;
    Swatch_DW->is_TimeCount = Swatch_IN_Count;

    /* Entry 'Count': '<S3>:47' */
    Swatch_DW->is_active_TimeCountStopWatch = 1U;

    /* Entry 'TimeCountStopWatch': '<S3>:27' */
    /* Entry Internal 'TimeCountStopWatch': '<S3>:27' */
    /* Transition: '<S3>:219' */
    Swatch_DW->is_TimeCountStopWatch = Swatch_IN_S_Count;

    /* Entry 'S_Count': '<S3>:190' */
    Swatch_DW->is_active_interface = 1U;

    /* Entry 'interface': '<S3>:28' */
    /* Entry Internal 'interface': '<S3>:28' */
    /* Transition: '<S3>:38' */
    Swatch_DW->hours = 1U;
    Swatch_DW->minutes = 0U;
    Swatch_DW->seconds = 45U;
    Swatch_DW->tenths = 0U;
    Swatch_DW->Aminutes = 1U;
    Swatch_DW->Ahours = 1U;
    Swatch_DW->Shours = 0U;
    Swatch_DW->Sminutes = 0U;
    Swatch_DW->Sseconds = 0U;
    Swatch_DW->Stenths = 0U;
    Swatch_DW->is_interface = Swatch_IN_TimeDisplay;

    /* Outport: '<Root>/mode' */
    /* Entry 'TimeDisplay': '<S3>:31' */
    *Swatch_Y_mode = 0U;
  } else {
    if (Swatch_DW->is_active_AlarmManagement != 0U) {
      /* During 'AlarmManagement': '<S3>:29' */
      switch (Swatch_DW->is_AlarmManagement) {
       case Swatch_IN_Buzzer_ON:
        /* During 'Buzzer_ON': '<S3>:76' */
        if ((Swatch_DW->Ahours != Swatch_DW->hours) || (Swatch_DW->Aminutes !=
             Swatch_DW->minutes)) {
          /* Transition: '<S3>:72' */
          Swatch_DW->is_AlarmManagement = Swatch_IN_Checking;
        }
        break;

       case Swatch_IN_Checking:
        /* During 'Checking': '<S3>:74' */
        if ((Swatch_DW->Ahours == Swatch_DW->hours) && (Swatch_DW->Aminutes ==
             Swatch_DW->minutes)) {
          /* Transition: '<S3>:71' */
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
      /* During 'TimeCount': '<S3>:25' */
      /* During 'Count': '<S3>:47' */
      /* Transition: '<S3>:56' */
      if (Swatch_DW->tenths == 9) {
        /* Transition: '<S3>:53' */
        Swatch_DW->tenths = 0U;
        if (Swatch_DW->seconds == 59) {
          /* Transition: '<S3>:54' */
          Swatch_DW->seconds = 0U;
          if (Swatch_DW->minutes == 59) {
            /* Transition: '<S3>:55' */
            Swatch_DW->minutes = 0U;

            /* Transition: '<S3>:60' */
            tmp = (int32_T)(Swatch_DW->hours + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Swatch_DW->hours = (uint8_T)tmp;
          } else {
            /* Transition: '<S3>:59' */
            tmp = (int32_T)(Swatch_DW->minutes + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Swatch_DW->minutes = (uint8_T)tmp;
          }
        } else {
          /* Transition: '<S3>:58' */
          tmp = (int32_T)(Swatch_DW->seconds + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Swatch_DW->seconds = (uint8_T)tmp;
        }
      } else {
        /* Transition: '<S3>:57' */
        tmp = (int32_T)(Swatch_DW->tenths + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Swatch_DW->tenths = (uint8_T)tmp;
      }

      Swatch_DW->is_TimeCount = Swatch_IN_Count;

      /* Entry 'Count': '<S3>:47' */
    }

    if (Swatch_DW->is_active_TimeCountStopWatch != 0U) {
      /* During 'TimeCountStopWatch': '<S3>:27' */
      if (Swatch_DW->sfEvent == Swatch_event_StopW_Start) {
        /* Transition: '<S3>:223' */
        /* Exit Internal 'TimeCountStopWatch': '<S3>:27' */
        Swatch_DW->is_TimeCountStopWatch = Swatch_IN_S_Count;

        /* Entry 'S_Count': '<S3>:190' */
      } else {
        switch (Swatch_DW->is_TimeCountStopWatch) {
         case Swatch_IN_S_Count:
          /* During 'S_Count': '<S3>:190' */
          if (Swatch_DW->sfEvent == Swatch_event_Tick) {
            /* Transition: '<S3>:221' */
            if (Swatch_DW->Stenths == 9) {
              /* Transition: '<S3>:182' */
              Swatch_DW->Stenths = 0U;
              if (Swatch_DW->Sseconds == 59) {
                /* Transition: '<S3>:189' */
                Swatch_DW->Sseconds = 0U;
                if (Swatch_DW->Sminutes == 59) {
                  /* Transition: '<S3>:191' */
                  Swatch_DW->Sminutes = 0U;
                  if (Swatch_DW->Shours == 24) {
                    /* Transition: '<S3>:183' */
                    Swatch_DW->Shours = 0U;

                    /* Transition: '<S3>:181' */
                  } else {
                    /* Transition: '<S3>:193' */
                    tmp = (int32_T)(Swatch_DW->hours + 1U);
                    if ((uint32_T)tmp > 255U) {
                      tmp = 255;
                    }

                    Swatch_DW->Shours = (uint8_T)tmp;
                  }
                } else {
                  /* Transition: '<S3>:184' */
                  tmp = (int32_T)(Swatch_DW->Sminutes + 1U);
                  if ((uint32_T)tmp > 255U) {
                    tmp = 255;
                  }

                  Swatch_DW->Sminutes = (uint8_T)tmp;
                }
              } else {
                /* Transition: '<S3>:186' */
                tmp = (int32_T)(Swatch_DW->Sseconds + 1U);
                if ((uint32_T)tmp > 255U) {
                  tmp = 255;
                }

                Swatch_DW->Sseconds = (uint8_T)tmp;
              }
            } else {
              /* Transition: '<S3>:178' */
              tmp = (int32_T)(Swatch_DW->Stenths + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              Swatch_DW->Stenths = (uint8_T)tmp;
            }

            Swatch_DW->is_TimeCountStopWatch = Swatch_IN_S_Count;

            /* Entry 'S_Count': '<S3>:190' */
          } else {
            if (Swatch_DW->sfEvent == Swatch_event_plusbutton) {
              /* Transition: '<S3>:230' */
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



/* Model data allocation function */
RT_MODEL_Swatch_T *Swatch(boolean_T *Swatch_U_plusButton, boolean_T
  *Swatch_U_minusButton, boolean_T *Swatch_U_timeMode, boolean_T
  *Swatch_U_timesetmode, boolean_T *Swatch_U_alarmMode, boolean_T
  *Swatch_U_swatchMode, uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes,
  uint8_T *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode)
{
  RT_MODEL_Swatch_T *Swatch_M;
  Swatch_M = (RT_MODEL_Swatch_T *) malloc(sizeof(RT_MODEL_Swatch_T));
  if (Swatch_M == NULL) {
    return NULL;
  }

  (void) memset((char *)Swatch_M, 0,
                sizeof(RT_MODEL_Swatch_T));

  /* states (dwork) */
  {
    DW_Swatch_T *dwork = (DW_Swatch_T *) malloc(sizeof(DW_Swatch_T));
    rt_VALIDATE_MEMORY(Swatch_M,dwork);
    Swatch_M->dwork = (dwork);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_Swatch_T *zc = (PrevZCX_Swatch_T *) malloc(sizeof(PrevZCX_Swatch_T));
    rt_VALIDATE_MEMORY(Swatch_M,zc);
    Swatch_M->prevZCSigState = (zc);
  }

  {
    DW_Swatch_T *Swatch_DW = ((DW_Swatch_T *) Swatch_M->dwork);
    PrevZCX_Swatch_T *Swatch_PrevZCX = ((PrevZCX_Swatch_T *)
      Swatch_M->prevZCSigState);

    /* states (dwork) */
    (void) memset((void *)Swatch_DW, 0,
                  sizeof(DW_Swatch_T));

    /* external inputs */
    *Swatch_U_plusButton = false;
    *Swatch_U_minusButton = false;
    *Swatch_U_timeMode = false;
    *Swatch_U_timesetmode = false;
    *Swatch_U_alarmMode = false;
    *Swatch_U_swatchMode = false;

    /* external outputs */
    (*Swatch_Y_hours) = 0U;
    (*Swatch_Y_minutes) = 0U;
    (*Swatch_Y_seconds) = 0U;
    (*Swatch_Y_tenths) = 0U;
    (*Swatch_Y_mode) = 0U;

    /* previous zero-crossing states */
    {
    }
  }

  return Swatch_M;
}


/* Model step function */
void Swatch_step(RT_MODEL_Swatch_T *const Swatch_M, boolean_T Swatch_U_Bplus,
                 boolean_T Swatch_U_Bminus, boolean_T Swatch_U_Btime, boolean_T
                 Swatch_U_Btimeset, boolean_T Swatch_U_Balarm, boolean_T
                 Swatch_U_Bswatch, uint8_T *Swatch_Y_hours, uint8_T
                 *Swatch_Y_minutes, uint8_T *Swatch_Y_seconds, uint8_T
                 *Swatch_Y_tenths, uint8_T *Swatch_Y_mode)
{
  DW_Swatch_T *Swatch_DW = ((DW_Swatch_T *) Swatch_M->dwork);
  PrevZCX_Swatch_T *Swatch_PrevZCX = ((PrevZCX_Swatch_T *)
    Swatch_M->prevZCSigState);
  uint8_T rtb_FixPtSum1;
  boolean_T zcEvent[7];
  int8_T rtb_inputevents[7];
  int32_T i;
  boolean_T zcEvent_0;

  /* Chart: '<S1>/StopWatch2018' incorporates:
   *  TriggerPort: '<S3>/input events'
   */
  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  zcEvent[0] = ((Swatch_DW->Output_DSTATE != 0) &&
                (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[0] != POS_ZCSIG));

  /* Inport: '<Root>/Bplus' */
  zcEvent[1] = (Swatch_U_Bplus && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[1] !=
    POS_ZCSIG));

  /* Inport: '<Root>/Bminus' */
  zcEvent[2] = (Swatch_U_Bminus && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[2] !=
    POS_ZCSIG));

  /* Inport: '<Root>/Btime' */
  zcEvent[3] = (Swatch_U_Btime && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[3] !=
    POS_ZCSIG));

  /* Inport: '<Root>/Btimeset ' */
  zcEvent[4] = (Swatch_U_Btimeset && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[4]
    != POS_ZCSIG));

  /* Inport: '<Root>/Balarm' */
  zcEvent[5] = (Swatch_U_Balarm && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[5] !=
    POS_ZCSIG));

  /* Inport: '<Root>/Bswatch' */
  zcEvent[6] = (Swatch_U_Bswatch && (Swatch_PrevZCX->StopWatch2018_Trig_ZCE[6]
    != POS_ZCSIG));
  zcEvent_0 = false;
  for (i = 0; i < 7; i++) {
    zcEvent_0 = (zcEvent_0 || zcEvent[i]);
  }

  if (zcEvent_0) {
    for (i = 0; i < 7; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    /* Gateway: Swatch  /StopWatch2018 */
    if (rtb_inputevents[0U] == 1) {
      /* Event: '<S3>:2' */
      Swatch_DW->sfEvent = Swatch_event_Tick;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[1U] == 1) {
      /* Event: '<S3>:1' */
      Swatch_DW->sfEvent = Swatch_event_plusbutton;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[2U] == 1) {
      /* Event: '<S3>:3' */
      Swatch_DW->sfEvent = Swatch_event_minusbutton;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[3U] == 1) {
      /* Event: '<S3>:4' */
      Swatch_DW->sfEvent = Swatch_event_timemode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[4U] == 1) {
      /* Event: '<S3>:5' */
      Swatch_DW->sfEvent = Swatch_event_timesetmode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[5U] == 1) {
      /* Event: '<S3>:6' */
      Swatch_DW->sfEvent = Swatch_event_alarmmode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }

    if (rtb_inputevents[6U] == 1) {
      /* Event: '<S3>:7' */
      Swatch_DW->sfEvent = Swatch_event_swatchmode;
      Swatch_chartstep_c3_Swatch(Swatch_Y_hours, Swatch_Y_minutes,
        Swatch_Y_seconds, Swatch_Y_tenths, Swatch_Y_mode, Swatch_DW);
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[0] = (ZCSigState)
    (Swatch_DW->Output_DSTATE != 0);

  /* Inport: '<Root>/Bplus' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[1] = Swatch_U_Bplus;

  /* Inport: '<Root>/Bminus' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[2] = Swatch_U_Bminus;

  /* Inport: '<Root>/Btime' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[3] = Swatch_U_Btime;

  /* Inport: '<Root>/Btimeset ' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[4] = Swatch_U_Btimeset;

  /* Inport: '<Root>/Balarm' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[5] = Swatch_U_Balarm;

  /* Inport: '<Root>/Bswatch' */
  Swatch_PrevZCX->StopWatch2018_Trig_ZCE[6] = Swatch_U_Bswatch;

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(Swatch_DW->Output_DSTATE + 1U);

  /* Switch: '<S5>/FixPt Switch' */
  if (rtb_FixPtSum1 > 1) {
    /* Update for UnitDelay: '<S2>/Output' incorporates:
     *  Constant: '<S5>/Constant'
     */
    Swatch_DW->Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S2>/Output' */
    Swatch_DW->Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void Swatch_initialize(RT_MODEL_Swatch_T *const Swatch_M, boolean_T
  *Swatch_U_Bplus, boolean_T *Swatch_U_Bminus, boolean_T *Swatch_U_Btime,
  boolean_T *Swatch_U_Btimeset, boolean_T *Swatch_U_Balarm, boolean_T
  *Swatch_U_Bswatch, uint8_T *Swatch_Y_hours, uint8_T *Swatch_Y_minutes, uint8_T
  *Swatch_Y_seconds, uint8_T *Swatch_Y_tenths, uint8_T *Swatch_Y_mode)
{
  DW_Swatch_T *Swatch_DW = ((DW_Swatch_T *) Swatch_M->dwork);
  PrevZCX_Swatch_T *Swatch_PrevZCX = ((PrevZCX_Swatch_T *)
    Swatch_M->prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)Swatch_DW, 0,
                sizeof(DW_Swatch_T));

  /* external inputs */
  *Swatch_U_Bplus = false;
  *Swatch_U_Bminus = false;
  *Swatch_U_Btime = false;
  *Swatch_U_Btimeset = false;
  *Swatch_U_Balarm = false;
  *Swatch_U_Bswatch = false;

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
