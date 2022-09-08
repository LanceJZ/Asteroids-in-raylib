#include "UFO.h"

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
	CheckScreenEdgeY(); //TODO: Does not seem to work.

	if (CheckReachedSide())
	{
		Enabled = false;
	}

	if (vectorTimer->Elapsed())
	{
		ChangeVector();
		ResetVectorTimer();
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