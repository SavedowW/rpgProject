#pragma once
#include "Object.h"

class Wall_high_out_lTop : 
    public Object
{
Public:
    Wall_high_out_lTop(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};