#pragma once
#include "Object.h"

class Wall_middle : 
    public Object
{
public:
    Wall_middle(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};