#include "Game.h"

Game game;

int main()
{

    while (game.running())
    {
       game.update();
       game.render();
    }
    game.close();
    
}