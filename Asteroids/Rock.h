#pragma once
#include "LineModel.h"
#include "Player.h"
#include "UFO.h"
#include "Exploder.h"

class Rock : public LineModel
{
public:
	enum RockSize
	{
		Small,
		Medium,
		Large
	};

	RockSize size = Large;

	Exploder* exploder;
	virtual void Update(float deltaTime);
	virtual void Draw();
	bool Initialize();

	void Spawn(Vector3 pos, float speed, RockSize size);
	void LoadModel(string rockModel);
	void LoadSound(Sound exp);
	Rock(float windowWidth, float windowHeight, Player* player, UFO* ufo);


private:
	void GiveScore();
	bool CheckCollision();
	Player* player;
	UFO* ufo;
};

