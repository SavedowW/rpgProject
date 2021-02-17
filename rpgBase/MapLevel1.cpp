#include "MapLevel1.h"

MapLevel1::MapLevel1(int nLevelId) :
    MapLevel({ 360, 1000 }, { 640, 360 }, nLevelId, GameCore::MUS_DUNGEON)
{
	//Spawn points
	spawnPoints.push_back({ 173.5, 930 });
	spawnPoints.push_back({ 305, 91.5 });

    //Objects
    Object* obj;
    activeObjects.push_back(player);

    obj = new Floor({ 160, 992 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 992 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 960 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 960 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 928 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 928 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 896 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 896 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 864 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 864 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 832 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 832 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 800 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 800 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 768 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 768 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 736 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 736 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 704 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 704 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 672 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 672 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 640 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 640 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 608 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 608 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 576 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 576 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 544 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 544 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 512 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 512 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 480 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 480 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 448 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 448 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 416 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 416 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 384 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 384 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 352 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 352 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 320 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 320 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 288 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 288 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 256 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 256 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 224 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 224 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 192, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 224, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 256, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 288, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 320, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 352, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 160, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 128, 640 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 640 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 608 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 576 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 544 });
    staticObjects.push_back(obj);
    obj = new Floor_cLeft({ 64, 640 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 512 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 480 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 448 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 416 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 384 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 352 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 320 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 288 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 256 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 224 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 192 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 160 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 128 });
    staticObjects.push_back(obj);
    obj = new Floor({ 64, 96 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 768 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 800 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 832 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 864 });
    staticObjects.push_back(obj);
    obj = new Floor_cBottomDuo({ 96, 896 });
    staticObjects.push_back(obj);
    obj = new Floor({ 96, 736 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 192, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 224, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 256, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 288, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 320, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_bottom({ 352, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftIn_bottom({ 160, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftIn_top({ 160, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 320, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 224, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 256, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 288, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 352, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_in_duo_top({ 64, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_top({ 192, 32 });
    staticObjects.push_back(obj);
    obj = new Monitor({ 191, 50 }, *textureList);
    staticObjects.push_back(obj);
    obj = new Monitor({ 302.5, 50 }, *textureList);
    staticObjects.push_back(obj);
    obj = new Wall_in_duo_bottom({ 64, 64 });
    staticObjects.push_back(obj);
    obj = new Chest1({ 64, 81.5 }, { BuildItem(ITEMLIST::ITEM_NOTE_BITE) });
    staticObjects.push_back(obj);
    chests.push_back((Chest*)obj);
    obj = new Wall_cRightOut_top({ 128, 576 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftOut_top({ 96, 576 });
    staticObjects.push_back(obj);
    obj = new Wall_cLeftOut_bottom({ 96, 608 });
    staticObjects.push_back(obj);
    obj = new Wall_cRightOut_bottom({ 128, 608 });
    staticObjects.push_back(obj);
    obj = new Chest1({ 96.5, 887 }, { BuildItem(ITEMLIST::ITEM_CLARENT) });
    staticObjects.push_back(obj);
    chests.push_back((Chest*)obj);
    obj = new Darkness({ 96, 672 });
    staticObjects.push_back(obj);
    obj = new Darkness({ 96, 704 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 480 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 448 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 224, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 256, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 288, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 320, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 352, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lTop({ 128, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 352 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 288 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 672 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 384 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 320 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 352 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 416 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 416 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 448 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 480 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 512 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 544 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 320 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 288 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 576 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 544 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 704 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 736 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 960 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 928 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 896 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 864 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 832 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 800 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 704 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 96, 672 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bLeft({ 64, 672 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lBottom({ 32, 640 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 672 });
    staticObjects.push_back(obj);
    obj = new Wall_high_rTop({ 96, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lTop({ 32, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 640 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 608 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 576 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 544 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 512 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 992 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 384 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 832 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 864 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 896 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 928 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 768 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 224, 736 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 992 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 128, 672 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 288 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 320 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 608 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 384 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 416 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 448 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 480 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 512 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 800 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 768 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 416 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 448 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 480 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 512 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 960 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_rBottom({ 128, 896 });
    staticObjects.push_back(obj);
    obj = new Wall_high_lBottom({ 64, 896 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 64, 864 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 64, 832 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 64, 800 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 64, 768 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 64, 736 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 352 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 128, 864 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 128, 832 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 128, 800 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 128, 768 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 128, 736 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 96, 736 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 96, 544 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 288 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bDuo({ 96, 928 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 320 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 352 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 32, 384 });
    staticObjects.push_back(obj);

    sort(staticObjects.begin(), staticObjects.end(), isLower);

    //Hitboxes
    staticSolidMap.push_back(new hitbox(32, 96, 352, -64));
    staticSolidMap.push_back(new hitbox(224, 128, 160, 896));
    staticSolidMap.push_back(new hitbox(128, 672, 32, 352));
    staticSolidMap.push_back(new hitbox(0, 736, 96, 256));
    staticSolidMap.push_back(new hitbox(96, 928, 32, 64));
    staticSolidMap.push_back(new hitbox(0, 672, 96, 64));
    staticSolidMap.push_back(new hitbox(32, 96, 32, 576));
    staticSolidMap.push_back(new hitbox(96, 96, 64, 544));
    staticSolidMap.push_back(new hitbox(71, 105.5, 17.5, 8.5));
    staticSolidMap.push_back(new hitbox(102.5, 907, 19, 13.5));

    //Leave points
    staticLeavePoints.push_back(new LeavePoint(hitbox{ 160, 992, 66.5, 14.5 }, 1, 1));
    staticLeavePoints.push_back(new LeavePoint(hitbox{ 350, 92, 23.5, 42.5 }, 3, 0));

    //Triggers
    Trigger* trig;
    trig = new Trigger({ 32, 192, 96, 64 },

        //Enter function
        [this](Trigger* trig)
        {
            beginBattle(new Wyvern(gameCore), 0);
            trig->enabled = false;
        },

        //Leave function
        [this](Trigger* trig)
        {
                    //Custom code here
        }, true
    );
    staticTriggerList.push_back(trig);
}