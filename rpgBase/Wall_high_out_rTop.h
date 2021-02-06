#pragma once
#include "Object.h"

class Wall_high_out_rTop : 
    public Object
{
Public:
    Wall_high_out_rTop(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};