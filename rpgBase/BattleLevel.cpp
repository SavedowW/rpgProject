#include "BattleLevel.h"
#include "MessageHandler.h"

BattleLevel::BattleLevel() :
	Level({ 640, 360 }, new Camera({ 0, 0 }, { 640, 360 }, { 640, 360 }, Camera::SET))
{
	battleHud = new BattleHUD(gameCore, player);
	backgrounds[0] = new Background1(gameCore);
}

void BattleLevel::enter(int entrance)
{
	returnVal = { -1, 0 };
	gameCore->setCam(cam);
	isRunning = true;
	inputMethod = INPUT_DEFAULT;
	state = ENTER;
	battleState = ENTERSTATE;
	currentAction = NULL;
	currentSkill = NULL;
	currentBuff = -1;
}

LevelResult BattleLevel::levelProcess()
{
	SDL_Event e;

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			processInput(e);
		}
		gameCore->resetScreen();

		//LOGIC

		handleDelayedActions();

		//Begin leaving animation
		if (state == RUN && battleState == RESULTS && !*battleHud->messageBoxOpened && actionList.size() == 0)
		{
			state = LEAVE;
		}

		if (state == RUN)
		{

			//Battle end
			if (!*battleHud->messageBoxOpened)
			{
				handleEnd();
			}

			//Beginning of the battle
			if (battleState == ENTERSTATE)
			{
				handleEnter();
			}

			//Proceeding through registered player action
			else if (battleState == PLAYERTURNRES)
			{
				//If just received from HUD
				if (currentAction != NULL)
				{
					handlePlayerAction();
				}

				//If already parsed and player did not used skill
				else
				{
					//Wait until player read and continue
					if (!*battleHud->messageBoxOpened)
					{
						currentCharEffect = -1;
						battleState = PLAYERTURNEND;
					}
				}

			}

			//If player used skill
			else if (battleState == PLAYERSKILLPARSE)
			{
				handlePlayerSkillParse();
			}

			//Player effects at the end of the turn
			else if (battleState == PLAYERTURNEND)
			{
				handlePlayerEffects();
			}

			//Enemy turn
			else if (battleState == ENEMYTURN)
			{
				getEnemyAction();
			}

			//Enemy turn results
			else if (battleState == ENEMYTURNRES)
			{
				handleEnemyAction();
			}

			//If enemy used skill
			else if (battleState == ENEMYSKILLPARSE)
			{
				handleEnemySkillParse();
			}

			//End of the enemy turn
			else if (battleState == ENEMYTURNEND)
			{
				handleEnemyEffects();
			}

		}

		//PRE-DRAWING
		cam->update({ 0, 0 });

		//DRAWING

		renderLevel();
		SDL_Delay(1000.0 / 60.0);
	}
	gameCore->deleteCam();
	return returnVal;
}

void BattleLevel::processInput(const SDL_Event& e)
{
	if (e.type == SDL_QUIT)
	{
		returnVal = { -1, 0 };
		isRunning = false;
	}

	if (inputMethod == INPUT_DEFAULT)
	{
		if (e.type == SDL_KEYDOWN && !e.key.repeat)
		{
			switch (e.key.keysym.sym)
			{
			case (SDLK_p):
				state = LEAVE;
				battleHud->close();
				break;
			}
		}

		CharacterAction* actionTemp = battleHud->proceedInput(e);

		if (battleState == PLAYERTURN)
			if (actionTemp->action != CharacterAction::NONE)
			{
				battleState = PLAYERTURNRES;
				currentAction = actionTemp;
			}
			else
				delete actionTemp;
	}
}

void BattleLevel::renderLevel()
{
	gameCore->resetScreen();

	backgrounds[0]->draw();

	battleRequest.enemy->draw();

	if (state == ENTER)
		if (gameCore->drawTransitionBattle(false))
		{
			state = RUN;
			battleHud->pushMessage(battleRequest.enemy->appearanceText(), 9, 5, 10, 0);
		}

	if (state == LEAVE)
	{
		if (gameCore->drawTransitionBattle(true))
		{
			returnVal = { battleRequest.srcLevel, -1 };
			isRunning = false;
			gameCore->resetTransition();
		}
	}

	gameCore->quickDrawText(("Player: " + gameCore->intToString(player->HP) + " / " + gameCore->intToString(player->MP)).c_str(), { 0, 0 }, 9, GameCore::TOP, GameCore::LEFT);
	gameCore->quickDrawText((battleRequest.enemy->name + ": " + gameCore->intToString(battleRequest.enemy->HP) + " / " + gameCore->intToString(battleRequest.enemy->MP)).c_str(), { 0, 20 }, 9, GameCore::TOP, GameCore::LEFT);

	battleHud->draw();
	gameCore->updateScreen();
}

void BattleLevel::handleEnd()
{
	//Loose
	if (player->HP <= 0)
	{
		battleState = RESULTS;
		returnVal = { battleRequest.srcLevel, -1 };
		battleHud->pushMessage({
					{"You lost!"}
			}, 9, 5, 10, 0);
	}

	//Win
	else if (battleRequest.enemy->HP <= 0)
	{
		battleState = RESULTS;
		returnVal = { battleRequest.srcLevel, -1 };

		int expUp = battleRequest.enemy->getExp();
		cout << expUp << endl;
		int lvlUp = player->gainExp(expUp);
		cout << lvlUp << endl;
		cout << player->exp << endl << endl;

		const vector<Item*>& droplist = battleRequest.enemy->reward();

		battleHud->pushMessage({
					{"You won!", "Gained " + gameCore->intToString(expUp) + " EXP."}
			}, 9, 5, 10, 0);

		if (lvlUp > 0)
			actionList.push_back(new ReverseFlagAction(battleHud->messageBoxOpened, [this]()
				{
					gameCore->playSfx(GameCore::SFX_HEAL);
					battleHud->pushMessage({
						{"Level up!"}
						}, 9, 5, 10, 0);
				}
			)
			);

		for (int i = 0; i < droplist.size(); i++)
		{
			battleHud->pushMessage({
					{droplist[i]->name + " added", "to your inventory. "}
				}, 9, 5, 10, 0);
		}
	}
}

void BattleLevel::handleEnter()
{
	//Wait until player read entry message
	if (!*battleHud->messageBoxOpened)
	{
		battleState = PLAYERTURN;
		battleHud->open();
		player->beginTurn();
	}
}

void BattleLevel::handlePlayerAction()
{
	//parse and delete currentAction

	//Attack action
	if (currentAction->action == CharacterAction::ATTACK)
	{
		cam->shake(10, 10, 20);
		gameCore->playSfx(GameCore::SFX_HIT1);
		int damage = battleRequest.enemy->receivePhysDamage(player->calcPhysDamage());
		if (damage > 0)
		{
			battleHud->pushMessage({
				{"You're falling your blade onto enemy."},
				{"-" + gameCore->intToString(damage) + " HP"}
				}, 9, 5, 10, 0);
		}
		else {
			battleHud->pushMessage({
				{"You're falling your blade onto enemy."},
				{"Parry! 0 HP lost"}
				}, 9, 5, 10, 0);
		}
	}

	//Skill action
	else if (currentAction->action == CharacterAction::SKILL)
	{
		currentSkill = player->spells[currentAction->id];
		if (player->MP >= currentSkill->cost)
		{
			player->MP -= currentSkill->cost;
			currentBuff = -1;
			battleState = PLAYERSKILLPARSE;
			battleHud->pushMessage(
				currentSkill->battleDescr,
				9, 5, 10, 0
			);
		}
		else
		{
			battleHud->pushMessage({
				{"Not enough MP"}
				},
				9, 5, 10, 0
			);
		}
	}

	//Item use action
	else if (currentAction->action == CharacterAction::ITEM)
	{
		int selected = currentAction->id;
		string name = player->inventory[selected]->name;
		int result = player->useItem(selected);

		MessageHandler::itemMessage(result, name, selected, battleHud->messageBox, player);
	}

	//Defend action
	else if (currentAction->action == CharacterAction::DEFEND)
	{
		player->block = true;
		battleHud->pushMessage({
			{"You're raising whatever-you-hold to protect yourself"}
			}, 9, 5, 10, 0);
	}
	delete currentAction;
	currentAction = NULL;

	if (battleState != PLAYERSKILLPARSE)
	{
		actionList.push_back(new ReverseFlagAction(battleHud->messageBoxOpened, [this]()
				{
					currentCharEffect = -1;
					battleState = PLAYERTURNEND;
				}
			)
		);
	}
}

void BattleLevel::handlePlayerSkillParse()
{
	//Get through all of the skill effects
	if (!*battleHud->messageBoxOpened)
	{
		++currentBuff;
		if (currentBuff < currentSkill->effects.size())
		{
			Buff& effect = currentSkill->effects[currentBuff];
			/*switch (effect.effect)
			{
			case (Buff::INSTANT_HP_RESTORE):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::INSTANT_MP_RESTORE):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::INSTANT_MAGICAL_DAMAGE):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::INSTANT_PHYSICAL_DAMAGE):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::OT_CURSE):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::INSTANT_CURSE_DAMAGE):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::OT_SOULPROTECTION):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::OT_HPREGEN):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;
			}*/
			handleEffectFrom(BattleCharacter::PLAYER, effect);
		}
		else
		{
			if (!*battleHud->messageBoxOpened)
			{
				currentCharEffect = -1;
				battleState = PLAYERTURNEND;
			}
		}
	}
}

void BattleLevel::handlePlayerEffects()
{
	//If player finished reading info about effect, get to the next
	if (!*battleHud->messageBoxOpened)
	{
		++currentCharEffect;
		if (currentCharEffect < player->buffs.size())
		{
			//Handle buffs[currentCharEffect]

			Buff& effect = player->buffs[currentCharEffect];
			switch (effect.effect)
			{
			case (Buff::OT_CURSE):
				handleEffectTo(BattleCharacter::PLAYER, Buff(Buff::INSTANT_CURSE_DAMAGE, effect.value, Buff::SELF));
				break;

			case (Buff::OT_HPREGEN):
				handleEffectTo(BattleCharacter::PLAYER, Buff(Buff::INSTANT_HP_RESTORE, effect.value, Buff::SELF));
				break;
			}
		}
	}

	//If there is no effects to handle
	if (!*battleHud->messageBoxOpened)
	{
		player->endTurn();
		battleState = ENEMYTURN;
		battleRequest.enemy->beginTurn();
	}
}

void BattleLevel::getEnemyAction()
{
	battleRequest.enemy->beginTurn();
	currentAction = battleRequest.enemy->stepAI();
	battleState = ENEMYTURNRES;
}

void BattleLevel::handleEnemyAction()
{
	//If enemy just made his turn
	if (currentAction != NULL)
	{
		//Attack action
		if (currentAction->action == CharacterAction::ATTACK)
		{
			cam->shake(15, 15, 20);
			gameCore->playSfx(GameCore::SFX_HIT2);
			int damage = player->receivePhysDamage(battleRequest.enemy->calcPhysDamage());
			if (damage > 0)
			{
				battleHud->pushMessage({
					{battleRequest.enemy->name + " attacks you!"},
					{"-" + gameCore->intToString(damage) + " HP"}
					}, 9, 5, 10, 0);
			}
			else {
				battleHud->pushMessage({
					{battleRequest.enemy->name + " attacks you!"},
					{"Parry! 0 HP lost"}
					}, 9, 5, 10, 0);
			}
		}

		//Skill action
		else if (currentAction->action == CharacterAction::SKILL)
		{
			currentSkill = battleRequest.enemy->spells[currentAction->id];
			battleRequest.enemy->MP -= currentSkill->cost;
			currentBuff = -1;
			battleState = ENEMYSKILLPARSE;
			battleHud->pushMessage(
				currentSkill->battleDescr,
				9, 5, 10, 0
			);
		}

		//Defend action
		else if (currentAction->action == CharacterAction::DEFEND)
		{
			battleRequest.enemy->block = true;
			battleHud->pushMessage({
				{"Enemy tries to protect himself from you"}
				}, 9, 5, 10, 0);
		}

		delete currentAction;
		currentAction = NULL;
	}

	//If player reads info
	else
	{
		//Wait and begin player turn
		if (!*battleHud->messageBoxOpened)
		{
			currentCharEffect = -1;
			battleState = ENEMYTURNEND;
		}
	}
}

void BattleLevel::handleEnemySkillParse()
{
	//Get through all of the skill effects
	if (!*battleHud->messageBoxOpened)
	{
		++currentBuff;
		if (currentBuff < currentSkill->effects.size())
		{
			Buff& effect = currentSkill->effects[currentBuff];
			/*switch (effect.effect)
			{
			case (Buff::INSTANT_HP_RESTORE):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::INSTANT_MP_RESTORE):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::INSTANT_MAGICAL_DAMAGE):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::INSTANT_PHYSICAL_DAMAGE):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::OT_CURSE):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::INSTANT_CURSE_DAMAGE):
				handleEffectTo(BattleCharacter::PLAYER, effect);
				break;

			case (Buff::OT_SOULPROTECTION):
				handleEffectTo(BattleCharacter::ENEMY, effect);
				break;

			case (Buff::OT_HPREGEN):
				handleEffectTo(BattleCharacter::ENEMY, effect);
			}*/
			handleEffectFrom(BattleCharacter::ENEMY, effect);
		}
		else
		{
			if (!*battleHud->messageBoxOpened)
			{
				currentCharEffect = -1;
				battleState = ENEMYTURNEND;
			}
		}
	}
}

void BattleLevel::handleEnemyEffects()
{
	//If player finished reading info about effect, get to the next
	if (!*battleHud->messageBoxOpened)
	{
		++currentCharEffect;
		if (currentCharEffect < battleRequest.enemy->buffs.size())
		{
			//Handle buffs[currentCharEffect]

			Buff& effect = battleRequest.enemy->buffs[currentCharEffect];
			float value;
			switch (effect.effect)
			{
			case (Buff::OT_CURSE):
				handleEffectTo(BattleCharacter::ENEMY, Buff(Buff::INSTANT_CURSE_DAMAGE, effect.value, Buff::SELF));
				break;

			case (Buff::OT_HPREGEN):
				handleEffectTo(BattleCharacter::ENEMY, Buff(Buff::INSTANT_HP_RESTORE, effect.value, Buff::SELF));
				break;
			}
		}
	}

	//If there is no effects to handle
	if (!*battleHud->messageBoxOpened)
	{
		battleRequest.enemy->endTurn();
		battleState = PLAYERTURN;
		battleHud->open();
		player->beginTurn();
	}
}

void BattleLevel::handleEffectFrom(BattleCharacter user, const Buff& effect)
{
	cout << int(effect.effect) << " : " << int(effect.target) << endl;
	if (user == BattleCharacter::PLAYER)
	{
		if (effect.target == Buff::SELF)
		{
			handleEffectTo(BattleCharacter::PLAYER, effect);
		}
		else
		{
			handleEffectTo(BattleCharacter::ENEMY, effect);
		}
	}

	else if (user == BattleCharacter::ENEMY)
	{
		if (effect.target == Buff::SELF)
		{
			handleEffectTo(BattleCharacter::ENEMY, effect);
		}
		else
		{
			handleEffectTo(BattleCharacter::PLAYER, effect);
		}
	}
}

void BattleLevel::handleEffectTo(BattleCharacter tar, const Buff& effect)
{
	if (tar == BattleCharacter::PLAYER)
	{
		int val = player->receiveEffect(effect);
		switch (effect.effect)
		{

		case (Buff::INSTANT_HP_RESTORE):
			gameCore->playSfx(GameCore::SFX_HEAL);
			battleHud->pushMessage({
			{"You have restored " + gameCore->intToString(val) + " HP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_MP_RESTORE):
			gameCore->playSfx(GameCore::SFX_HEAL);
			battleHud->pushMessage({
			{"You have restored " + gameCore->intToString(val) + " MP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::OT_SOULPROTECTION):
			battleHud->pushMessage({
			{"You are now under \"soul protection\"."}
				}, 9, 5, 10, 0);
			break;

		case (Buff::OT_HPREGEN):
			battleHud->pushMessage({
			{"You are now healing much faster."}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_MAGICAL_DAMAGE):
			cam->shake(15, 15, 20);
			gameCore->playSfx(GameCore::SFX_HIT2);
			battleHud->pushMessage({
			{"You have taken magical damage! -" + gameCore->intToString(val) + " HP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_PHYSICAL_DAMAGE):
			cam->shake(15, 15, 20);
			gameCore->playSfx(GameCore::SFX_HIT2);
			battleHud->pushMessage({
			{"You have taken physical damage! -" + gameCore->intToString(val) + " HP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::OT_CURSE):
			battleHud->pushMessage({
			{"You are now under curse!"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_CURSE_DAMAGE):
			if (val == 0)
				battleHud->pushMessage({
				{"\"Soul protection\" reduced curse damage to 0!"}
					}, 9, 5, 10, 0);
			else
				battleHud->pushMessage({
				{"You have taken curse damage! -" + gameCore->intToString(val) + " HP"}
					}, 9, 5, 10, 0);
			break;
		}
	}

	else if (tar == BattleCharacter::ENEMY)
	{
		int val = battleRequest.enemy->receiveEffect(effect);
		switch (effect.effect)
		{
		case (Buff::INSTANT_HP_RESTORE):
			gameCore->playSfx(GameCore::SFX_HEAL);
			battleHud->pushMessage({
			{battleRequest.enemy->name + " have restored " + gameCore->intToString(val) + " HP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_MP_RESTORE):
			gameCore->playSfx(GameCore::SFX_HEAL);
			battleHud->pushMessage({
			{battleRequest.enemy->name + " have restored " + gameCore->intToString(val) + " MP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::OT_SOULPROTECTION):
			battleHud->pushMessage({
			{battleRequest.enemy->name + " is now under \"soul protection\"."}
				}, 9, 5, 10, 0);
			break;

		case (Buff::OT_HPREGEN):
			battleHud->pushMessage({
			{battleRequest.enemy->name + " is now healing much faster."}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_MAGICAL_DAMAGE):
			cam->shake(10, 10, 20);
			gameCore->playSfx(GameCore::SFX_HIT1);
			battleHud->pushMessage({
			{battleRequest.enemy->name + " have taken magical damage! -" + gameCore->intToString(val) + " HP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_PHYSICAL_DAMAGE):
			cam->shake(10, 10, 20);
			gameCore->playSfx(GameCore::SFX_HIT1);
			battleHud->pushMessage({
			{battleRequest.enemy->name + " have taken physical damage! -" + gameCore->intToString(val) + " HP"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::OT_CURSE):
			battleHud->pushMessage({
			{battleRequest.enemy->name + " is now under curse!"}
				}, 9, 5, 10, 0);
			break;

		case (Buff::INSTANT_CURSE_DAMAGE):
			if (val == 0)
				battleHud->pushMessage({
				{"\"Soul protection\" reduced curse damage to 0!"}
					}, 9, 5, 10, 0);
			else
				battleHud->pushMessage({
				{battleRequest.enemy->name + " have taken curse damage! -" + gameCore->intToString(val) + " HP"}
					}, 9, 5, 10, 0);
			break;
		}
	}
}