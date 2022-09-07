#pragma once
#include "raylib.h"
#include "PositionedObject.h"

class Entity : public PositionedObject
{
public:
	//using PositionedObject::MaxSpeed;
	//using PositionedObject::Position;
	//using PositionedObject::RotationZ;
	//using PositionedObject::Rotation;
	//using PositionedObject::Velocity;
	//using PositionedObject::Acceleration;
	//using PositionedObject::Velocity2;
	//using PositionedObject::Acceleration2;
	//using PositionedObject::Position2;
	//using PositionedObject::ScreenWidth;
	//using PositionedObject::ScreenHeight;

	bool Enabled = true;
	bool Hit = false;
	float Scale = 1.0f;

	virtual float X();
	virtual float Y();
	virtual float Z();
	virtual void X(float x);
	virtual void Y(float y);
	virtual void Z(float z);

	Model TheModel;

	virtual void LoadModel(Model model);
	virtual void Update(float deltaTime);
	virtual void Draw();
	bool CirclesIntersect(Entity* target);

private:

};

