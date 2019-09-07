#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include "Machine/rtwtypes.h"

/**
 * Initializes the LCD screen with background and hour/minutes separator
*/
extern void init_interface();

/**
 * Updates the LCD screen and its widget
*/
extern void update_interface(uint8_T mode,
							uint8_T hours,
							uint8_T minutes,
							uint8_T seconds,
							uint8_T tenths,
							boolean_T alarmactive,
							boolean_T hblink,
							boolean_T mblink,
							boolean_T ringalarm);

/**
 * Update the current mode of stop-watch and make prepare some widget on screen
 */
void update_mode(unsigned char mode, uint8_T seconds, uint8_T tenths);

// ------------------------
// LCD TEXT CLEAR FUNCTIONS
// ------------------------

/**
 * Clear seconds text and separator if needed
 */
void seconds_text_clear(uint8_T mode);

/**
 * Clear tenths text and separator
 */
void tenths_text_clear();

// ------------------------
// LCD TEXT DRAW FUNCTIONS
// ------------------------

/**
 * Draw seconds text and separator if needed
 */
void seconds_text_draw(uint8_T old_mode, uint8_T seconds);

/**
 * Draw tenths text and separator
 */
void tenths_text_draw(uint8_T tenths);

// ---------------------------
// LCD TEXT UPDATING FUNCTIONS
// ---------------------------

/**
 * Update on-screen hours text if it is needed
 */
void update_hours_text(uint8_T newer_hours_value);

/**
 * Update on-screen minutes text if it is needed
 */
void update_minutes_text(uint8_T newer_minutes_value);

/**
 * Update on-screen seconds text if it is needed
 */
void update_seconds_text(uint8_T newer_seconds_value, uint8_T mode);

/**
 * Update on-screen tenths text if it is needed
 */
void update_tenths_text(uint8_T newer_tenths_value, uint8_T mode);

// ---------------------------
// BLINKING FUNCTIONS
// ---------------------------

/**
 * Make the text blinking if enabled is true
 */
void text_blink(uint8_T time_q, uint8_T widget_num, boolean_T enabled);

/**
 * Use the correct alarm icon and manage icon-blinking
 */
void alarmicon_manage(uint8_T mode, boolean_T active, boolean_T enabled);

// ------------------------
// UTILITY FUNCTIONS
// ------------------------

/**
 * Encode 2-digits number to string
 */
void strencode2digit(char *str, int digit);

/**
 * Encode 1-digits number to string
 */
void strencode1digit(char *str, int digit);

#endif
