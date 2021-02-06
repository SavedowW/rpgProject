#pragma once
#include "Object.h"

class Monitor : 
    public Object
{
public:
    Monitor(const Vector2 & nPos, vector<AnimatedTexture*>& textureList);
    SDL_Texture* getSprite();

private:
    static AnimatedTexture* spr_idle;
};