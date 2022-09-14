#pragma once
#include "raylib.h"
#include "Entity.h"
#include "Timer.h"
#include "Common.h"

class Dot : public Entity, Common
{
public:
	virtual void Update(float deltaTime);
	virtual void Draw();

	bool Initialise();

	void Spawn(Vector3 position, float time);
	void Clear();

private:
	Timer* timer;
};

