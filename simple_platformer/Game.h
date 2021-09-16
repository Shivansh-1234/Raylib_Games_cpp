#pragma once

#include "raylib.h"
#include "raymath.h"

#include"Animation.h"

#define WINDOW_WIDTH 384
#define WINDOW_HEIGHT 384

class Game
{
private:
    void initWindow();
    void initVariables();
    void initTextures();
    void renderTextures();

    Animation anim;

    float speed;
    float rotation;

    Texture2D map;
    Texture2D knight;

    Texture2D idle;
    Texture2D run;

    Rectangle knightSource;
    Rectangle knightDest;

    Vector2 origin{};

    Vector2 mapPos {0.0f, 0.0f};
    Vector2 knightPos {};

    //Animation anim;

public:
    Game();
    ~Game();

    void update();
    void render();

    void movePlayer();
    void updateRecs();

    const bool running() const;
    const void close() const;
};


