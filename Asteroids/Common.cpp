#include "Common.h"

bool Common::Initialise()
{

	return false;
}

float Common::GetRandomScreenY() //Fix so it is float.
{
	//return GetRandomValue(-GameScreenHeight, GameScreenHeight);
	return GetRandomFloat(-GameScreenHeight, GameScreenHeight);
}

float Common::GetRandomFloat(float min, float max)
{
	default_random_engine eng(rd());
	uniform_real_distribution<float> distr(min, max);

	return distr(eng);
}
