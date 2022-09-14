#pragma once
#include <vector>
#include "raylib.h"

class Common
{
public:
	float GameScreenWidth;
	float GameScreenHeight;

	float GetRandomScreenY();
	float GetRandomFloat(float min, float max);


private:
};

