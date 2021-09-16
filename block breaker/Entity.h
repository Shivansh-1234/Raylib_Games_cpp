#pragma once

#include <raylib.h>
#include <iostream>

class Entity
{
private:
    float e_width,e_height;
    float e_radius;
    float e_posX,e_posY;

    bool isActive;

    Color outlineColor;
    Color gradientColor;
    void initColor();
public:
    Entity();
    ~Entity();

    void initRect(Rectangle rec, Color color, bool outline, bool gradient);
    void initBall(Vector2 centre,float radius ,Color color ,bool outline, bool gradient);

    void move(float velocity);

    void setOutlineColor(Color outColor);
    void setGradientColor(Color gradColor);

    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();
    void setActive(bool e_isActive);

};




