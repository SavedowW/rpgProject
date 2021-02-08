#pragma once

#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "ItemBuffer.h"

enum class ITEMLIST{
	ITEM_JUNK,
	ITEM_APPLE,
	ITEM_EXCALIBUR_RUSTY,
	ITEM_NOTE_BITE,
	ITEM_CLARENT,
	ITEM_DEADBODIES,
	ITEM_CLAWS,
	ITEM_DENSE_SKIN
};

Item* BuildItem(ITEMLIST itemId);