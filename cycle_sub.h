void cycle_sub()
{

	if (strcmp(gPlaylist[gCurrentTrackNumber].mName , "Randomizer") == 0)
	{
		FastLED.showColor(CHSV(gPlaylist[randomizerTrackNumber].mHue, 255, high_intensity));

	}
	else
	{
		FastLED.showColor(CHSV(gPlaylist[gCurrentTrackNumber].mHue, 255, high_intensity));
	}
	last_millis=millis ();

}
