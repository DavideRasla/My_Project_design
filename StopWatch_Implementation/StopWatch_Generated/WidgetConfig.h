/*
 * WidgetConfig.h
 *
 *  Created on: 22/ott/2015
 *      Author: admim
 */

#ifndef WIDGETCONFIG_H_
#define WIDGETCONFIG_H_

#define NUMWIDGETS 13

#define BAKCG 0
#define BTIME 1
#define BTIMESET 2
#define BALARM 3
#define BSWATCH 4
#define BPLU 5
#define BMINUS 6
#define HRSSTR 7
#define MINSTR 8
#define SECSTR 9
#define TTSSTR 10
#define SEP1STR 11
#define SEP2STR 12

#define TIMEMODE 0x01
#define TIMESETMODE 0x02
#define ALARMMODE 0x04
#define SWATCHMODE 0x08
#define PLUS 0x10
#define MINUS 0x20

extern const Widget MyWatchScr[NUMWIDGETS];

#endif /* WIDGETCONFIG_H_ */
