#pragma once
#include "Entity.h"
#include "Shot.h"

class UFO : public Entity
{
public:
	Shot* shot;

	void LoadModel(Model model, Model shotmodel);
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Spawn(Vector3 pos, Vector3 vel);

private:

};

