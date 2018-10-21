#pragma once


class Random
{
public: // Interface
	
	// Initializes RNG using current time as seed.
	static void SetRand();

	// Initializes RNG.
	static void SetRand(
		int seed
	 );
	
	// Returns random number from 0.0 to 1.0 inclusively.
	static float GetNumber();

	// Returns random signed integer number from 0 to max exclusively.
	static int GetNumber(
		int max
	 );
};
