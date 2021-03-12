#pragma once
#include "GameCore.h"
#include "ElementMessageBox.h"
#include "ELementMenuVSwitch.h"
#include "ElementInventoryMenu.h"
#include "ElementSkillsMenu.h"
#include "ElementChestMenu.h"
#include "ElementStoreMenu.h"
#include "Chest.h"

class LevelHUD
{
public:
	LevelHUD(GameCore* nGameCore, Player* nPlayer);
	void draw();
	bool proceedInput(const SDL_Event &e); //true if closing
	bool open(); //true if opening
	bool open(Chest* chest);
	bool open(vector<StoreItem> *store, const string& storeName);
	void pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);
	void pushQuestionMultiselect(vector<string>* options, int** nTarget);

	bool* messageBoxOpened;

private:
	GameCore* gameCore;
	Player* player;
	enum BaseState {OPENED, CLOSED} baseState;
	enum State {MAINMENU, PLAYERDATA, INVENTORY, SKILLS, CHEST, STORE} state;

	Vector2 titlePos;

	ElementMessageBox* messageBox;

	ElementMenuVSwitch* mainMenu;

	TextMultiline* playerData;

	ElementInventoryMenu* inventoryMenu;
	ElementSkillsMenu* skillsMenu;

	ElementChestMenu* chestMenu;
	ElementStoreMenu* storeMenu;
};