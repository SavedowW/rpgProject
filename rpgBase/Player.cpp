#include "Player.h"

int getLimitedInput(int lowerEdge, int higherEdge);


Player::Player(const Vector2& nPos) :
	Object(nPos)
{
	name = "Altrei";

	maxHP = 100;
	maxMP = 30;
	HP = maxHP;
	MP = maxMP;

	bpDamage = 30;
	bmPower = 10;
	bpResist = 15;
	bmResist = 20;

	block = false;

	exp = 1;
	lvl = 1;

	spells.push_back(SkillFactory::BuildSkill(SkillFactory::SKILL_HEAL));
	spells.push_back(new Spell(
		"Firestorm",
		{ {Buff::INSTANT_MAGICAL_DAMAGE, 50, Buff::ENEMY} }, 15,
		{ {"A merciless fire absorbs everything around you.", "There is no way to dodge this spell." } },
		{"A complicated spell that",
		"summons a firestorm. Yes,",
		"it's a summon spell, not a",
		"manifestation one. Hell is",
		"full of this storms so no",
		"one would notice this loss...",
		"And they don't even care about",
		"it."})
	);
	spells.push_back(new Spell(
		"Vampire's bite",
		{ {Buff::INSTANT_PHYSICAL_DAMAGE, 20, Buff::ENEMY}, {Buff::INSTANT_HP_RESTORE, 5, Buff::SELF} }, 3,
		{ {"You're quickly jump to the enemy", "and put your fangs into his neck." } },
		{"A legacy of your vampire roots.",
		"It's a basic skill, avaible",
		"for all vampires."})
	);
	spells.push_back(new Spell(
		"Ultima",
		{ {Buff::OT_CURSE, 10, Buff::ENEMY, 3}, {Buff::OT_HPREGEN, 10, Buff::SELF, 4} }, 10,
		{ {"Broken spell activated" } },
		{ "Not required." })
	);
	spells.push_back(new Spell(
		"Soul protection",
		{ {Buff::OT_SOULPROTECTION, 1, Buff::SELF, 2} }, 10,
		{ {"Blessed spell activated" } },
		{ "Not required." })
	);

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

int Player::gainExp(int nExp)
{
	if (exp < 10 && exp + nExp >= 10 ||
		exp < 20 && exp + nExp >= 20)
	{
		exp += nExp;
		++lvl;
		return lvl;
	}
	else
	{
		exp += nExp;
		return 0;
	}
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