#include "Floor_cLeft.h"

Floor_cLeft::Floor_cLeft(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_floor_cLeft.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 0;
}

SDL_Texture* Floor_cLeft::getSprite()
{
	return spr_idle;
}
