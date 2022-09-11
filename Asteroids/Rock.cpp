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
	Rock::size = size;

	switch (size)
	{
	case Small:
		Scale = 0.0666f / 4;
		Radius = 3.0f / 4;
		break;
	case Medium:
		Scale = 0.0666f / 2;
		Radius = 3.0f / 2;
		break;
	case Large:
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

void Rock::GiveScore()
{
	switch (size)
	{
	case Large:
		player->score += 20;
		break;
	case Medium:
		player->score += 50;
		break;
	case Small:
		player->score += 100;
		break;
	}
}

bool Rock::CheckCollision()
{
	for (auto shot : player->shots)
	{
		if (CirclesIntersect(shot))
		{
			shot->Enabled = false;
			GiveScore();

			return true;
		}
	}

	if (CirclesIntersect(player))
	{
		player->Hit();
		GiveScore();

		return true;
	}

	if (CirclesIntersect(ufo))
	{
		ufo->Enabled = false;

		return true;
	}

	if (CirclesIntersect(ufo->shot))
	{
		ufo->shot->Enabled = false;

		return true;
	}

	return false;
}
