#pragma once
#include "Object.h"

class Wall_in_duo_bottom : 
    public Object
{
public:
    Wall_in_duo_bottom(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};