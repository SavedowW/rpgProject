#pragma once
#include "InteractiveObject.h"

class Blader : 
    public InteractiveObject
{
public:
    Blader(const Vector2 & nPos, int** nTarget);
    SDL_Texture* getSprite();

    vector<StoreItem> storeList;

private:
    static SDL_Texture* spr_idle;
};