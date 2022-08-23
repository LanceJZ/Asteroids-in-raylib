#pragma once
#include "raylib.h"
#include "Entity.h"
#include "PositionedObject.h"

class Shot : Entity
{
public:
	using Entity::Enabled;

	void LoadModel(Model model);
	Shot(Vector2 pos, float windowWidth, float windowHeight);
	virtual void Update(float deltaTime);

private:
	Model shot;
	float windowWidth;
	float windowHeight;
	Color color{ LIGHTGRAY };

};