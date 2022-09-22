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
	if (FileExists("HighScoreList")) //Figure out how to convert char* to string.
	{
		//char* sl = LoadFileText("HighScoresList");
		//highScoreListRaw = sl;
	}
	else
	{
		MakeNewScoreList();
	}

	if (FileExists("HighScore"))
	{
		highScore = atoi(LoadFileText("HighScore")); //Load Text high score as int.
	}
}

void HighScore::Save()
{
	if (highScore > 0)
	{
		SaveFileText("HighScore", const_cast<char*>(to_string(highScore).c_str()));
	}

	SaveFileText("HighScoreList", const_cast<char*>(highScoreListRaw.c_str()));
}

void HighScore::MakeNewScoreList()
{
	for (int i = 0; i < 10; i++)
	{
		scores[i].Name = "AAA";
		scores[i].Score = 1000;
	}

	ConvertScoreListToString();
	Save();
}

void HighScore::ConvertScoreListToString()
{
	highScoreListRaw = "";

	for (auto score : scores)
	{
		highScoreListRaw += score.Name;
		highScoreListRaw += ":";
		highScoreListRaw += to_string(score.Score);
		highScoreListRaw += ",";
	}
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