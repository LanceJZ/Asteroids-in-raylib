#include "RockControl.h"

void RockControl::NewGame(void)
{
	NewWave();
}

bool RockControl::CheckEndOfWave(void)
{
	return false;
}

void RockControl::NewWave(void)
{
	SpawnNewWave(4);
}


void RockControl::LoadModel(Model modelOne, Model modelTwo, Model modelThree, Model modelFour)
{
	RockControl::modelOne = modelOne;
	RockControl::modelTwo = modelTwo;
	RockControl::modelThree = modelThree;
	RockControl::modelFour = modelFour;
}

void RockControl::Update(float deltaTime)
{
	for (int rock = 0; rock < rocks.size(); rock++)
	{
		rocks[rock]->Update(deltaTime);
	}
}

void RockControl::Draw()
{
	for (int rock = 0; rock < rocks.size(); rock++)
	{
		rocks[rock]->Draw();
	}
}

RockControl::RockControl(float screenWidth, float screenHeight)
{
	RockControl::screenWidth = screenWidth;
	RockControl::screenHeight = screenHeight;
}

void RockControl::SpawnNewWave(int numberOfRocks)
{
	for (int rock = 0; rock < numberOfRocks; rock++)
	{
		bool spawnnewrock = true;

		for (int rockcheck = 0; rockcheck < rocks.size(); rockcheck++)
		{
			if (!rocks[rockcheck]->Enabled)
			{
				spawnnewrock = false;
				rocks[rockcheck]->Spawn({0, GetRandomY(), 0}, {0, 0, 0});
				break;
			}
		}

		if (spawnnewrock)
		{
			rocks.push_back(new Rock());
			rocks[rocks.size() - 1]->LoadModel(modelOne);
			rocks[rocks.size() - 1]->Spawn({ screenWidth, GetRandomY(), 0 }, {0, 0, 0});
		}
	}
}

float RockControl::GetRandomY()
{
	return GetRandomValue(-screenHeight, screenHeight);
}
