#include "Wall_cRightOut_middle.h"

Wall_cRightOut_middle::Wall_cRightOut_middle(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_cRightOut_middle.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_cRightOut_middle::getSprite()
{
	return spr_idle;
}
