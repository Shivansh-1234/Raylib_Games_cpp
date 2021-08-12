#pragma once

#include "raylib.h"
#include <iostream>

class Game
{
private:
    const int windowWidth = 512;
    const int windowHeight = 380;
    const int gravity = 1000;
    float dt;

    float jumpVelocity;
    float velocity;
    bool isGrounded;

    Texture2D scarfy;

    Texture2D nebula;
    float nebVelocity;

    struct AnimData{
        Rectangle rec;
        Vector2 pos;
        int frame;
        float updatingTime;
        float runningTime;
    };

    AnimData scarfyData;
    AnimData nebData;
    AnimData neb2Data;
    
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


