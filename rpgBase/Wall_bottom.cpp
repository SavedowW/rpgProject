#include "Wall_bottom.h"

Wall_bottom::Wall_bottom(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_bottom.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 1;
}

SDL_Texture* Wall_bottom::getSprite()
{
	return spr_idle;
}
