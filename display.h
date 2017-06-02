void display ()
{
	if (strcmp(gPlaylist[gCurrentTrackNumber].mName , "Randomizer") == 0)
	{
		lcd.clear();
		lcd.setBacklight(gPlaylist[randomizerTrackNumber].mLcdColor);
		lcd.setCursor(0,0);
		lcd.print("Random");
		//		lcd.print(" ");
		//		lcd.print(randomizerTrackNumber);

		if (gPlaylist[randomizerTrackNumber].mUIVariable == 1)
		{
			lcd.print(" ");
			lcd.print(gPlaylist[randomizerTrackNumber].mHue);
			lcd.print(" ");
			lcd.print (gPlaylist[randomizerTrackNumber].mSaturation);
		}
		lcd.setCursor(0,1);
		lcd.print(gPlaylist[randomizerTrackNumber].mName);

	}
	else
	{
		lcd.clear();
		lcd.setBacklight(gPlaylist[gCurrentTrackNumber].mLcdColor);
		lcd.setCursor(0,0);
		lcd.print("Berkana");
		if (gPlaylist[gCurrentTrackNumber].mUIVariable == 1)
		{
			lcd.print(" ");
			lcd.print(gPlaylist[gCurrentTrackNumber].mHue);
			lcd.print(" ");
			lcd.print (gPlaylist[gCurrentTrackNumber].mSaturation);
		}
		lcd.setCursor(0,1);
		lcd.print(gPlaylist[gCurrentTrackNumber].mName);
	}

}