#include "MapLevel2.h"

MapLevel2::MapLevel2(int nLevelId) :
    MapLevel({ 1000, 360 }, { 640, 360 }, nLevelId, GameCore::MUS_DUNGEON)
{
	//Spawn points
	spawnPoints.push_back({ 38.5, 173.5 });

    //Objects
    Object* obj;
    activeObjects.push_back(player);

    obj = new Floor({ 0, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 0, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 32, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 32, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 128, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 128, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 224, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 224, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 256, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 256, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 288, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 288, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 320, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 320, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 352, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 352, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 384, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 384, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 224, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 256, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 288, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 320, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 352, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 384, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 288, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 320, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 416, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 416, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 416, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 448, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 448, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 480, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 480, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 512, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 512, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 544, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 544, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 576, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 576, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 608, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 608, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 640, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 640, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 448, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 480, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 512, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 544, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 576, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 608, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 640, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 672, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 672, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 704, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 704, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 736, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 736, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 768, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 768, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 800, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 800, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 832, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 832, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 832, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 864, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 864, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 864, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 896, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 896, 160 });
    staticObjects.push_back(obj);
    obj = new Floor_cLeft({ 800, 192 });
    staticObjects.push_back(obj);
    obj = new Floor_cRight({ 672, 192 });
    staticObjects.push_back(obj);
    obj = new Floor_cRight({ 896, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 32, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 64, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 96, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 128, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 160, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftIn_bottom({ 224, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftIn_bottom({ 288, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 384, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 416, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 448, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 480, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 512, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 544, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 576, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 608, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 640, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 672, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 704, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 736, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 768, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 800, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 832, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 864, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 0, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightIn_top({ 320, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftIn_top({ 288, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightIn_bottom({ 320, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftIn_top({ 224, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftOut_top({ 352, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightIn_top({ 896, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 864, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 832, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 800, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 768, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 736, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 704, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 672, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 640, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 608, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 576, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 544, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 512, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 480, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 448, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 416, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 384, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightOut_top({ 256, 64 });
    staticObjects.push_back(obj);
    obj = new Monitor({ 646.5, 80.5 }, *textureList);
    staticObjects.push_back(obj);
    obj = new Monitor({ 417.5, 83.5 }, *textureList);
    staticObjects.push_back(obj);
    obj = new Trashcan1({ 304, 86.5 }, { BuildItem(ITEMLIST::ITEM_DEADBODIES) });
    staticObjects.push_back(obj);
    chests.push_back((Chest*)obj);
    obj = new Wall_top({ 0, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 32, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 128, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftOut_bottom({ 352, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightOut_top({ 192, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightOut_bottom({ 256, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightIn_bottom({ 896, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 160, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 96, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 64, 96 });
    staticObjects.push_back(obj);
    obj = new Monitor({ 114.5, 115.5 }, *textureList);
    staticObjects.push_back(obj);
    obj = new Wall_cRightOut_bottom({ 192, 128 });
    staticObjects.push_back(obj);
    obj = new Blader({ 856.5, 144 }, &sceneInt[0]);
    staticObjects.push_back(obj);
    interactiveObjects.push_back((InteractiveObject*)obj);
    blader = (Blader*)obj;
    obj = new Wall_high_left({ 928, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 928, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_rBottom({ 928, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bRight({ 896, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 864, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 832, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bLeft({ 800, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lBottom({ 768, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 768, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 736, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 704, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_rBottom({ 704, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lTop({ 192, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lTop({ 256, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_high_rTop({ 352, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_high_rTop({ 928, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 928, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 480, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 512, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 448, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 416, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 384, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 352, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 320, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 288, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 256, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 224, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 192, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 160, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 128, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 96, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 64, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 32, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 0, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bRight({ 672, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 640, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 608, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 576, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 544, 224 });
    staticObjects.push_back(obj);

    sort(staticObjects.begin(), staticObjects.end(), isLower);

    //Hitboxes
    staticSolidMap.push_back(new hitbox(310, 118.5, 20, -8.5));
    staticSolidMap.push_back(new hitbox(0, 224, 928, 32));
    staticSolidMap.push_back(new hitbox(928, 64, 32, 160));
    staticSolidMap.push_back(new hitbox(352, 32, 576, 96));
    staticSolidMap.push_back(new hitbox(288, 32, 64, 64));
    staticSolidMap.push_back(new hitbox(224, 64, 64, 64));
    staticSolidMap.push_back(new hitbox(0, 96, 224, 64));
    staticSolidMap.push_back(new hitbox(704, 192, 96, 32));

    //Leave points
    staticLeavePoints.push_back(new LeavePoint(hitbox{ -9.5, 156.5, 23, 71 }, 2, 1));

    //Triggers
    Trigger* trig;

    isPlayerFocused = true;
}

void MapLevel2::uniqueLogic()
{
    if (sceneInt[0])
    {
        switch (*sceneInt[0])
        {
            //Blader dialogue
        case (1):
            pushMessage({
                    {"What?", "Want to buy something?"}
                }, 5, 5, 10, 0);
            pushQuestionMultiselect(new vector<string>{"Store", "Talk", "Quit"}, &sceneInt[1]);
            break;
        }

        delete sceneInt[0];
        sceneInt[0] = NULL;
    }

    if (sceneInt[1])
    {
        switch (*sceneInt[1])
        {
            //Blader dialogue
        case (0):
            levelHud->open(&blader->storeList, "Blader");
            inputMethod = INPUT_HUD;
            break;
        }

        delete sceneInt[1];
        sceneInt[1] = NULL;
    }
}

void MapLevel2::updCam()
{
    if (isPlayerFocused)
        cam->update(player->pos);
    else
        cam->update(blader->pos);
}

void MapLevel2::localDefInputControls(const SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_t)
        {
            isPlayerFocused = !isPlayerFocused;
            cam->setLimited(true, isPlayerFocused);
        }
    }
}
