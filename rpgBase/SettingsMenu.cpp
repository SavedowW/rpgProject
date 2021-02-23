#include "SettingsMenu.h"

SettingsMenu::SettingsMenu(int nLevelId) :
	Level({ 640, 360 }, new Camera({ 0, 0 }, { 640, 360 }, { 640, 360 }, Camera::SET), nLevelId)
{
	vector<string>* options = new vector<string>(int(MenuElements::SIZE));
	(*options)[int(MenuElements::FULLSCREEN)] = "Fullscreen";
	(*options)[int(MenuElements::RESOLUTION)] = "Resolution";
	(*options)[int(MenuElements::RETURNTOMM)] = "Return to main menu";
	mainMenu = new ElementMenuVSwitch(gameCore, options, Vector2{ 10, 100 }, 17, 16, 40, 50, 3, 3 );

	options = new vector<string>(2);
	(*options)[0] = "Disabled";
	(*options)[1] = "Enabled";
	fsMenu = new ElementMenuVSwitch(gameCore, options, Vector2{ 320, 100 }, 17, 16, 40, 50, 3, 3);

	options = new vector<string>(5);
	(*options)[R640] = "640x360";
	(*options)[R1280] = "1280x720";
	(*options)[R1600] = "1600x900";
	(*options)[R1920] = "1920x1080";
	(*options)[R2560] = "2560x1440";
	resMenu = new ElementMenuVSwitch(gameCore, options, Vector2{ 320, 100 }, 17, 16, 40, 50, 3, 3);
}

void SettingsMenu::enter(int entrance)
{
	cout << "Entering\n";
	returnVal = { -1, 0 };
	gameCore->setCam(cam);
	isRunning = true;
	inputMethod = INPUT_DEFAULT;
	state = MAINMENU;
}

LevelResult SettingsMenu::levelProcess()
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

void SettingsMenu::renderLevel()
{

	gameCore->resetScreen();

	mainMenu->draw();

	if (state == FSCREEN)
		fsMenu->draw();

	else if (state == RESOLUTION)
		resMenu->draw();

	gameCore->updateScreen();
}

void SettingsMenu::processInput(const SDL_Event& e)
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
			if (state == MAINMENU)
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
				case (SDLK_x):
					tar = int(MenuElements::RETURNTOMM);
					break;
				}
				
				if (tar != -1)
				{
					switch (tar)
					{
					case (int(MenuElements::FULLSCREEN)):
						state = FSCREEN;
						break;

					case (int(MenuElements::RESOLUTION)):
						state = RESOLUTION;
						break;

					case (int(MenuElements::RETURNTOMM)):
						returnVal = { 1, 0 };
						isRunning = false;
						break;
					}
				}
			}

			else if (state == FSCREEN)
			{
				switch (e.key.keysym.sym)
				{
				case (SDLK_UP):
					fsMenu->inputUp();
					break;
				case (SDLK_DOWN):
					fsMenu->inputDown();
					break;
				case (SDLK_z):
					tar = fsMenu->inputEnter();
					break;
				case (SDLK_x):
					state = MAINMENU;
					break;
				}

				if (tar != -1)
				{
					switch (tar)
					{
					case (0):
						gameCore->setFS(0);
						break;

					case (1):
						gameCore->setFS(2);
						break;

					}
				}
			}

			else if (state == RESOLUTION)
			{
				switch (e.key.keysym.sym)
				{
				case (SDLK_UP):
					resMenu->inputUp();
					break;
				case (SDLK_DOWN):
					resMenu->inputDown();
					break;
				case (SDLK_z):
					tar = resMenu->inputEnter();
					break;
				case (SDLK_x):
					state = MAINMENU;
					break;
				}

				if (tar != -1)
				{
					switch (tar)
					{
					case (R640):
						gameCore->setResolution({640, 360});
						break;

					case (R1280):
						gameCore->setResolution({ 1280, 720 });
						break;

					case (R1600):
						gameCore->setResolution({ 1600, 900 });
						break;

					case (R1920):
						gameCore->setResolution({ 1920, 1080 });
						break;

					case (R2560):
						gameCore->setResolution({ 2560, 1440 });
						break;
					}
				}
			}
		}
	}
}