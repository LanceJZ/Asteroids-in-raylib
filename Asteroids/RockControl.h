#pragma once
#include <vector>
#include "raylib.h"
#include "Common.h"
#include "Rock.h"
using namespace std;

class RockControl : public Common
{
public:
	bool CheckEndOfWave(void);
	bool CheckPlayerClear(void);

	void NewGame(void);
	void NewWave(void);
	vector<Rock*> rocks;

	virtual void LoadModel(Model modelOne, Model modelTwo, Model modelThree,
		Model modelFour);
	virtual void Update(float deltaTime);
	virtual void Draw();

	void RockHit(Rock* rockHit);

	RockControl(float screenWidth, float screenheight, Player* player, UFO* ufo);


private:
	int rockCount;

	Model rockModels[4];

	void CreateRocks(void);
	void ClearAllRocks(void);
	void SpawnNewWave(int NumberOfRocks);
	void SpawnRocks(Vector3 pos, int count, Rock::RockSize size);
	void SpawnRock(int rock, float scale, int points, Vector3 position,
		float speed, Rock::RockSize size);
	Player* player;
	UFO* ufo;
};

