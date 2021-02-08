#pragma once
#include "Object.h"

class Floor : 
    public Object
{
public:
    Floor(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};