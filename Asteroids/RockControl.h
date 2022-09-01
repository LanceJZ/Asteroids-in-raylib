#pragma once
#include <vector>
#include "raylib.h"
#include "Rock.h"
using namespace std;

class RockControl
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

	RockControl(float screenWidth, float screenheight, Player* player);


private:
	enum RockSize
	{
		Small,
		Medium,
		Large
	};

	int rockCount;
	float screenWidth;
	float screenHeight;

	Model modelOne;
	Model modelTwo;
	Model modelThree;
	Model modelFour;

	void CreateRocks(void);
	void ClearAllRocks(void);
	void SpawnNewWave(int NumberOfRocks);
	void SpawnMedRocks(Vector3 pos);
	void SpawnSmallRocks(Vector3 pos);
	void SpawnRock(int rock, float scale, int points, Vector3 position,
		float speed, RockSize size);
	float GetRandomY();
	Player* player;
};

