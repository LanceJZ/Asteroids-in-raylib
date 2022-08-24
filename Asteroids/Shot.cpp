#include "Shot.h"

Shot::Shot(Vector2 pos, float windowWidth, float windowHeight)
{
	Shot::windowWidth = windowWidth;
	Shot::windowHeight = windowHeight;
	Enabled = false;
	float perH = 60;
	float perW = 44;
	ScreenWidth = windowWidth / perW;
	ScreenHeight = windowHeight / perH;

	Scale = 0.15f;

	timer = new Timer();
	timer->Set(1.25f);
}

void Shot::LoadModel(Model model)
{
	Entity::model = model;
}

void Shot::Draw()
{
	Entity::Draw();
}

void Shot::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	Entity::CheckScreenEdge();
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