#include "Wall_cLeftOut_bottom.h"

Wall_cLeftOut_bottom::Wall_cLeftOut_bottom(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_cLeftOut_bottom.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_cLeftOut_bottom::getSprite()
{
	return spr_idle;
}
