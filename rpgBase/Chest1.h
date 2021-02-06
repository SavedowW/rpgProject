#pragma once
#include "Chest.h"

class Chest1 : 
    public Chest
{
public:
    Chest1(const Vector2 & nPos, const vector<Item*>& nInv);
    SDL_Texture* getSprite();

private:
    static SDL_Texture* spr_idle;
};