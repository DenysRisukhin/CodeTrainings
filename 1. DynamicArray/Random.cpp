#include "Random.h"
#include <cstdlib>
#include <ctime>

void Random::SetRand()
{
	SetRand((int)time(NULL));
}

void Random::SetRand(int seed)
{
	srand(seed);
}

float Random::GetNumber()
{
	return rand() / (int)RAND_MAX;
}

int Random::GetNumber(
	int max
 )
{
	return 0 + rand() % max;
}