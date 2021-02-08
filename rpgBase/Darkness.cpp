#include "Darkness.h"

Darkness::Darkness(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_darkness.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 999999;
}

SDL_Texture* Darkness::getSprite()
{
	return spr_idle;
}
