
<!-- saved from url=(0052)https://raw.github.com/nemith/serLCD/master/serLCD.h -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"><style id="clearly_highlighting_css" type="text/css">/* selection */ html.clearly_highlighting_enabled ::-moz-selection { background: rgba(246, 238, 150, 0.99); } html.clearly_highlighting_enabled ::selection { background: rgba(246, 238, 150, 0.99); } /* cursor */ html.clearly_highlighting_enabled {    /* cursor and hot-spot position -- requires a default cursor, after the URL one */    cursor: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--cursor.png") 14 16, text; } /* highlight tag */ em.clearly_highlight_element {    font-style: inherit !important; font-weight: inherit !important;    background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--yellow.png");    background-repeat: repeat-x; background-position: top left; background-size: 100% 100%; } /* the delete-buttons are positioned relative to this */ em.clearly_highlight_element.clearly_highlight_first { position: relative; } /* delete buttons */ em.clearly_highlight_element a.clearly_highlight_delete_element {    display: none; cursor: pointer;    padding: 0; margin: 0; line-height: 0;    position: absolute; width: 34px; height: 34px; left: -17px; top: -17px;    background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--delete-sprite.png"); background-repeat: no-repeat; background-position: 0px 0px; } em.clearly_highlight_element a.clearly_highlight_delete_element:hover { background-position: -34px 0px; } /* retina */ @media (min--moz-device-pixel-ratio: 2), (-webkit-min-device-pixel-ratio: 2), (min-device-pixel-ratio: 2) {    em.clearly_highlight_element { background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--yellow@2x.png"); }    em.clearly_highlight_element a.clearly_highlight_delete_element { background-image: url("chrome-extension://pioclpoplcdbaefihamjohnefbikjilc/clearly/images/highlight--delete-sprite@2x.png"); background-size: 68px 34px; } } </style><style>[touch-action="none"]{ -ms-touch-action: none; touch-action: none; }[touch-action="pan-x"]{ -ms-touch-action: pan-x; touch-action: pan-x; }[touch-action="pan-y"]{ -ms-touch-action: pan-y; touch-action: pan-y; }[touch-action="scroll"],[touch-action="pan-x pan-y"],[touch-action="pan-y pan-x"]{ -ms-touch-action: pan-x pan-y; touch-action: pan-x pan-y; }</style></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">/*
 serLCD.h - Library for controlling a SparkFun serLCD module
	    Code written for firmware version 2.5

 Created by Cody B. Null, September 9, 2011
 Modified by Jordan Hochenbaum, Dec 5, 2011. (Version 1.5)

 Version 1.4 - This version wrote specifically for 16x2
               Display.
               More display support coming in later version.
 
 Version 1.5 - Since mid 2011 the Arduino IDE has implemented the NewSoftSerial 
               library updates in the standard SoftwareSerial library and so 
               using NewSoftSerial is no longer needed. serLCD has been updated 
               to use the Standard SoftwareSerial library. Also, Arduino 1.0
               support has been added. Backwards compatible with previous versions.

 Note -	This library requires NewSoftSerial library
        The latest version of NewSoftSerial library can 
        always be found at http://arduiniana.org. -&gt; NO LONGER NECESSARY. See 1.5 notes above.-Jordan Hochenbaum
*/
#ifndef serLCD_h
#define serLCD_h

#if ARDUINO &gt;= 100
#include "Arduino.h"       // for delayMicroseconds,digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif
#include "SoftwareSerial.h"

// Commands
#define LCD_BACKLIGHT		0x80
#define LCD_CLEARDISPLAY	0x01
#define LCD_CURSORSHIFT		0x10
#define LCD_DISPLAYCONTROL	0x08
#define LCD_ENTRYMODESET	0x04
#define LCD_FUNCTIONSET		0x20
#define LCD_SETCGRAMADDR	0x40
#define LCD_SETDDRAMADDR	0x80
#define LCD_SETSPLASHSCREEN	0x0A
#define LCD_SPLASHTOGGLE	0x09
#define LCD_RETURNHOME		0x02

// Flags for display entry mode
#define LCD_ENTRYRIGHT		0x00
#define LCD_ENTRYLEFT		0x02

// Flags for display on/off control
#define LCD_BLINKON		0x01
#define LCD_CURSORON		0x02
#define LCD_DISPLAYON		0x04

// Flags for display size
#define LCD_2LINE		0x02
#define LCD_4LINE		0x04
#define LCD_16CHAR		0x10
#define LCD_20CHAR		0x14

//  Flags for setting display size
#define LCD_SET2LINE		0x06
#define LCD_SET4LINE		0x05
#define LCD_SET16CHAR		0x04
#define LCD_SET20CHAR		0x03

class serLCD : public SoftwareSerial {
public:
	serLCD (int pin);

	void clear();
	void clearLine(int);
	void home();
	void setBrightness(int);

	void setSplash();
	void toggleSplash();

	void blink();
	void noBlink();
	void cursor();
	void noCursor();
	void display();
	void noDisplay();

	void setCursor(int, int);
	void selectLine(int);

	void leftToRight();
	void rightToLeft();
	void autoscroll();
	void noAutoscroll();

	void createChar(int, uint8_t[]);
	void printCustomChar(int);

private:
	void command(uint8_t);
	void specialCommand(uint8_t);

	uint8_t _displayfunction;
	uint8_t _displaycontrol;
	uint8_t _displaymode;
	uint8_t _numlines;
	uint8_t _numchars;
	uint8_t _rowoffset;
};

#endif</pre></body><iframe id="evernoteFilingTools" src="./serLCD_files/filing_tools.htm"></iframe><iframe id="evernoteUserTools" src="./serLCD_files/user_tools.htm"></iframe><iframe id="evernoteShareTools" src="./serLCD_files/share_tools.htm"></iframe><iframe id="evernoteEmailSharing" src="./serLCD_files/email_sharing.htm"></iframe><iframe id="evernoteGlobalTools" src="./serLCD_files/global_tools.htm"></iframe></html>