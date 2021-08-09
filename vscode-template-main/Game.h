#pragma once

#include "raylib.h"
#include <iostream>

class Game
{
private:
    const int windowWidth = 900;
    const int windowHeight = 600;

    float enemyMoveSpeed;
    float playerMoveSpeed;
    float circleRad;

    bool collision;

    void initVariables();
    void initWindow();
    void initShapes();
    void enemylogic();
public:
    Game();
    ~Game();

    Vector2 circlepos;
    Vector2 rectpos;
    Vector2 rectSize;

    void update();
    void render(); 
    void handleInputs();
    void checkCollision();
    const bool running() const;
};
