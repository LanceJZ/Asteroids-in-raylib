#include "UFO.h"
#include "raymath.h"

void UFO::LoadModel(Model model, Model shotmodel)
{
	TheModel = model;
	shot->LoadModel(shotmodel);
	Enabled = false;
	BeenHit = false;
}

void UFO::LoadSound(Sound exp, Sound big, Sound small)
{
	SoundMain = exp;
	SoundSecond = big;
	SoundThird = small;

	SetSoundVolume(SoundMain, 0.5f);
	SetSoundVolume(SoundSecond, 0.5f);
	SetSoundVolume(SoundThird, 0.5f);
}

void UFO::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	exploder->Update(deltaTime);

	if (Enabled)
	{
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
	}

	if (CheckCollision())
	{
		Enabled = false;
		BeenHit = true;
		exploder->Spawn(Position, 15, radius / 2.0f);
		PlaySound(SoundMain);
		StopSound(SoundSecond);
		StopSound(SoundThird);
	}

	switch (size)
	{
	case UFO::Small:
		if (!IsSoundPlaying(SoundThird))
		{
			PlaySound(SoundThird);
		}
		break;
	case UFO::Large:
		if (!IsSoundPlaying(SoundSecond))
		{
			PlaySound(SoundSecond);
		}
		break;
	default:
		break;
	}
}

void UFO::Draw()
{
	if (!BeenHit)
		Entity::Draw();

	exploder->Draw();
}

bool UFO::Initialise()
{
	return false;
}

void UFO::Spawn(Vector3 pos, Vector3 vel)
{
	Position = pos;
	Velocity = vel;
	Enabled = true;
	BeenHit = false;

	ResetVectorTimer();
	ResetFireTimer();
	ChangeVector();
}

UFO::UFO(float windowWidth, float windowHeight, Player* player)
{
	shot = new Shot(windowWidth, windowHeight);
	UFO::player = player;
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	fireTimer = new Timer();
	vectorTimer = new Timer();
	exploder = new Exploder();
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
	if (GetRandomFloat(1, 10) < 7)
	{
		if ((int)Velocity.y == 0)
		{
			if (GetRandomFloat(1, 10) < 5)
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
		ang = GetRandomRadian();
		break;
	case UFO::Small:
		ang = AimedShot();
		break;
	}

	if (!shot->Enabled)
	{
		Vector3 offset = Vector3Add(VelocityFromAngleZ(ang, Radius), Position);

		shot->Spawn(offset,	VelocityFromAngleZ(ang, shotSpeed), 1.75f);
	}
}

void UFO::GiveScore()
{
	switch (size)
	{
	case Large:
		player->ScoreUpdate(200);
		break;
	case Small:
		player->ScoreUpdate(1000);
		break;
	}
}

bool UFO::CheckCollision()
{
	if (shot->CirclesIntersect(player))
	{
		player->Hit();
		shot->Enabled = false;
	}

	if (CirclesIntersect(player))
	{
		player->Hit();
		GiveScore();
		return true;
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

	percentChance += GetRandomFloat(0.0, 0.05f);

	return AngleFromVectorZ(player->Position) +
		GetRandomFloat(-percentChance, percentChance);

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