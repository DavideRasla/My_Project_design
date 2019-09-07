/**
* Subsystem.c
* Represent the main code file for the stateflow
* subsystem of stopwatch
*
* Author:
* 	Gabriele Serra
*/

#include "Subsystem.h"

// -------------------------
// CURRENT STATE AND EVENT
// -------------------------

signal event;			// event on state machine
uint8_T curr_mode;		// current state machine mode

// --------------------------
// VARIABLES WITH LOCAL SCOPE
// --------------------------

uint8_T abs_hours;		// absolute hour count
uint8_T abs_minutes;	// absolute minutes count
uint8_T abs_seconds;	// absolute seconds count
uint8_T abs_tenths;		// absolute tenths count

uint8_T a_hours;		// alarm-mode hours setting
uint8_T a_minutes;		// alarm-mode minutes setting

uint8_T sw_hours;		// stopwatch-mode hour count
uint8_T sw_minutes;		// stopwatch-mode minutes count
uint8_T sw_seconds; 	// stopwatch-mode seconds count
uint8_T sw_tenths;		// stopwatch-mode tenths count

uint8_T count_h_blink;	// number of tick before hours blink transition
uint8_T count_m_blink;	// number of tick before minutes blink transition
uint8_T count_a_blink;	// number of tick before alarm blink transition

boolean_T sw_lap;		// used to track stopwatch lap-mode

// --------------------------------------------
// VARIABLE USED TO DISTINGUISH INTERNAL STATES
// --------------------------------------------

boolean_T ts_state;		// true if hours is blinking, false if minutes is blinking
boolean_T a_state;		// true if hours is blinking, false if minutes is blinking
boolean_T sw_running;	// true if stopwatch is running, false if not

// initialize all state machine internal vars and output to zero
void Subsystem_initialize(boolean_T *Subsystem_U_plusbutton, boolean_T
	*Subsystem_U_minusbutton, boolean_T *Subsystem_U_timemode, boolean_T
	*Subsystem_U_timesetmode, boolean_T *Subsystem_U_alarmmode, boolean_T
	*Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
	*Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
	*Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
	*Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
	*Subsystem_Y_mblink, boolean_T *Subsystem_Y_ringalarm) {

	curr_mode = TIME_MODE;

	// set to zero local variables and displayed ones
	set_timestamp_to_zero(&abs_hours, &abs_minutes, &abs_seconds, &abs_tenths);
	set_timestamp_to_zero(Subsystem_Y_hours, Subsystem_Y_minutes, 
								Subsystem_Y_seconds, Subsystem_Y_tenths);
	
	
	set_blink_to_false(Subsystem_Y_hblink, Subsystem_Y_mblink);
	set_blink_to_zero();
	ts_state = true;

	a_hours = 0;
	a_minutes = 0;
	count_a_blink = 0;
	*Subsystem_Y_alarmactive = false;
	*Subsystem_Y_ringalarm = false;
	
}

// let the model evolve
void Subsystem_step(boolean_T Subsystem_U_plusbutton, boolean_T
	Subsystem_U_minusbutton, boolean_T Subsystem_U_timemode, boolean_T
	Subsystem_U_timesetmode, boolean_T Subsystem_U_alarmmode, boolean_T
	Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
	*Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
	*Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
	*Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
	*Subsystem_Y_mblink, boolean_T *Subsystem_Y_ringalarm) {

	event = trig_signal(Subsystem_U_plusbutton, Subsystem_U_minusbutton, 
						Subsystem_U_timemode, Subsystem_U_timesetmode, 
						Subsystem_U_alarmmode, Subsystem_U_swatchmode);

	switch(*Subsystem_Y_mode){
		case TIME_MODE:
			timemode_during(Subsystem_Y_hours, Subsystem_Y_minutes, 
							Subsystem_Y_seconds, Subsystem_Y_tenths);

			switch(event) {
				case B_TIMESET:
					timesetmode_entry(Subsystem_Y_hblink, Subsystem_Y_mblink,
										Subsystem_Y_hours, Subsystem_Y_minutes, 
										Subsystem_Y_seconds, Subsystem_Y_tenths);
					break;

				case B_ALARM:
					alarmmode_entry(Subsystem_Y_hblink, Subsystem_Y_mblink,
									Subsystem_Y_alarmactive, Subsystem_Y_hours, Subsystem_Y_minutes);
					break;

				case B_SWATCH:
					swatchmode_entry(Subsystem_Y_hours, Subsystem_Y_minutes, 
										Subsystem_Y_seconds, Subsystem_Y_tenths);
					break;

		 		default:
		 			break;
			}

			break;

		case TIMESET_MODE:
			timesetmode_during(Subsystem_Y_hblink, Subsystem_Y_mblink,
								Subsystem_Y_hours, Subsystem_Y_minutes);

			switch(event) {
				case B_TIME:
					timesetmode_exit(Subsystem_Y_hblink, Subsystem_Y_mblink);
					timemode_entry();
					break;

				case B_TIMESET:
					if(ts_state) {
						*Subsystem_Y_hblink = false;
						count_h_blink = 0;
						ts_state = false;
					} else {
						*Subsystem_Y_mblink = false;
						count_m_blink = 0;
						ts_state = true;
					}
					break;

				case B_ALARM:
					timesetmode_exit(Subsystem_Y_hblink, Subsystem_Y_mblink);
					alarmmode_entry(Subsystem_Y_hblink, Subsystem_Y_mblink,
									Subsystem_Y_alarmactive, Subsystem_Y_hours, Subsystem_Y_minutes);
					break;

				case B_SWATCH:
					timesetmode_exit(Subsystem_Y_hblink, Subsystem_Y_mblink);
					swatchmode_entry(Subsystem_Y_hours, Subsystem_Y_minutes, 
										Subsystem_Y_seconds, Subsystem_Y_tenths);
					break;

				case B_PLUS:
					if(ts_state)
						abs_hours = (abs_hours+1) % 24;
					else
						abs_minutes = (abs_minutes+1) % 60;
					break;

				case B_MINUS:
					if(ts_state)
						if(abs_hours == 0) abs_hours = 23;
						else abs_hours = abs_hours - 1;
					else
						if(abs_minutes == 0) abs_minutes = 59;
						else abs_minutes = abs_minutes -1;
					break;

				default:
					break;
			}

			break;

		case ALARM_MODE:
			alarmmode_during(Subsystem_Y_hblink, Subsystem_Y_mblink,
								Subsystem_Y_hours, Subsystem_Y_minutes);

		 	switch(event) {
				case B_TIME:
					alarmmode_exit(Subsystem_Y_hblink, Subsystem_Y_mblink);
					timemode_entry();
				break;

				case B_TIMESET:
					alarmmode_exit(Subsystem_Y_hblink, Subsystem_Y_mblink);
					timesetmode_entry(Subsystem_Y_hblink, Subsystem_Y_mblink,
										Subsystem_Y_hours, Subsystem_Y_minutes, 
										Subsystem_Y_seconds, Subsystem_Y_tenths);
			 	break;

				case B_ALARM:
					if(a_state) {
						*Subsystem_Y_hblink = false;
						count_h_blink = 0;
						a_state = false;
					} else {
						*Subsystem_Y_mblink = false;
						count_m_blink = 0;
						a_state = true;
						*Subsystem_Y_alarmactive = true;
					}
				break;

				case B_SWATCH:
					alarmmode_exit(Subsystem_Y_hblink, Subsystem_Y_mblink);
					swatchmode_entry(Subsystem_Y_hours, Subsystem_Y_minutes, 
										Subsystem_Y_seconds, Subsystem_Y_tenths);
				break;
				
				case B_PLUS:
					if(a_state)
						a_hours = (a_hours+1) % 24;
					else
						a_minutes = (a_minutes+1) % 60;
				break;

				case B_MINUS:
					if(a_state)
						if(a_hours == 0) a_hours = 23;
						else a_hours = a_hours - 1;
					else
						if(a_minutes == 0) a_minutes = 59;
						else a_minutes = a_minutes -1;
				break;

		 	    default:
		 	    	 break;

		 	}
		break;

		case SWATCH_MODE:
			swatchmode_during(Subsystem_Y_hours, Subsystem_Y_minutes,
								Subsystem_Y_seconds, Subsystem_Y_tenths);

			switch(event) {

				case B_TIME:
					timemode_entry();
				break;

				case B_TIMESET:
					timesetmode_entry(Subsystem_Y_hblink, Subsystem_Y_mblink,
										Subsystem_Y_hours, Subsystem_Y_minutes, 
										Subsystem_Y_seconds, Subsystem_Y_tenths);
			 	break;

				case B_ALARM:
					alarmmode_entry(Subsystem_Y_hblink, Subsystem_Y_mblink,
									Subsystem_Y_alarmactive, Subsystem_Y_hours, Subsystem_Y_minutes);
			 	break;

				case B_PLUS:
					sw_running = !sw_running;
				break;

				case B_MINUS:
					if(sw_running) sw_lap = !sw_lap;
				break;

				default:
					break;
			}
		    break;
		
		default:
			break;

		}

		time_count();
		alarm_manage(Subsystem_Y_alarmactive, Subsystem_Y_ringalarm);
		*Subsystem_Y_mode = curr_mode;
}

// finite state machine terminating
void Subsystem_terminate(){}

// trig the correct signal if an input is present
signal trig_signal(boolean_T b_plus, boolean_T b_minus, boolean_T b_time, 
	boolean_T b_timeset, boolean_T b_alarm, boolean_T b_stop) {

if(b_plus)
	return B_PLUS;
else if(b_minus)
	return B_MINUS;
else if(b_time)
	return B_TIME;
else if(b_timeset)
	return B_TIMESET;
else if(b_alarm)
	return B_ALARM;
else if(b_stop)
	return B_SWATCH;
else
	return ABSENT;
}

// -------------------------
// STATEFLOW EXTENSION
// -------------------------

void timemode_entry() {
	curr_mode = TIME_MODE;
}

void timemode_during(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths) {
	load_curr_timestamp(d_hours, d_minutes, d_seconds, d_tenths);
}

void timesetmode_entry(boolean_T *hblink, boolean_T *mblink, 
						uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths) {
	curr_mode = TIMESET_MODE;
	set_blink_to_false(hblink, mblink);
	set_blink_to_zero();

	load_curr_timestamp(d_hours, d_minutes, d_seconds, d_tenths);
	ts_state = true;
}

void timesetmode_during(boolean_T *hblink, boolean_T *mblink, 
							uint8_T *d_hours, uint8_T *d_minutes) {
	if(ts_state) {
		*d_hours = abs_hours;
		count_h_blink = (count_h_blink+1) % 5;
		if(count_h_blink == 0)
			*hblink = !(*hblink);
	} else {
		*d_minutes = abs_minutes;
		count_m_blink = (count_m_blink+1) % 5;
		if(count_m_blink == 0)
			*mblink = !(*mblink);
	}
}

void timesetmode_exit(boolean_T *hblink, boolean_T *mblink) {
	*hblink = false;
	*mblink = false;
	set_blink_to_zero();
}

void alarmmode_entry(boolean_T *hblink, boolean_T *mblink, boolean_T *alarmactive,
						uint8_T *d_hours, uint8_T *d_minutes) {
	curr_mode = ALARM_MODE;
	set_blink_to_false(hblink, mblink);
	set_blink_to_zero();
	*alarmactive = false;
	
	load_alarm_timestamp(d_hours, d_minutes);
	a_state = true;
}

void alarmmode_during(boolean_T *hblink, boolean_T *mblink, 
						uint8_T *d_hours, uint8_T *d_minutes) {
	if(a_state) {
		*d_hours = a_hours;
		count_h_blink = (count_h_blink+1) % 5;
		if(count_h_blink == 0)
			*hblink = !(*hblink);
	} else {
		*d_minutes = a_minutes;
		count_m_blink = (count_m_blink+1) % 5;
		if(count_m_blink == 0)
			*mblink = !(*mblink);
	}
}

void alarmmode_exit(boolean_T *hblink, boolean_T *mblink) {
	*hblink = false;
	*mblink = false;
	set_blink_to_zero();
}

void swatchmode_entry(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths) {
	curr_mode = SWATCH_MODE;
	set_timestamp_to_zero(&sw_hours, &sw_minutes, &sw_seconds, &sw_tenths);
	load_sw_timestamp(d_hours, d_minutes, d_seconds, d_tenths);

	sw_lap = false;
	sw_running = false;
}

void swatchmode_during(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths) {
	if(sw_running == true) {
		sw_time_count();
		if(sw_lap == false) {
			load_sw_timestamp(d_hours, d_minutes, d_seconds, d_tenths);
		}
	}
}

// -------------------------
// PARALLEL STATES FUNCTIONS
// -------------------------

// update timestamp every tick
void time_count() {
	abs_tenths = (abs_tenths+1) % 10;
	
	if(abs_tenths == 0) {
		abs_seconds = (abs_seconds+1) % 60;
		
		if(abs_seconds == 0) {
			abs_minutes = (abs_minutes+1) % 60;
			
			if(abs_minutes == 0) {
				abs_hours = (abs_hours+1) % 24;
			}
		}
	}
}

// manage the alarm and check if is ringing
void alarm_manage(boolean_T *alarm_active, boolean_T *ring_alarm) {
	if(*alarm_active && abs_hours == a_hours && abs_minutes == a_minutes) {
		count_a_blink = (count_a_blink+1) % 5;	
		if(count_a_blink == 0)
			*ring_alarm = !(*ring_alarm);
	} else {
		ring_alarm = false;
	}
}


// ----------------------
// UTILITIES
// ---------------------

// set to zero the timestamp provided
void set_timestamp_to_zero(uint8_T *hours, uint8_T *minutes, uint8_T *seconds, uint8_T *tenths) {
	*hours = 0;
	*minutes = 0;
	*seconds = 0;
	*tenths= 0 ;
}

// set the blink to false
void set_blink_to_false(boolean_T *hblink, boolean_T *mblink) {
	*hblink = false;
	*mblink = false;
}

// set blink count to zero
void set_blink_to_zero() {
	count_h_blink = 0;
	count_m_blink = 0;
}

// load timestamp into display variable
void load_curr_timestamp(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths) {
	*d_hours = abs_hours;
	*d_minutes = abs_minutes;
	*d_seconds = abs_seconds;
	*d_tenths = abs_tenths;
}

// load timestamp into display variable
void load_alarm_timestamp(uint8_T *d_hours, uint8_T *d_minutes) {
	*d_hours = a_hours;
	*d_minutes = a_minutes;
}

// load swatch time into display variable
void load_sw_timestamp(uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths) {
	*d_hours = sw_hours;
	*d_minutes = sw_minutes;
	*d_seconds = sw_seconds;
	*d_tenths = sw_tenths;
}

// update sw timestamp
void sw_time_count() {
	sw_tenths = (sw_tenths+1) % 10;
	
	if(sw_tenths == 0) {	
		sw_seconds = (sw_seconds+1) % 60;
		
		if(sw_seconds == 0) {
			sw_minutes = (sw_minutes+1) % 60;
			
			if(sw_minutes == 0) {	
				sw_hours = (sw_hours+1) % 24;
			}
		}
	}
}




