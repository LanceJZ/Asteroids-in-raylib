#pragma once
#include <vector>
#include "raylib.h"

class Exploder
{
public:
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Spawn(Vector3 position, int count, float radius);
	void Clear();

private:
};

