#include "Game.h"

Game::Game()
{
    this->initVariables();
    this->initwindow();
}

Game::~Game()
{
}

void Game::initwindow()
{
    InitWindow(windowWidth, windowHeight, "EndRunner");
    SetTargetFPS(60);
}

void Game::initVariables()
{
    this->rectSize.x = 50;
    this->rectSize.y = 80;
    this->rectPosY = windowHeight - rectSize.y;
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
    if (rectPosY >= windowHeight - rectSize.y)
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

    rectPosY += velocity;
}

void Game::playerRender()
{
    DrawRectangle(windowWidth / 2, rectPosY, rectSize.x, rectSize.y, GREEN);
}

const bool Game::running() const
{
    return !WindowShouldClose();
}

const void Game::close() const
{
    return CloseWindow();
}