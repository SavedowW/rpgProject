#include "Player.h"
#include "EnemiesH.h"
#include <ctime>
#include "LevelsH.h"
//#define FSCREEN

using namespace std;

int getLimitedInput(int lowerEdge, int higherEdge);
bool proceedBattle(Player* player, Character* enemy);

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
	core->setResolution({ 1280, 720 });
#endif

	gameCore->registerFont("Fonts/mainOld.ttf", 27, {0, 0, 0, 255}); //Titles
	gameCore->registerFont("Fonts/mainOld.ttf", 15, {0, 0, 0, 255});   //Unselected in menu
	gameCore->registerFont("Fonts/mainOld.ttf", 22, {100, 50, 50, 255}); //Selected in menu
	gameCore->registerFont("Fonts/mainOld.ttf", 18, { 0, 0, 0, 255 });   //Unselected in main menu
	gameCore->registerFont("Fonts/mainOld.ttf", 27, {100, 50, 50, 255 }); //Selected in main menu
	gameCore->registerFont("Fonts/mainOld.ttf", 15, {0, 0, 0, 255}); //MessageBox - 5
	gameCore->registerFont("Fonts/mainOld.ttf", 18, { 0, 0, 0, 255 });   //Info
	gameCore->registerFont("Fonts/mainOld.ttf", 24, { 0, 0, 0, 255 }); //Subtitle unselected
	gameCore->registerFont("Fonts/mainOld.ttf", 27, { 100, 50, 50, 255 }); //Subtitle selected
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 }); //MessageBox battle - 9
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 255, 255 }); //Menu battle unselected - 10
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 255, 255, 0, 255 }); //Menu battle selected - 11
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 0, 0, 0, 255 }); //MessageBox question unselected - 12
	gameCore->registerFont("Fonts/mainOld.ttf", 15, { 100, 50, 50, 255 }); //MessageBox question selected - 13

	Player* player = new Player({ 10, 10 });

	Level::player = player;
	Trigger::player = player;
	Level::gameCore = gameCore;

	LevelResult levelResult = {1, 0};
	Level* levels[4];

	levels[0] = new BattleLevel();
	levels[1] = new MapLevel0();
	levels[2] = new MapLevel1();
	levels[3] = new MapLevel2();


	while (levelResult.nextLvl != -1)
	{
		levels[levelResult.nextLvl]->enter(levelResult.entrance);
		levelResult = levels[levelResult.nextLvl]->levelProcess();
	}

	core->close();
	return 0;
}