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
	windowHeight = 960; //height
	windowWidth = 1280;

	InitWindow(windowWidth, windowHeight, "Asteroids");
	SetTargetFPS(60);

	// Define the camera to look into our 3D world
	camera.position = { 0.0f, 0.0f, -50.0f };   // Camera position
	camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                       // Camera field-of-view Y
	camera.projection = CAMERA_ORTHOGRAPHIC;   // Camera mode type

	//SetCameraMode(camera, CAMERA_ORBITAL);

	float perH = 60;
	float perW = 44;
	float windowH = windowWidth / perW;
	float windowW = windowHeight / perH;


	player = new Player(windowW, windowH);

	return 0;
}

bool Game::Load()
{
	Model playerShip = LoadModel("models/playership.obj");
	playerShip.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/playership.png");
	Model shot = LoadModel("models/shot.obj");
	shot.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/shot.png");
	Model rockOne = LoadModel("models/rockone.obj");
	rockOne.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rockone.png");

	player->LoadModel(playerShip, shot);


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

	if (player->Enabled)
	{
		player->Update(deltaTime);
	}
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