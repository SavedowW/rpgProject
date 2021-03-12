#include "Player.h"
#include "EnemiesH.h"
#include <ctime>
#include "LevelsH.h"
//#define FSCREEN
#define THIS_DEF_IS_DEFINED_FROM_OTHER_DEVICE
//com

using namespace std;

const int LVLOFFSET = 3;

int SDL_main(int argc, char* args[])
{
	srand(time(NULL));

	Core* core = new Core;
	if (!core->init())
	{
		std::system("pause");
		return 1;
	}

	Object::core = core;
	GameCore* gameCore = new GameCore(core);

#ifdef FSCREEN
	core->setResolution({1920, 1080});
	core->setFS(1);
#else
	core->setResolution({ 640, 360 });
#endif

	gameCore->registerFont("Fonts/mainOld.ttf", 27, { 255, 255, 255, 255 }); //Titles
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 });   //Unselected in menu
	gameCore->registerFont("Fonts/mainOld.ttf", 22, { 255, 255, 0, 255 }); //Selected in menu
	gameCore->registerFont("Fonts/mainOld.ttf", 18, { 255, 255, 255, 255 });   //Unselected in HUD main menu
	gameCore->registerFont("Fonts/mainOld.ttf", 27, { 255, 255, 0, 255 }); //Selected in HUD main menu
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 }); //MessageBox - 5
	gameCore->registerFont("Fonts/mainOld.ttf", 18, { 255, 255, 255, 255 });   //Info
	gameCore->registerFont("Fonts/mainOld.ttf", 24, { 255, 255, 255, 255 }); //Subtitle unselected
	gameCore->registerFont("Fonts/mainOld.ttf", 27, { 255, 255, 0, 255 }); //Subtitle selected
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 }); //MessageBox battle - 9
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 }); //Menu battle unselected - 10
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 0, 255 }); //Menu battle selected - 11
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 }); //MessageBox question unselected - 12
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 0, 255 }); //MessageBox question selected - 13
	gameCore->registerFont("Fonts/mainOld.ttf", 8, { 255, 255, 255, 255 }); //BattleHud bars - 14
	gameCore->registerFont("Fonts/mainOld.ttf", 13, { 255, 255, 255, 255 }); //BattleHud small font - 15
	gameCore->registerFont("Fonts/mainOld.ttf", 25, { 255, 255, 255, 255 });   //Unselected in main menu - 16
	gameCore->registerFont("Fonts/mainOld.ttf", 30, { 255, 255, 0, 255 }); //Selected in main menu - 17

	Player* player = new Player({ 10, 10 });

	Level::player = player;
	Trigger::player = player;
	Level::gameCore = gameCore;

	LevelResult levelResult = {1, 0};
	Level* levels[7];

	/*levels[0] = new BattleLevel(0);
	levels[1] = new MapLevel0(1);
	levels[2] = new MapLevel1(2);
	levels[3] = new MapLevel2(3);*/

	levels[0] = new BattleLevel(0); //battle level
	levels[1] = new MainMenu(1); //main menu
	levels[2] = new SettingsMenu(2); //settings
	levels[3]; //death screen
	levels[LVLOFFSET + 1] = new MapLevel0(LVLOFFSET + 1);
	levels[LVLOFFSET + 2] = new MapLevel1(LVLOFFSET + 2);
	levels[LVLOFFSET + 3] = new MapLevel2(LVLOFFSET + 3);

	while (levelResult.nextLvl != -1)
	{
		levels[levelResult.nextLvl]->enter(levelResult.entrance);
		levelResult = levels[levelResult.nextLvl]->levelProcess();
	}
	
	core->close();
	return 0;
}