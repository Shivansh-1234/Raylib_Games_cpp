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
    float velocity;
    bool isGrounded;

    Texture2D scarfy;
    Rectangle scarfyRect;
    Vector2 scarfyPos;
    
    void initwindow();
    void initVariables();
    void initSprites();
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


