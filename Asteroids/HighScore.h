#pragma once
#include "raylib.h"
#include "Timer.h"
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
	bool gameOver = false;
	int highScore = { 0 };
	ScoreList scores[10];
	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Load();
	void Save();
	void MakeNewScoreList();
	void ConvertScoreListToString();
	void ConvertRawScoreListToArray();
	void CheckForNewHighScore(int score);
	void NewHighScoreEntry();

	HighScore();
	virtual ~HighScore();

private:
	bool newHighScore = false;
	int newHighScoreRank = 0;
	int highScoreSelectedLetter = 0;
	string highScoreEntryText = "";
	string highScoreListRaw = "";
	Timer* timer;
};

