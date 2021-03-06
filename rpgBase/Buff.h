#pragma once

struct Buff
{
	enum Buffs {
		INSTANT_HP_RESTORE,
		INSTANT_MP_RESTORE,
		INSTANT_MAGICAL_DAMAGE,
		INSTANT_PHYSICAL_DAMAGE,
		OT_CURSE,
		INSTANT_CURSE_DAMAGE,
		OT_SOULPROTECTION,
		OT_HPREGEN
	} effect;
	enum Target {SELF, ENEMY} target;
	float value;
	int timer;
	Buff(Buffs nEffect, float nValue, Target nTar, int nTimer = -1)
	{
		effect = nEffect;
		value = nValue;
		timer = nTimer;
		target = nTar;
	}
};