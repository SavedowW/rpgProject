//========================
//
//		Character.h
//		Base class with stats and functions, required in battle
//		Must be used in pair with Enemy, with an exception of Player
//
//========================
#pragma once
#include "ItemTypeH.h"
#include "SkillFactory.h"

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

struct CharacterStats
{
	int HP;
	int MP;
	int maxHP;
	int maxMP;

	int bpDamage; //base physical damage
	int bmPower; //base magical power
	int bpResist; //base physical resist
	int bmResist; //base magical resist
};

class Character
{
public:
	string name;

	CharacterStats stats;

	vector<Spell*> spells;

	ItemWeapon* weapon;
	ItemArmor* armor;

	vector<Buff> buffs;

	bool block;

	virtual void addHp(int addVal);
	virtual void addMp(int addVal);

	int calcPhysDamage();
	int receivePhysDamage(int damage, int mayBeParried = true);

	virtual void beginTurn();
	virtual void endTurn();

	int receiveEffect(Buff effect);
	bool checkEffect(Buff::Buffs effect);

	void addSkill(SkillFactory::SkillList skillId);
	void deleteSkill(SkillFactory::SkillList skillId);

	float getMagicalMultiplier();

	const virtual int getExp();
	const virtual vector<Item*> reward();

	virtual CharacterAction* stepAI();
};