#include "Player.h"
#include "Game.h"
#include "raymath.h"

Player::Player()
{
	position = Vector2{ 0, 0 };
}

Player::Player(Vector2 pos, float windowWidth, float windowHeight) : position{ pos }
{
	Player::windowWidth = windowWidth;
	Player::windowHeight = windowHeight;
}

void Player::LoadModel(Camera *camera, Model ship)
{
	Player::ship = ship;
	Player::camera = camera;
}

void Player::SetPosition(Vector2 pos)
{
	position = pos;
}

Vector2 Player::GetPosition()
{
	return position;
}

void Player::Input()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		angle += 0.1f;
	}

	if (IsKeyDown(KEY_LEFT))
	{
		angle -= 0.1;
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
	ship.transform = MatrixRotateZ(angle);      // Rotate 3D model

	if (thrustOff)
	{
		acceleration.x = (-velocity.x * 0.1f) * deltaTime;
		acceleration.y = (-velocity.y * 0.1f) * deltaTime;
	}

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;

	acceleration = { 0 };

	float perH = 60;
	float perW = 44;

	if (position.x > windowWidth / perW)
	{
		position.x = -windowWidth / perW;
	}

	if (position.y > windowHeight / perH)
	{
		position.y = -windowHeight / perH;
	}

	if (position.x < -windowWidth / perW)
	{
		position.x = windowWidth / perW;
	}

	if (position.y < -windowHeight / perH)
	{
		position.y = windowHeight / perH;
	}

}

void Player::Draw()
{
	DrawModel(ship, { position.x, position.y, 0 }, 0.250f, LIGHTGRAY);        // Draw 3D model


}

void Player::ThrustOn()
{
	acceleration.x = (cos(angle) * 0.1f);
	acceleration.y = (sin(angle) * 0.1f);
	thrustOff = false;
}

void Player::ThrustOff()
{
	thrustOff = true;
}