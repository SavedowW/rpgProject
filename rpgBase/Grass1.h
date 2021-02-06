#pragma once
#include "Object.h"

class Grass1 : 
    public Object
{
public:
    Grass1(float x, float y);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};