#pragma once
#include "Object.h"

class Wall_high_left : 
    public Object
{
Public:
    Wall_high_left(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};