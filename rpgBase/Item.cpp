#include "Item.h"

Item::Item(string nName, string nShortName, int nPrice, Type nType, Rarity nRarity, const vector<string>& nDescr, int nId)
{
	itemId = nId;

	name = nName;
	shortName = nShortName;
	price = nPrice;
	type = nType;
	rarity = nRarity;
	description = nDescr;
}