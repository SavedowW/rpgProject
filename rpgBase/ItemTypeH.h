#pragma once

#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "ItemBuffer.h"

enum class ITEMLIST{
	ITEM_APPLE,
	ITEM_EXTHORIUM,
	ITEM_EMPTINESS,
	ITEM_CLAWS,
	ITEM_DENSE_SKIN
};

Item* BuildItem(ITEMLIST itemId);