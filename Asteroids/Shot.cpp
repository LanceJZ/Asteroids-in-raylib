#include "Shot.h"

Shot::Shot()
{
}

Shot::Shot(float windowWidth, float windowHeight)
{
	Enabled = false;
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;

	Scale = 0.15f;
	Radius = 0.05f;

	timer = new Timer();
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

void Shot::Spawn(Vector3 pos, Vector3 vel, float timer)
{
	Position = pos;
	Velocity = vel;
	Enabled = true;

	Shot::timer->Reset(timer);
}