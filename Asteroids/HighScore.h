#pragma once
#include "raylib.h"
#include <string>
using namespace std;

struct Score
{
	string Name;
	int Score;
};

class HighScore
{
public:
	Score scores[10];
	int highScore;
	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Load();
	void Save();
	void ConvertScoreListToString();
	void ConvertRawScoreListToArray();

	HighScore();
	virtual ~HighScore();

private:
	string highScoreListRaw;
};

