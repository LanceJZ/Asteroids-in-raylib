#pragma once
#include "Entity.h"
#include "Shot.h"
#include "LineModel.h"
#include "Line.h"
#include <vector>

class Player : public LineModel
{
public:
	int wave { 0 };
	int score { 0 };
	int highScore{ 0 };
	int lives { 0 };
	bool newLife = false;
	bool exploding = false;
	bool gameOver = true;

	Shot* shots[4];
	vector<Line*> lines;

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void ScoreUpdate(int addToScore);
	void NewGame();
	void Reset();
	void Hit();
	void LoadModel(string shipmodel, Model shotmodel, string flamemodel);
	void LoadSound(Sound fireS, Sound thrustS, Sound exp);
	Player(float windowWidth, float windowHeight);

private:
	int nextNewLifeScore{ 10000 };
	bool thrustOff = true;
	float thrustSoundTime = { 0 };
	Color color{ RAYWHITE };

	LineModel* flame;

	void ThrustOn();
	void ThrustOff(float deltaTime);
	void Fire();
};

