#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight)
{
	Player::windowWidth = windowWidth;
	Player::windowHeight = windowHeight;
	MaxSpeed = 50;

	shot = new Shot({ 0 }, windowWidth, windowHeight);
}

void Player::LoadModel(Model model, Model shotmodel)
{
	Entity::model = model;
	shotModel = shotmodel;
}

void Player::Input()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		RotationZ += 0.1f;
	}

	if (IsKeyDown(KEY_LEFT))
	{
		RotationZ -= 0.1;
	}

	if (IsKeyDown(KEY_UP))
	{
		ThrustOn();
	}
	else
	{
		ThrustOff();
	}
}

void Player::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	model.transform = MatrixRotateZ(RotationZ);      // Rotate 3D model

	if (thrustOff)
	{
		Acceleration.x = (-Velocity.x * 0.1f) * deltaTime;
		Acceleration.y = (-Acceleration.y * 0.1f) * deltaTime;
	}

	float perH = 60;
	float perW = 44;

	if (X() > windowWidth / perW)
	{
		X(-windowWidth / perW);
	}

	if (Y() > windowHeight / perH)
	{
		Y(-windowHeight / perH);
	}

	if (X() < -windowWidth / perW)
	{
		X(windowWidth / perW);
	}

	if (Y() < -windowHeight / perH)
	{
		Y(windowHeight / perH);
	}

}

void Player::Draw()
{
	Entity::Draw();

}

void Player::ThrustOn()
{
	Acceleration.x = (cos(RotationZ) * 0.1f);
	Acceleration.y = (sin(RotationZ) * 0.1f);
	thrustOff = false;
}

void Player::ThrustOff()
{
	thrustOff = true;
}