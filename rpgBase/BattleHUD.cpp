#include "BattleHUD.h"

BattleHUD::BattleHUD(GameCore* nGameCore, Player* nPlayer)
{
	player = nPlayer;
	gameCore = nGameCore;

	baseState = CLOSED;
	state = MAINMENU;

	messageBox = new ElementBattleMessageBox(gameCore, { 30.0f, 270.0f },
		{ gameCore->loadSfx("SFX/voices/voice_system.wav", 60)});

	messageBoxOpened = &messageBox->enabled;

	vector<string>* options = new vector<string>{
		"ATTACK",
		"SKILL",
		"ITEM",
		"DEFEND"
	};
	mainMenu = new ElementMenuHSelect(gameCore, options, {108, 337}, 11, 10, 130, 4);

}

void BattleHUD::draw()
{
	gameCore->setRenderMode(GameCore::RM_HUD);

	if (baseState == OPENED)
	{
		if (state == MAINMENU)
		{
			gameCore->drawDarkWindow({ 30, 322 }, { 564, 14 });
			mainMenu->draw();
		}

		if (state == SKILLS)
		{
			gameCore->drawDarkWindow({ 30, 280 }, { 564, 54 });
			skills->draw();
		}

		if (state == INVENTORY)
		{
			gameCore->drawDarkWindow({ 30, 280 }, { 564, 54 });
			inventory->draw();
		}
	}

	messageBox->draw();
}

CharacterAction* BattleHUD::proceedInput(const SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (messageBox->enabled)
		{
			if (e.key.keysym.sym == SDLK_z)
				messageBox->input();
			return new CharacterAction();
		}
	}

	if (baseState == CLOSED)
		return new CharacterAction();

	if (state == MAINMENU)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_LEFT)
				mainMenu->inputLeft();
			if (e.key.keysym.sym == SDLK_RIGHT)
				mainMenu->inputRight();
			if (e.key.keysym.sym == SDLK_z)
			{
				int id = mainMenu->inputEnter();
				vector<string>* options;
				switch (id)
				{
					//Attack
				case (0):
					close();
					cout << "Attack\n";
					return new CharacterAction(CharacterAction::ATTACK);
					break;

					//Skill
				case (1):
					state = SKILLS;
					options = new vector<string>;
					for (int i = 0; i < player->spells.size(); ++i)
					{
						options->push_back(player->spells[i]->name);
					}
					skills = new ElementMenuVSelect(gameCore, options, {40, 287}, 11, 10, 20, 3);
					return new CharacterAction();
					break;

					//Item
				case (2):
					state = INVENTORY;
					options = new vector<string>;
					for (int i = 0; i < player->inventory.size(); ++i)
					{
						options->push_back(player->inventory[i]->shortName);
					}
					inventory = new ElementMenuVSelect(gameCore, options, { 40, 287 }, 11, 10, 20, 3);
					return new CharacterAction();
					break;

					//Defend
				case (3):
					close();
					cout << "Defend\n";
					return new CharacterAction(CharacterAction::DEFEND);
					break;
				}
			}
		}
	}

	if (state == SKILLS)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_UP)
				skills->inputUp();
			if (e.key.keysym.sym == SDLK_DOWN)
				skills->inputDown();
			if (e.key.keysym.sym == SDLK_z)
			{
				CharacterAction* chAct = new CharacterAction(CharacterAction::SKILL, skills->inputEnter());
				close();
				return chAct;
			}
			if (e.key.keysym.sym == SDLK_x)
			{
				state = MAINMENU;
				delete skills;
				skills = NULL;
			}
		}
	}

	if (state == INVENTORY)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_UP)
				inventory->inputUp();
			if (e.key.keysym.sym == SDLK_DOWN)
				inventory->inputDown();
			if (e.key.keysym.sym == SDLK_z)
			{
				CharacterAction* chAct = new CharacterAction(CharacterAction::ITEM, inventory->inputEnter());
				close();
				return chAct;
			}
			if (e.key.keysym.sym == SDLK_x)
			{
				state = MAINMENU;
				delete inventory;
				inventory = NULL;
			}
		}
	}

	return new CharacterAction();
}

void BattleHUD::open()
{
	baseState = OPENED;
	state = MAINMENU;
}

void BattleHUD::close()
{
	if (state == SKILLS && skills != NULL)
	{
		delete skills;
	}

	if (state == INVENTORY && inventory != NULL)
	{
		delete inventory;
	}

	baseState = CLOSED;
}

void BattleHUD::pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId)
{
	messageBox->pushMessages(multilines, font, nPeriod, nLinePeriod, voiceId);
}