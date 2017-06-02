void build_logical_arrays(int _startPosition){
	// build logical arrays
	int logical_array_one_position = _startPosition;
	int logical_array_two_position = _startPosition-1;
	for (int a = 0;a <= ((NUM_LEDS/2)-1); a++)
	{
		if (logical_array_one_position > NUM_LEDS-1)
		{
			logical_array_one_position=logical_array_one_position-NUM_LEDS;
		}
		if (logical_array_two_position < 0)
		{
			logical_array_two_position=logical_array_two_position+NUM_LEDS;
		}
		logical_array_one[a]=logical_array_one_position;
		logical_array_two[a]=logical_array_two_position;
		logical_array_one_position++;
		logical_array_two_position--;
	}

}
