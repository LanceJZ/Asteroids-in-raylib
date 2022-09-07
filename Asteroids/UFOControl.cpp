#include "UFOControl.h"

void UFOControl::LoadModel(Model theModel, Model shot)
{
	ufo->LoadModel(theModel, shot);
	Reset();
}

void UFOControl::Update(float deltaTime) //add Y edge loop, and disable of off X edge.
{
	ufo->Update(deltaTime);
	timer->Update(deltaTime);

	if (timer->Elapsed() && !ufo->Enabled)
	{
		SpawnUFO();
	}
	else if (ufo->Enabled)
	{
		ResetTimer();
	}
}

void UFOControl::Draw()
{
	ufo->Draw();
}

void UFOControl::Reset()
{
	ResetTimer();
	spawnCount = 0;
	ufo->Enabled = false;
	ufo->shot->Enabled = false;
}

UFOControl::UFOControl(float playScreenW, float playScreenH, Player* player)
{
	GameScreenWidth = playScreenW;
	GameScreenHeight = playScreenH;

	ufo = new UFO(playScreenW, playScreenH, player);

	timer = new Timer();
	Reset();
}

void UFOControl::SpawnUFO()
{
	spawnCount++;
	ResetTimer();
	ufo->Spawn({ -GameScreenWidth, GameScreenHeight / 2, 0 }, { 5, 0, 0 });
}

void UFOControl::ResetTimer()
{
	float amt = GetRandomValue(10.0f, 11.0f); //10-wave * 0.1, 10.15 + wave * 0.1
	timer->Reset(amt);
}
