#pragma once
#include "raylib.h"
#include "PositionedObject.h"

class Player : PositionedObject
{
public:
	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void LoadModel(Model ship);
	void SetPosition(Vector2 pos);
	Vector2 GetPosition();

	Player(Vector2 pos, float windowWidth, float windowHeight);

private:
	Model ship;

	float radius{ 5 };
	float windowWidth;
	float windowHeight;
	bool thrustOff = true;
	Color color{ LIGHTGRAY };

	void ThrustOn();
	void ThrustOff();
};

