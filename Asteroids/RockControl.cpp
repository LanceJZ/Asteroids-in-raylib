#include "RockControl.h"

void RockControl::NewGame(void)
{

}

bool RockControl::CheckEndOfWave(void)
{
	return false;
}

void RockControl::NewWave(void)
{

}

void RockControl::Update(float deltaTime)
{
	for (int rock = 0; rock < rocks.size(); rock++)
	{

	}
}

void RockControl::Draw()
{
	for (int rock = 0; rock < rocks.size(); rock++)
	{

	}
}

RockControl::RockControl(float screenWidth, float screenheight)
{
	ScreenWidth = screenWidth;
	Screenheight = screenheight;
}

void RockControl::SpawnNewWave(int NumberOfRocks)
{
	for (int rock = 0; rock < NumberOfRocks; rock++)
	{
		bool spawnnewrock = true;

		for (int rockcheck = 0; rockcheck < rocks.size(); rockcheck++)
		{
			if (!rocks[rockcheck]->Enabled)
			{
				spawnnewrock = false;
				//rocks[rockcheck]->Spawn(Vector(0, GetRandomY()));
				break;
			}
		}

		if (spawnnewrock)
		{
			rocks.push_back(new Rock());
			//rocks[m_LargeRocks.size() - 1]->Spawn(Vector2i(0, GetRandomY()));
		}
	}
}
