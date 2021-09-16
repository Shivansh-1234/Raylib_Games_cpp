#include "Animation.h"

Animation::Animation()
{
    this->initVariables();
    //this->initSprites();
}

Animation::~Animation()
{
}

void Animation::initVariables()
{
    this->rotation = 1.0f;
    this->runningTime = 0.0f;
    this->frame = 0;
}

void Animation::initSprites()
{
    this->text = LoadTexture("characters/idle.png");
    
}

void Animation::setWorldPos(int winWidth, int winHeight)
{
    this->screenPos  = {
        (float)winWidth/2.0f - (4.0f * (0.5f * (float)text.width/6.0f)),
        (float)winHeight/2.0f - (4.0f * (0.5f * (float)text.height))
    };
}

void Animation::updateAnim()
{
    runningTime += GetFrameTime();

    if(runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;

        if (frame > maxFrames)
        {
            frame = 0;
        }
    }
}

void Animation::tick(float deltaTime)
{
    
}
