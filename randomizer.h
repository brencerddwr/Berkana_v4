void randomizer(){
	do
	{
		randomizerTrackNumber = random(0,(ARRAY_SIZE(gPlaylist)));
	} while (strcmp(gPlaylist[randomizerTrackNumber].mName , "Randomizer")==0);
	display ();

}
