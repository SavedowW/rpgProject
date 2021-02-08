#include "Monitor.h"

Monitor::Monitor(const Vector2& nPos, vector<AnimatedTexture*>& textureList) :
    Object(nPos)
{
    if (spr_idle == NULL)
    {
        spr_idle = new AnimatedTexture("Sprites/Enviroment/monitor", core, 0.2);
        textureList.push_back(spr_idle);
    }

    int w, h;
	SDL_QueryTexture((*spr_idle)[0], NULL, NULL, &w, &h);
	depth = pos.y + h;
}

SDL_Texture* Monitor::getSprite()
{
	return spr_idle->getSprite();
}
