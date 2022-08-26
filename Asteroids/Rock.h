#pragma once
#include "Entity.h"

class Rock : public Entity
{
public:
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Spawn(Vector3 pos, Vector3 vel);
	void LoadModel(Model model);


private:

};

