#pragma once
#include "GameCore.h"
#include "Player.h"
#include "ElementMessageBox.h"
#include "ElementMenuVSwitch.h"
#include "TextMultiline.h"

class ElementSkillsMenu
{
public:
	ElementSkillsMenu(GameCore* nGameCore, Player* nPlayer, ElementMessageBox* nMessageBox);

	void reset();
	bool inputBack();
	void inputUp();
	void inputDown();
	bool inputEnter();
	void draw();

private:
	GameCore* gameCore;
	Player* player;
	ElementMessageBox* messageBox;

	ElementMenuVSwitch* skills;

	TextMultiline* currentInfo;

	enum State { SKILLS, INFO } state;
};