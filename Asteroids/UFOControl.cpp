#include "UFOControl.h"
#include "raymath.h"

void UFOControl::LoadModel(Model theModel, Model shot)
{
	ufo->LoadModel(theModel, shot);
	Reset();
}

void UFOControl::Update(float deltaTime) //add Y edge loop, and disable of off X edge.
{
	ufo->Update(deltaTime);
	timer->Update(deltaTime);

	if (timer->Elapsed() && !ufo->Enabled && player->Enabled && !player->Entity::Hit)
	{
		SpawnUFO();
	}
	else
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
	UFOControl::player = player;

	ufo = new UFO(playScreenW, playScreenH, player);

	timer = new Timer();
	Reset();
}

void UFOControl::SpawnUFO()
{
	spawnCount++;
	ResetTimer();
	float spawnPercent = (float)(pow(0.915, spawnCount /
		(player->wave + 1)) * 100);

	if (GetRandomValue(0, 99) < spawnPercent - player->score)
	{
		ufo->size = UFO::Large;
		ufo->Scale = 0.5f;
		ufo->MaxSpeed = 5;
	}
	else
	{
		ufo->size = UFO::Small;
		ufo->Scale = 0.25f;
		ufo->MaxSpeed = 7;
	}

	float speed = 0;
	float height = GetRandomValue(GameScreenHeight / 4, GameScreenHeight / 1.25f);
	float side = 0;

	if (GetRandomValue(0, 10) < 5)
	{
		speed = 5;
		side = -GameScreenWidth;
	}
	else
	{
		speed = -5;
		side = GameScreenWidth;
	}

	ufo->Spawn({ side, height, 0 }, { speed, 0, 0 });
}

void UFOControl::ResetTimer()
{
	float amt = GetRandomValue(10.0f, 11.0f); //10-wave * 0.1, 10.15 + wave * 0.1
	timer->Reset(amt);
}
