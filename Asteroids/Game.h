#pragma once
#include "raylib.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	bool Initialise();
	bool Load();
	void GameLoop();
	void Shutdown();

	Camera camera = { 0 };


private:
	void ProcessInput();
	void Update(float deltaTime);
	void Draw();

	Player* player;
};

