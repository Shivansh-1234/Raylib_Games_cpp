#pragma once

#include "raylib.h"

class Game
{
private:
    const int windowWidth = 512;
    const int windowHeight = 380;

    void initwindow();
    void initVariables();
public:
    Game();
    ~Game();

    const bool running() const;
    const void close() const;

    void update();
    void render();
};


