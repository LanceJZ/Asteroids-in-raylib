#include "Shot.h"

void Shot::LoadModel(Model model)
{
	Entity::model = model;
}

Shot::Shot(Vector2 pos, float windowWidth, float windowHeight)
{
	Shot::windowWidth = windowWidth;
	Shot::windowHeight = windowHeight;
	Enabled = false;


}

void Shot::Update(float deltaTime)
{
	Entity::Update(deltaTime);
}

