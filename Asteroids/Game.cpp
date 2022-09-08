#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::Initialise()
{
	int windowHeight = 960; //height
	int windowWidth = 1280; //width

	InitWindow(windowWidth, windowHeight, "Asteroids");
	SetTargetFPS(60);

	// Define the camera to look into our 3D world
	camera.position = { 0.0f, 0.0f, -50.0f };  // Camera position
	camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                       // Camera field-of-view Y
	camera.projection = CAMERA_ORTHOGRAPHIC;   // Camera mode type

	float perH = 43;
	float perW = 43;
	float playScreenW = windowWidth / perW;
	float playScreenH = windowHeight / perH;

	playerClear.Radius = 10.0f;

	player = new Player(playScreenW, playScreenH);
	rockControl = new RockControl(playScreenW, playScreenH, player);
	theUFOControl = new UFOControl(playScreenW, playScreenH, player);

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
	Model rockTwo = LoadModel("models/rocktwo.obj");
	rockOne.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rocktwo.png");
	Model rockThree = LoadModel("models/rockthree.obj");
	rockOne.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/rockthree.png");
	Model rockFour = LoadModel("models/RockFour.obj");
	rockOne.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/RockFour.png");
	Model modelUFO = LoadModel("models/UFO.obj");
	modelUFO.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
		LoadTexture("models/UFO.png");

	player->LoadModel(playerShip, shot);
	rockControl->LoadModel(rockOne, rockTwo, rockThree, rockFour);
	theUFOControl->LoadModel(modelUFO, shot);
	rockControl->NewGame();

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

		if (player->Entity::Hit) //When explosion is done, turn Hit off.
		{
			CheckPlayerClear();
		}
	}

	for (auto shot : player->shots)
	{
		shot->Update(deltaTime);
	}

	rockControl->Update(deltaTime);
	theUFOControl->Update(deltaTime);
}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground({10, 10, 10, 100});
	BeginMode3D(camera);

	theUFOControl->Draw();
	rockControl->Draw();
	player->Draw();

	for (auto shot : player->shots)
	{
		shot->Draw();
	}

	EndMode3D();
	EndDrawing();
}

void Game::CheckPlayerClear()
{
	bool clear = true;

	for (int rock = 0; rock < rockControl->rocks.size(); rock++)
	{
		if (playerClear.CirclesIntersect(rockControl->rocks[rock]))
		{
			clear = false;
		}
	}

	if (clear)
	{
			player->Reset();
	}
}

void Game::Shutdown()
{
	CloseWindow();
}