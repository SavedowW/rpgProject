#include "Wall_cLeftIn_middle.h"

Wall_cLeftIn_middle::Wall_cLeftIn_middle(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_cLeftIn_middle.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 1;
}

SDL_Texture* Wall_cLeftIn_middle::getSprite()
{
	return spr_idle;
}
