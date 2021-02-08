#pragma once
#include "Object.h"

class Darkness : 
    public Object
{
public:
    Darkness(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};