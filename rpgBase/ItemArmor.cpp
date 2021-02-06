#include "ItemArmor.h"

ItemArmor::ItemArmor(string nName, string nShortName, int nPrice, Rarity nRarity, ArmorStats nStats, const vector<string>& nDescr, int nId) :
	Item(nName, nShortName, nPrice, ARMOR, nRarity, nDescr, nId)
{
	stats = nStats;
}