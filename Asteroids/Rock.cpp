#include "Rock.h"

void Rock::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

void Rock::Draw()
{
	Entity::Draw();
}

void Rock::Spawn(Vector3 pos, Vector3 vel)
{
	Position = pos;
	Velocity = vel;

	Scale = 0.1;
}

void Rock::LoadModel(Model model)
{
	TheModel = model;
}
