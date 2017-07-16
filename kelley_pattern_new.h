void kelley_pattern_new()
{
	F16pos += F16delta;
	
	// wrap around at end
	// remember that F16pos contains position in "16ths of a pixel"
	// so the 'end of the strip' is ((NUM_LEDS/2) * 16)
	if( F16pos >= ((NUM_LEDS/2) * 16))
	{
		F16pos -= ((NUM_LEDS/2) * 16);
	}
	
	
	// Draw everything:
	// clear the pixel buffer
	//	memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
	FastLED.clear();
	
	// draw the Fractional Bar, length=4px
	if (strcmp(gPlaylist[gCurrentTrackNumber].mName , "Randomizer") == 0)
	{
		drawFractionalBar( F16pos, Width, gPlaylist[randomizerTrackNumber].mHue, gPlaylist[randomizerTrackNumber].mSaturation);
	}
	else
	{
		drawFractionalBar( F16pos, Width, gPlaylist[gCurrentTrackNumber].mHue, gPlaylist[gCurrentTrackNumber].mSaturation);
	}
	
	FastLED.show();
	last_millis=millis();
}
