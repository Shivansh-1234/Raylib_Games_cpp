#include "Entity.h"

Entity::Entity()
{
    initColor();
}

Entity::~Entity()
{
}

void Entity::initColor()
{
    this->outlineColor = BLACK;
    this->gradientColor = RAYWHITE;
    this->isActive = false;
}

void Entity::initRect(Rectangle rec, Color color, bool outline, bool gradient)
{
    e_width = rec.width; e_height = rec.height; e_posX = rec.x; e_posY = rec.y;

    if(isActive)
    {
        if(!gradient) { DrawRectangle(e_posX, e_posY, e_width, e_height, color); }
        else if(gradient) { DrawRectangleGradientV(e_posX, e_posY, e_width, e_height, color, gradientColor); }
        if(outline) { DrawRectangleLines(e_posX, e_posY, e_width, e_height, outlineColor); }
    }
}

void Entity::initBall(Vector2 centre,float radius ,Color color ,bool outline, bool gradient)
{   
    if(!gradient) { DrawCircleV(centre, radius, color); }
    else if(gradient) { DrawCircleGradient(static_cast<int>(centre.x), static_cast<int>(centre.y), radius, color, gradientColor); }
    if(outline) { DrawCircleLines(static_cast<int>(centre.x), static_cast<int>(centre.y), radius, outlineColor); }
}

void Entity::setOutlineColor(Color outColor)
{
    outlineColor = outColor;
}

void Entity::setGradientColor(Color gradColor)
{
    gradientColor = gradColor;
}


float Entity::getPosX()
{
    return e_posX;
}
float Entity::getPosY()
{
    return e_posY;
}

void Entity::move(float velocity)
{
    e_posY += velocity;
    std::cout << e_posY << std::endl;
}

void Entity::setActive(bool e_isActive)
{
    isActive = e_isActive;
}

float Entity::getWidth()
{
    return e_width;
}

float Entity::getHeight()
{
    return e_height;
}
