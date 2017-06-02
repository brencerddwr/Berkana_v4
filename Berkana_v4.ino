/***************************************************************************/
//LED sign for our home using RadioShack Tricolor LED Strip
//  By Richard Bailey
//
//  Version 4.0.0
// complete rebuild to try and deal with slow output while UI is active
//
// Version 3.0.0
// complete recode to allow easier addition of patterns and features
// convert to HSV and redesign UI
//
// Version 2.2.3
// User interface fixed for now, brightness implemented.
// Future updates from this point will most likely to clean up the code and reduce size.
//
// Version 2.2.2
// Start implementation of menu options to adjust brightness and frame speed
// frame delay adjustment implemented, need to tweak user interface to be more
// user friendly.
//
// Version 2.2.1
// move kelley pattern out of main loop into subroutine as prep for menu system.
//
// Version 2.2.0
// physical prototyping board with  LED connector, analog color selector and circuits on it built.
// incorporate LCD sample code to begin working on menu system.
// reorganize code to be closer to standard practices.
//
//  Version 2.1.1
//  complete restucture to stop using delay()
//
// Version 2.1.0
// convert colors from RGB to HSV to allow simple addition of color picker
//
// Version 2.0.4
// June 24, 2014
// implement use of high_intensity variable, move blanking to subroutine, and bug fixes
//
//
// Version 2.0.3
// June 20, 2014
// setup color codes into two dimensional array and a code option to
// have random colors. Currently set to cycle through the preprogrammed colors.
// Need to get the display shield to program the
// interface for stand alone operation as well as a 12vdc power supply
// of at least 2 amps.
//
//
// Version 2.0.2
// June 20, 2014
// converted from using hex color codes to individual RGB colors
// to allow custom color selection with on board controls planned
// for later versions.
// now includes output to serial for debugging use.
//
//
// Version 2.0.1
// complete rebuild using FastLED library instead of the RadioShack code.
/***************************************************************************/

void chase_sub();
void cycle_sub();
void kelley_pattern_new ();
void drawFractionalBar(int,int,byte,byte);
void build_logical_arrays(int);
void colorBars();
void ui();
void display();
void randomizer();
//void showAnalogRGB();

#include <avr/pgmspace.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#include <FastLED.h>

#include "defines.h"
#include "showAnalogRGB.h"
#include "colorBars.h"
#include "chase_sub.h"
#include "cycle_sub.h"
#include "drawFractionalBar.h"
#include "build_logical_arrays.h"
#include "ui.h"
#include "kelley_pattern_new.h"
#include "display.h"
#include "randomizer.h"
#include "seedOut.h"

void setup()
{
//	while(!Serial);
// 	Serial.begin(115200);
	unsigned long seed=seedOut(31);
// 	Serial.println(seed);
	randomSeed(seed);
	do
	{
		randomizerTrackNumber = random(0,(ARRAY_SIZE(gPlaylist)));
// 		Serial.println(randomizerTrackNumber);
	} while (strcmp(gPlaylist[randomizerTrackNumber].mName , "Randomizer")==0);

	for (int i = 0; i < ((ARRAY_SIZE(gPlaylist))); i++)
	{
		if (strcmp(gPlaylist[i].mName , "Randomizer") == 0)
		{
			gCurrentTrackNumber = i;
		}
	}

	// set up the LCD's number of columns and rows:
	lcd.begin(16, 2);
	lcd.setBacklight(RED);
	lcd.print("Booting");
	build_logical_arrays(logical_array_one_start);

	// sanity check delay - allows reprogramming if accidently blowing power w/leds
	delay(3000);


	// Change this line as needed to match the LED string type, control chip and color sequence
	FastLED.addLeds<TM1803, DATA_PIN, GBR>(leds, NUM_LEDS); // RadioShack LED String

	// turn off all leds
	FastLED.clear();
	FastLED.show();
	FastLED.setBrightness(32);
	delay (200);

	pinMode(REDPIN,   OUTPUT);
	pinMode(GREENPIN, OUTPUT);
	pinMode(BLUEPIN,  OUTPUT);

	// Flash the "hello" color sequence: R, G, B, black.
	colorBars();
	lcd.clear();
	lcd.setBacklight(GREEN);
	lcd.setCursor(0,0);
	lcd.print("Berkana");
	lcd.setCursor(0,1);
	lcd.print("Ready");
	delay (1000);
	// 	lcd.setCursor(0,1);
	// 	lcd.print(gPlaylist[gCurrentTrackNumber].mName);
	// 	lcd.setBacklight(gPlaylist[gCurrentTrackNumber].mLcdColor);
	display ();
	last_button=millis();
	last_millis=millis();


}

void loop()
{
	// read the analog in value: and adjust brightness
	sensorValue = analogRead(analogInPin);
	brightness = constrain(map(sensorValue, 0, 1023, 80, 255),80,255);
	if (high_intensity != brightness)
	{
		high_intensity = brightness;
	}
	FastLED.setBrightness(brightness);

	if (strcmp(gPlaylist[gCurrentTrackNumber].mName , "Randomizer") == 0)
	{
		if ((millis ()-last_millis) > 1000/gPlaylist[randomizerTrackNumber].mFPS)
		{
			switch(gPlaylist[randomizerTrackNumber].mColorCycle)
			{
				
				case 0:
				break;
				
				case 1:
				gPlaylist[randomizerTrackNumber].mHue--;
				break;
				
				case 2:
				gPlaylist[randomizerTrackNumber].mHue++;
				break;
				
			}
			gPlaylist[randomizerTrackNumber].mPattern ();
			showAnalogRGB( CHSV(gPlaylist[randomizerTrackNumber].mHue,gPlaylist[randomizerTrackNumber].mSaturation,brightness));
		}

	}
	else
	{
		if ((millis ()-last_millis) > 1000/gPlaylist[gCurrentTrackNumber].mFPS)
		{
			switch(gPlaylist[gCurrentTrackNumber].mColorCycle)
			{
				
				case 0:
				break;
				
				case 1:
				gPlaylist[gCurrentTrackNumber].mHue--;
				break;
				
				case 2:
				gPlaylist[gCurrentTrackNumber].mHue++;
				break;
				
			}
			gPlaylist[gCurrentTrackNumber].mPattern ();
			showAnalogRGB( CHSV(gPlaylist[gCurrentTrackNumber].mHue,gPlaylist[gCurrentTrackNumber].mSaturation,brightness));
		}
	}

	// check for button
	buttons = lcd.readButtons();
	if (buttons && millis()-last_button > menuDelay)
	{
		ui ();
		display ();
	}
	EVERY_N_MINUTES (10)
	{
		randomizer();
	}

}
