#include "Trashcan1.h"

Trashcan1::Trashcan1(const Vector2& nPos, const vector<Item*>& nInv) :
    Chest(nPos, nInv)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/s_trashcan.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Trashcan1::getSprite()
{
	return spr_idle;
}
