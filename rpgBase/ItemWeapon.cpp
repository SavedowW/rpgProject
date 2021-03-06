#include "ItemWeapon.h"

ItemWeapon::ItemWeapon(string nName, string nShortName,
    int nPrice, Rarity nRarity,
    WepStats nStats,
    const vector<string>& nDescr,
    vector<SkillFactory::SkillList> nLinkedSkills,
    int nId) :
	Item(nName, nShortName, nPrice, WEAPON, nRarity, nDescr, nId)
{
	stats = nStats;
    linkedSkills = nLinkedSkills;
}