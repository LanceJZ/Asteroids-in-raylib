#pragma once
#include "raylib.h"
#include "Entity.h"
#include "PositionedObject.h"
#include "Shot.h"

class Player : Entity
{
public:
	using Entity::Enabled;
	using Entity::Position;

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void LoadModel(Model model, Model shotmodel);

	Player(float windowWidth, float windowHeight);

private:
	float radius{ 5 };
	float windowWidth;
	float windowHeight;
	bool thrustOff = true;
	Color color{ LIGHTGRAY };
	Model shotModel;
	void ThrustOn();
	void ThrustOff();

	Shot* shot;
};

