#pragma once
#include "raylib.h"

class Player
{
public:
	float maxSpeed{ 50 };
	float angle;
	Vector2 acceleration;
	Vector2 velocity;

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void LoadModel(Camera *camera, Model ship);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();

	Player(Vector2 pos);
	Player();

private:
	Model ship;

	Camera *camera;
	Vector2 position{ 0, 0 };
	float radius{ 5 };
	bool thrustOff;
	Color color{ LIGHTGRAY };
	const int screenWidth = 800;
	const int screenHeight = 600; //height

	void ThrustOn();
	void ThrustOff();
};

