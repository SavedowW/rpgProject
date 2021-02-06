#include "Wall_out_right_bottom.h"

Wall_out_right_bottom::Wall_out_right_bottom(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_cRightOutl_bottom1.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_out_right_bottom::getSprite()
{
	return spr_idle;
}
