#pragma once
#include "raylib.h"
#include "Common.h"
#include "Player.h"
#include "UFO.h"
#include "Timer.h"

class UFOControl : public Common
{
public:
	virtual void LoadModel(Model theModel, Model shot);
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Reset();

	UFOControl(float playScreenW, float playScreenH, Player* player);

private:
	int spawnCount = {0};

	Timer* timer;
	UFO* ufo;

	void SpawnUFO();
	void ResetTimer();
};

