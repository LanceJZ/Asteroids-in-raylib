#include "HighScore.h"

void HighScore::Input()
{

}

void HighScore::Update(float deltaTime)
{

}

void HighScore::Draw()
{

}

void HighScore::Load()
{
	if (FileExists("HighScoreList"))
	{
		highScoreListRaw = LoadFileText("HighScores");
	}

	if (FileExists("HighScore"))
	{
		highScore = atoi(LoadFileText("HighScore")); //Load Text high score as int.
	}
}

void HighScore::Save()
{
	SaveFileText("HighScore", const_cast<char*>(to_string(highScore).c_str()));
	SaveFileText("HighScoreList", const_cast<char*>(highScoreListRaw.c_str()));
}

void HighScore::ConvertScoreListToString()
{

}

void HighScore::ConvertRawScoreListToArray()
{

}

HighScore::HighScore()
{

}

HighScore::~HighScore()
{
}