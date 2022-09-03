#include "RockControl.h"
#include <vector>

void RockControl::NewGame(void)
{
	rockCount = 4;
	NewWave();
}

bool RockControl::CheckEndOfWave(void)
{
	return false;
}

bool RockControl::CheckPlayerClear(void)
{


	return false;
}

void RockControl::NewWave(void)
{
	SpawnNewWave(rockCount);

	if (rockCount < 12)
		rockCount++;
}


void RockControl::LoadModel(Model modelOne, Model modelTwo, Model modelThree, Model modelFour)
{
	rockModels[0] = modelOne;
	rockModels[1] = modelTwo;
	rockModels[2] = modelThree;
	rockModels[3] = modelFour;
}

void RockControl::Update(float deltaTime)
{
	bool rockHit = false;
	Rock* rockWasHit = NULL;

	for (auto rock : rocks)
	{
		if (rock->Hit)
		{
			rockHit = true;
			rockWasHit = rock;
			rockWasHit->Hit = false;
		}
		else if (rock->Enabled)
		{
			rock->Update(deltaTime);
		}

	}

	if (rockHit)
	{
		RockHit(rockWasHit);
	}
}

void RockControl::Draw(void)
{
	for (auto rock : rocks)
	{
		if (rock->Enabled)
		{
			rock->Draw();
		}
	}
}

void RockControl::RockHit(Rock* rockHit)
{
	switch (rockHit->Size)
	{
	case Rock::Large:
		SpawnRocks(rockHit->Position, 2, Rock::Medium);
		break;

	case Rock::Medium:
		SpawnRocks(rockHit->Position, 2, Rock::Small);
		break;

	case Rock::Small:
		bool spawnWave = true;

		for (auto rock: rocks)
		{
			if (rock->Enabled)
				spawnWave = false;
		}

		if (spawnWave)
			NewWave();
		break;
	}
}

RockControl::RockControl(float screenWidth, float screenHeight, Player* player)
{
	GameScreenWidth = screenWidth;
	GameScreenWidth = screenHeight;
	RockControl::player = player;
}

void RockControl::SpawnNewWave(int numberOfRocks)
{
	SpawnRocks({ 0, 0, 0 }, numberOfRocks, Rock::Large);
}

void RockControl::SpawnRocks(Vector3 pos, int count, Rock::RockSize size)
{
	for (int rock = 0; rock < count; rock++)
	{
		bool spawnnewrock = true;
		int rockN = rocks.size();
		float maxSpeed = 10.666f;

		for (int rockcheck = 0; rockcheck < rockN; rockcheck++)
		{
			if (!rocks[rockcheck]->Enabled)
			{
				spawnnewrock = false;
				rockN = rockcheck;
				break;
			}
		}

		if (spawnnewrock)
		{
			rocks.push_back(new Rock(GameScreenWidth, GameScreenWidth, player));
			rocks[rockN]->LoadModel(rockModels[GetRandomValue(0, 3)]);
		}

		switch (size)
		{
			float speed;

		case Rock::Large:
			speed = GetRandomValue(maxSpeed / 10, maxSpeed / 3);
			rocks[rockN]->Spawn({ GameScreenWidth, GetRandomScreenY(), 0 }, speed, size);
			break;

		case Rock::Medium:
			speed = GetRandomValue(maxSpeed / 10, maxSpeed / 2);
			rocks[rockN]->Spawn(pos, speed, size);
			break;

		case Rock::Small:
			speed = GetRandomValue(maxSpeed / 10, maxSpeed);
			rocks[rockN]->Spawn(pos, speed, size);
			break;
		}
	}
}