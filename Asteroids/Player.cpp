#include "Player.h"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight) : Entity()
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	MaxSpeed = 20;
	Radius = 0.6f;
	Scale = 0.2f;
	Enabled = false;

	flame = new Entity();
	flame->Scale = Scale;
	flame->Radius = 0.1f;
	flame->Enabled = false;

	for (int i = 0; i < 4; i++)
	{
		shots[i] = new Shot(windowWidth, windowHeight);
	}

	for (int i = 0; i < 6; i++)
	{
		lines.push_back(new Line());
	}
}

void Player::Hit()
{
	BeenHit = true;
	Enabled = false;
	thrustOff = true;
	lives--;
	exploding = true;

	for (auto line : lines)
	{
		line->Spawn(Position);
	}
}

void Player::LoadModel(Model model, Model shotmodel, Model flamemodel)
{
	TheModel = model;
	flame->LoadModel(flamemodel);

	for (auto shot : shots)
	{
		shot->LoadModel(shotmodel);
	}
}

void Player::LoadSound(Sound fireS, Sound thrustS)
{
	fireSound = fireS;
	thrustSound = thrustS;
}

void Player::Input()
{
	float velocityRotZ = 0.07666f;

	if (IsKeyDown(KEY_RIGHT))
	{
		RotationZ += velocityRotZ;
	}

	if (IsKeyDown(KEY_LEFT))
	{
		RotationZ -= velocityRotZ;
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

	Vector3 offset = VelocityFromAngleZ(RotationZ, -Radius * 1.25f);

	flame->Position = Vector3Add(offset, Position);
	flame->RotationZ = RotationZ;
	flame->Update(deltaTime);

	if (thrustOff)
	{
		ThrustOff(deltaTime);
	}
}

void Player::Draw()
{
	Entity::Draw();
	flame->Draw();

	for (auto line : lines)
	{
		line->Draw();
	}
}

void Player::ThrustOn()
{
	Acceleration.x = (cos(RotationZ) * 0.1f);
	Acceleration.y = (sin(RotationZ) * 0.1f);
	thrustOff = false;
	flame->Enabled = true;
}

void Player::ThrustOff(float deltaTime)
{
	Acceleration.x = (-Velocity.x * 0.1f) * deltaTime;
	Acceleration.y = (-Velocity.y * 0.1f) * deltaTime;
	flame->Enabled = false;
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

void Player::ScoreUpdate(int addToScore)
{
	score += addToScore;

	if (score > nextNewLifeScore)
	{
		nextNewLifeScore += 10000;
		lives++;
		newLife = true;
	}
}

void Player::NewGame()
{
	lives = 4;
	nextNewLifeScore = 10000;
	score = 0;
	wave = 0;
	Reset();
}

void Player::Reset()
{
	Position = { 0, 0, 0 };
	Velocity = { 0, 0, 0 };
	BeenHit = false;
	Enabled = true;

	for (auto line : lines)
	{
		line->Clear();
	}
}
