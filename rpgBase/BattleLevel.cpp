#include "BattleLevel.h"
#include "MessageHandler.h"

BattleLevel::BattleLevel(int nLevelId) :
	Level({ 640, 360 }, new Camera({ 0, 0 }, { 640, 360 }, { 640, 360 }, Camera::SET), nLevelId)
{
	battleHud = new BattleHUD(gameCore, player);
	backgrounds[0] = new Background1(gameCore);
	backgrounds[1] = new Background2(gameCore);
}

void BattleLevel::enter(int entrance)
{
	returnVal = { -1, 0 };
	if (battleRequest.battleId == 0)
	{
		gameCore->playMusic(GameCore::MUS_BATTLE1);
	}

	gameCore->setCam(cam);
	isRunning = true;
	inputMethod = INPUT_DEFAULT;
	state = ENTER;
	battleState = ENTERSTATE;
	currentAction = NULL;
	currentSkill = NULL;
	currentBuff = -1;
	battleHud->setEnemy(battleRequest.enemy);
}

LevelResult BattleLevel::levelProcess()
{
	SDL_Event e;

	while (isRunning)
	{
		fpsManager->beginFrame();

		while (SDL_PollEvent(&e))
		{
			processInput(e);
		}
		gameCore->resetScreen();

		//LOGIC

		handleDelayedActions();

		if (state == RUN)
		{

			if (player->stats.HP <= 0 || battleRequest.enemy->stats.HP <= 0)
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

		if (state == END)
		{
			if (!*battleHud->messageBoxOpened && actionList.size() <= 0)
			{
				state = LEAVE;
			}
		}

		//PRE-DRAWING
		cam->update({ 0, 0 });

		//DRAWING

		renderLevel();
		SDL_Delay(fpsManager->delayFrame());
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

	
	battleHud->draw();
	gameCore->updateScreen();
}

void BattleLevel::handleEnd()
{
	state = END;
	returnVal = { battleRequest.srcLevel, -1 };

	//Loose
	if (player->stats.HP <= 0)
	{
		actionList.push_back(new ReverseFlagAction(battleHud->messageBoxOpened, [this]()
			{
			gameCore->stopMusic();
			battleHud->pushMessage({
						{"You lost!"}
				}, 9, 5, 10, 0);
			})
			);
	}

	//Win
	else if (battleRequest.enemy->stats.HP <= 0)
	{
		
		int expUp = battleRequest.enemy->getExp();
		cout << expUp << endl;
		vector <PlayerLevel> lvlUp = player->gainExp(expUp);

		const vector<Item*>& droplist = battleRequest.enemy->reward();
		actionList.push_back(new ReverseFlagAction(battleHud->messageBoxOpened, [this, expUp]()
			{
				gameCore->stopMusic();
				battleHud->pushMessage({
							{"You won!", "Gained " + gameCore->intToString(expUp) + " EXP."}
					}, 9, 5, 10, 0);
			})
		);

		if (lvlUp.size() > 0)
		{
			cout << lvlUp.size() << endl;
			actionList.push_back(new ReverseFlagAction(battleHud->messageBoxOpened, [this, lvlUp]()
				{
					cout << lvlUp.size() << endl;

					gameCore->playSfx(GameCore::SFX_HEAL);
					for (int i = 0; i < lvlUp.size(); ++i)
					{

						PlayerLevel prevLevel = player->levels[lvlUp[i].lvl - 1];

						battleHud->pushMessage({
						{"Level increased to " + gameCore->intToString(lvlUp[i].lvl) + "!"}
							}, 9, 5, 10, 0);

						battleHud->pushMessage({
						{"Max HP went up by " + gameCore->intToString(lvlUp[i].levelStats.maxHP - prevLevel.levelStats.maxHP) + "!",
						 "Max MP went up by " + gameCore->intToString(lvlUp[i].levelStats.maxMP - prevLevel.levelStats.maxMP) + "!",
						 "HP and MP restored."}
							}, 9, 5, 10, 0);

						int diff = lvlUp[i].levelStats.bpDamage - prevLevel.levelStats.bpDamage;
						if (diff > 0)
							battleHud->pushMessage({
							{"Base physical damage went up by " + gameCore->intToString(diff)}
								}, 9, 5, 10, 0);

						diff = lvlUp[i].levelStats.bmPower - prevLevel.levelStats.bmPower;
						if (diff > 0)
							battleHud->pushMessage({
							{"Base magical power went up by " + gameCore->intToString(diff)}
								}, 9, 5, 10, 0);

						diff = lvlUp[i].levelStats.bpResist - prevLevel.levelStats.bpResist;
						if (diff > 0)
							battleHud->pushMessage({
							{"Base physical resist went up by " + gameCore->intToString(diff)}
								}, 9, 5, 10, 0);

						diff = lvlUp[i].levelStats.bmResist - prevLevel.levelStats.bmResist;
						if (diff > 0)
							battleHud->pushMessage({
							{"Base magical resist went up by " + gameCore->intToString(diff)}
								}, 9, 5, 10, 0);
					}
				}
			)
			);
		}

		actionList.push_back(new ReverseFlagAction(battleHud->messageBoxOpened, [this, &droplist]()
			{
				for (int i = 0; i < droplist.size(); i++)
				{
					battleHud->pushMessage({
							{droplist[i]->name + " added", "to your inventory. "}
						}, 9, 5, 10, 0);
				}
			}
		)
		);
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
		if (player->stats.MP >= currentSkill->cost)
		{
			player->addMp(-currentSkill->cost);
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
		Item* selectedItem = player->inventory[selected];
		string name = selectedItem->name;
		int result = player->useItem(selected);

		MessageHandler::itemMessage(result, selectedItem, name, selected, battleHud->messageBox, player);
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
			battleRequest.enemy->addMp(-currentSkill->cost);
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
	Buff actualEffect = effect;
	if (user == BattleCharacter::PLAYER)
	{
		actualEffect.value *= player->getMagicalMultiplier();
		if (effect.target == Buff::SELF)
		{
			handleEffectTo(BattleCharacter::PLAYER, actualEffect);
		}
		else
		{
			handleEffectTo(BattleCharacter::ENEMY, actualEffect);
		}
	}

	else if (user == BattleCharacter::ENEMY)
	{
		actualEffect.value *= battleRequest.enemy->getMagicalMultiplier();
		if (effect.target == Buff::SELF)
		{
			handleEffectTo(BattleCharacter::ENEMY, actualEffect);
		}
		else
		{
			handleEffectTo(BattleCharacter::PLAYER, actualEffect);
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