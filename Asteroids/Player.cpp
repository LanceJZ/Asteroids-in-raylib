#include "Player.h"
#include "Game.h"
#include "raymath.h"

Player::Player(Vector2 pos, float windowWidth, float windowHeight)
{
	Player::windowWidth = windowWidth;
	Player::windowHeight = windowHeight;
	MaxSpeed = 50;
}

void Player::LoadModel(Model ship)
{
	Player::ship = ship;
}

void Player::SetPosition(Vector2 pos)
{
	Position2 = pos;
}

Vector2 Player::GetPosition()
{
	return Position2;
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
	PositionedObject::Update(deltaTime);

	ship.transform = MatrixRotateZ(RotationZ);      // Rotate 3D model

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
	DrawModel(ship, Position, 0.250f, LIGHTGRAY);        // Draw 3D model


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