#include "Rock.h"

void Rock::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	CheckScreenEdge();

	if (CheckCollision())
	{
		Enabled = false;
	}
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
	Radius = 10;
}

void Rock::LoadModel(Model model)
{
	TheModel = model;
}

Rock::Rock(float windowWidth, float windowHeight, Player* player)
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	Rock::player = player;
}

bool Rock::CheckCollision()
{

	for (int i = 0; i < 4; i++)
	{
		Shot* shot = &player->CheckShots()[i];

		if (CirclesIntersect((Entity*)shot))
		{
			shot->Enabled = false;
			return true;
		}
	}

	return false;
}
