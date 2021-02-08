#include "Wall_in_duo_middle.h"

Wall_in_duo_middle::Wall_in_duo_middle(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_in_duo_middle.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Wall_in_duo_middle::getSprite()
{
	return spr_idle;
}
