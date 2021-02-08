#pragma once
#include "Object.h"

class Wall_high_lTop : 
    public Object
{
public:
    Wall_high_lTop(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};