#include "UFO.h"
#include "raymath.h"

void UFO::LoadModel(Model model, Model shotmodel)
{
	TheModel = model;
	shot->LoadModel(shotmodel);
	Enabled = false;
	BeenHit = false;
}

void UFO::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	fireTimer->Update(deltaTime);
	vectorTimer->Update(deltaTime);
	CheckScreenEdgeY();

	if (CheckReachedSide())
	{
		Enabled = false;
	}

	if (vectorTimer->Elapsed())
	{
		ChangeVector();
		ResetVectorTimer();
	}

	if (fireTimer->Elapsed())
	{
		FireShot();
		ResetFireTimer();
	}

	if (CheckCollision())
	{
		Enabled = false;
		BeenHit = true;
	}
}

void UFO::Draw()
{
	if (!BeenHit)
		Entity::Draw();

	shot->Draw();
}

void UFO::Spawn(Vector3 pos, Vector3 vel)
{
	Position = pos;
	Velocity = vel;
	Enabled = true;
	BeenHit = false;

	ResetVectorTimer();
	ResetFireTimer();
}

UFO::UFO(float windowWidth, float windowHeight, Player* player)
{
	shot = new Shot(windowWidth, windowHeight);
	UFO::player = player;
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	fireTimer = new Timer();
	vectorTimer = new Timer();
	Radius = 0.9f;
}

void UFO::ResetFireTimer()
{
	fireTimer->Reset(2.75f);
}

void UFO::ResetVectorTimer()
{
	vectorTimer->Reset(3.15f);
}

void UFO::ChangeVector()
{
	if (GetRandomValue(1, 10) < 7)
	{
		if ((int)Velocity.y == 0)
		{
			if (GetRandomValue(1, 10) < 5)
			{
				Velocity.y = MaxSpeed;
			}
			else
			{
				Velocity.y = -MaxSpeed;
			}
		}
		else
		{
			Velocity.y = 0;
		}
	}
}

void UFO::FireShot()
{
	float ang = 0;
	float shotSpeed = 15;

	switch (size)
	{
	case UFO::Large:
		ang = GetRandomValue(0, PI * 2);
		break;
	case UFO::Small:
		ang = AimedShot();
		break;
	}

	if (!shot->Enabled)
	{
		Vector3 offset = VelocityFromAngleZ(ang, Radius);
		offset.x += Position.x;
		offset.y += Position.y;

		Vector3;

		shot->Spawn(offset,	VelocityFromAngleZ(ang, shotSpeed), 1.45f);
	}
}

void UFO::GiveScore()
{
	switch (size)
	{
	case Large:
		player->score += 200;
		break;
	case Small:
		player->score += 1000;
		break;
	}
}

bool UFO::CheckCollision()
{
	if (CirclesIntersect(player))
	{
		player->Hit();
		GiveScore();
		return true;
	}

	if (shot->CirclesIntersect(player))
	{
		player->Hit();
		shot->Enabled = false;
	}

	for (auto shot : player->shots)
	{
		if (CirclesIntersect(shot))
		{
			shot->Enabled = false;
			GiveScore();
			return true;
		}
	}

	return false;
}

float UFO::AimedShot()
{
	float percentChance = 0.2f - (player->score * 0.00001f);

	if (percentChance < 0)
	{
		percentChance = 0;
	}

	percentChance += GetRandomValue(0.0, 0.05f);

	return AngleFromVectorZ(player->Position) +
		GetRandomValue(-percentChance, percentChance);

}

float UFO::AngleFromVectorZ(Vector3 target)
{
	return atan2(target.y - Y(), target.x - X());
}

Vector3 UFO::VelocityFromAngleZ(float rotation, float magnitude)
{
	return { (float)cos(rotation) * magnitude,
				(float)sin(rotation) * magnitude, 0 };
}

Vector3 UFO::VelocityFromAngleZ(float magnitude)
{
	float ang = GetRandomValue(0, PI * 2);

	return VelocityFromAngleZ(ang, magnitude);
}

bool UFO::CheckReachedSide()
{
	if (X() < -WindowWidth)
	{
		return true;
	}
	if (X() > WindowWidth)
	{
		return true;
	}

	return false;
}