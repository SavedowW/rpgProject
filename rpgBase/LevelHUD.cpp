#include "LevelHUD.h"

LevelHUD::LevelHUD(GameCore* nGameCore, Player* nPlayer)
{
	gameCore = nGameCore;
	player = nPlayer;

	baseState = CLOSED;
	state = MAINMENU;

	titlePos = {320, 51};

	messageBox = new ElementMessageBox(gameCore, { 30.0f, 270.0f },
		{gameCore->loadSfx("SFX/voices/voice_system.wav", 60),
		gameCore->loadSfx("SFX/voices/voice_main.wav", 60)});

	messageBoxOpened = &messageBox->enabled;

	std::vector<string>* lines = new std::vector<string>;
	*lines = { "Player Data",
		"Inventory",
		"Skills"
	};
	mainMenu = new ElementMenuVSwitch(gameCore, lines, {40, 120}, 4, 3, 20, 25, 3, 2);

	inventoryMenu = new ElementInventoryMenu(gameCore, player, messageBox);
	skillsMenu = new ElementSkillsMenu(gameCore, player, messageBox);
	chestMenu = new ElementChestMenu(gameCore, player, messageBox);

	playerData = NULL;

	currentChest = NULL;
}

void LevelHUD::draw()
{
	gameCore->setRenderMode(GameCore::RM_HUD);


	if (baseState != CLOSED)
	{
		gameCore->drawDarkWindow(Vector2(203, 26), Vector2(210, 34));

		if (state == MAINMENU)
		{
			gameCore->quickDrawText("MAIN MENU", titlePos, 0, GameCore::VCENTER, GameCore::HCENTER);
			gameCore->drawDarkWindow(Vector2(20, 100), Vector2(200, 120));
			mainMenu->draw();
		}
		else if (state == PLAYERDATA)
		{
			gameCore->quickDrawText("PLAYER DATA", titlePos, 0, GameCore::VCENTER, GameCore::HCENTER);
			gameCore->drawDarkWindow(Vector2(20, 100), Vector2(200, 120));
			mainMenu->draw();
			gameCore->drawDarkWindow(Vector2(240, 80), Vector2(300, 170));
			playerData->draw(Vector2(260, 90));
		}
		else if (state == INVENTORY)
		{
			gameCore->quickDrawText("INVENTORY", titlePos, 0, GameCore::VCENTER, GameCore::HCENTER);
			inventoryMenu->draw();
		}
		else if (state == SKILLS)
		{
			gameCore->quickDrawText("SKILLS", titlePos, 0, GameCore::VCENTER, GameCore::HCENTER);
			skillsMenu->draw();
		}
		else if (state == CHEST)
		{
			gameCore->quickDrawText("CHEST", titlePos, 0, GameCore::VCENTER, GameCore::HCENTER);
			chestMenu->draw();
		}
	}

	messageBox->draw();
	//cout << state << endl;
}

bool LevelHUD::proceedInput(const SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (messageBox->enabled)
		{
			if (e.key.keysym.sym == SDLK_z)
				messageBox->inputEnter();
			if (e.key.keysym.sym == SDLK_UP)
				messageBox->inputUp();
			if (e.key.keysym.sym == SDLK_DOWN)
				messageBox->inputDown();
			if (!messageBox->enabled && baseState == CLOSED)
				return true;
			else
				return false;
		}
		if (e.key.keysym.sym == SDLK_c || e.key.keysym.sym == SDLK_x)
		{
			baseState = CLOSED;
			return true;
		}
	}
	if (state == MAINMENU)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_DOWN)
				mainMenu->inputDown();
			else if (e.key.keysym.sym == SDLK_UP)
				mainMenu->inputUp();
			else if (e.key.keysym.sym == SDLK_z)
			{
				state = (State)(mainMenu->inputEnter() + 1);
				if (state == INVENTORY)
					inventoryMenu->reset();
				if (state == PLAYERDATA)
				{
					std::vector<string>* playerDataLines = new std::vector<string>;
					playerDataLines->push_back("=== PLAYER DATA ===");
					playerDataLines->push_back("Name: " + player->name);
					playerDataLines->push_back("EXP: " + gameCore->intToString(player->exp));
					playerDataLines->push_back("LVL: " + gameCore->intToString(player->lvl));
					playerDataLines->push_back("");
					playerDataLines->push_back("HP: " + gameCore->intToString(player->stats.HP) + " / " + gameCore->intToString(player->stats.maxHP));
					playerDataLines->push_back("MP: " + gameCore->intToString(player->stats.MP) + " / " + gameCore->intToString(player->stats.maxMP));
					playerDataLines->push_back("");
					playerDataLines->push_back("Base physical damage: " + gameCore->intToString(player->stats.bpDamage));
					playerDataLines->push_back("Base magical power: " + gameCore->intToString(player->stats.bmPower));
					playerDataLines->push_back("Base physical resist: " + gameCore->intToString(player->stats.bpResist));
					playerDataLines->push_back("Base magical resist: " + gameCore->intToString(player->stats.bmResist));
					playerDataLines->push_back("");
					playerDataLines->push_back("Weapon: ");
					playerDataLines->push_back(player->weapon->shortName + " (" + gameCore->intToString(player->weapon->stats.pDamage) + ", " + gameCore->intToString(player->weapon->stats.mDamage) + ")");
					playerDataLines->push_back("Armor: ");
					playerDataLines->push_back(player->armor->shortName + " (" + gameCore->intToString(player->armor->stats.pResist) + ", " + gameCore->intToString(player->armor->stats.mResist) + ")");
					playerData = new TextMultiline(gameCore, playerDataLines, 6, 23, 7);
				}
				if (state == SKILLS)
					skillsMenu->reset();
			}
		}
	}
	else if (state == INVENTORY)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_DOWN)
				inventoryMenu->inputDown();
			else if (e.key.keysym.sym == SDLK_UP)
				inventoryMenu->inputUp();
			else if (e.key.keysym.sym == SDLK_z)
			{
				if (!inventoryMenu->inputEnter())
				{
					state = MAINMENU;
				}
			}
			else if (e.key.keysym.sym == SDLK_x)
			{
				if (!inventoryMenu->inputBack())
				{
					state = MAINMENU;
				}
			}
		}
	}
	else if (state == PLAYERDATA)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_x)
			{
				delete playerData;
				state = MAINMENU;
			}
			else if (e.key.keysym.sym == SDLK_DOWN)
				playerData->inputDown();
			else if (e.key.keysym.sym == SDLK_UP)
				playerData->inputUp();
		}
	}
	else if (state == SKILLS)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_DOWN)
				skillsMenu->inputDown();
			else if (e.key.keysym.sym == SDLK_UP)
				skillsMenu->inputUp();
			else if (e.key.keysym.sym == SDLK_z)
			{
				if (!skillsMenu->inputEnter())
				{
					state = MAINMENU;
				}
			}
			else if (e.key.keysym.sym == SDLK_x)
			{
				if (!skillsMenu->inputBack())
				{
					state = MAINMENU;
				}
			}
		}
	}
	else if (state == CHEST)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_DOWN)
				chestMenu->inputDown();
			else if (e.key.keysym.sym == SDLK_UP)
				chestMenu->inputUp();
			if (e.key.keysym.sym == SDLK_LEFT)
				chestMenu->inputLeft();
			else if (e.key.keysym.sym == SDLK_RIGHT)
				chestMenu->inputRight();
			else if (e.key.keysym.sym == SDLK_z)
			{
				if (!chestMenu->inputEnter())
				{
					state = MAINMENU;
				}
			}
			else if (e.key.keysym.sym == SDLK_x)
			{
				if (!chestMenu->inputBack())
				{
					baseState = CLOSED;
					return true;
				}
			}
		}
	}
	return false;
}

bool LevelHUD::open()
{
	baseState = OPENED;
	state = MAINMENU;

	mainMenu->reset();

	return true;
}

bool LevelHUD::open(Chest* chest)
{
	baseState = OPENED;
	state = CHEST;
	currentChest = chest;

	chestMenu->openChest(chest);

	return true;
}

void LevelHUD::pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId)
{
	messageBox->pushMessages(multilines, font, nPeriod, nLinePeriod, voiceId);
}

void LevelHUD::pushQuestionMultiselect(vector<string>* options, int** nTarget)
{
	messageBox->pushQuestionMultiselect(options, nTarget);
}
