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
    UnloadTexture(this->nebula);
}

void Game::initwindow()
{
    InitWindow(windowWidth, windowHeight, "EndRunner");
    SetTargetFPS(60);
}

void Game::initVariables()
{
    this->velocity = 0.0f;
    this->jumpVelocity = -600.0f;
    this->nebVelocity = -200.0f;

    this->isGrounded = true;
}

void Game::initSprites()
{   
    //SCARFY
    this->scarfy = LoadTexture("textures/scarfy.png");
    this->nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    this->scarfyData.rec.width = scarfy.width/6;
    this->scarfyData.rec.height = scarfy.height;
    this->scarfyData.rec.x = 0;
    this->scarfyData.rec.y = 0;

    this->scarfyData.pos.x = windowWidth/2 - scarfyData.rec.width/2;
    this->scarfyData.pos.y = windowHeight - scarfyData.rec.height;
    this->scarfyData.frame = 0;
    this->scarfyData.updatingTime = 1.0f/12.0f;
    this->scarfyData.runningTime = 0.0f;

    // NEBULA
    
    this->nebData.rec.width = nebula.width/8;
    this->nebData.rec.height = nebula.height/8;
    this->nebData.rec.x = 0;
    this->nebData.rec.y = 0;

    this->nebData.pos.x = windowWidth;
    this->nebData.pos.y = windowHeight - nebula.height/8;
    this->nebData.frame = 0;
    this->nebData.updatingTime = 1.0f/12.0f;
    this->nebData.runningTime = 0.0f;

    //NEBULA 2
    this->neb2Data.rec.width = nebula.width/8;
    this->neb2Data.rec.height = nebula.height/8;
    this->neb2Data.rec.x = 0;
    this->neb2Data.rec.y = 0;

    this->neb2Data.pos.x = windowWidth + 300;
    this->neb2Data.pos.y = windowHeight - nebula.height/8;
    this->neb2Data.frame = 0;
    this->neb2Data.updatingTime = 1.0f/16.0f;
    this->neb2Data.runningTime = 0.0f;
}

void Game::update()
{
    this->getdeltaTime();
    this->animatePlayer();
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
    if (scarfyData.pos.y >= windowHeight - scarfyData.rec.height)
    {
        velocity = 0.0f;
        isGrounded = true;
    }

    else
    {
        velocity += gravity * setdeltaTime();
    }

    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        velocity += jumpVelocity;
        isGrounded = false;
    }

    this->nebData.pos.x += nebVelocity * setdeltaTime();
    this->neb2Data.pos.x += nebVelocity * setdeltaTime();
    this->scarfyData.pos.y += velocity * setdeltaTime();
}

void Game::playerRender()
{
    DrawTextureRec(this->nebula, this->nebData.rec, this->nebData.pos, WHITE);
    DrawTextureRec(this->nebula, this->neb2Data.rec, this->neb2Data.pos, RED);
    DrawTextureRec(this->scarfy, this->scarfyData.rec, this->scarfyData.pos, WHITE);
}

void Game::animatePlayer()
{
    //SCARFY
    this->scarfyData.runningTime += this->setdeltaTime();

    if (this->scarfyData.runningTime >= this->scarfyData.updatingTime && isGrounded)
    {
        this->scarfyData.runningTime = 0.0f;

        this->scarfyData.rec.x = this->scarfyData.frame * this->scarfyData.rec.width;
        this->scarfyData.frame++;

        if (this->scarfyData.frame > 5)
            this->scarfyData.frame = 0;
    }

    //NEBULA
    this->nebData.runningTime += this->setdeltaTime();

    if(this->nebData.runningTime >= this->nebData.updatingTime)
    {
        this->nebData.runningTime = 0.0f;

        this->nebData.rec.x = this->nebData.frame * this->nebData.rec.width;
        this->nebData.frame++;

        if(this->nebData.frame> 7)
            this->nebData.frame = 0;    
    }

    //NEB2
    this->neb2Data.runningTime += this->setdeltaTime();

    if(this->neb2Data.runningTime >= this->neb2Data.updatingTime)
    {
        this->neb2Data.runningTime = 0.0f;

        this->neb2Data.rec.x = this->neb2Data.frame * this->neb2Data.rec.width;
        this->neb2Data.frame++;

        if(this->neb2Data.frame> 7)
            this->neb2Data.frame = 0;    
    }

}

void Game::getdeltaTime()
{
    this->dt = GetFrameTime();
}

float Game::setdeltaTime()
{
    return this->dt;
}

const bool Game::running() const
{
    return !WindowShouldClose();
}

const void Game::close() const
{
    return CloseWindow();
}