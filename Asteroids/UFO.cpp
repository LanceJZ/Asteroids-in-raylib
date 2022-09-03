#include "UFO.h"

void UFO::LoadModel(Model model, Model shotmodel)
{
	TheModel = model;
	shot->LoadModel(shotmodel);
	Enabled = false;
}

void UFO::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

void UFO::Draw()
{
	Entity::Draw();
}

void UFO::Spawn(Vector3 pos, Vector3 vel)
{
	Position = pos;
	Velocity = vel;
	Enabled = true;
}
