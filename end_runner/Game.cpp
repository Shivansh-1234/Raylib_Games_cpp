#include "Game.h"

Game::Game()
{
    this->initwindow();
    this->initVariables();
    this->initSprites();
}

Game::~Game()
{
    UnloadTexture(this->scarfy);
}

void Game::initwindow()
{
    InitWindow(windowWidth, windowHeight, "EndRunner");
    SetTargetFPS(60);
}

void Game::initVariables()
{
    this->velocity = 0.0f;
    this->jumpVelocity = -22.0f;

    this->isGrounded = true;
}

void Game::update()
{
    this->playerMovement();
}

void Game::render()
{
    BeginDrawing();

    ClearBackground(WHITE);

    this->playerRender();

    EndDrawing();
}

void Game::playerMovement()
{
    if (scarfyPos.y >= windowHeight - scarfyRect.height)
    {
        velocity = 0.0f;
        isGrounded = true;
    }

    else
    {
        velocity += gravity;
    }

    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        velocity += jumpVelocity;
        isGrounded = false;
    }

    scarfyPos.y += velocity;
}

void Game::playerRender()
{
    DrawTextureRec(scarfy, scarfyRect , scarfyPos , WHITE);
}

void Game::initSprites()
{
    
    this->scarfy = LoadTexture("textures/scarfy.png");
    //Rec Properties
    this->scarfyRect.width = this->scarfy.width/6;
    this->scarfyRect.height = this->scarfy.height;
    this->scarfyRect.x = 0;
    this->scarfyRect.y = 0;

    //Vector Properties
    this->scarfyPos.x = this->windowWidth/2 - this->scarfyRect.width/2;
    this->scarfyPos.y = this->windowHeight - this->scarfyRect.height;
    
}

const bool Game::running() const
{
    return !WindowShouldClose();
}

const void Game::close() const
{
    return CloseWindow();
}