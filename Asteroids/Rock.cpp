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
	Radius = 3.0f;
	Enabled = true;
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
		Entity* shot = (Entity*)player->shots[i];

		if (CirclesIntersect(shot))
		{
			player->shots[i]->Enabled = false;
			return true;
		}
	}

	return false;
}
