#pragma once
#include "GameCore.h"
#include "Player.h"
#include "ElementMessageBox.h"
#include "ElementMenuVSwitch.h"
#include "TextMultiline.h"

class ElementStoreMenu
{
public:
	ElementStoreMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox);
	void openStore(vector<StoreItem>* nStore, const string& name);

	void reset();
	bool inputBack();
	void inputUp();
	void inputDown();
	void inputLeft();
	void inputRight();
	bool inputEnter();
	void draw();

private:
	GameCore* gameCore;
	Player* player;
	vector<StoreItem>* store;
	ElementMessageBox* messageBox;

	ElementMenuVSelect* pPrices;
	ElementMenuVSelect* pInv;

	ElementMenuVSelect* sPrices;
	ElementMenuVSelect* sInv;
	ElementMenuVSelect* sAmount;

	string storeName;
	enum State { PLAYER, STORE } state;
};