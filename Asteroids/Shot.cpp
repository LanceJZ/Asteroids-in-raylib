#include "Shot.h"

Shot::Shot(float windowWidth, float windowHeight)
{
	Enabled = false;
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;

	Scale = 0.15f;

	timer = new Timer();
	timer->Set(1.25f);
}

void Shot::LoadModel(Model model)
{
	TheModel = model;
}

void Shot::Draw()
{
	Entity::Draw();
}

void Shot::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	CheckScreenEdge();
	timer->Update(deltaTime);

	if (timer->Elapsed())
	{
		Enabled = false;
	}
}

void Shot::Spawn(Vector3 pos, Vector3 vel)
{
	Position = pos;
	Velocity = vel;
	Enabled = true;

	timer->Reset();
}