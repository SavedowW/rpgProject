#pragma once
#include "Object.h"

class Wall_high_lBottom : 
    public Object
{
public:
    Wall_high_lBottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};