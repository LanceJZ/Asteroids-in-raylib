#pragma once
#include "raylib.h"
#include "Entity.h"
#include "PositionedObject.h"

class Shot : Entity
{
public:
	using Entity::Enabled;

	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void LoadModel(Model model);
	void Spawn(Vector3 pos, Vector3 vel);

	Shot(Vector2 pos, float windowWidth, float windowHeight);

private:
	Model shot;
	float windowWidth;
	float windowHeight;
	Color color{ LIGHTGRAY };

};