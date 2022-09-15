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
	bool Initialise();

	void NewGame();

	UFOControl(float playScreenW, float playScreenH, Player* player);
	UFO* ufo;

private:
	int spawnCount = {0};

	Timer* timer;
	Player* player;

	void SpawnUFO();
	void ResetTimer();
};

