void ui ()
{
	if (buttons == BUTTON_DOWN)
	{
		// subtract one to the current pattern number
		//		gCurrentTrackNumber = gCurrentTrackNumber - 1;
		
		// If we've come to the end of the playlist, we can either
		// automatically restart it at the beginning, or just stay at the end.
		if( gCurrentTrackNumber == 0 )
		{
			gCurrentTrackNumber = (ARRAY_SIZE(gPlaylist)-1);
		}
		else
		{
			gCurrentTrackNumber--;
		}
	}
	if (buttons == BUTTON_UP)
	{
		// add one to the current pattern number
		//gCurrentTrackNumber = gCurrentTrackNumber + 1;
		
		// If we've come to the end of the playlist, we can either
		// automatically restart it at the beginning, or just stay at the end.
		if( gCurrentTrackNumber == (ARRAY_SIZE( gPlaylist)-1) )
		{
			gCurrentTrackNumber = 0;
		}
		else
		{
			gCurrentTrackNumber++;
		}
	}
	if (buttons == BUTTON_LEFT && setHue  && gPlaylist[gCurrentTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[gCurrentTrackNumber].mHue == 0)
		{
			gPlaylist[gCurrentTrackNumber].mHue = 255;
		}
		else
		{
			gPlaylist[gCurrentTrackNumber].mHue--;
		}
	}
	if (buttons == BUTTON_LEFT && setHue  && strcmp(gPlaylist[gCurrentTrackNumber].mName,"Randomizer" == 0) && gPlaylist[randomizerTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[randomizerTrackNumber].mHue == 0)
		{
			gPlaylist[randomizerTrackNumber].mHue = 255;
		}
		else
		{
			gPlaylist[randomizerTrackNumber].mHue--;
		}
	}

	if (buttons == BUTTON_RIGHT && setHue  && gPlaylist[gCurrentTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[gCurrentTrackNumber].mHue == 255)
		{
			gPlaylist[gCurrentTrackNumber].mHue = 0;
		}
		else
		{
			gPlaylist[gCurrentTrackNumber].mHue++;
		}
	}
	if (buttons == BUTTON_RIGHT && setHue  && strcmp(gPlaylist[gCurrentTrackNumber].mName,"Randomizer" == 0) && gPlaylist[randomizerTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[randomizerTrackNumber].mHue == 255)
		{
			gPlaylist[randomizerTrackNumber].mHue = 0;
		}
		else
		{
			gPlaylist[randomizerTrackNumber].mHue++;
		}
	}

	if (buttons == BUTTON_LEFT && setSaturation  && strcmp(gPlaylist[gCurrentTrackNumber].mName,"Randomizer" == 0) && gPlaylist[randomizerTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[randomizerTrackNumber].mSaturation == 0)
		{
			gPlaylist[randomizerTrackNumber].mSaturation = 255;
		}
		else
		{
			gPlaylist[randomizerTrackNumber].mSaturation--;
		}
	}
	if (buttons == BUTTON_LEFT && setSaturation  && gPlaylist[gCurrentTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[gCurrentTrackNumber].mSaturation == 0)
		{
			gPlaylist[gCurrentTrackNumber].mSaturation = 255;
		}
		else
		{
			gPlaylist[gCurrentTrackNumber].mSaturation--;
		}
	}
	if (buttons == BUTTON_RIGHT && setSaturation  && strcmp(gPlaylist[gCurrentTrackNumber].mName,"Randomizer" == 0) && gPlaylist[randomizerTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[randomizerTrackNumber].mSaturation == 255)
		{
			gPlaylist[randomizerTrackNumber].mSaturation = 0;
		}
		else
		{
			gPlaylist[randomizerTrackNumber].mSaturation++;
		}
	}

	if (buttons == BUTTON_RIGHT && setSaturation  && gPlaylist[gCurrentTrackNumber].mUIVariable == 1)
	{
		if (gPlaylist[gCurrentTrackNumber].mSaturation == 255)
		{
			gPlaylist[gCurrentTrackNumber].mSaturation = 0;
		}
		else
		{
			gPlaylist[gCurrentTrackNumber].mSaturation++;
		}
	}
	if (buttons == BUTTON_SELECT  && gPlaylist[gCurrentTrackNumber].mUIVariable == 1)
	{
		showAnalogRGB(0x000000);
		delay(100);
		setHue=!setHue;
		setSaturation=!setSaturation;
	}
	if (buttons == BUTTON_SELECT && strcmp(gPlaylist[gCurrentTrackNumber].mName,"Randomizer" == 0) && gPlaylist[randomizerTrackNumber].mUIVariable == 1)
	{
		showAnalogRGB(0x000000);
		delay(100);
		setHue=!setHue;
		setSaturation=!setSaturation;
	}
}