#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight) : Entity()
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	MaxSpeed = 20;
	Radius = 0.8f;
	Scale = 0.25f;

	for (int i = 0; i < 4; i++)
	{
		shots[i] = new Shot(windowWidth, windowHeight);
	}
}

void Player::Hit()
{
	BeenHit = true;
	Enabled = false;
	thrustOff = true;
}

void Player::LoadModel(Model model, Model shotmodel)
{
	TheModel = model;

	for (auto shot : shots)
	{
		shot->LoadModel(shotmodel);
	}
}

void Player::Input()
{
	float rots = 0.07666f;

	if (IsKeyDown(KEY_RIGHT))
	{
		RotationZ += rots;
	}

	if (IsKeyDown(KEY_LEFT))
	{
		RotationZ -= rots;
	}

	if (IsKeyDown(KEY_UP))
	{
		ThrustOn();
	}
	else
	{
		thrustOff = true;
	}

	if (IsKeyPressed(KEY_RIGHT_CONTROL) || IsKeyPressed(KEY_LEFT_CONTROL))
	{
		Fire();
	}
}

void Player::Update(float deltaTime)
{
	Entity::Update(deltaTime);
	Entity::CheckScreenEdge();

	if (thrustOff)
	{
		ThrustOff(deltaTime);
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

void Player::ThrustOff(float deltaTime)
{
	Acceleration.x = (-Velocity.x * 0.1f) * deltaTime;
	Acceleration.y = (-Velocity.y * 0.1f) * deltaTime;
}

void Player::Fire()
{
	float speed = 25.5f;
	Vector3 velocity = {((float)cos(RotationZ) * speed), ((float)sin(RotationZ) * speed), 0};

	for (auto shot : shots)
	{
		if (!shot->Enabled)
		{
			shot->Spawn(Position, velocity, 1.5f);
			break;
		}
	}

}

void Player::Reset()
{
	Position = { 0, 0, 0 };
	Velocity = { 0, 0, 0 };
	BeenHit = false;
	Enabled = true;
}
