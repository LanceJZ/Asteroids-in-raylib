#include "UFOControl.h"
#include "raymath.h"

void UFOControl::LoadModel(Model theModel, Model shot)
{
	ufo->LoadModel(theModel, shot);
	Reset();
}

void UFOControl::Update(float deltaTime)
{
	if (ufo->Enabled)
		ufo->Update(deltaTime);

	timer->Update(deltaTime);
	ufo->shot->Update(deltaTime);

	if (timer->Elapsed() && !ufo->Enabled && player->Enabled)
	{
		SpawnUFO();
	}
	else if (!player->Enabled || ufo->Enabled)
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

	if (GetRandomValue(0, 99) < spawnPercent - player->score / 400)
	{
		ufo->size = UFO::Large;
		ufo->Scale = 0.5f;
		ufo->MaxSpeed = 5.0f;
		ufo->Radius = 0.9f;
	}
	else
	{
		ufo->size = UFO::Small;
		ufo->Scale = 0.25f;
		ufo->MaxSpeed = 7.0f;
		ufo->Radius = 0.4f;
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
	float min = 10 - (player->wave * 0.1f);
	float max = 11 + (player->wave * 0.1f);
	timer->Reset(GetRandomValue(min, max));
}
