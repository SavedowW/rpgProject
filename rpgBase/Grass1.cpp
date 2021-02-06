#include "Grass1.h"

Grass1::Grass1(float x, float y) :
    Object({x, y})
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/s_grass1.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 0;
}

SDL_Texture* Grass1::getSprite()
{
	return spr_idle;
}
