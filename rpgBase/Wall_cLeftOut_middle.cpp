#include "Wall_cLeftOut_middle.h"

Wall_cLeftOut_middle::Wall_cLeftOut_middle(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_cLeftOut_middle.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_cLeftOut_middle::getSprite()
{
	return spr_idle;
}
