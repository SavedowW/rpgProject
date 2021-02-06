#include "Character.h"

int Character::calcPhysDamage()
{
	int damage = float(weapon->stats.pDamage) * (1 + float(bpDamage) / 100.0);
	//cout << "Damage output: " << damage << endl;
	return float(weapon->stats.pDamage) * (1 + float(bpDamage) / 100.0);
}

int Character::receivePhysDamage(int damage, int mayBeParried)
{
	bool parry = (rand() % 100 < weapon->stats.mainParry) || (rand() % 100 < weapon->stats.blockParry) && block;
	if (parry && mayBeParried) return 0;

	int def = bpResist + armor->stats.pResist;
	if (block) def += weapon->stats.pResist;
	int realDamage = float(damage) / (1.0 + float(def) / 100);
	HP -= realDamage;
	//cout << "Def: " << def << endl;
	//cout << "Damage input: " << realDamage << endl;
	return realDamage;
}

void Character::beginTurn()
{
	block = false;
}

void Character::endTurn()
{
	//Effects from buffs must be handled by the BattleLevel
	for (int i = 0; i < buffs.size(); i++)
	{
		--buffs[i].timer;
	}
	for (int i = 0; i < buffs.size(); i++)
	{
		while (i < buffs.size() && buffs[i].timer == 0)
		{
			buffs.erase(buffs.begin() + i);
		}
	}
}

int Character::receiveEffect(Buff effect)
{
	if (effect.effect == Buff::INSTANT_HP_RESTORE) {
		int hpGain = effect.value * getMagicalMultiplier();
		HP += hpGain;
		if (HP > maxHP) HP = maxHP;
		return hpGain;

	} else if (effect.effect == Buff::INSTANT_MP_RESTORE) {
		int mpGain = effect.value * getMagicalMultiplier();
		MP += mpGain;
		if (MP > maxMP) MP = maxMP;
		return mpGain;

	} else if (effect.effect == Buff::INSTANT_MAGICAL_DAMAGE) {
		int def = bmResist + armor->stats.mResist;
		int realDamage = float(effect.value) / (1.0 + float(def) / 100) / getMagicalMultiplier();
		HP -= realDamage;
		return realDamage;

	} else if (effect.effect == Buff::INSTANT_PHYSICAL_DAMAGE) {
		return receivePhysDamage(effect.value, false);

	} else if (effect.effect == Buff::OT_CURSE) {
		buffs.push_back(effect);

	} else if (effect.effect == Buff::INSTANT_CURSE_DAMAGE) {
		if (checkEffect(Buff::OT_SOULPROTECTION))
			return 0;
		else
			return receiveEffect(Buff(Buff::INSTANT_MAGICAL_DAMAGE, effect.value));

	} else if (effect.effect == Buff::OT_SOULPROTECTION) {
		buffs.push_back(effect);

	} else if (effect.effect == Buff::OT_HPREGEN) {
		buffs.push_back(effect);

	}
}

bool Character::checkEffect(Buff::Buffs effect)
{
	for (int i = 0; i < buffs.size(); i++)
	{
		if (effect == buffs[i].effect)
			return true;
	}
	return false;
}

float Character::getMagicalMultiplier()
{
	return (1.0 + float(bmPower) / 100.0);
}

const int Character::getExp()
{
	return 0;
}

const vector<Item*> Character::reward()
{
	return vector<Item*>();
}

CharacterAction* Character::stepAI()
{
	return new CharacterAction;
}
