#include "ElementChestMenu.h"

ElementChestMenu::ElementChestMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox)
{
	gameCore = nGameCore;
	player = nPlayer;
	chest = NULL;
	messageBox = nMessageBox;

	pInv = NULL;
	cInv = NULL;

	state = PLAYER;
}

void ElementChestMenu::openChest(Chest* nChest)
{
	chest = nChest;
	reset();
	pInv->reset();
	cInv->reset();
}

void ElementChestMenu::reset()
{
	int tgl = 0;

	if (pInv != NULL)
	{
		tgl = pInv->toggle;
		delete pInv;
	}
	std::vector<string>* options = new std::vector<string>;
	for (int i = 0; i < player->inventory.size(); i++)
	{
		options->push_back(player->inventory[i]->shortName);
	}
	pInv = new ElementMenuVSwitch(gameCore, options, { 25, 97 }, 2, 1, 17, 25, 6, 2);
	pInv->reset(tgl);

	if (cInv != NULL)
	{
		tgl = cInv->toggle;
		delete cInv;
	}
	options = new std::vector<string>;
	for (int i = 0; i < chest->inventory.size(); i++)
	{
		options->push_back(chest->inventory[i]->shortName);
	}
	cInv = new ElementMenuVSwitch(gameCore, options, { 345, 97 }, 2, 1, 17, 25, 6, 2);
	cInv->reset(tgl);

}

bool ElementChestMenu::inputBack()
{
	return false;
}

void ElementChestMenu::inputUp()
{
	if (state == PLAYER)
		pInv->inputUp();
	else
		cInv->inputUp();
}

void ElementChestMenu::inputDown()
{
	if (state == PLAYER)
		pInv->inputDown();
	else
		cInv->inputDown();
}

void ElementChestMenu::inputLeft()
{
	state = PLAYER;
}

void ElementChestMenu::inputRight()
{
	state = CHEST;
}

bool ElementChestMenu::inputEnter()
{
	if (state == PLAYER)
	{
		int id = pInv->inputEnter();
		if (id == -1)
			return true;
		chest->inventory.push_back(player->inventory[id]);
		player->inventory.erase(player->inventory.begin() + id);
	}
	else
	{
		int id = cInv->inputEnter();
		if (id == -1)
			return true;
		player->inventory.push_back(chest->inventory[id]);
		chest->inventory.erase(chest->inventory.begin() + id);
	}

	reset();

	return true;
}

void ElementChestMenu::draw()
{
	//Main windows
	gameCore->drawDarkWindow(Vector2(15, 80), Vector2(274, 170));
	gameCore->drawDarkWindow(Vector2(335, 80), Vector2(274, 170));

	//Inventories
	pInv->draw();
	cInv->draw();

	//Player title
	gameCore->drawDarkWindow(Vector2(15, 50), Vector2(100, 20));
	if (state == PLAYER)
		gameCore->quickDrawText(player->name.c_str(), Vector2(73, 68), 8, GameCore::VCENTER, GameCore::HCENTER);
	else
		gameCore->quickDrawText(player->name.c_str(), Vector2(73, 68), 7, GameCore::VCENTER, GameCore::HCENTER);

	//Chest title
	gameCore->drawDarkWindow(Vector2(509, 50), Vector2(100, 20));
	if (state == CHEST)
		gameCore->quickDrawText("Chest", Vector2(567, 68), 8, GameCore::VCENTER, GameCore::HCENTER);
	else
		gameCore->quickDrawText("Chest", Vector2(567, 68), 7, GameCore::VCENTER, GameCore::HCENTER);
}