#include "Floor_cRight.h"

Floor_cRight::Floor_cRight(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_floor_cRight.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 0;
}

SDL_Texture* Floor_cRight::getSprite()
{
	return spr_idle;
}
