#include "Item.h"

Item::Item(string nName, string nShortName, int nPrice, Type nType, Rarity nRarity, const vector<string>& nDescr, int nId)
{
	itemId = nId;

	name = nName;
	shortName = nShortName;
	price = nPrice;
	priceToSell = nPrice * 0.8;
	type = nType;
	rarity = nRarity;
	description = nDescr;
}