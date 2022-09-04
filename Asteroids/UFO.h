#pragma once
#include "Player.h"
#include "Entity.h"
#include "Shot.h"
#include "Timer.h"

class UFO : public Entity
{
public:
	Shot* shot;
	Timer* fireTimer;
	Timer* vectorTimer;

	void LoadModel(Model model, Model shotmodel);
	virtual void Update(float deltaTime);
	virtual void Draw();

	void Spawn(Vector3 pos, Vector3 vel);

	UFO(float windowWidth, float windowHeight, Player* player);

private:
		float radius{ 5 };
		float speed{ 0 };

		Player* player;

		void ResetFireTimer();
		void ResetVectorTimer();
		void ChangeVector();
};

