#pragma once

#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "ItemBuffer.h"

enum class ITEMLIST{
	ITEM_EXCALIBUR,
	ITEM_APPLE,
	ITEM_NOTHINGNESS,
	ITEM_CLAWS,
	ITEM_DENSE_SKIN
};

Item* BuildItem(ITEMLIST itemId);