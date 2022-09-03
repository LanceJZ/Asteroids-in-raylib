#pragma once
#include "raylib.h"
#include "Player.h"
#include "RockControl.h"
#include "UFOControl.h"

enum GameState
{
	PlayerHit,
	Over,
	InPlay,
	Pause,
	HighScore,
	MainMenu
};

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
	void CheckPlayerClear();

	Entity playerClear;
	Player* player;
	RockControl* rockControl;
	UFOControl* theUFOControl;
};

