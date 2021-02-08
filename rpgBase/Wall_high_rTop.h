#pragma once
#include "Object.h"

class Wall_high_rTop : 
    public Object
{
public:
    Wall_high_rTop(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};