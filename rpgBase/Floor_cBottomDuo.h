#pragma once
#include "Object.h"

class Floor_cBottomDuo : 
    public Object
{
public:
    Floor_cBottomDuo(const Vector2 & nPos);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};