void colorBars()
{
	// colorBars: flashes Red, then Green, then Blue, then Black.
	// Helpful for diagnosing if you've mis-wired which is which.

	showAnalogRGB( CRGB::Red );
	fill_solid ( &(leds[0]), NUM_LEDS, CRGB::Red);
	FastLED.show();
	delay(350);
	showAnalogRGB( CRGB::Green );
	fill_solid ( &(leds[0]), NUM_LEDS, CRGB::Green);
	FastLED.show();
	delay(350);
	showAnalogRGB( CRGB::Blue );
	fill_solid ( &(leds[0]), NUM_LEDS, CRGB::Blue);
	FastLED.show();
	delay(350);
	showAnalogRGB( CRGB::Black );
	fill_solid ( &(leds[0]), NUM_LEDS, CRGB::Black);
	FastLED.show();
}
