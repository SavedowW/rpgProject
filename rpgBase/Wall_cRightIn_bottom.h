#pragma once
#include "Object.h"

class Wall_cRightIn_bottom : 
    public Object
{
public:
    Wall_cRightIn_bottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};