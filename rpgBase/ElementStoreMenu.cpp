#include "ElementStoreMenu.h"

ElementStoreMenu::ElementStoreMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox)
{
	gameCore = nGameCore;
	player = nPlayer;
	store = NULL;
	messageBox = nMessageBox;

	pPrices = NULL;
	pInv = NULL;

	sPrices = NULL;
	sInv = NULL;
	sAmount = NULL;

	state = PLAYER;
}

void ElementStoreMenu::openStore(vector<StoreItem>* nStore, const string& name)
{
	store = nStore;
	storeName = name;
	reset();

	pPrices->reset();
	pInv->reset();

	sPrices->reset();
	sInv->reset();
	sAmount->reset();
}

void ElementStoreMenu::reset()
{
	int tgl = 0;
	int menuSize = 8;

	//pPrices
	if (pPrices != NULL)
	{
		tgl = pPrices->toggle;
		delete pPrices;
	}
	std::vector<string>* options = new std::vector<string>;
	for (int i = 0; i < player->inventory.size(); i++)
	{
		options->push_back(gameCore->intToString(player->inventory[i]->priceToSell));
	}
	pPrices = new ElementMenuVSelect(gameCore, options, { 20, 97 }, 11, 10, 20, menuSize, GameCore::TOP, GameCore::LEFT);
	pPrices->reset(tgl);

	//pInv
	if (pInv != NULL)
	{
		tgl = pInv->toggle;
		delete pInv;
	}
	options = new std::vector<string>;
	for (int i = 0; i < player->inventory.size(); i++)
	{
		options->push_back(player->inventory[i]->shortName);
	}
	pInv = new ElementMenuVSelect(gameCore, options, { 60, 97 }, 11, 10, 20, menuSize, GameCore::TOP, GameCore::LEFT);
	pInv->reset(tgl);

	//sPrices
	if (sPrices != NULL)
	{
		tgl = sPrices->toggle;
		delete sPrices;
	}
	options = new std::vector<string>;
	for (int i = 0; i < store->size(); i++)
	{
		options->push_back(gameCore->intToString(getItemPrice((*store)[i].itemId)));
	}
	sPrices = new ElementMenuVSelect(gameCore, options, { 340, 97 }, 11, 10, 20, menuSize, GameCore::TOP, GameCore::LEFT);
	sPrices->reset(tgl);

	//sInv
	if (sInv != NULL)
	{
		tgl = sInv->toggle;
		delete sInv;
	}
	options = new std::vector<string>;
	for (int i = 0; i < store->size(); i++)
	{
		options->push_back(getItemShortName((*store)[i].itemId));
	}
	sInv = new ElementMenuVSelect(gameCore, options, { 380, 97 }, 11, 10, 20, menuSize, GameCore::TOP, GameCore::LEFT);
	sInv->reset(tgl);

	//sAmount
	if (sAmount != NULL)
	{
		tgl = sAmount->toggle;
		delete sAmount;
	}
	options = new std::vector<string>;
	for (int i = 0; i < store->size(); i++)
	{
		if ((*store)[i].amount > 0)
			options->push_back(gameCore->intToString((*store)[i].amount));
		else if ((*store)[i].amount == 0)
			options->push_back("SOLD OUT");
		else if ((*store)[i].amount < 0)
			options->push_back("UNLIMITED");
	}
	sAmount = new ElementMenuVSelect(gameCore, options, { 620, 97 }, 11, 10, 20, menuSize, GameCore::TOP, GameCore::RIGHT);
	sAmount->reset(tgl);
}

bool ElementStoreMenu::inputBack()
{
	return false;
}

void ElementStoreMenu::inputUp()
{
	if (state == PLAYER)
	{
		pPrices->inputUp();
		pInv->inputUp();
	}
	else
	{
		sAmount->inputUp();
		sPrices->inputUp();
		sInv->inputUp();
	}
}

void ElementStoreMenu::inputDown()
{
	if (state == PLAYER)
	{
		pPrices->inputDown();
		pInv->inputDown();
	}
	else
	{
		sAmount->inputDown();
		sPrices->inputDown();
		sInv->inputDown();
	}
}

void ElementStoreMenu::inputLeft()
{
	state = PLAYER;
}

void ElementStoreMenu::inputRight()
{
	state = STORE;
}

bool ElementStoreMenu::inputEnter()
{
	if (state == PLAYER)
	{
		int id = pInv->inputEnter();
		if (id == -1)
			return true;
		player->addMoney(player->inventory[id]->priceToSell);
		player->removeItem(id);
	}

	else if (state == STORE)
	{
		int id = sInv->inputEnter();
		if (id == -1)
			return true;
		int price = getItemPrice((*store)[id].itemId);
		if (player->money >= price && (*store)[id].amount != 0)
		{
			player->addMoney(-price);
			player->inventory.push_back(BuildItem((*store)[id].itemId));
			(*store)[id].decrease();
		}
	}

	reset();

	return true;
}

void ElementStoreMenu::draw()
{
	//Main windows
	gameCore->drawDarkWindow(Vector2(15, 80), Vector2(274, 170));
	gameCore->drawDarkWindow(Vector2(335, 80), Vector2(274, 170));

	//Inventories
	pInv->draw();
	pPrices->draw();
	sAmount->draw();
	sInv->draw();
	sPrices->draw();

	//Player title
	gameCore->drawDarkWindow(Vector2(15, 50), Vector2(100, 20));
	if (state == PLAYER)
		gameCore->quickDrawText(player->name.c_str(), Vector2(73, 68), 8, GameCore::VCENTER, GameCore::HCENTER);
	else
		gameCore->quickDrawText(player->name.c_str(), Vector2(73, 68), 7, GameCore::VCENTER, GameCore::HCENTER);
	gameCore->drawDarkWindow(Vector2(135, 50), Vector2(50, 20));
	gameCore->quickDrawText(gameCore->intToString(player->money).c_str(), Vector2(168, 68), 7, GameCore::VCENTER, GameCore::HCENTER);

	//Store title
	gameCore->drawDarkWindow(Vector2(509, 50), Vector2(100, 20));
	if (state == STORE)
		gameCore->quickDrawText(storeName.c_str(), Vector2(567, 68), 8, GameCore::VCENTER, GameCore::HCENTER);
	else
		gameCore->quickDrawText(storeName.c_str(), Vector2(567, 68), 7, GameCore::VCENTER, GameCore::HCENTER);
}