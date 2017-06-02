void chase_sub()
{
	if (strcmp(gPlaylist[gCurrentTrackNumber].mName , "Randomizer") == 0)
	{
		leds[x % NUM_LEDS]=CHSV(gPlaylist[randomizerTrackNumber].mHue--, 255, high_intensity);
	}
	else
	{
		leds[x % NUM_LEDS]=CHSV(gPlaylist[gCurrentTrackNumber].mHue--, 255, high_intensity);
	}
	FastLED.show();
	x++;
	last_millis=millis ();
}
