/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2013  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

// ------------
// ERIKA LIBS
// ------------
#include "ee.h"
#include "ee_irq.h"
#include <stdio.h>
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "stm32f4xx.h"

// ---------------
// DI NATALE LIBS
// ---------------
#include "Lib/STMPE811QTR.h"
#include "Lib/Widget.h"
#include "Lib/WidgetConfig.h"
#include "Lib/Touch.h"
#include "Lib/Event.h"

// ---------------------
// SIMULINK AND ASSETS
// ---------------------
#include "Machine/Subsystem.h"
#include "Assets/pictures.h"

// ------------------
// MY LIBS
// ----------------
#include "GUI_manager.h"

// ---------------------
// STOPWATCH INPUT AND OUTPUT
// ---------------------
boolean_T tick, button[6];							// input
boolean_T alarmactive, hblink, mblink, ringalarm;	// output
uint8_T hours = 0, 									// machine internal vars
		minutes = 0,
		seconds = 0,
		tenths = 0,
		mode = 0;

// -----------------------------------------------------
// SysTick ISR2
// Count the interrupts, waking up expired alarms
// -----------------------------------------------------
ISR2(systick_handler)
{
	CounterTick(myCounter);
}

// -------------------------------------------------------
// TASK LCD
// get a tap on LCD touch-screen and saves the coordinates
// -------------------------------------------------------
TASK(TaskLCD)
{
	unsigned int px, py;
	TPoint p;
	if (GetTouch_SC_Async(&px, &py)) {
		p.x = px;
		p.y = py;
		OnTouch(MyWatchScr, &p);
		delay(10);	// not good thing but avoid multiple touch
	}
}

// -------------------------------------------------------
// TASK CLOCK
// run on each clock cycle, permit to the machine to evolve
// -------------------------------------------------------
TASK(TaskClock)
{

	// check if an event (button pressed) was triggered
	if (IsEvent(PLUS)) 			button[0] = 1;
	if (IsEvent(MINUS)) 		button[1] = 1;
	if (IsEvent(TIMEMODE)) 		button[2] = 1;
	if (IsEvent(TIMESETMODE)) 	button[3] = 1;
	if (IsEvent(ALARMMODE)) 	button[4] = 1;
	if (IsEvent(SWATCHMODE)) 	button[5] = 1;

	// let matlab state machine evolve
	Subsystem_step(
			button[0],
			button[1],
			button[2],
			button[3],
			button[4],
			button[5],
			&hours,
			&minutes,
			&seconds,
			&tenths,
			&mode,
			&alarmactive,
			&hblink,
			&mblink,
			&ringalarm);

	// clear events and button pressed state
	ClearEvents();
	button[0] = 0;
	button[1] = 0;
	button[2] = 0;
	button[3] = 0;
	button[4] = 0;
	button[5] = 0;

	// update all the LCD interface and widgets
	update_interface(mode, hours, minutes, seconds, tenths, alarmactive, hblink, mblink, ringalarm);
}

// -------------------------------------------------------
// TASK MAIN
// initialize the system, the RTOS and the state machine
// -------------------------------------------------------
int main(void)
{
	// initializes system and Erika related stuffs
	SystemInit();
	EE_system_init();

	// initialize matlab state machine
	Subsystem_initialize(
			button,
			button+1,
			button+2,
			button+3,
			button+4,
			button+5,
			&hours,
			&minutes,
			&seconds,
			&tenths,
			&mode,
			&alarmactive,
			&hblink,
			&mblink,
			&ringalarm);

	// initialize systick and start timer
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, SystemCoreClock));
	EE_systick_enable_int();
	EE_systick_start();

	// initializes LCD and touchscreen and set LCD touch size
	IOE_Config();
	STM32f4_Discovery_LCD_Init();
	InitTouch(-0.09, 0.0656, -353, 10);

	// initializes the interface
	init_interface();

	// cyclic alarms, trigger every 50 and 100 ms
	SetRelAlarm(AlarmTaskLCD, 10, 50);
	SetRelAlarm(AlarmTaskClock, 10, 100);

	// background activities
	for (;;) {}
}


