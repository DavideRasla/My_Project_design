/*!	\file	Button.h
 	\author Daniel Casini
 	\date	10/03/2014
	\brief	Button handling file for the watch
*/

#ifndef WIDGET_H_
#define WIDGET_H_

#include "Event.h"
#include "Touch.h"
#include "fonts.h"


typedef enum  {
	BACKGROUND, BUTTONICON, TEXT, IMAGE, BACKTEXT
} WidgetType;

typedef struct {
	unsigned char *image;
} Image;

typedef struct {
	unsigned char *iconp;
	unsigned char *iconr;
	unsigned char *icon2p;
	unsigned char *icon2r;
	Event		  onpress;
} ButtonIcon;

typedef struct {
	sFONT *font;
	unsigned short int	color;
	unsigned char *background;
} Text;

typedef struct {
	const Text super;
	unsigned char *background;
} BackText;

typedef struct {
	unsigned short int xl;
	unsigned short int yt;
	unsigned short int xw;
	unsigned short int yh;
	WidgetType wt;
	void     *ws;
} Widget;

#define txtinfo(w) ((Text *)((w)->ws))
#define biconinfo(w) ((ButtonIcon *)((w)->ws))
#define imginfo(w) ((Image *)((w)->ws))
#define backinfo(w) ((BackText *)((w)->ws))

unsigned char OnTouch(const Widget ws[], TPoint *press);
unsigned char DrawInit(const Widget ws[]);
unsigned char DrawOn(const Widget *w);
unsigned char DrawOff(const Widget *w);
unsigned char DrawOn2(const Widget *w);
unsigned char DrawOff2(const Widget *w);
unsigned char WPrint(const Widget *w, char *s);
unsigned char WClear(const Widget *w);
unsigned char WErase(const Widget *w);

#endif /* BUTTON_H_ */
