#pragma once
#include "Object.h"

class Floor1 : 
    public Object
{
public:
    Floor1(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};