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
string getItemShortName(ITEMLIST itemId);
int getItemPrice(ITEMLIST itemId);

struct StoreItem
{
	ITEMLIST itemId;
	int amount;
	StoreItem(ITEMLIST nItemId, int nAmount)
	{
		itemId = nItemId;
		amount = nAmount;
	}
	void decrease()
	{
		if (amount > 0)
			--amount;
	}
};