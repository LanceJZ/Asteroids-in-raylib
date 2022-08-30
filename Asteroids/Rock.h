#pragma once
#include "Entity.h"
#include "Player.h"

class Rock : public Entity
{
public:
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Spawn(Vector3 pos, Vector3 vel);
	void LoadModel(Model model);
	Rock(float windowWidth, float windowHeight, Player* player);


private:
	bool CheckCollision();
	Player* player;
};

