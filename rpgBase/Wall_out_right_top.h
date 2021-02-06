#pragma once
#include "Object.h"

class Wall_out_right_top : 
    public Object
{
Public:
    Wall_out_right_top(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};