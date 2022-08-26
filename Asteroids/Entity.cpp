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

void Entity::LoadModel(Model* model)
{
	Entity::TheModel = model;
}

void Entity::Update(float deltaTime)
{
	PositionedObject::Update(deltaTime);
	TheModel->transform = MatrixRotateZ(RotationZ);      // Rotate 3D model

}

void Entity::Draw()
{
	if (Enabled)
	{
		DrawModel(*TheModel, Position, Scale, RAYWHITE);	// Draw 3D model
	}

}

void Entity::CheckScreenEdge()
{
	PositionedObject::CheckScreenEdge();
}
