#pragma once
#include "Spell.h"

class SkillFactory
{
public:
	enum SkillList {
		SKILL_HEAL,
		SKILL_FIRESTORM,
		SKILL_VAMPBITE,
		SKILL_ULTIMA,
		SKILL_SOULPROTECTION,
		SKILL_CURSE_OF_GONE_HOLINESS,
		SKILL_BLESSING_OF_SECONDARY_SWORD
	};

	static Spell* BuildSkill(SkillList skillId);
	static string GetSkillName(SkillList skillId);
};