#include "raylib.h"
#include "Game.h"

int main()
{
    Game game;

    game.Initialise();
    game.Load();
    game.GameLoop();
    game.Shutdown();

}