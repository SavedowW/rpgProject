#pragma once
#include "Item.h"

struct WepStats
{
    int pDamage; //Physical damage (base as a +%)
    int mDamage; //Magical damage (+% to base)
    int pResist; //Physical resist (additional with BLOCK)
    int mainParry; //Chance to parry
    int blockParry; //Chance to parry in block
};

class ItemWeapon :
    public Item
{
public:
    WepStats stats;
    vector<SkillFactory::SkillList> linkedSkills;
    ItemWeapon(string nName, string nShortName,
        int nPrice, Rarity nRarity,
        WepStats nStats,
        const vector<string>& nDescr,
        vector<SkillFactory::SkillList> nLinkedSkills,
        int nId = 0);
};