#pragma once
#include "Object.h"

class Floor_cRight : 
    public Object
{
public:
    Floor_cRight(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};