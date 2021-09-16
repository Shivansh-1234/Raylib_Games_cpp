#include "Game.h"

Game* game = new Game();
int main()
{
    while (game->isRunning())
    {
        game->update();
        game->render();
    }
    
    return 0;
}