#pragma once
#include "ElementMenuVSwitch.h"
#include "ElementBattleMessageBox.h"
#include "ElementMenuHSelect.h"
#include "ElementMenuVSelect.h"

class BattleHUD
{
public:
	BattleHUD(GameCore* nGameCore, Player* nPlayer);
	void draw();
	CharacterAction* proceedInput(const SDL_Event& e);
	void open();
	void close();
	void pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);

	bool *messageBoxOpened;

	ElementBattleMessageBox* messageBox;

private:
	GameCore* gameCore;
	Player* player;
	enum BaseState {OPENED, CLOSED} baseState;
	enum State {MAINMENU, SKILLS, INVENTORY} state;

	ElementMenuHSelect* mainMenu;
	ElementMenuVSelect* skills;
	ElementMenuVSelect* inventory;

};

