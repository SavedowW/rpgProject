#include "Chest1.h"

Chest1::Chest1(const Vector2& nPos, const vector<Item*>& nInv) :
    Chest(nPos, nInv)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/s_chest1.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Chest1::getSprite()
{
	return spr_idle;
}
