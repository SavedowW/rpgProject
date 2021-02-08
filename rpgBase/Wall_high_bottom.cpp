#include "Wall_high_bottom.h"

Wall_high_bottom::Wall_high_bottom(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_high_bottom.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 1000000;
}

SDL_Texture* Wall_high_bottom::getSprite()
{
	return spr_idle;
}
