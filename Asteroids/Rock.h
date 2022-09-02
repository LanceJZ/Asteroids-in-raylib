#pragma once
#include "Entity.h"
#include "Player.h"

class Rock : public Entity
{
public:
	enum RockSize
	{
		Small,
		Medium,
		Large
	};

	RockSize Size = Large;

	virtual void Update(float deltaTime);
	virtual void Draw();

	void Spawn(Vector3 pos, float speed, RockSize size);
	void LoadModel(Model model);
	Rock(float windowWidth, float windowHeight, Player* player);


private:

	bool CheckCollision();
	Player* player;
};

