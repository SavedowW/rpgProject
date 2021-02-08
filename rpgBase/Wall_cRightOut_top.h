#pragma once
#include "Object.h"

class Wall_cRightOut_top : 
    public Object
{
public:
    Wall_cRightOut_top(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};