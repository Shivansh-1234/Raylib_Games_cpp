#pragma once

#include "raylib.h"
#include <iostream>

class Game
{
private:
    const int windowWidth = 512;
    const int windowHeight = 380;
    const float updateTime = 1.0f/12.0f;
    const int gravity = 1000;
    float dt;

    int frame;
    float runningTime;

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
    void getdeltaTime();
    void animatePlayer();
    float setdeltaTime();
    void update();
    void render();
};


