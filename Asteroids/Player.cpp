#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight)
{
	Player::windowWidth = windowWidth;
	Player::windowHeight = windowHeight;
	MaxSpeed = 20;

	shot = new Shot({ 0 }, windowWidth, windowHeight);

	float perH = 60;
	float perW = 44;
	ScreenWidth = windowWidth / perW;
	ScreenHeight = windowHeight / perH;
}

void Player::LoadModel(Model model, Model shotmodel)
{
	Entity::model = model;
	shotModel = shotmodel;

	shot->LoadModel(shotModel);
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
		thrustOff = true;
	}

	if (IsKeyPressed(KEY_RIGHT_CONTROL))
	{
		Fire();
	}
}

void Player::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	Entity::CheckScreenEdge();

	shot->Update(deltaTime);

	model.transform = MatrixRotateZ(RotationZ);      // Rotate 3D model

	if (thrustOff)
	{
		ThrustOff(deltaTime);
	}

}

void Player::Draw()
{
	Entity::Draw();
	shot->Draw();
}

void Player::ThrustOn()
{
	Acceleration.x = (cos(RotationZ) * 0.1f);
	Acceleration.y = (sin(RotationZ) * 0.1f);
	thrustOff = false;
}

void Player::ThrustOff(float deltaTime)
{
	Acceleration.x = (-Velocity.x * 0.1f) * deltaTime;
	Acceleration.y = (-Velocity.y * 0.1f) * deltaTime;
}

void Player::Fire()
{
	float vel = 25.5f;
	Vector3 velocity = {((float)cos(RotationZ) * vel), ((float)sin(RotationZ) * vel), 0};

	shot->Spawn(Position, velocity);
}
