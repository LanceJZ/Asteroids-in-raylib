#pragma once
#include "raylib.h"
#include "PositionedObject.h"

class Shot : PositionedObject
{
public:
	Shot(Vector2 pos, float windowWidth, float windowHeight);
	virtual void Update(float deltaTime);
	virtual void Draw();
	void LoadModel(Model ship);


private:
	Model shot;
	float windowWidth;
	float windowHeight;
	Color color{ LIGHTGRAY };

};