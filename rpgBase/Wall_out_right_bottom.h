#pragma once
#include "Object.h"

class Wall_out_right_bottom : 
    public Object
{
Public:
    Wall_out_right_bottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};