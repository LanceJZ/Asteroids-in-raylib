#pragma once
#include "Entity.h"
#include "Shot.h"

class Player : public Entity
{
public:
	//using Entity::Enabled;
	//using Entity::Position;

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void LoadModel(Model* model, Model* shotmodel);

	Player(float windowWidth, float windowHeight);

private:
	float radius{ 5 };
	bool thrustOff = true;
	Color color{ RAYWHITE };
	void ThrustOn();
	void ThrustOff(float deltaTime);
	void Fire();

	Shot* shots[4];
};

