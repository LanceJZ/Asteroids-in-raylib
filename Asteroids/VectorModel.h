#pragma once
#include "raylib.h"
#include <vector>
#include "Entity.h"
using namespace std;

class VectorModel : public Entity
{
public:
	vector<Vector3> verts;
	Color color = {255, 255, 255, 255};
	float modelScale = 1;
	float Alpha = 1;

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

	VectorModel();
	virtual ~VectorModel();

private:

};

