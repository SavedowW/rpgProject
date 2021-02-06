#pragma once
#include "Item.h"

class ItemBuffer :
    public Item
{
public:
    vector<Buff> effects;
    ItemBuffer(string nName, string nShortName, int nPrice, Rarity nRarity, const vector<Buff> &nEffects, const vector<string>& nDescr, int nId = 0);
};

