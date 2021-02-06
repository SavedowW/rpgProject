#pragma once
#include "Object.h"

class Floor_cLeft : 
    public Object
{
public:
    Floor_cLeft(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};