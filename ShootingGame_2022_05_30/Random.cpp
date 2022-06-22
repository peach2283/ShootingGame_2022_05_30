#include <stdlib.h>
#include <time.h>
#include "Random.h"

void Random::Init()
{
	//·£´ı ÃÊ±âÈ­
	srand(time(nullptr));
}

int Random::Range(int min, int max)
{
	int r = rand() % (max - min) + min;
	return r;
}
