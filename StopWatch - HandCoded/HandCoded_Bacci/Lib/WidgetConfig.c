/*
 * WidgetConfig.c
 *
 *  Created on: 21/ott/2015
 *      Author: admim
 */

#include "Widget.h"
#include "WidgetConfig.h"
#include "../Assets/pictures.h"

#include <stdio.h>
#include "stm32f4_discovery_lcd.h"
#include "fonts.h"

ButtonIcon buttontime = {
		icontime_on, icontime_off, 0, 0, TIMEMODE
};

ButtonIcon buttontimeset = {
		icontimeset_on, icontimeset_off, 0, 0, TIMESETMODE
};

ButtonIcon buttonalarm = {
		iconnalarm_on, iconnalarm_off, iconalarm_on, iconalarm_off, ALARMMODE
};

ButtonIcon buttonswatch = {
		iconswatch_on, iconswatch_off, 0, 0, SWATCHMODE
};

ButtonIcon buttonplus = {
		0, 0, 0, 0, PLUS
};

ButtonIcon buttonminus = {
		0, 0, 0, 0, MINUS
};

Text txth = {
		&Font32x48, White, back_hours
};

Text txtm = {
		&Font32x48, White, back_minutes
};

Text txts = {
		&Font32x48, White, back_seconds
};

Text txtt = {
		&Font32x48, White, back_tenths
};

Text txtsephm = {
		&Font32x48, White, backsep_hm
};

Text txtsepms = {
		&Font32x48, White, backsep_ms
};

Text txtsepst = {
		&Font32x48, White, backsep_st
};

Image backg = {
	image_background
};

const Widget MyWatchScr[NUMWIDGETS] = {
		{0, 0, 320, 240, BACKGROUND, (void *)&backg},
		{30, 190, 40, 40, BUTTONICON, (void *)&buttontime},
		{100, 190, 40, 40, BUTTONICON, (void *)&buttontimeset},
		{170, 190, 40, 40, BUTTONICON, (void *)&buttonalarm},
		{240, 190, 40, 40, BUTTONICON, (void *)&buttonswatch},
		{250, 20, 50, 50, BUTTONICON, (void *)&buttonplus},
		{250, 90, 50, 50, BUTTONICON, (void *)&buttonminus},
		{10, 90, 60, 40, TEXT, (void *)&txth},
		{80, 90, 60, 40, TEXT, (void *)&txtm},
		{150, 90, 60, 40, TEXT, (void *)&txts},
		{220, 90, 30, 40, TEXT, (void *)&txtt},
		{60, 90, 20, 40, TEXT, (void *)&txtsephm},
		{130, 90, 20, 40, TEXT, (void *)&txtsepms},
		{200, 90, 20, 40, TEXT, (void *)&txtsepst},
};

