#include "Wyvern.h"

Wyvern::Wyvern(GameCore* nGameCore)
{
	gameCore = nGameCore;

	name = "Wyvern";

	maxHP = 50;
	maxMP = 10;
	HP = maxHP;
	MP = maxMP;

	bpDamage = 20;
	bmPower = 10;
	bpResist = 10;
	bmResist = 20;

	weapon = (ItemWeapon*)BuildItem(ITEMLIST::ITEM_CLAWS);
	armor = (ItemArmor*)BuildItem(ITEMLIST::ITEM_DENSE_SKIN);

	spells.push_back(new Spell(
		"Ultima",
		{ {Buff::OT_CURSE, 10, Buff::ENEMY, 3}, {Buff::OT_HPREGEN, 10, Buff::SELF, 4} }, 10,
		{ {"Broken spell activated" } },
		{ "Not required." })
	);

	int w, h;
	if (spr_idle == NULL)
	{
		spr_idle = gameCore->loadTexture("Sprites/Enemies/Wyvern/spr_idle.png");
	}
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	pos = {320.0f - float(w) / 2.0f, 100.0f - float(h) / 2.0f};
	offset = { 0, 0 };
	timer = 0;
	period = PI / 35;

}

CharacterAction* Wyvern::stepAI()
{
	if (MP == maxMP)
		return new CharacterAction(CharacterAction::SKILL, 0);
	else
		return new CharacterAction(CharacterAction::ATTACK, 0);
}

void Wyvern::draw()
{
	timer += period;
	while (timer >= PI * 2)
		timer -= PI * 2;
	offset = {0, sin(timer) * 25};
	gameCore->drawTexture(spr_idle, pos + offset);
}

vector<vector<string>> Wyvern::appearanceText()
{
	return {
		{"A wild dragon-like wyvern appears!", "Be ready to beat it"},
		{"Technical line"}
	};
}

const int Wyvern::getExp()
{
	return 5;
}

const vector<Item*> Wyvern::reward()
{
	return vector<Item*>();
}
