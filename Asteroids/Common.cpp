#include "Common.h"

float Common::GetRandomScreenY()
{
	return GetRandomValue(-GameScreenHeight, GameScreenHeight);
}
