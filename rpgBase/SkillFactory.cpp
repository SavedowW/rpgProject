#include "SkillFactory.h"

Spell* SkillFactory::BuildSkill(SkillList skillId)
{
	switch (skillId)
	{
	case (SKILL_HEAL):
		return new Spell(
			"Heal",
			{ {Buff::INSTANT_HP_RESTORE, 50, Buff::SELF} }, 5,
			{ {"A green shine surrounds you, and your wounds are quickly healing", "For a certain price, of course."} },
			{ "A simple \"regeneration burst\"",
			"spell. It wastes mana as a",
			"resource. Other way, it would",
			"waste your health what would",
			"make it useless" }, SKILL_HEAL);
		break;

	case (SKILL_FIRESTORM):
		return new Spell(
			"Firestorm",
			{ {Buff::INSTANT_MAGICAL_DAMAGE, 50, Buff::ENEMY} }, 15,
			{ {"A merciless fire absorbs everything around you.", "There is no way to dodge this spell." } },
			{ "A complicated spell that",
			"summons a firestorm. Yes,",
			"it's a summon spell, not a",
			"manifestation one. Hell is",
			"full of this storms so no",
			"one would notice this loss...",
			"And they don't even care about",
			"it." }, SKILL_FIRESTORM);
		break;

	case (SKILL_VAMPBITE):
		return new Spell(
			"Vampire's bite",
			{ {Buff::INSTANT_PHYSICAL_DAMAGE, 20, Buff::ENEMY}, {Buff::INSTANT_HP_RESTORE, 5, Buff::SELF} }, 3,
			{ {"You're quickly jump to the enemy", "and put your fangs into his neck." } },
			{ "A legacy of your vampire roots.",
			"It's a basic skill, avaible",
			"for all vampires." }, SKILL_VAMPBITE);
		break;

	case (SKILL_ULTIMA):
		return new Spell(
			"Ultima",
			{ {Buff::OT_CURSE, 10, Buff::ENEMY, 3}, {Buff::OT_HPREGEN, 10, Buff::SELF, 4} }, 10,
			{ {"Broken spell activated" } },
			{ "Not required." }, SKILL_ULTIMA);
		break;

	case (SKILL_SOULPROTECTION):
		return new Spell(
			"Soul protection",
			{ {Buff::OT_SOULPROTECTION, 1, Buff::SELF, 2} }, 10,
			{ {"Blessed spell activated" } },
			{ "Not required." }, SKILL_SOULPROTECTION);
		break;

	case (SKILL_CURSE_OF_GONE_HOLINESS):
		return new Spell(
			"Curse of gone holiness",
			{ { Buff::INSTANT_PHYSICAL_DAMAGE, 20, Buff::ENEMY }, { Buff::INSTANT_CURSE_DAMAGE, 20, Buff::ENEMY } }, 5,
			{ {"You swing your blade quickly, in a single plane,", "and unleash it's curse onto enemy"} },
			{ "This spell is basically",
			"a result of the leftovers",
			"of this sword's powers.",
			"Although you cannot",
			"perform miracles like",
			"it was in true form,",
			"it still may be effective."
			}, SKILL_CURSE_OF_GONE_HOLINESS);
		break;

	case (SKILL_BLESSING_OF_SECONDARY_SWORD):
		return new Spell(
			"Blessing of secondary sword",
			{ { Buff::INSTANT_PHYSICAL_DAMAGE, 40, Buff::ENEMY }, { Buff::INSTANT_MAGICAL_DAMAGE, 30, Buff::ENEMY } }, 5,
			{ {"You fill your sword with magical energy,", "and unleash it's power onto enemy"} },
			{ "You would be disappointed",
			"in it's power if you knew",
			"the strength of the true",
			"Excalibur, but, still..."
			}, SKILL_BLESSING_OF_SECONDARY_SWORD);
		break;

	}
}

string SkillFactory::GetSkillName(SkillList skillId)
{
	Spell* skill = BuildSkill(skillId);
	string name = skill->name;
	delete skill;
	return name;
}
