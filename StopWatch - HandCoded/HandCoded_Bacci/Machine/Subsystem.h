/**
* Subsystem.h
* Represent the header file for the stateflow
* subsystem of stopwatch
*
* Author:
* 	Gabriele Serra
*/

#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

// include matlab primitive types
#include "rtwtypes.h"

// ------------------------
// STATE AND INPUT CONSTANT
// ------------------------

#define NO_OF_STATES 4;

typedef enum {
	TIME_MODE = 0, 		// time mode state -> 0
	TIMESET_MODE = 1, 	// timeset mode state -> 1
	ALARM_MODE = 2, 	// alarm mode state -> 2
	SWATCH_MODE = 3 	// stopwatch mode state -> 3
} state;

typedef enum {
	B_PLUS, 		// plus button -> 0
	B_MINUS, 		// minus button -> 1
	B_TIME, 		// timemode button -> 2
	B_TIMESET, 		// timemodeset button -> 3
	B_ALARM, 		// alarmmode button -> 4
	B_SWATCH, 		// stopwatchmode button -> 5
	ABSENT			// absent input -> 6
} signal;

// ------------------------
// MY MODEL PUBLIC FUNCTIONS
// ------------------------

// initialize the model
extern void Subsystem_initialize(
	boolean_T *Subsystem_U_plusbutton, 
	boolean_T *Subsystem_U_minusbutton, 
	boolean_T *Subsystem_U_timemode, 
	boolean_T *Subsystem_U_timesetmode, 
	boolean_T *Subsystem_U_alarmmode, 
	boolean_T *Subsystem_U_swatchmode, 
	uint8_T *Subsystem_Y_hours, 
	uint8_T *Subsystem_Y_minutes, 
	uint8_T *Subsystem_Y_seconds, 
	uint8_T *Subsystem_Y_tenths, 
	uint8_T *Subsystem_Y_mode, 
	boolean_T *Subsystem_Y_alarmactive, 
	boolean_T *Subsystem_Y_hblink, 
	boolean_T *Subsystem_Y_mblink, 
	boolean_T *Subsystem_Y_ringalarm);

// let the model evolve
extern void Subsystem_step(
	boolean_T Subsystem_U_plusbutton, 
	boolean_T Subsystem_U_minusbutton, 
	boolean_T Subsystem_U_timemode, 
	boolean_T Subsystem_U_timesetmode, 
	boolean_T Subsystem_U_alarmmode, 
	boolean_T Subsystem_U_swatchmode, 
	uint8_T *Subsystem_Y_hours, 
	uint8_T *Subsystem_Y_minutes, 
	uint8_T *Subsystem_Y_seconds, 
	uint8_T *Subsystem_Y_tenths, 
	uint8_T *Subsystem_Y_mode, 
	boolean_T *Subsystem_Y_alarmactive, 
	boolean_T *Subsystem_Y_hblink, 
	boolean_T *Subsystem_Y_mblink, boolean_T *Subsystem_Y_ringalarm);

// terminate the model behavior
extern void Subsystem_terminate();

// -------------------------------------------------------------------------
// SOME PRIVATE FUNCTION
// -------------------------------------------------------------------------

// trig the correct signal if an input is present
signal trig_signal(boolean_T b_plus, boolean_T b_minus, boolean_T b_time, 
	boolean_T b_timeset, boolean_T b_alarm, boolean_T b_stop);

// -------------------------
// STATEFLOW EXTENSION
// -------------------------

// timemode entry function
void timemode_entry();

// timemode during function
void timemode_during(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths);

// timesetmode entry function
void timesetmode_entry(boolean_T *hblink, boolean_T *mblink, 
						uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths);

// timesetmode during function
void timesetmode_during(boolean_T *hblink, boolean_T *mblink, 
							uint8_T *d_hours, uint8_T *d_minutes);

// timesetmode exit function
void timesetmode_exit(boolean_T *hblink, boolean_T *mblink);

// alarmmode entry function
void alarmmode_entry(boolean_T *hblink, boolean_T *mblink, boolean_T *alarmactive,
						uint8_T *d_hours, uint8_T *d_minutes);
					
// alarmmode during function
void alarmmode_during(boolean_T *hblink, boolean_T *mblink, 
						uint8_T *d_hours, uint8_T *d_minutes);

// alarmmode exit function
void alarmmode_exit(boolean_T *hblink, boolean_T *mblink);

// swatchmode entry function
void swatchmode_entry(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths);

// swatchmode during function
void swatchmode_during(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths);

// -------------------------
// PARALLEL STATES FUNCTIONS
// -------------------------

// update timestamp every tick
void time_count();

// manage the alarm and check if is ringing
void alarm_manage(boolean_T *alarm_active, boolean_T *ring_alarm);

// ----------------------
// UTILITIES
// ---------------------

// set to zero the timestamp provided
void set_timestamp_to_zero(uint8_T *hours, uint8_T *minutes, uint8_T *seconds, uint8_T *tenths);

// set the blink to false
void set_blink_to_false(boolean_T *hblink, boolean_T *mblink);

// set blink count to zero
void set_blink_to_zero();

// load timestamp into display variable
void load_curr_timestamp(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths);

// load timestamp into display variable
void load_alarm_timestamp(uint8_T *_hours, uint8_T *d_minutes);

// load swatch time into display variable
void load_sw_timestamp(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths);

// update sw timestamp
void sw_time_count();

#endif
