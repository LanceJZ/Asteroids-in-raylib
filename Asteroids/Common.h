#pragma once
#include <vector>
#include <random>
#include "raylib.h"
using namespace std;

class Common
{
public:
	float GameScreenWidth;
	float GameScreenHeight;

	bool Initialise();
	float GetRandomScreenY();
	float GetRandomFloat(float min, float max);


private:
	random_device rd;
};

