#pragma once
#include <vector>
#include "raylib.h"
#include "Rock.h"
using namespace std;

class RockControl
{
public:
	Rock* rock;

	void NewGame(void);
	bool CheckEndOfWave(void);
	void NewWave(void);

	virtual void Update(float deltaTime);
	virtual void Draw();

	RockControl(float screenWidth, float screenheight);

	enum RockSize
	{
		Small,
		Medium,
		Large
	};


private:
	vector<Rock*> rocks;

	void CreateRocks(void);
	void ClearAllRocks(void);
	void SpawnNewWave(int NumberOfRocks);
	void SpawnMedRocks(Vector2 location);
	void SpawnSmallRocks(Vector2 location);


};

