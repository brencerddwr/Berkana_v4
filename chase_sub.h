void chase_sub()
{
	if (strcmp(gPlaylist[gCurrentTrackNumber].mName , "Randomizer") == 0)
	{
		leds[chasePostiion]=CHSV(gPlaylist[randomizerTrackNumber].mHue--, 255, high_intensity);
	}
	else
	{
		leds[chasePostiion]=CHSV(gPlaylist[gCurrentTrackNumber].mHue--, 255, high_intensity);
	}
	FastLED.show();
	chasePostiion++;
	if (chasePostiion==NUM_LEDS)
	{
		chasePostiion=0;
	}
	last_millis=millis ();
}
