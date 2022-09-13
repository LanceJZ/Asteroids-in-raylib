#pragma once
#include "Entity.h"
#include "Shot.h"
#include "VectorModel.h"

class Player : public Entity
{
public:
	int wave { 0 };
	int score { 0 };
	int lives { 0 };
	bool newLife = false;

	Shot* shots[4];

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void ScoreUpdate(int addToScore);
	void NewGame();
	void Reset();
	void Hit();
	void LoadModel(Model model, Model shotmodel, Model flamemodel);
	void LoadSound(Sound fireS, Sound thrustS);
	Player(float windowWidth, float windowHeight);

private:
	int nextNewLifeScore{ 10000 };
	bool thrustOff = true;
	Color color{ RAYWHITE };
	Sound fireSound;
	Sound thrustSound;

	Entity* flame;

	void ThrustOn();
	void ThrustOff(float deltaTime);
	void Fire();
};

