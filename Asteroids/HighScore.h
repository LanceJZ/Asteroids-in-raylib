#pragma once
#include "raylib.h"
#include <string>
using namespace std;

struct ScoreList
{
	string Name;
	int Score;
};

class HighScore
{
public:
	ScoreList scores[10];
	int highScore = { 0 };
	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Load();
	void Save();
	void MakeNewScoreList();
	void ConvertScoreListToString();
	void ConvertRawScoreListToArray();
	void CheckForNewHighScore(int score);

	HighScore();
	virtual ~HighScore();

private:
	string highScoreListRaw = "";
	bool newHighScore = false;
	int newHighScoreRank = 0;
};

