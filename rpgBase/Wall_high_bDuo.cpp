#include "Wall_high_bDuo.h"

Wall_high_bDuo::Wall_high_bDuo(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_wall_high_bDuo.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 1000000;
}

SDL_Texture* Wall_high_bDuo::getSprite()
{
	return spr_idle;
}
