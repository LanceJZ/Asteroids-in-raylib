#include "HighScore.h"

void HighScore::Input()
{

}

void HighScore::Update(float deltaTime)
{
	if (newHighScore)
	{
		NewHighScoreEntry();
	}
}

void HighScore::Draw()
{
	if (newHighScore)
	{
		DrawText(const_cast<char*>(highScoreEntryText.c_str()), GetScreenWidth() / 2, 200, 60, WHITE);
	}
}

void HighScore::Load()
{
	if (FileExists("HighScoreList"))
	{
		highScoreListRaw = LoadFileText("HighScoreList");
		ConvertRawScoreListToArray();
		highScore = scores[0].Score;
	}
	else
	{
		MakeNewScoreList();
	}
}

void HighScore::Save()
{
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
	int listNumber = 0;
	bool isLetter = true;
	string number = "";

	for (auto character : highScoreListRaw)
	{
		if (isLetter)
		{
			if (character !=  58) //58 for colon.
			{
				scores[listNumber].Name.append(1, character);
			}
			else
			{
				isLetter = false;
			}
		}
		else
		{
			if (character != 44) //44 for comma.
			{
				number.append(1, character);
			}
			else
			{
				scores[listNumber].Score = stoi(number);
				isLetter = true;
				listNumber++;
				number = "";
			}
		}
	}
}

void HighScore::CheckForNewHighScore(int score)
{
	for (int rank = 0; rank < 10; rank++)
	{
		if (score > scores[rank].Score)
		{
			if (rank < 9)
			{
				ScoreList oldScores[10];

				for (int oldRank = rank; oldRank < 10; oldRank++)
				{
					oldScores[oldRank] = scores[oldRank];
				}

				for (int newRank = rank; newRank < 9; newRank++)
				{
					scores[newRank + 1] = oldScores[newRank];
				}
			}

			scores[rank].Name = "XXX";
			scores[rank].Score = score;
			highScoreEntryText = "___";
			newHighScoreRank = rank;
			newHighScore = true;

			break;
		}
	}

	while (IsKeyDown(KEY_DOWN || KEY_LEFT || KEY_RIGHT))
	{
		int i = 0;
	}
}

void HighScore::NewHighScoreEntry()
{
	if (IsKeyPressed(KEY_DOWN))
	{
		highScoreSelectedLetter++;

		if (highScoreSelectedLetter > 2)
		{
			scores[newHighScoreRank].Name = highScoreEntryText;
			newHighScore = false;
			ConvertScoreListToString();
			Save();
			return;
		}
		else
		{
			highScoreEntryText[highScoreSelectedLetter] = (char)65;
		}
	}
	else if (IsKeyPressed(KEY_LEFT))
	{
		highScoreEntryText[highScoreSelectedLetter]--;

		if (highScoreEntryText[highScoreSelectedLetter] < (char)65)
		{
			highScoreEntryText[highScoreSelectedLetter] = (char)90;
		}
	}
	else if (IsKeyPressed(KEY_RIGHT))
	{
		highScoreEntryText[highScoreSelectedLetter]++;

		if (highScoreEntryText[highScoreSelectedLetter] > (char)90)
		{
			highScoreEntryText[highScoreSelectedLetter] = (char)65;
		}
	}
}

HighScore::HighScore()
{
	timer = new Timer();
}

HighScore::~HighScore()
{
}