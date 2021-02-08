#pragma once
#include "Object.h"

class Wall_cRightIn_middle : 
    public Object
{
public:
    Wall_cRightIn_middle(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};