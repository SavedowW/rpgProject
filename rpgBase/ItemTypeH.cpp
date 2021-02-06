#include "ItemTypeH.h"

Item* BuildItem(ITEMLIST itemId)
{
	switch (itemId)
	{
	case (ITEMLIST::ITEM_APPLE):
		return new ItemBuffer(
			"Apple", "Apple", 15, Item::COMMON,
			{ {Buff::INSTANT_HP_RESTORE, 30, Buff::SELF} },
			{ "Just an apple, but you'd",
			"better wash it before",
			"eat it" }
		);
		break;

	case (ITEMLIST::ITEM_EXTHORIUM):
		return new ItemWeapon(
			"Exthorium", "Exthorium", 250, Item::UNIQUE,
			{ 30, 15, 10, 3, 10 },
			{ "A blade that makes user",
			"able to send magical waves",
			"like he's using spells" },
			6);
		break;

	case (ITEMLIST::ITEM_EMPTINESS):
		return new Item(
			"Emptiness", "Emptiness", 0, Item::OTHER, Item::COMMON,
			{ "Literally nothing.",
			"Nothing at all.",
			"Just remove it." }
		);
		break;

	case (ITEMLIST::ITEM_CLAWS):
		return new ItemWeapon("Claws", "Claws", 100, Item::COMMON, { 15, 5, 10, 1, 2 }, {});
		break;

	case (ITEMLIST::ITEM_DENSE_SKIN):
		return new ItemArmor("Dense skin", "Dense skin", 100, Item::COMMON, { 15, 10 }, {});
		break;

	}
}