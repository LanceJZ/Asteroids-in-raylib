#pragma once
#include <vector>
#include "raylib.h"
#include "Rock.h"
using namespace std;

class RockControl
{
public:
	void NewGame(void);
	bool CheckEndOfWave(void);
	void NewWave(void);

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

	float screenWidth;
	float screenHeight;

	vector<Rock*> rocks;

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

