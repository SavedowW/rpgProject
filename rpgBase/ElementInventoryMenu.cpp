#include "ElementInventoryMenu.h"
#include "MessageHandler.h"

ElementInventoryMenu::ElementInventoryMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox)
{
	gameCore = nGameCore;
	player = nPlayer;
	messageBox = nMessageBox;
	inventory = NULL;

	std::vector<string>* options = new std::vector<string>{ "Use", "Info", "Drop" };
	menu = new ElementMenuVSwitch(gameCore, options, {245, 97}, 2, 1, 17, 25, 4, 4);
}

void ElementInventoryMenu::reset()
{
	int tgl = 0;
	if (inventory != NULL)
	{
		tgl = inventory->toggle;
		delete inventory;
	}
	std::vector<string>* options = new std::vector<string>;
	for (int i = 0; i < player->inventory.size(); i++)
	{
		options->push_back(player->inventory[i]->shortName);
	}
	inventory = new ElementMenuVSwitch(gameCore, options, { 25, 97 }, 2, 1, 17, 25, 6, 2);
	inventory->reset(tgl);
	state = INVENTORY;
}

bool ElementInventoryMenu::inputBack()
{
	if (state == INVENTORY)
		return false;

	else
	{
		state = State(state - 1);
		if (state == MENU)
		{
			delete currentInfo;
			currentInfo = NULL;
		}
	}
}

void ElementInventoryMenu::inputUp()
{
	if (state == INVENTORY)
		inventory->inputUp();
	else if (state == MENU)
		menu->inputUp();
	else if (state == INFO)
		currentInfo->inputUp();
}

void ElementInventoryMenu::inputDown()
{
	if (state == INVENTORY)
		inventory->inputDown();
	else if (state == MENU)
		menu->inputDown();
	else if (state == INFO)
		currentInfo->inputDown();
}

bool ElementInventoryMenu::inputEnter()
{
	if (state == INVENTORY)
	{
		state = MENU;
		menu->reset();
		return true;
	}

	if (state == MENU)
	{
		int id = menu->inputEnter();

		//USE
		if (id == 0)
		{
			int selected = inventory->inputEnter();
			Item* selectedItem = player->inventory[selected];
			string name = selectedItem->name;
			int result = player->useItem(selected);

			MessageHandler::itemMessage(result, selectedItem, name, selected, messageBox, player);

			reset();
		}

		//INFO
		if (id == 1)
		{
			state = INFO;

			std::vector<string>* infoLines = new std::vector<string>;

			Item* item = player->inventory[inventory->inputEnter()];

			infoLines->push_back("=== ITEM INFO ===");
			infoLines->push_back(item->name);
			infoLines->push_back("Price: " + gameCore->intToString(item->price));
			switch (item->rarity)
			{
			case (Item::COMMON):
				infoLines->push_back("Rarity: common");
				break;

			case (Item::RARE):
				infoLines->push_back("Rarity: rare");
				break;

			case (Item::UNIQUE):
				infoLines->push_back("Rarity: unique");
				break;

			case (Item::LEGENDARY):
				infoLines->push_back("Rarity: legendary");
				break;
			}
			switch (item->type)
			{
			case (Item::OTHER):
				infoLines->push_back("Type: other");
				break;

			case (Item::WEAPON):
				infoLines->push_back("Type: weapon");
				infoLines->push_back("");
				infoLines->push_back("=== WEAPON STATS ===");
				infoLines->push_back("Physical damage: " + gameCore->intToString(((ItemWeapon*)item)->stats.pDamage));
				infoLines->push_back("Magical damage: " + gameCore->intToString(((ItemWeapon*)item)->stats.mDamage));
				infoLines->push_back("Physical resist: " + gameCore->intToString(((ItemWeapon*)item)->stats.pResist));
				infoLines->push_back("Parry chance: " + gameCore->intToString(((ItemWeapon*)item)->stats.mainParry));
				infoLines->push_back("Parry in block chance: " + gameCore->intToString(((ItemWeapon*)item)->stats.blockParry));
				break;

			case (Item::ARMOR):
				infoLines->push_back("Type: armor");
				infoLines->push_back("");
				infoLines->push_back("=== ARMOR STATS ===");
				infoLines->push_back("Physical resist: " + gameCore->intToString(((ItemArmor*)item)->stats.pResist));
				infoLines->push_back("Magical resist: " + gameCore->intToString(((ItemArmor*)item)->stats.mResist));
				break;

			case (Item::BUFFER):
				infoLines->push_back("Type: buffer");
				infoLines->push_back("");
				infoLines->push_back("=== BUFFER STATS ===");
				for (int i = 0; i < ((ItemBuffer*)item)->effects.size(); i++)
				{
					switch (((ItemBuffer*)item)->effects[i].effect)
					{
					case (Buff::INSTANT_HP_RESTORE):
						infoLines->push_back("Instant HP restore: " + gameCore->floatToString(((ItemBuffer*)item)->effects[i].value, 5));
						break;
					case (Buff::INSTANT_MP_RESTORE):
						infoLines->push_back("Instant MP restore: " + gameCore->floatToString(((ItemBuffer*)item)->effects[i].value, 5));
						break;
					}
				}
				break;
			}

			infoLines->push_back("");
			infoLines->insert(infoLines->end(), item->description.begin(), item->description.end());

			currentInfo = new TextMultiline(gameCore, infoLines, 6, 23, 7);
		}

		//DROP
		if (id == 2)
		{
			string name = player->inventory[inventory->inputEnter()]->name;
			int result = player->removeItem(inventory->inputEnter());

			if (result == 0)
				messageBox->pushMessages(
					{
							{name + " does not exist anymore."}
					}, 5, 5, 10, 0
				);

			reset();
		}
		return true;
	}
}

void ElementInventoryMenu::draw()
{
	gameCore->drawDarkWindow(Vector2(10, 80), Vector2(200, 170));
	inventory->draw();

	if (state >= MENU)
	{
		gameCore->drawDarkWindow(Vector2(230, 110), Vector2(65, 110));
		menu->draw();
	}

	if (state >= INFO)
	{
		gameCore->drawDarkWindow(Vector2(315, 80), Vector2(300, 170));
		currentInfo->draw(Vector2{330, 90});
	}
}