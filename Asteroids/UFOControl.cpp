#include "UFOControl.h"

void UFOControl::LoadModel(Model theModel, Model shot)
{
	ufo->LoadModel(theModel, shot);
}

void UFOControl::Update(float deltaTime)
{
	ufo->Update(deltaTime);
	timer->Update(deltaTime);

	if (timer->Elapsed())
	{
		SpawnUFO();
	}
}

void UFOControl::Draw()
{
	ufo->Draw();
}

UFOControl::UFOControl(float playScreenW, float playScreenH, Player* player)
{
	GameScreenWidth = playScreenW;
	GameScreenHeight = playScreenH;
	UFOControl::player = player;

	timer = new Timer();
	ResetTimer();
}

void UFOControl::SpawnUFO()
{

}

void UFOControl::ResetTimer()
{
	float amt = GetRandomValue(10.0f, 11.0f); //10-wave * 0.1, 10.15 + wave * 0.1
	timer->Reset(amt);
}
