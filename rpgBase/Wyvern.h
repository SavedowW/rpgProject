#pragma once
#include "Character.h"
#include "Enemy.h"

class Wyvern :
    public Enemy
{
public:
    Wyvern(GameCore* nGameCore);

    CharacterAction* stepAI();
    
    void draw();

    vector<vector<string>> appearanceText();

    const int getExp();
    const vector<Item*> reward();

private:
    static SDL_Texture* spr_idle;
};