#include "ItemTypeH.h"

Item* BuildItem(ITEMLIST itemId)
{
	switch (itemId)
	{
	case (ITEMLIST::ITEM_JUNK):
		return new Item(
			"Junk", "Junk", 1, Item::OTHER, Item::COMMON,
			{ "Just a junk.",
			  "No way to use it." }
		);
		break;

	case (ITEMLIST::ITEM_APPLE):
		return new ItemBuffer(
			"Apple", "Apple", 15, Item::COMMON,
			{ {Buff::INSTANT_HP_RESTORE, 30, Buff::SELF} },
			{ "Just an apple, but you'd",
			"better wash it before",
			"eat it. Especially because",
			"it's from a trash can."}
		);
		break;

	case (ITEMLIST::ITEM_EXCALIBUR_RUSTY):
		return new ItemWeapon(
			"Rusty Excalibur", "Rusty Excalibur", 100, Item::UNIQUE,
			{ 15, 20, 5, 3, 5 },
			{ "It used to be a sacred",
			"sword, but now it's",
			"power is gone. Probably,",
			"it's possible to reveal",
			"a part of it's previous",
			"strength."}, 
			{SkillFactory::SKILL_CURSE_OF_GONE_HOLINESS});
		break;

	case (ITEMLIST::ITEM_NOTE_BITE):
		return new Item(
			"Disappointing note", "Disappointing note", 0, Item::OTHER, Item::RARE,
			{ "HAHA",
			"GOT BITED LOL" }
		);
		break;

	case (ITEMLIST::ITEM_CLARENT):
		return new ItemWeapon(
			"Clarent", "Clarent", 400, Item::LEGENDARY,
			{ 30, 25, 10, 3, 10 },
			{ "A legendary sacred",
			"sword. It supposed to",
			"grand additional",
			"abilities to kings,",
			"but since you're not",
			"one, it's just a powerfull",
			"sword. "},
			{ SkillFactory::SKILL_BLESSING_OF_SECONDARY_SWORD });
		break;

	case (ITEMLIST::ITEM_DEADBODIES):
		return new Item(
			"Dead bodies", "Deads", 1, Item::OTHER, Item::COMMON,
			{ "Whoever did it,",
			  "has a silly sense",
			"of humor..."}, 4
		);
		break;

	case (ITEMLIST::ITEM_CLAWS):
		return new ItemWeapon("Claws", "Claws", 100, Item::COMMON, { 15, 5, 10, 1, 2 }, {}, {});
		break;

	case (ITEMLIST::ITEM_DENSE_SKIN):
		return new ItemArmor("Dense skin", "Dense skin", 100, Item::COMMON, { 15, 10 }, {}, {});
		break;

	}
}

string getItemShortName(ITEMLIST itemId)
{
	Item* item = BuildItem(itemId);
	string name = item->shortName;
	delete item;
	return name;
}

int getItemPrice(ITEMLIST itemId)
{
	Item* item = BuildItem(itemId);
	int price = item->price;
	delete item;
	return price;
}
