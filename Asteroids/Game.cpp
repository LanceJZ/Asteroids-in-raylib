#include "Game.h"
#include "raymath.h"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::Initialise()
{
	InitWindow(1280, 960, "Asteroids");
	SetTargetFPS(60);

	// Define the camera to look into our 3D world
	camera.position = { 0.0f, 0.0f, -50.0f };   // Camera position
	camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = { 1.0f, 0.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                       // Camera field-of-view Y
	camera.projection = CAMERA_ORTHOGRAPHIC;   // Camera mode type

	//SetCameraMode(camera, CAMERA_ORBITAL);

	player = new Player({ 0 });

	return 0;
}

bool Game::Load()
{
	Model playerShip = LoadModel("models/playership.obj");
	playerShip.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("models/playership.png");

	player->LoadModel(&camera, playerShip);


	return 0;
}

void Game::GameLoop()
{
	while (!WindowShouldClose())
	{
		ProcessInput();
		Update(GetFrameTime());
		Draw();
	}
}

void Game::ProcessInput()
{
	player->Input();
}


void Game::Update(float deltaTime)
{
	UpdateCamera(&camera);

	player->Update(deltaTime);
}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground({10, 10, 10, 100});
	BeginMode3D(camera);

	player->Draw();

	EndMode3D();

	EndDrawing();
}

void Game::Shutdown()
{
	CloseWindow();
}