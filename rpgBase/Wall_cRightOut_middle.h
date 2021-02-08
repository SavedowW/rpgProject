#pragma once
#include "Object.h"

class Wall_cRightOut_middle : 
    public Object
{
public:
    Wall_cRightOut_middle(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};