#include "Floor.h"

Floor::Floor(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_floor1.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 0;
}

SDL_Texture* Floor::getSprite()
{
	return spr_idle;
}
