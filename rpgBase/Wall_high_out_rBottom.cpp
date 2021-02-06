#include "Wall_high_out_rBottom.h"

Wall_high_out_rBottom::Wall_high_out_rBottom(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_high_out_rBottom.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_high_out_rBottom::getSprite()
{
	return spr_idle;
}
