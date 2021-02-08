#include "Wall_cLeftIn_top.h"

Wall_cLeftIn_top::Wall_cLeftIn_top(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_cLeftIn_top.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_cLeftIn_top::getSprite()
{
	return spr_idle;
}
