#pragma once
#include "raylib.h"
#include "Player.h"
#include "RockControl.h"
#include "UFOControl.h"
#include "VectorModel.h"
#include "HighScore.h"
#include <vector>
using namespace std;

enum GameState
{
	PlayerHit,
	Over,
	InPlay,
	Pause,
	HighScores,
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
	HighScore* highscores;
	vector<Entity*> playerShips;

	VectorModel* testVectorModel;
};

