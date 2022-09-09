#include "Entity.h"
#include "raymath.h"

float Entity::X()
{
	return Position.x;
}

float Entity::Y()
{
	return Position.y;
}

float Entity::Z()
{
	return Position.z;
}

void Entity::X(float x)
{
	Position.x = x;
}

void Entity::Y(float y)
{
	Position.y = y;
}

void Entity::Z(float z)
{
	Position.z = z;
}

void Entity::LoadModel(Model model)
{
	TheModel = model;
}

void Entity::Update(float deltaTime)
{
	if (Enabled)
	{
		PositionedObject::Update(deltaTime);
		TheModel.transform = MatrixRotateZ(RotationZ);	// Rotate 3D model
	}
}

void Entity::Draw()
{
	if (Enabled)
	{
		DrawModel(TheModel, Position, Scale, RAYWHITE);	// Draw 3D model
		DrawCircle3D(Position, Radius, { 0 }, 0, { 150, 50, 200, 200 });
	}
}

/// <summary>
/// Circle collusion detection. Target circle will be compared to this class's.
/// Will return true of they intersect. Only for use with 2D Z plane.
/// </summary>
/// <param name="target">Target Positioned Object.</param>
/// <returns></returns>
bool Entity::CirclesIntersect(Entity* target)
{
	if (!Enabled || !target->Enabled)
		return false;

	Vector3 posT = target->Position;
	float distanceX = posT.x - X();
	float distanceY = posT.y - Y();
	float radius = Radius + target->Radius;

	if ((distanceX * distanceX) + (distanceY * distanceY) < radius * radius)
		return true;

	return false;
}