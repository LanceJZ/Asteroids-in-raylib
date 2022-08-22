#pragma once
#include "raylib.h"

class PositionedObject
{
public:
	bool Enabled;
	float MaxSpeed{ 0 };
	float RotationZ{ 0 };
	Vector2 Acceleration2 = { 0 };
	Vector2 Velocity2 = { 0 };
	Vector2 Position2 = { 0 };
	Vector2 Rotation2 = { 0 };
	Vector2 RotationVelocity2{ 0 };
	Vector2 RotationAcceleration2{ 0 };
	Vector3 Acceleration = { 0 };
	Vector3 Velocity = { 0 };
	Vector3 Position = { 0 };
	Vector3 Rotation = { 0 };
	Vector3 RotationVelocity = { 0 };
	Vector3 RotationAcceleration = { 0 };

	float X();
	float Y();
	float Z();
	void X(float x);
	void Y(float y);
	void Z(float z);

	PositionedObject();

	virtual void Update(float deltaTime);

private:

};

