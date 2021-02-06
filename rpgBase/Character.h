//========================
//
//		Character.h
//		Base class with stats and functions, required in battle
//		Must be used in pair with Enemy, with an exception of Player
//
//========================
#pragma once
#include "ItemTypeH.h"
#include "Spell.h"

struct CharacterAction
{
	enum ActionType { NONE, ATTACK, SKILL, ITEM, DEFEND } action;
	int id;
	CharacterAction(ActionType nAction = NONE, int nId = 0)
	{
		action = nAction;
		id = nId;
	}
};

class Character
{
public:
	string name;

	int HP;
	int MP;
	int maxHP;
	int maxMP;

	int bpDamage; //base physical damage
	int bmPower; //base magical power
	int bpResist; //base physical resist
	int bmResist; //base magical resist

	vector<Spell*> spells;

	ItemWeapon* weapon;
	ItemArmor* armor;

	vector<Buff> buffs;

	bool block;

	int calcPhysDamage();
	int receivePhysDamage(int damage, int mayBeParried = true);

	virtual void beginTurn();
	virtual void endTurn();

	int receiveEffect(Buff effect);
	bool checkEffect(Buff::Buffs effect);

	float getMagicalMultiplier();

	const virtual int getExp();
	const virtual vector<Item*> reward();

	virtual CharacterAction* stepAI();
};