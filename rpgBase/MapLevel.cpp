#include "MapLevel.h"

MapLevel::MapLevel(const Vector2& nLvlSize, const Vector2& nCamSize, int nLevelId, GameCore::Music nTheme):
	Level(nLvlSize, new Camera({0, 0}, nCamSize, nLvlSize, Camera::LOCK), nLevelId)
{
	musTheme = nTheme;

	int timer = 0;
	isRunning = false;
	staticSolidMap.push_back(new hitbox(-10, 0, 10, size.y));
	staticSolidMap.push_back(new hitbox(size.x, 0, 10, size.y));
	staticSolidMap.push_back(new hitbox(0, -10, size.x, 10));
	staticSolidMap.push_back(new hitbox(0, size.y, size.x, 10));

	if (spr_transition == NULL)
	{
		spr_transition = gameCore->loadTexture("Sprites/HUD/s_lvlTransition.png");
		SDL_SetTextureBlendMode(spr_transition, SDL_BLENDMODE_BLEND);
	}

	if (levelHud == NULL)
	{
		levelHud = new LevelHUD(gameCore, player);
	}

	currentChest = NULL;

	if (textureList == NULL)
		textureList = new std::vector<AnimatedTexture*>;

	dialogueInt = NULL;

}

void MapLevel::enter(int entrance)
{
	//Player properly enter location
	if (entrance != -1)
	{
		player->pos = spawnPoints[entrance];
	}

	//Player returns after battle
	else
	{
		//Any regular battles
		if (battleRequest.battleId == 0)
		{
			delete battleRequest.enemy;
		}

		//Place specific ID's here
	}

	gameCore->playMusicFaded(musTheme, 500);

	gameCore->setCam(cam);

	isRunning = true;
	returnVal = { -1, 0 };

	timer = transitionPeriod + 1;
	state = ENTER;
	inputMethod = INPUT_DEFAULT;
	player->updateHBox();
}

LevelResult MapLevel::levelProcess()
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

		for (int i = 0; i < textureList->size(); ++i)
		{
			(*textureList)[i]->update();
		}

		for (int i = 0; i < activeObjects.size(); i++)
			activeObjects[i]->update();

		movePlayer();

		currentChest = NULL;
		for (int i = 0; i < chests.size(); i++)
		{
			if (chests[i]->isCollide(player->hBox))
			{
				currentChest = chests[i];
				break;
			}
		}

		handleDelayedActions();

		uniqueLogic();

		//PRE-DRAWING

		cam->update(player->pos);

		//DRAWING

		renderLevel();
		SDL_Delay(1000.0 / 60.0);
	}
	gameCore->deleteCam();
	return returnVal;
}

void MapLevel::renderLevel()
{
	gameCore->resetScreen();
	for (int i = 0; i < activeObjects.size(); i++)
		activeObjects[i]->updateDepth();
	sort(activeObjects.begin(), activeObjects.end(), isLower);
	for (int i = 0; i < staticObjects.size(); i++)
	{
		for (int k = 0; k < activeObjects.size(); k++)
		{
			if (activeObjects[k]->depth < staticObjects[i]->depth)
			{
				if (!activeObjects[k]->drawn)
				{
					gameCore->drawObject(activeObjects[k]);
					activeObjects[k]->drawn = true;
				}
			}
			else break;
		}
		gameCore->drawObject(staticObjects[i]);
	}
	for (int k = 0; k < activeObjects.size(); k++)
	{
		if (!activeObjects[k]->drawn)
			gameCore->drawObject(activeObjects[k]);
		else
			activeObjects[k]->drawn = false;
	}

#ifdef DRAWHBOX
	gameCore->setRenderMode(GameCore::RM_QUICKHUD);

	gameCore->drawHBox(player->hBox, { 0, 255, 0, 100 });
	for (int i = 0; i < staticSolidMap.size(); i++)
	{
		gameCore->drawHBox(*staticSolidMap[i], { 255, 0, 0, 100 });
	}
	for (int i = 0; i < staticLeavePoints.size(); i++)
	{
		gameCore->drawHBox(staticLeavePoints[i]->hBox, { 0, 0, 255, 100 });
	}

	for (int i = 0; i < chests.size(); i++)
	{
		gameCore->drawHBox(chests[i]->hBox, {255, 0, 255, 100});
	}

	for (int i = 0; i < interactiveObjects.size(); i++)
	{
		gameCore->drawHBox(interactiveObjects[i]->hBox, { 255, 0, 255, 100 });
	}

	for (int i = 0; i < staticTriggerList.size(); ++i)
	{
		gameCore->drawHBox(staticTriggerList[i]->hBox, {255, 255, 0, 100});
	}
#endif

	if (state != RUN)
	{
		gameCore->setRenderMode(GameCore::RM_HUD);
		switch (state)
		{
		case (ENTER):
			--timer;
			SDL_SetTextureAlphaMod(spr_transition, 255.0 * float(timer) / transitionPeriod);
			gameCore->drawTexture(spr_transition, {0, 0});
			if (timer == 0) state = RUN;
			break;
		case (LEAVE):
			++timer;
			SDL_SetTextureAlphaMod(spr_transition, 255.0 * float(timer) / transitionPeriod);
			gameCore->drawTexture(spr_transition, { 0, 0 });
			if (timer == transitionPeriod)
			{
				isRunning = false;
			}
			break;
		case (LEAVEBATTLE):
			if (gameCore->drawTransitionBattle(true))
			{
				isRunning = false;
			}
			break;
		}

	}

	levelHud->draw();
	gameCore->updateScreen();
}

void MapLevel::processInput(const SDL_Event& e)
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
			case (SDLK_LEFT):
				player->movement.beginMovement(Movement::LEFT);
				break;
			case (SDLK_RIGHT):
				player->movement.beginMovement(Movement::RIGHT);
				break;
			case (SDLK_UP):
				player->movement.beginMovement(Movement::UP);
				break;
			case (SDLK_DOWN):
				player->movement.beginMovement(Movement::DOWN);
				break;
			case (SDLK_ESCAPE):
				isRunning = false;
				break;
			case (SDLK_c):
				if (levelHud->open())
				{
					inputMethod = INPUT_HUD;
					player->stop();
				}
				break;
			case (SDLK_z):
				if (currentChest != NULL)
				{
					if (levelHud->open(currentChest))
					{
						inputMethod = INPUT_HUD;
						player->stop();
					}
				}
				else
				{
					for (int i = 0; i < interactiveObjects.size(); ++i)
					{
						if (interactiveObjects[i]->checkCollision(player->hBox))
							break;
					}
				}
				break;
			case (SDLK_p):
				beginBattle(new Wyvern(gameCore), 0);
				break;
			case (SDLK_o):
				pushMessage({
					{"This is a simple question"},
					{"Tell me, ", "what do you choose?"}
					}, 5, 5, 10, 0);
				dialogueInt = NULL;
				pushQuestionMultiselect(new vector<string>{"First", "second"}, &dialogueInt);
				break;
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case (SDLK_LEFT):
				player->movement.endMovement(Movement::LEFT);
				break;
			case (SDLK_RIGHT):
				player->movement.endMovement(Movement::RIGHT);
				break;
			case (SDLK_UP):
				player->movement.endMovement(Movement::UP);
				break;
			case (SDLK_DOWN):
				player->movement.endMovement(Movement::DOWN);
				break;
			}
		}
	}
	else if (inputMethod == INPUT_HUD)
	{
		if (levelHud->proceedInput(e))
		{
			inputMethod = INPUT_DEFAULT;
		}
	}
}

void MapLevel::movePlayer()
{
	int offsetx = 0;
	if (player->movement.velocity.x > 0)
		offsetx = 1;
	else
		offsetx = -1;
	int offsety = 0;
	if (player->movement.velocity.y > 0)
		offsety = 1;
	else
		offsety = -1;
	for (int i = 0; i < abs(player->movement.velocity.x); i++)
	{
		player->pos.x += offsetx;
		player->updateHBox();
		bool isCollide = false;
		for (int k = 0; k < staticSolidMap.size(); k++)
		{
			if (staticSolidMap[k]->isCollideWith(player->hBox))
			{
				isCollide = true;
				break;
			}
		}
		if (isCollide)
		{
			player->pos.x -= offsetx;
			player->updateHBox();
			break;
		}
	}
	for (int i = 0; i < abs(player->movement.velocity.y); i++)
	{
		player->pos.y += offsety;
		player->updateHBox();
		bool isCollide = false;
		for (int k = 0; k < staticSolidMap.size(); k++)
		{
			if (staticSolidMap[k]->isCollideWith(player->hBox))
			{
				isCollide = true;
				break;
			}
		}
		if (isCollide)
		{
			player->pos.y -= offsety;
			player->updateHBox();
			break;
		}
	}

	for (int i = 0; i < staticLeavePoints.size(); ++i)
	{
		if (staticLeavePoints[i]->hBox.isCollideWith(player->hBox))
		{
			state = LEAVE;
			inputMethod = INPUT_NOINPUT;
			returnVal = { staticLeavePoints[i]->nextLvl, staticLeavePoints[i]->entrance };
			player->stop();
			break;
		}
	}

	for (int i = 0; i < staticTriggerList.size(); ++i)
	{
		staticTriggerList[i]->update();
	}
}

void MapLevel::pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId)
{
	levelHud->pushMessage(multilines, font, nPeriod, nLinePeriod, voiceId);
	inputMethod = INPUT_HUD;
	player->stop();
}

void MapLevel::uniqueLogic()
{
	if (dialogueInt)
	{
		delete dialogueInt;
		dialogueInt = NULL;
	}
}

void MapLevel::beginBattle(Enemy* enemy, int battleId)
{
	gameCore->stopMusic();

	inputMethod = INPUT_NOINPUT;
	player->stop();
	gameCore->playSfx(GameCore::SFX_BATTLEBEGIN_P1);

	actionList.push_back(new TimerAction(30,
		[this, enemy, battleId]()
		{
			beginBattleInstantly(enemy, battleId);
		}
	));
}

void MapLevel::beginBattleInstantly(Enemy* enemy, int battleId)
{
	gameCore->stopMusic();

	inputMethod = INPUT_NOINPUT;
	player->stop();

	battleRequest.enemy = enemy;
	battleRequest.srcLevel = levelId;
	battleRequest.battleId = battleId;

	gameCore->playSfx(GameCore::SFX_BATTLEBEGIN_P2);
	state = LEAVEBATTLE;
	returnVal = { 0, 0 };
}

void MapLevel::pushQuestionMultiselect(vector<string>* options, int** nTarget)
{
	levelHud->pushQuestionMultiselect(options, nTarget);
	inputMethod = INPUT_HUD;
	player->stop();
}