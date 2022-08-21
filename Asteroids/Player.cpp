#include "Player.h"
#include "Game.h"
#include "raymath.h"

Player::Player()
{
	position = Vector2{ 0, 0 };
}

Player::Player(Vector2 pos) : position{ pos }
{

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
	Matrix matRotate = MatrixRotateZ(angle);

	ship.transform = matRotate;

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
}

void Player::Draw()
{
	Vector3 position3 = { position.x, position.y, 0 };

	DrawModel(ship, position3, 0.250f, LIGHTGRAY);        // Draw 3d model with texture


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