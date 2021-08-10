#pragma once

#include "raylib.h"
#include <iostream>

class Game
{
private:
    const int windowWidth = 512;
    const int windowHeight = 380;

    const int gravity = 1;
    float jumpVelocity;
    Vector2 rectSize;
    int rectPosY;
    float velocity;
    bool isGrounded;

    void initwindow();
    void initVariables();
public:
    Game();
    ~Game();

    const bool running() const;
    const void close() const;

    void playerMovement();
    void playerRender();

    void update();
    void render();
};


