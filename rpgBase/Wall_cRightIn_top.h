#pragma once
#include "Object.h"

class Wall_cRightIn_top : 
    public Object
{
public:
    Wall_cRightIn_top(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};