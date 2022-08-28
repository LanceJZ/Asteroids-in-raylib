#pragma once
#include "raylib.h"
#include "Player.h"
#include "RockControl.h"

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
	float windowWidth;
	float windowHeight;

	void ProcessInput();
	void Update(float deltaTime);
	void Draw();

	Player* player;
	RockControl* rockControl;
};

