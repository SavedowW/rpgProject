#include "Wall_high_rTop.h"

Wall_high_rTop::Wall_high_rTop(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_high_rTop.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 1000000;
}

SDL_Texture* Wall_high_rTop::getSprite()
{
	return spr_idle;
}
