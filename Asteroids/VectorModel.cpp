#include "VectorModel.h"

void VectorModel::Input()
{

}

void VectorModel::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

void VectorModel::Draw()
{
	for (int i = 0; i < verts.size(); i+=2)
	{
		Vector3 point1 = { verts[i].x + Position.x, verts[i].y + Position.y, 0 };
		Vector3 point2 = { verts[i + 1].x + Position.x, verts[i + 1].y + Position.y, 0 };

		DrawLine3D(point1, point2, { 255, 255, 255, 255 });
	}

}

VectorModel::VectorModel()
{

}

VectorModel::~VectorModel()
{
}