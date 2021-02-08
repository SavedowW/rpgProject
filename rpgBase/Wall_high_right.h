#pragma once
#include "Object.h"

class Wall_high_right : 
    public Object
{
public:
    Wall_high_right(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};