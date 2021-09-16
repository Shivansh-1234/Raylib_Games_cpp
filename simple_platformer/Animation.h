#pragma once

#include "raylib.h"
#include "raymath.h"

class Animation
{
private:
    Texture2D text;
    

    Vector2 screenPos;
    Vector2 worlPos;

    float rotation;
    float runningTime;
    int frame;
    const int maxFrames{6};
    const float updateTime {1.0f/12.0f};

    void initVariables();
    void initSprites();
public:
    Animation();
    ~Animation();

    Vector2 getWorlPos() { return worlPos; }
    Texture2D getText() { return text; }
    //Texture2D getidle() { return idle; }
    //Texture2D getrun() { return run; }
    int getFrame() { return frame;}
    void setWorldPos(int winWidth, int winHeight);
    void updateAnim();
    void tick(float deltaTime);
};


