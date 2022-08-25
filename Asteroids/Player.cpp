#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight) : Entity()
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	MaxSpeed = 20;

	for (int i = 0; i < 4; i++)
	{
		shots[i] = new Shot(windowWidth, windowHeight);
	}
}

void Player::LoadModel(Model model, Model shotmodel)
{
	Entity::model = model;

	for (int i = 0; i < 4; i++)
	{
		shots[i]->LoadModel(shotmodel);
	}
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

	for (int i = 0; i < 4; i++)
	{
		if (shots[i]->Enabled)
			shots[i]->Update(deltaTime);
	}


	model.transform = MatrixRotateZ(RotationZ);      // Rotate 3D model

	if (thrustOff)
	{
		ThrustOff(deltaTime);
	}

}

void Player::Draw()
{
	Entity::Draw();

	for (int i = 0; i < 4; i++)
	{
		if (shots[i]->Enabled)
			shots[i]->Draw();
	}
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

	for (int i = 0; i < 4; i++)
	{
		if (!shots[i]->Enabled)
		{
			shots[i]->Spawn(Position, velocity);
			break;
		}
	}

}
