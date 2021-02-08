#include "ElementSkillsMenu.h"

ElementSkillsMenu::ElementSkillsMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox)
{
	gameCore = nGameCore;
	player = nPlayer;
	messageBox = nMessageBox;
	skills = NULL;
	currentInfo = NULL;
}

void ElementSkillsMenu::reset()
{
	int tgl = 0;
	if (skills != NULL)
	{
		tgl = skills->toggle;
		delete skills;
	}
	std::vector<string>* options = new std::vector<string>;
	for (int i = 0; i < player->spells.size(); i++)
	{
		options->push_back(player->spells[i]->name);
	}
	skills = new ElementMenuVSwitch(gameCore, options, { 25, 97 }, 2, 1, 17, 25, 6, 2);
	skills->reset(tgl);
	if (currentInfo != NULL)
	{
		delete currentInfo;
		currentInfo = NULL;
	}
	state = SKILLS;
}

bool ElementSkillsMenu::inputBack()
{
	if (state == SKILLS)
		return false;

	else
	{
		delete currentInfo;
		currentInfo = NULL;
		state = SKILLS;
	}
}

void ElementSkillsMenu::inputUp()
{
	if (state == SKILLS)
		skills->inputUp();
	else if (state == INFO)
		currentInfo->inputUp();
}

void ElementSkillsMenu::inputDown()
{
	if (state == SKILLS)
		skills->inputDown();
	else if (state == INFO)
		currentInfo->inputDown();
}

bool ElementSkillsMenu::inputEnter()
{
	if (state == SKILLS)
	{
		state = INFO;

		std::vector<string>* infoLines = new std::vector<string>;
		Spell* spell = player->spells[skills->inputEnter()];

		infoLines->push_back("=== SKILL INFO ===");
		infoLines->push_back(spell->name);
		infoLines->push_back("Cost: " + gameCore->intToString(spell->cost));
		for (int i = 0; i < spell->effects.size(); i++)
		{
			switch (spell->effects[i].effect)
			{
			case (Buff::INSTANT_HP_RESTORE):
				infoLines->push_back("Instant HP restore: " + gameCore->floatToString(spell->effects[i].value, 5));
				break;
			case (Buff::INSTANT_MP_RESTORE):
				infoLines->push_back("Instant MP restore: " + gameCore->floatToString(spell->effects[i].value, 5));
				break;
			case (Buff::INSTANT_MAGICAL_DAMAGE):
				infoLines->push_back("Instant magical damage: " + gameCore->floatToString(spell->effects[i].value, 5));
				break;
			case (Buff::INSTANT_PHYSICAL_DAMAGE):
				infoLines->push_back("Instant physical damage: " + gameCore->floatToString(spell->effects[i].value, 5));
				break;
			}
		}

		infoLines->push_back("");
		infoLines->insert(infoLines->end(), spell->description.begin(), spell->description.end());

		currentInfo = new TextMultiline(gameCore, infoLines, 6, 23, 7);

		return true;
	}
}

void ElementSkillsMenu::draw()
{
	gameCore->drawDarkWindow(Vector2(10, 80), Vector2(220, 170));
	skills->draw();

	if (state == INFO)
	{
		gameCore->drawDarkWindow(Vector2(250, 80), Vector2(360, 170));
		currentInfo->draw(Vector2(270, 90));
	}
}