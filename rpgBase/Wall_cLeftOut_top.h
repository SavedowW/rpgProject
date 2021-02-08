#pragma once
#include "Object.h"

class Wall_cLeftOut_top : 
    public Object
{
public:
    Wall_cLeftOut_top(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};