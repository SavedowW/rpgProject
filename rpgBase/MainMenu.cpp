#include "MainMenu.h"

MainMenu::MainMenu(int nLevelId) :
	Level({ 640, 360 }, new Camera({ 0, 0 }, { 640, 360 }, { 640, 360 }, Camera::SET), nLevelId)
{
	vector<string> *options = new vector<string>(int(Elements::SIZE));
	(*options)[int(Elements::NEWGAME)] = "New game";
	(*options)[int(Elements::LOADGAME)] = "Load game";
	(*options)[int(Elements::SETTINGS)] = "Settings";
	(*options)[int(Elements::QUIT)] = "Quit";

	mainMenu = new ElementMenuVSelect(gameCore, options, Vector2{10, 100}, 17, 16, 40, 10);
}

void MainMenu::enter(int entrance)
{
	returnVal = { -1, 0 };
	gameCore->setCam(cam);
	isRunning = true;
	inputMethod = INPUT_DEFAULT;
}

LevelResult MainMenu::levelProcess()
{
	SDL_Event e;

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			processInput(e);
		}

		//LOGIC
		handleDelayedActions();

		//pre-drawing
		cam->update({ 0, 0 });

		//DRAWING
		renderLevel();
		SDL_Delay(1000.0 / 60.0);
	}
	gameCore->deleteCam();
	return returnVal;
}

void MainMenu::renderLevel()
{
	gameCore->resetScreen();

	mainMenu->draw();

	gameCore->quickDrawText("An image is supposed to be here  ", {640, 180}, 1, GameCore::VCENTER, GameCore::RIGHT);

	gameCore->updateScreen();
}

void MainMenu::processInput(const SDL_Event& e)
{
	int tar = -1;

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
			case (SDLK_UP):
				mainMenu->inputUp();
				break;
			case (SDLK_DOWN):
				mainMenu->inputDown();
				break;
			case (SDLK_z):
				tar = mainMenu->inputEnter();
				break;
			}
		}
	}

	if (tar != -1)
	{
		switch (tar)
		{
		case (int(Elements::NEWGAME)):
			returnVal = { LVLOFFSET + 1, 0 };
			isRunning = false;
			break;
		case (int(Elements::LOADGAME)):
			cout << "case LOADGAME\n";
			break;
		case (int(Elements::SETTINGS)):
			cout << "case SETTINGS\n";
			break;
		case (int(Elements::QUIT)):
			returnVal = { -1, 0 };
			isRunning = false;
			break;
		}
	}
}