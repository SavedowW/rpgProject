#pragma once
#include "Object.h"

class Blader : 
    public Object
{
public:
    Blader(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};