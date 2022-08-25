#pragma once
#include "Entity.h"
#include "Timer.h"

class Shot : public Entity
{
public:
	//using Entity::Enabled;

	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void LoadModel(Model model);
	void Spawn(Vector3 pos, Vector3 vel);

	Shot(float windowWidth, float windowHeight);

private:
	Model shot;
	float windowWidth;
	float windowHeight;
	Color color{ RAYWHITE };
	Timer* timer;
};