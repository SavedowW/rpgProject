#pragma once
#include "Object.h"

class Wall_high_out_lBottom : 
    public Object
{
Public:
    Wall_high_out_lBottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};