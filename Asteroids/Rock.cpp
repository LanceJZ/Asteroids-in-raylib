#include "Rock.h"

void Rock::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	CheckScreenEdge();
}

void Rock::Draw()
{
	Entity::Draw();
}

void Rock::Spawn(Vector3 pos, Vector3 vel)
{
	Position = pos;
	Velocity = vel;

	Scale = 0.0666;
}

void Rock::LoadModel(Model model)
{
	TheModel = model;
}

Rock::Rock(float windowWidth, float windowHeight)
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;

}
