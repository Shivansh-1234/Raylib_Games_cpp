#include "Game.h"

Game::Game()
{
    this->initVariables();
    this->initWindow();    
}

Game::~Game()
{
}

void Game::initVariables()
{
    this->circleRad = 40.0f;
    this->circlepos = {windowWidth/2.0f,windowHeight/2.0f};
    this->rectpos = {800,0};
    this->rectSize= {30,30};
    this->playerMoveSpeed = 2.3f;
    this->enemyMoveSpeed = 5.0f;
    this->collision = false;
}

void Game::initWindow()
{
    InitWindow(windowWidth, windowHeight, "ULALALAL");
    SetTargetFPS(144);
}

void Game::update()
{
    this->checkCollision();

    if(!collision)
    {
        this->initShapes();
        this->handleInputs();
        this->enemylogic();
    }

    if(collision)
    {
        DrawText("GAME OVER NOOB!", windowWidth/2.0f , windowHeight/2.0f, 30, RED);
    }
   
    
}

void Game::render()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
}

void Game::initShapes()
{
    DrawCircleV(circlepos, circleRad, RED);
    DrawRectangleV(rectpos, rectSize, GREEN);
}

void Game::handleInputs()
{
    if(IsKeyDown(KEY_A) && (circlepos.x - circleRad) > 0)
        circlepos.x -= playerMoveSpeed;
    if(IsKeyDown(KEY_D) && (circlepos.x + circleRad) < 900)
        circlepos.x += playerMoveSpeed;
    if(IsKeyDown(KEY_W) && (circlepos.y - circleRad) > 0)
        circlepos.y -= playerMoveSpeed;
    if(IsKeyDown(KEY_S) && (circlepos.y + circleRad) < 600)
        circlepos.y += playerMoveSpeed;
}

void Game::enemylogic()
{
    rectpos.y += enemyMoveSpeed;

    if(rectpos.y >= 580 || rectpos.y <= 0)
        enemyMoveSpeed = -enemyMoveSpeed;
}

void Game::checkCollision()
{
    if((circlepos.x + circleRad) >= (rectpos.x - rectSize.x) && 
        (circlepos.y  - circleRad) <= (rectpos.y + rectSize.y)&&
        (circlepos.x - circleRad) <= (rectpos.x + rectSize.x)&&
        (circlepos.y + circleRad) >= (rectpos.y - rectSize.y)
    )
    {
        collision = true;
    }
}

const bool Game::running() const
{
    return !WindowShouldClose();
}
