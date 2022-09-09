#include "Rock.h"
#include "raymath.h"

void Rock::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	CheckScreenEdge();

	if (CheckCollision())
	{
		BeenHit = true;
		Enabled = false;
	}
}

void Rock::Draw()
{
	Entity::Draw();
}

void Rock::Spawn(Vector3 pos, float speed, RockSize size)
{
	float magnitude = GetRandomValue(1.1f, 5.1f);
	float angle = GetRandomValue(0, PI * 2);
	Vector3 dir = {cos(angle) * magnitude, sin(angle) * magnitude};

	Position = pos;
	Velocity = dir;
	Size = size;

	switch (size)
	{
	case Rock::Small:
		Scale = 0.0666f / 4;
		Radius = 3.0f / 4;
		break;
	case Rock::Medium:
		Scale = 0.0666f / 2;
		Radius = 3.0f / 2;
		break;
	case Rock::Large:
		Scale = 0.0666f;
		Radius = 3.0f;
		break;
	}

	Enabled = true;
	BeenHit = false;
}

void Rock::LoadModel(Model model)
{
	TheModel = model;
}

Rock::Rock(float windowWidth, float windowHeight, Player* player, UFO* ufo)
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	Rock::player = player;
	Rock::ufo = ufo;
}

bool Rock::CheckCollision()
{
	for (auto shot : player->shots)
	{
		if (CirclesIntersect(shot))
		{
			shot->Enabled = false;
			return true;
		}
	}

	//for (int i = 0; i < 4; i++)
	//{
	//	Entity* shot = (Entity*)player->shots[i];

	//	if (CirclesIntersect(shot))
	//	{
	//		player->shots[i]->Enabled = false;
	//		return true;
	//	}
	//}

	if (CirclesIntersect(player))
	{
		if (player->Enabled)
			player->Hit();

		return true;
	}

	return false;
}
