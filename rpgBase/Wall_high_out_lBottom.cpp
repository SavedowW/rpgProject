#include "Wall_high_out_lBottom.h"

Wall_high_out_lBottom::Wall_high_out_lBottom(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_high_out_lBottom.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_high_out_lBottom::getSprite()
{
	return spr_idle;
}
