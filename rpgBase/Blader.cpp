#include "Blader.h"

Blader::Blader(const Vector2& nPos, int** nTarget) :
    InteractiveObject(nPos, hitbox(nPos.x, nPos.y + 10, 32, 32), nTarget)
{
    if (spr_idle == NULL)
    {
        spr_idle = core->loadTexture("Sprites/Enviroment/Blader/idle/s_1.png");
    }

    int w, h;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;

    storeList = {StoreItem(ITEMLIST::ITEM_APPLE, -1), StoreItem(ITEMLIST::ITEM_EXCALIBUR_RUSTY, 1)};
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));
    storeList.push_back(StoreItem(ITEMLIST::ITEM_APPLE, -1));

    targetScene = 1;
}

SDL_Texture* Blader::getSprite()
{
	return spr_idle;
}
