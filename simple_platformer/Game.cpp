#include "Game.h"

Game::Game()
{
    this->initWindow();
    this->initVariables();
    this->initTextures(); 
}

Game::~Game()
{
}

void Game::initWindow()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "platformer_2D");
    SetTargetFPS(60);
}

void Game::initVariables()
{
    this->speed = 4.0f;
    this->rotation = 1.0f;
    this->knightPos.x = (float)WINDOW_WIDTH/2.0f - (4.0f * (0.5f * (float)knight.width/6.0f));
    this->knightPos.y = (float)WINDOW_HEIGHT/2.0f - (4.0f * (0.5f * (float)knight.height));
}

void Game::update()
{
    this->movePlayer();
    this->anim.updateAnim();
    this->updateRecs();
}

void Game::render()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    this->renderTextures();

    EndDrawing();
}

void Game::initTextures()
{
    this->knight = LoadTexture("characters/idle.png");
    this->map = LoadTexture("nature_tileset/world_map.png");
    this->idle = LoadTexture("characters/idle.png");
    this->run  = LoadTexture("characters/run.png");

}

void Game::renderTextures()
{
    
    DrawTextureEx(map, mapPos, 0.0f, 4.0f, WHITE);
    DrawTexturePro(this->knight, this->knightSource, this->knightDest, origin, 0.0f, WHITE);
    
}

void Game::movePlayer()
{
    Vector2 direction{};

    if(IsKeyDown(KEY_D))
        direction.x -= 1.0f;
    if(IsKeyDown(KEY_A))
        direction.x += 1.0f;
    if(IsKeyDown(KEY_S))
        direction.y -= 1.0f;
    if(IsKeyDown(KEY_W))
        direction.y += 1.0f;

    if(Vector2Length(direction) != 0.0f)
    {
        mapPos = Vector2Add(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0f ? rotation = -1.0f : rotation = 1.0f;
        this->knight = run;
    }

    else
    {
        this->knight = idle;
    }
}

void Game::updateRecs()
{

    this->knightSource.x = anim.getFrame() * (float)knight.width/6.0f;
    this->knightSource.y = 0.0f;
    this->knightSource.width = -rotation * (float)knight.width/6.0f;
    this->knightSource.height = (float)knight.height;

    this->knightDest.x = this->knightPos.x;
    this->knightDest.y = this->knightPos.y;
    this->knightDest.width = 4.0f * (float)knight.width/6.0f;
    this->knightDest.height = 4.0f * (float)knight.height;
}

const bool Game::running() const
{
    return !WindowShouldClose();
}

const void Game::close() const
{
    return CloseWindow();
}