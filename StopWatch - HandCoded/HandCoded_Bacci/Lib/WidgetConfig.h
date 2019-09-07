/*
 * WidgetConfig.h
 *
 *  Created on: 22/ott/2015
 *      Author: admim
 */

#ifndef WIDGETCONFIG_H_
#define WIDGETCONFIG_H_

// ---------------------------
// WIDGETS
// --------------------------

#define NUMWIDGETS 		14		// total number of widgets

#define BAKCG 			0		// background image

#define BTIME 			1		// time button
#define BTIMESET 		2		// set time button
#define BALARM 			3		// alarm button
#define BSWATCH 		4		// stopwatch button
#define BPLUS 			5		// plus button
#define BMINUS 			6		// minus button

#define HRSSTR 			7		// hours string
#define MINSTR 			8		// minutes string
#define SECSTR 			9		// seconds string
#define TTSSTR 			10		// tenths string

#define SEP1STR 		11		// separator hours-minutes
#define SEP2STR 		12		// separator minutes-seconds
#define SEP3STR			13		// separator seconds-tenth

// -----------------------
// EVENTS
// -----------------------

#define TIMEMODE 		0x01	// time mode button event
#define TIMESETMODE 	0x02	// timeset mode button event
#define ALARMMODE 		0x04	// alarm mode button event
#define SWATCHMODE 		0x08	// stopwatch mode button event

#define PLUS 			0x10	// plus button event
#define MINUS 			0x20	// minus button event

// -----------------------
// MY STOPWATCH SCREEN
// ------------------------
extern const Widget MyWatchScr[NUMWIDGETS];

#endif
/* WIDGETCONFIG_H_ */
