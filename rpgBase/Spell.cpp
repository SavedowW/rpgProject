#include "Spell.h"

Spell::Spell(string nName, const vector<Buff>& nEffects, int nCost, const vector<vector<string>>& nBattleDescr, const vector<string>& nDescr, int nId)
{
	name = nName;
	effects = nEffects;
	cost = nCost;
	spellId = nId;
	battleDescr = nBattleDescr;
	description = nDescr;
}