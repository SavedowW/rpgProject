#pragma once
#include "Object.h"

class Wall_middle_bottom : 
    public Object
{
Public:
    Wall_middle_bottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};