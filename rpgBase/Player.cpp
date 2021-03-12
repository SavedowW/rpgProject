#include "Player.h"

int getLimitedInput(int lowerEdge, int higherEdge);

Player::Player(const Vector2& nPos) :
	Object(nPos)
{
	prepareLevels();

	name = "Altrei";

	stats = levels[1].levelStats;

	block = false;

	exp = 1;
	lvl = 1;
	money = 999999;

	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_HEAL));
	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_FIRESTORM));
	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_VAMPBITE));
	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_ULTIMA));
	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_SOULPROTECTION));
	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_SOULPROTECTION));

	weapon = new ItemWeapon(
		"Steel sword", "Steel sword", 50, Item::COMMON,
		{ 10, 5, 20, 5, 5 },
		{"A common steel sword.",
		"Usually, army orders pales",
		"of them, and then they",
		"appear outside.",
		"And soldiers somehow",
		"gets a bit richer."},
		{}
	);
	armor = new ItemArmor(
		"Leather armor", "Leather armor", 100, Item::RARE,
		{ 10, 10 },
		{"Just a leather armor.",
		"It would be great if",
		"it was made of a",
		"dragon's scales, but it's",
		"probably only a wolf's",
		"leather."}
	);

	if (spr_idle == NULL)
	{
		spr_idle = core->loadTexture("Sprites/Player/s_idle.png");
	}
	int w;
	SDL_QueryTexture(spr_idle, NULL, NULL, &w, &h);
	depth = pos.y + h;
	movement.spd = 3;
	relativeHBox = {9, 25, 14, 6 };
	updateHBox();
}

int Player::useItem(int id)
{
	int itemId = inventory[id]->itemId;
	if (inventory[id]->type == Item::OTHER) {
		if (itemId == 0)
			return 0;
		else
			return itemId * 10;

	} else if (inventory[id]->type == Item::WEAPON) {
		ItemWeapon* temp = (ItemWeapon*)(inventory[id]);
		inventory[id] = weapon;
		weapon = temp;

		//Receive unique skills
		for (int i = 0; i < weapon->linkedSkills.size(); ++i)
		{
			addSkill(weapon->linkedSkills[i]);
		}

		//Remove unique skills
		ItemWeapon* oldWeapon = (ItemWeapon*)(inventory[id]);
		for (int i = 0; i < oldWeapon->linkedSkills.size(); ++i)
		{
			deleteSkill(oldWeapon->linkedSkills[i]);
		}

		//Return ID of a new weapon
		if (itemId == 0)
			return 1;
		else
			return itemId * 10 + 1;

	} else if (inventory[id]->type == Item::ARMOR) {
		ItemArmor* temp = (ItemArmor*)(inventory[id]);
		inventory[id] = armor;
		armor = temp;
		if (itemId == 0)
			return 2;
		else
			return itemId * 10 + 2;

	} else if (inventory[id]->type == Item::BUFFER) {
		for (int i = 0; i < ((ItemBuffer*)inventory[id])->effects.size(); i++)
		{
			receiveEffect(((ItemBuffer*)inventory[id])->effects[i]);
		}
		delete inventory[id];
		inventory.erase(inventory.begin() + id);
		if (itemId == 0)
			return 3;
		else
			return itemId * 10 + 3;

	}
	return 0;
}

int Player::removeItem(int id)
{
	int itemId = inventory[id]->itemId;
	delete inventory[id];
	inventory.erase(inventory.begin() + id);
	return itemId;
}

vector<PlayerLevel> Player::gainExp(int nExp)
{
	vector<PlayerLevel> newLevels;

	if (lvl == MAXLVL)
		return {};
	else
	{
		exp += nExp;
		for (int i = lvl + 1; i <= MAXLVL; ++i)
		{
			if (exp >= levels[i].minExp)
			{
				stats = levels[i].levelStats;
				newLevels.push_back(levels[i]);
				lvl = i;
			}
		}
		if (lvl == MAXLVL)
			exp = levels[MAXLVL].minExp;
		return newLevels;
	}
}

void Player::addMoney(int addM)
{
	money += addM;
}

SDL_Texture* Player::getSprite()
{
	return spr_idle;
}

void Player::update()
{
	
}

void Player::updateDepth()
{
	depth = pos.y + h;
}

void Player::updateHBox()
{
	hBox = relativeHBox + pos;
}

void Player::stop()
{
	movement.velocity = { 0, 0 };
}

void Player::prepareLevels()
{
	levels[0].lvl = 0;
	levels[0].minExp = 0;

	levels[0].levelStats.maxHP = 0;
	levels[0].levelStats.maxMP = 0;
	levels[0].levelStats.HP = levels[0].levelStats.maxHP;
	levels[0].levelStats.MP = levels[0].levelStats.maxMP;

	levels[0].levelStats.bpDamage = 0;
	levels[0].levelStats.bmPower = 0;
	levels[0].levelStats.bpResist = 0;
	levels[0].levelStats.bmResist = 0;

	//Level 1
	levels[1].lvl = 1;
	levels[1].minExp = 1;

	levels[1].levelStats.maxHP = 100;
	levels[1].levelStats.maxMP = 30;
	levels[1].levelStats.HP = levels[1].levelStats.maxHP;
	levels[1].levelStats.MP = levels[1].levelStats.maxMP;

	levels[1].levelStats.bpDamage = 30;
	levels[1].levelStats.bmPower = 10;
	levels[1].levelStats.bpResist = 15;
	levels[1].levelStats.bmResist = 20;

	//Level 2
	levels[2].lvl = 2;
	levels[2].minExp = 10;

	levels[2].levelStats.maxHP = 110;
	levels[2].levelStats.maxMP = 35;
	levels[2].levelStats.HP = levels[2].levelStats.maxHP;
	levels[2].levelStats.MP = levels[2].levelStats.maxMP;

	levels[2].levelStats.bpDamage = 35;
	levels[2].levelStats.bmPower = 12;
	levels[2].levelStats.bpResist = 16;
	levels[2].levelStats.bmResist = 20;

	//Level 3
	levels[3].lvl = 3;
	levels[3].minExp = 30;

	levels[3].levelStats.maxHP = 120;
	levels[3].levelStats.maxMP = 40;
	levels[3].levelStats.HP = levels[3].levelStats.maxHP;
	levels[3].levelStats.MP = levels[3].levelStats.maxMP;

	levels[3].levelStats.bpDamage = 40;
	levels[3].levelStats.bmPower = 14;
	levels[3].levelStats.bpResist = 18;
	levels[3].levelStats.bmResist = 24;

	//Level 4
	levels[4].lvl = 4;
	levels[4].minExp = 65;

	levels[4].levelStats.maxHP = 130;
	levels[4].levelStats.maxMP = 45;
	levels[4].levelStats.HP = levels[4].levelStats.maxHP;
	levels[4].levelStats.MP = levels[4].levelStats.maxMP;

	levels[4].levelStats.bpDamage = 40;
	levels[4].levelStats.bmPower = 18;
	levels[4].levelStats.bpResist = 20;
	levels[4].levelStats.bmResist = 24;

	//Level 5
	levels[5].lvl = 5;
	levels[5].minExp = 100;

	levels[5].levelStats.maxHP = 140;
	levels[5].levelStats.maxMP = 50;
	levels[5].levelStats.HP = levels[5].levelStats.maxHP;
	levels[5].levelStats.MP = levels[5].levelStats.maxMP;

	levels[5].levelStats.bpDamage = 44;
	levels[5].levelStats.bmPower = 20;
	levels[5].levelStats.bpResist = 22;
	levels[5].levelStats.bmResist = 26;
}