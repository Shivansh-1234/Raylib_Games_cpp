#pragma once

#include "raymath.h"
#include"Entity.h"

class Game
{
private:
    const int SCREENWIDTH = 1280;
    const int SCREENHEIGHT = 720;

    float velocity;
    Vector2 ballVelocity;

    void initWindow();
    void initVariables();
    void getInputs();
    void clampPlayer();
    void ballPhysics();
    inline void enemyCollisions();
    void spawnEnemies();

    bool moveBall;
    bool endGame;

    float ballRadius;
    Vector2 ballParameters;
    Rectangle playerParameters;
    //Rectangle enemyParameters[12][7];
    Entity* player = new Entity();
    Entity* ball = new Entity();
    Entity* enemy[12][7];
public:
    Game();
    ~Game();

    const bool isRunning() const;
    void update();
    void render();

};



