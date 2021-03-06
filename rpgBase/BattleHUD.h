#pragma once
#include "ElementMenuVSwitch.h"
#include "ElementMessageBox.h"
#include "ElementMenuHSelect.h"
#include "ElementMenuVSelect.h"
#include "ElementBar.h"
#include "Enemy.h"

class BattleHUD
{
public:
	void setEnemy(Enemy* nEnemy);
	BattleHUD(GameCore* nGameCore, Player* nPlayer);
	void draw();
	CharacterAction* proceedInput(const SDL_Event& e);
	void open();
	void close();
	void pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);

	bool *messageBoxOpened;

	ElementMessageBox* messageBox;

private:
	GameCore* gameCore;
	Player* player;

	enum BaseState {OPENED, CLOSED} baseState;
	enum State {MAINMENU, SKILLS, INVENTORY} state;

	ElementMenuHSelect* mainMenu;
	ElementMenuVSelect* skills;
	ElementMenuVSelect* inventory;

	Enemy* enemy;

	ElementBar* playerHpBar;
	ElementBar* playerMpBar;

	ElementBar* enemyHpBar;
	ElementBar* enemyMpBar;
};

