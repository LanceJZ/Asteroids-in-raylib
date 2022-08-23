#pragma once
#include "raylib.h"
#include "PositionedObject.h"

class Entity : PositionedObject
{
public:
	using PositionedObject::MaxSpeed;
	using PositionedObject::Position;
	using PositionedObject::RotationZ;
	using PositionedObject::Rotation;
	using PositionedObject::Velocity;
	using PositionedObject::Acceleration;
	using PositionedObject::Velocity2;
	using PositionedObject::Acceleration2;
	using PositionedObject::Position2;

	bool Enabled = true;

	virtual float X();
	virtual float Y();
	virtual float Z();
	virtual void X(float x);
	virtual void Y(float y);
	virtual void Z(float z);

	Model model;

	virtual void LoadModel(Model model);
	virtual void Update(float deltaTime);
	virtual void Draw();

	Entity();

private:

};

