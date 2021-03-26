#include "Wyvern.h"

Wyvern::Wyvern(GameCore* nGameCore)
{
	gameCore = nGameCore;

	name = "Wyvern";

	stats.maxHP = 1;
	stats.maxMP = 10;
	stats.HP = stats.maxHP;
	stats.MP = stats.maxMP;

	stats.bpDamage = 20;
	stats.bmPower = 10;
	stats.bpResist = 10;
	stats.bmResist = 20;

	weapon = (ItemWeapon*)BuildItem(ITEMLIST::ITEM_CLAWS);
	armor = (ItemArmor*)BuildItem(ITEMLIST::ITEM_DENSE_SKIN);

	addSkill(SkillFactory::SKILL_ULTIMA);

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
	if (stats.MP == stats.maxMP)
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
