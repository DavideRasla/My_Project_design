#include "Lib/Widget.h"
#include "Lib/WidgetConfig.h"
#include "GUI_Manager.h"

// ---------------------------
// STATIC VARIABLES
// ---------------------------
uint8_T old_mode = 99,		// current mode
		oh = 99, 			// old hours
		om = 99, 			// old minutes
		os = 99, 			// old seconds
		ot = 99;			// old tenths

// -------------------------
// MAIN LCD SCREEN FUNCTIONS
// -------------------------

// Initializes the LCD screen with background and hour/minutes separator
void init_interface() {
	DrawInit(MyWatchScr);
	WPrint(&MyWatchScr[SEP1STR], ":");
	WPrint(&MyWatchScr[SEP2STR], ":");
}

// Update the current mode of stop-watch and make prepare some widget on screen
void update_mode(unsigned char mode, uint8_T seconds, uint8_T tenths){

	if(mode == old_mode)
		return;

	switch (old_mode) {
		// TIME
		case 0:
			seconds_text_clear(mode);
			DrawOff(&MyWatchScr[BTIME]);
			break;
		// TIMESET
		case 1:
			DrawOff(&MyWatchScr[BTIMESET]);
			break;
		// ALARM
		case 2:
			DrawOff(&MyWatchScr[BALARM]);
			break;
		// STOPWATCH
		case 3:
			seconds_text_clear(mode);
			tenths_text_clear();
			DrawOff(&MyWatchScr[BSWATCH]);
			break;
	}

	switch (mode) {
		// TIME
		case 0:
			seconds_text_draw(old_mode, seconds);
			DrawOn(&MyWatchScr[BTIME]);
			break;
		// TIMESET
		case 1:
			DrawOn(&MyWatchScr[BTIMESET]);
			break;
		// ALARM
		case 2:
			DrawOn(&MyWatchScr[BALARM]);
			break;
		// STOPWATCH
		case 3:
			seconds_text_draw(old_mode, seconds);
			tenths_text_draw(tenths);
			DrawOn(&MyWatchScr[BSWATCH]);
			break;
	}

	// update the mode
	old_mode = mode;
}

// Updates the LCD screen and its widget
void update_interface(uint8_T mode,
		uint8_T hours,
		uint8_T minutes,
		uint8_T seconds,
		uint8_T tenths,
		boolean_T alarmactive,
		boolean_T hblink,
		boolean_T mblink,
		boolean_T ringalarm) {

	// update on screen time-stamp
	update_hours_text(hours);
	update_minutes_text(minutes);
	update_seconds_text(seconds, mode);
	update_tenths_text(tenths, mode);

	// if needed, make text blinking
	text_blink(hours, HRSSTR, hblink);
	text_blink(minutes, MINSTR, mblink);

	// if needed, make alarm icon appear and blink
	alarmicon_manage(mode, alarmactive, ringalarm);

	// update mode
	update_mode(mode, seconds, tenths);
}

// ------------------------
// LCD TEXT CLEAR FUNCTIONS
// ------------------------

// Clear seconds text and separator if needed
void seconds_text_clear(uint8_T mode) {
	// if the mode is TIMESET or ALARM
	if(mode == 1 || mode == 2){
		WClear(&MyWatchScr[SEP2STR]);
		WClear(&MyWatchScr[SECSTR]);
	}
}

// Clear tenths text and separator
void tenths_text_clear() {
	WClear(&MyWatchScr[SEP3STR]);
	WClear(&MyWatchScr[TTSSTR]);
}

// ------------------------
// LCD TEXT DRAW FUNCTIONS
// ------------------------

// Draw seconds text and separator if needed
void seconds_text_draw(uint8_T old_mode, uint8_T seconds) {
	char seconds_string[3];

	// if previous mode was different from stop-watch or time
	if (old_mode == 1 || old_mode == 2) {
		WPrint(&MyWatchScr[SEP2STR], ":");
		strencode2digit(seconds_string, seconds);
		WPrint(&MyWatchScr[SECSTR], seconds_string);
	}
}

// Draw tenths text and separator
void tenths_text_draw(uint8_T tenths) {
	char tenths_string[2];

	WPrint(&MyWatchScr[SEP3STR], ".");
	strencode1digit(tenths_string, tenths);
	WPrint(&MyWatchScr[TTSSTR], tenths_string);
}

// ---------------------------
// LCD TEXT UPDATING FUNCTIONS
// ---------------------------

// Update on-screen hours text if it is needed
void update_hours_text(uint8_T newer_hours_value) {
	char hours_string[3];

	if (newer_hours_value != oh) {
		strencode2digit(hours_string, newer_hours_value);
		WClear(&MyWatchScr[HRSSTR]);
		WPrint(&MyWatchScr[HRSSTR], hours_string);
		oh = newer_hours_value;
	}
}

// Update on-screen minutes text if it is needed
void update_minutes_text(uint8_T newer_minutes_value) {
	char minutes_string[3];

	if (newer_minutes_value != om) {
		strencode2digit(minutes_string, newer_minutes_value);
		WClear(&MyWatchScr[MINSTR]);
		WPrint(&MyWatchScr[MINSTR], minutes_string);
		om = newer_minutes_value;
	}
}

// Update on-screen seconds text if it is needed
void update_seconds_text(uint8_T newer_seconds_value, uint8_T mode) {
	char seconds_string[3];

	if (newer_seconds_value != os && (mode == 0 || mode == 3)) {
		strencode2digit(seconds_string, newer_seconds_value);
		WClear(&MyWatchScr[SECSTR]);
		WPrint(&MyWatchScr[SECSTR], seconds_string);
		os = newer_seconds_value;
	}
}

// Update on-screen tenths text if it is needed
void update_tenths_text(uint8_T newer_tenths_value, uint8_T mode) {
	char tenths_string[3];

	if (newer_tenths_value != ot && mode == 3){
		strencode1digit(tenths_string, newer_tenths_value);
		WClear(&MyWatchScr[TTSSTR]);
		WPrint(&MyWatchScr[TTSSTR], tenths_string);
		ot = newer_tenths_value;
	}
}

// ---------------------------
// BLINKING FUNCTIONS
// ---------------------------

// Make the text blinking if enabled is true
void text_blink(uint8_T time_q, uint8_T widget_num, boolean_T enabled) {
	char time_string[3];

	if(enabled){
		WClear(&MyWatchScr[widget_num]);
	}else{
		strencode2digit(time_string, time_q);
		WPrint(&MyWatchScr[widget_num], time_string);
	}
}

// Use the correct alarm icon and manage icon-blinking
void alarmicon_manage(uint8_T mode, boolean_T active, boolean_T enabled) {
	if(mode == 2 && active)
		DrawOn2(&MyWatchScr[BALARM]);
	else if(mode != 2 && active)
		if(enabled)
			DrawOn2(&MyWatchScr[BALARM]);
		else
			DrawOff2(&MyWatchScr[BALARM]);
}

// ------------------------
// UTILITY FUNCTIONS
// ------------------------

// Encode 2-digits number to string
void strencode2digit(char *str, int digit)
{
	str[2]=0;
	str[0]=digit/10+'0';
	str[1]=digit%10+'0';
}

// Encode 1-digit number to string
void strencode1digit(char *str, int digit) {
	str[1] = 0;
	str[0] = digit%10+'0';
}


