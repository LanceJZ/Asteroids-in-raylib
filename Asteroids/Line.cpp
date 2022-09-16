#include "Line.h"
#include "raymath.h"

void Line::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	timer->Update(deltaTime);

	posStart = Vector3Add(startPos, Position);
	posEnd = Vector3Add(endPos, Position);

	if (timer->Elapsed())
	{
		Enabled;
	}
}

void Line::Draw()
{
	DrawLine3D(posStart, posEnd, WHITE);
}

void Line::Load()
{

}

void Line::LoadModel(Model model, Model shotmodel)
{

}

void Line::Spawn(Vector3 pos)
{
	Position = pos;
	Velocity = { GetRandomFloat(-1.0f, 1.0f), GetRandomFloat(-1.0f, 1.0f) , 0 };
	startPos = {GetRandomFloat(-1.0f, 1.0f), GetRandomFloat(-1.0f, 1.0f) , 0};
	endPos = { GetRandomFloat(-1.0f, 1.0f), GetRandomFloat(-1.0f, 1.0f) , 0 };

	Enabled = true;
	timer->Reset(GetRandomFloat(0.5f, 1));
}

void Line::Clear()
{
	Enabled = false;
}

Line::Line()
{
	timer = new Timer();
}

Line::~Line()
{
}