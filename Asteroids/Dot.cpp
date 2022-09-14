#include "Dot.h"

void Dot::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	if (timer->Elapsed())
	{
		Enabled = false;
	}
}

void Dot::Draw()
{
	DrawPoint3D(Position, WHITE);
}

bool Dot::Initialise()
{
	timer = new Timer();
	Enabled = false;

	return false;
}

void Dot::Spawn(Vector3 position, float time)
{
	Position = position;
	Velocity = { GetRandomValue(-10.0f, 10.0f), GetRandomValue(-10.0f, 10.0f),
		GetRandomValue(-10.0f, 10.0f) };
	timer->Set(time);
	Enabled = true;
}

void Dot::Clear()
{
	Enabled = false;
}
