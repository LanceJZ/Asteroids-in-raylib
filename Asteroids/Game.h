#pragma once
#include "raylib.h"
#include "Player.h"
#include "RockControl.h"
#include "UFOControl.h"
#include "VectorModel.h"

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
	bool BeginRun();

	void GameLoop();
	void Shutdown();

	Camera camera = { 0 };


private:
	Model playerShipModel;
	void ProcessInput();
	void Update(float deltaTime);
	void Draw();
	void PlayerShipDisplay();
	void CheckPlayerClear();

	Entity playerClear;
	Player* player;
	RockControl* rockControl;
	UFOControl* theUFOControl;
	vector<Entity> playerShips;

	VectorModel* testVectorModel;
};

