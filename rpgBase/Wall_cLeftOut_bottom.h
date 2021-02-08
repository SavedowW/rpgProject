#pragma once
#include "Object.h"

class Wall_cLeftOut_bottom : 
    public Object
{
public:
    Wall_cLeftOut_bottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};