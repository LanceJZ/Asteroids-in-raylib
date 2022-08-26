#include "Game.h"

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
	Model modelPS = LoadModel("models/playership.obj");
	Model modelS = LoadModel("models/shot.obj");
	Model modelRO = LoadModel("models/rockone.obj");
	Model modelRT = LoadModel("models/rocktwo.obj");
	Model modelRTh = LoadModel("models/rockthree.obj");
	Model modelF = LoadModel("models/rockfour.obj");

	Model* playerShip = &modelPS;
	playerShip->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/playership.png");
	Model* shot = &modelS;
	shot->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/shot.png");
	Model* rockOne = &modelRO;
	rockOne->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rockone.png");
	Model* rockTwo = &modelRT;
	rockOne->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rocktwo.png");
	Model* rockThree = &modelRTh;
	rockOne->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rockthree.png");
	Model* rockFour = &modelF;
	rockOne->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rockfour.png");

	player->LoadModel(playerShip, shot);
	rockControl->LoadModel(rockOne, rockTwo, rockThree, rockFour);

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