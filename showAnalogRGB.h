void showAnalogRGB( const CRGB& rgb)
{
	// showAnalogRGB: this is like FastLED.show(), but outputs on
	// analog PWM output pins instead of sending data to an intelligent,
	// pixel-addressable LED strip.
	//
	// This function takes the incoming RGB values and outputs the values
	// on three analog PWM output pins to the r, g, and b values respectively.

	analogWrite(REDPIN,   rgb.r );
	analogWrite(GREENPIN, rgb.g );
	analogWrite(BLUEPIN,  rgb.b );
}
