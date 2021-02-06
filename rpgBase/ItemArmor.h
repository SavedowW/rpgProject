#pragma once
#include "Item.h"

struct ArmorStats
{
    int pResist; //Additional physical resist
    int mResist; //Additional magical resist
};

class ItemArmor :
    public Item
{
public:
    ArmorStats stats;
    ItemArmor(string nName, string nShortName, int nPrice, Rarity nRarity, ArmorStats nStats, const vector<string>& nDescr, int nId = 0);
};