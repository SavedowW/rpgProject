#pragma once
#include "GameCore.h"
#include "Player.h"
#include "ElementMessageBox.h"
#include "ElementMenuVSwitch.h"
#include "TextMultiline.h"
#include "Chest.h"

class ElementChestMenu
{
public:
	ElementChestMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox);
	void openChest(Chest* nChest);

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
	Chest* chest;
	ElementMessageBox* messageBox;

	ElementMenuVSwitch* pInv;
	ElementMenuVSwitch* cInv;

	enum State { PLAYER, CHEST } state;
};