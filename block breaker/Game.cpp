#include "Game.h"

Game::Game()
{
    initWindow();
    initVariables();
}

Game::~Game()
{
    CloseWindow();
}

void Game::update()
{    
    getInputs();
    clampPlayer();
    ballPhysics();
    enemyCollisions();
}

void Game::render()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawFPS(10,10);

    if (!endGame)
    {
        player->initRect(playerParameters, RED, true, true);
        ball->initBall(ballParameters, ballRadius, GREEN, true, true);
        spawnEnemies();
    }

    else if(endGame)
    {
        DrawText("GAME OVER!", 400, 360, 60 ,RED);
    }

    EndDrawing();
}

const bool Game::isRunning() const
{
    return !WindowShouldClose();
}

void Game::initWindow()
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Block Breaker");
    SetTargetFPS(144);
}

void Game::initVariables()
{
    this->playerParameters.x = 400.0f;
    this->playerParameters.y = 620.0f;
    this->playerParameters.width = 200.0f;
    this->playerParameters.height = 20.0f;

    this->ballParameters.x = 640.0f;
    this->ballParameters.y = 600.0f;

    this->velocity = 4.0f;

    this->ballVelocity.x = 1.0f;
    this->ballVelocity.y = 5.0f;

    this->ballRadius = 5.0f;
    this->endGame = false;

    this->moveBall = false;
    player->setActive(true);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            enemy[j][i] = new Entity();
            enemy[j][i]->setActive(true);
        }
        
    }
        
}

void Game::getInputs()
{
    if(IsKeyDown(KEY_A))
        playerParameters.x += -velocity;
    if(IsKeyDown(KEY_D))
        playerParameters.x += velocity;
    if(IsKeyPressed(KEY_SPACE))
        moveBall = true;

    if(moveBall)
    {
        ballParameters.x += -ballVelocity.x;
        ballParameters.y += -ballVelocity.y;
    }
        
}

void Game::clampPlayer()
{
    if(playerParameters.x <= 0.0f)
        playerParameters.x = 0.0f;
    if(playerParameters.x >= SCREENWIDTH-playerParameters.width)
        playerParameters.x = SCREENWIDTH-playerParameters.width;
}

void Game::ballPhysics()
{
    if(ballParameters.y <= 0)
    {
        //ballVelocity.x = -ballVelocity.x; 
        ballVelocity.y *= -1; 
    }
        
    if(ballParameters.x <= 0)
    {
        ballVelocity.x *= -1; 
        //ballVelocity.y = -ballVelocity.y; 
    }

    if(ballParameters.x >=SCREENWIDTH-ballRadius)
    {
        ballVelocity.x *= -1; 
        //ballVelocity.y = -ballVelocity.y; 
    }

    if(ballParameters.y > SCREENHEIGHT)
    {
        endGame = true;
        //ballVelocity.y = -ballVelocity.y; 
    }
        

    // if((ballParameters.y + ballRadius) < (playerParameters.y - (playerParameters.height/2)) &&
    //     (ballParameters.y - ballRadius) > (playerParameters.y + (playerParameters.height/2)))
    //     {
    //         ballVelocity = -ballVelocity;     
    //     }

    if(CheckCollisionCircleRec(ballParameters, ballRadius, playerParameters))
    {      
        ballVelocity.y *= -1;   
    }
                       
}

void Game::spawnEnemies()
{
    float spaceX = 0.f;
    float spaceY = 0.f;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            enemy[j][i]->initRect({75.f  + spaceX ,50.f + spaceY,50.f,30.f}, BLUE, false, false);
            enemy[j][i]->setGradientColor(LIME);
            // enemyParameters[j][i].x = 75.f  + spaceX;
            // enemyParameters[j][i].y = 50.f + spaceY;
            // enemyParameters[j][i].width = 50.f;
            // enemyParameters[j][i].height = 30.f;
            spaceX += 100.f;
        }
        spaceX = 0.f;
        spaceY += 50.f;
    }
    
}

inline void Game::enemyCollisions()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            // if(CheckCollisionCircleRec(ballParameters, ballRadius, enemyParameters[j][i]))
            // {
            //     ballVelocity.y *= -1;
            //     enemy[j][i]->setActive(false);
            //     enemyParameters[j][i].height = 0.f;
            //     enemyParameters[j][i].width = 0.f;
            //     enemyParameters[j][i].x = 0.f;
            //     enemyParameters[j][i].y = 0.f;
            // }

            if((ballParameters.y - ballRadius) < (enemy[j][i]->getPosY() + (enemy[j][i]->getHeight()/2.f)) 
            && (ballParameters.y + ballRadius) > (enemy[j][i]->getPosY() - (enemy[j][i]->getHeight()/2.f))
            && (ballParameters.x + ballRadius) > (enemy[j][i]->getPosX() - (enemy[j][i]->getWidth()/2.f))
            && (ballParameters.y - ballRadius) < (enemy[j][i]->getPosX() + (enemy[j][i]->getWidth()/2.f)))
            {
                ballVelocity.y *= -1;
                enemy[j][i]->setActive(false);
            }
        }
        
    }
    
}