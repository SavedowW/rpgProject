#include "Character.h"

void Character::addHp(int addVal)
{
	stats.HP += addVal;
	if (stats.HP > stats.maxHP)
		stats.HP = stats.maxHP;
	if (stats.HP < 0)
		stats.HP = 0;
}

void Character::addMp(int addVal)
{
	stats.MP += addVal;
	if (stats.MP > stats.maxMP)
		stats.MP = stats.maxMP;
	if (stats.MP < 0)
		stats.MP = 0;
}

int Character::calcPhysDamage()
{
	//Base damage as +% to physical damage

	int damage = float(weapon->stats.pDamage) * (1 + float(stats.bpDamage) / 100.0);
	return float(weapon->stats.pDamage) * (1 + float(stats.bpDamage) / 100.0);
}

int Character::receivePhysDamage(int damage, int mayBeParried)
{
	// realDamage = damage / (realDef)
	// realDef = baseDefense + armorDefense + block

	// realDamage may be 0 with a huge differense between enemy and player power
	// realDamage 100% will not be lower than 0

	bool parry = (rand() % 100 < weapon->stats.mainParry) || (rand() % 100 < weapon->stats.blockParry) && block;
	if (parry && mayBeParried)
		return 0;

	int def = stats.bpResist + armor->stats.pResist;
	if (block) def += weapon->stats.pResist;
	int realDamage = float(damage) / (1.0 + float(def) / 100);
	stats.HP -= realDamage;
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
		int hpGain = effect.value;
		addHp(hpGain);
		return hpGain;

	} else if (effect.effect == Buff::INSTANT_MP_RESTORE) {
		int mpGain = effect.value;
		addMp(mpGain);
		return mpGain;

	} else if (effect.effect == Buff::INSTANT_MAGICAL_DAMAGE) {
		int def = stats.bmResist + armor->stats.mResist;
		int realDamage = float(effect.value) / (1.0 + float(def) / 100) / getMagicalMultiplier();
		addHp(-realDamage);
		return realDamage;

	} else if (effect.effect == Buff::INSTANT_PHYSICAL_DAMAGE) {
		return receivePhysDamage(effect.value, false);

	} else if (effect.effect == Buff::OT_CURSE) {
		buffs.push_back(effect);

	} else if (effect.effect == Buff::INSTANT_CURSE_DAMAGE) {
		if (checkEffect(Buff::OT_SOULPROTECTION))
			return 0;
		else
			return receiveEffect(Buff(Buff::INSTANT_MAGICAL_DAMAGE, effect.value, Buff::SELF));

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

void Character::addSkill(SkillFactory::SkillList skillId)
{
	spells.push_back(SkillFactory::BuildSkill(skillId));
}

void Character::deleteSkill(SkillFactory::SkillList skillId)
{
	for (int i = 0; i < spells.size(); i++)
	{
		while (i < spells.size() && spells[i]->spellId == skillId)
		{
			delete spells[i];
			spells.erase(spells.begin() + i);
		}
	}
}

float Character::getMagicalMultiplier()
{
	return (1.0 + float(stats.bmPower) / 100.0);
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
