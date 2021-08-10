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

}

void Game::update()
{

}

void Game::render()
{
    BeginDrawing();

    ClearBackground(WHITE);

    EndDrawing();
}

const bool Game::running() const
{
    return !WindowShouldClose();
}

const void Game::close() const
{
    return CloseWindow();
}