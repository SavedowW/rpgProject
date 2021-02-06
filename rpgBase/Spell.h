//=============================
//
//   Spell.h
//   Spell interface
//
//=============================
#pragma once
#include <iostream>
#include <vector>
#include "Buff.h"

using namespace std;

class Spell
{
public:
	int spellId;
	string name;
	vector<Buff> effects;
	int cost;
	vector<string> description;
	vector<vector<string>> battleDescr;
	Spell(string nName, const vector<Buff> &nEffects, int nCost, const vector<vector<string>> &nBattleDescr, const vector<string> &nDescr, int nId = 0);
};