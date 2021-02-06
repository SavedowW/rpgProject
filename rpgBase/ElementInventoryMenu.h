#pragma once
#include "GameCore.h"
#include "Player.h"
#include "ElementMessageBox.h"
#include "ElementMenuVSwitch.h"
#include "TextMultiline.h"

class ElementInventoryMenu
{
public:
	ElementInventoryMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox *nMessageBox);

	void reset();
	bool inputBack();
	void inputUp();
	void inputDown();
	bool inputEnter();
	void draw();

private:
	GameCore* gameCore;
	Player* player;
	ElementMessageBox *messageBox;

	ElementMenuVSwitch* inventory;
	ElementMenuVSwitch* menu;

	TextMultiline* currentInfo;

	enum State { INVENTORY, MENU, INFO } state;
};