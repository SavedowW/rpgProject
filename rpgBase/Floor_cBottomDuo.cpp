#include "Floor_cBottomDuo.h"

Floor_cBottomDuo::Floor_cBottomDuo(const Vector2& nPos) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/dungeon/s_floor_cBottomDuo.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = 0;
}

SDL_Texture* Floor_cBottomDuo::getSprite()
{
	return spr_idle;
}
