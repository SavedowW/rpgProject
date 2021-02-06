#include "MapLevel0.h"

MapLevel0::MapLevel0() :
    MapLevel({ 1000, 360 }, { 640, 360 })
{
	//Spawn points
	spawnPoints.push_back({ 368.5, 143.5 });
	spawnPoints.push_back({ 938, 142 });

    //Objects
    Object* obj;
    activeObjects.push_back(player);

obj = new Grass1(992, 128);
    staticObjects.push_back(obj);
obj = new Grass1(992, 160);
    staticObjects.push_back(obj);
obj = new Grass1(960, 160);
    staticObjects.push_back(obj);
obj = new Grass1(960, 128);
    staticObjects.push_back(obj);
obj = new Grass1(928, 128);
    staticObjects.push_back(obj);
obj = new Grass1(928, 160);
    staticObjects.push_back(obj);
obj = new Grass1(896, 160);
    staticObjects.push_back(obj);
obj = new Grass1(896, 128);
    staticObjects.push_back(obj);
obj = new Grass1(864, 128);
    staticObjects.push_back(obj);
obj = new Grass1(864, 160);
    staticObjects.push_back(obj);
obj = new Grass1(832, 160);
    staticObjects.push_back(obj);
obj = new Grass1(832, 128);
    staticObjects.push_back(obj);
obj = new Grass1(800, 160);
    staticObjects.push_back(obj);
obj = new Grass1(800, 128);
    staticObjects.push_back(obj);
obj = new Grass1(768, 128);
    staticObjects.push_back(obj);
obj = new Grass1(768, 160);
    staticObjects.push_back(obj);
obj = new Grass1(800, 96);
    staticObjects.push_back(obj);
obj = new Grass1(768, 96);
    staticObjects.push_back(obj);
obj = new Grass1(736, 96);
    staticObjects.push_back(obj);
obj = new Grass1(736, 128);
    staticObjects.push_back(obj);
obj = new Grass1(704, 128);
    staticObjects.push_back(obj);
obj = new Grass1(704, 96);
    staticObjects.push_back(obj);
obj = new Grass1(672, 128);
    staticObjects.push_back(obj);
obj = new Grass1(672, 160);
    staticObjects.push_back(obj);
obj = new Grass1(640, 160);
    staticObjects.push_back(obj);
obj = new Grass1(640, 128);
    staticObjects.push_back(obj);
obj = new Grass1(608, 128);
    staticObjects.push_back(obj);
obj = new Grass1(608, 160);
    staticObjects.push_back(obj);
obj = new Grass1(608, 96);
    staticObjects.push_back(obj);
obj = new Grass1(640, 96);
    staticObjects.push_back(obj);
obj = new Grass1(640, 64);
    staticObjects.push_back(obj);
obj = new Grass1(608, 64);
    staticObjects.push_back(obj);
obj = new Grass1(608, 32);
    staticObjects.push_back(obj);
obj = new Grass1(640, 32);
    staticObjects.push_back(obj);
obj = new Grass1(576, 32);
    staticObjects.push_back(obj);
obj = new Grass1(576, 64);
    staticObjects.push_back(obj);
obj = new Grass1(544, 64);
    staticObjects.push_back(obj);
obj = new Grass1(544, 32);
    staticObjects.push_back(obj);
obj = new Grass1(512, 32);
    staticObjects.push_back(obj);
obj = new Grass1(512, 64);
    staticObjects.push_back(obj);
obj = new Grass1(512, 96);
    staticObjects.push_back(obj);
obj = new Grass1(544, 96);
    staticObjects.push_back(obj);
obj = new Grass1(544, 128);
    staticObjects.push_back(obj);
obj = new Grass1(512, 128);
    staticObjects.push_back(obj);
obj = new Grass1(480, 128);
    staticObjects.push_back(obj);
obj = new Grass1(480, 96);
    staticObjects.push_back(obj);
obj = new Grass1(448, 96);
    staticObjects.push_back(obj);
obj = new Grass1(448, 128);
    staticObjects.push_back(obj);
obj = new Grass1(448, 160);
    staticObjects.push_back(obj);
obj = new Grass1(480, 160);
    staticObjects.push_back(obj);
obj = new Grass1(416, 160);
    staticObjects.push_back(obj);
obj = new Grass1(416, 128);
    staticObjects.push_back(obj);
obj = new Grass1(384, 160);
    staticObjects.push_back(obj);
obj = new Grass1(384, 128);
    staticObjects.push_back(obj);
obj = new Grass1(352, 128);
    staticObjects.push_back(obj);
obj = new Grass1(352, 160);
    staticObjects.push_back(obj);
obj = new Grass1(544, 0);
    staticObjects.push_back(obj);
obj = new Grass1(576, 0);
    staticObjects.push_back(obj);
obj = new Grass1(608, 0);
    staticObjects.push_back(obj);
    obj = new Chest1({ 576.5, 1 }, { BuildItem(ITEMLIST::ITEM_APPLE), BuildItem(ITEMLIST::ITEM_EXTHORIUM) });
    staticObjects.push_back(obj);
    chests.push_back((Chest*)obj);
    obj = new Monitor({ 710, 43 }, *textureList);
    staticObjects.push_back(obj);
    obj = new Monitor({ 898.5, 81 }, *textureList);
    staticObjects.push_back(obj);

    sort(staticObjects.begin(), staticObjects.end(), isLower);

    //Hitboxes
    staticSolidMap.push_back(new hitbox(352, 192, 672, 32));
    staticSolidMap.push_back(new hitbox(320, 128, 32, 64));
    staticSolidMap.push_back(new hitbox(352, 96, 96, 32));
    staticSolidMap.push_back(new hitbox(448, 64, 64, 32));
    staticSolidMap.push_back(new hitbox(480, 32, 32, 32));
    staticSolidMap.push_back(new hitbox(512, 0, 32, 32));
    staticSolidMap.push_back(new hitbox(640, 0, 32, 32));
    staticSolidMap.push_back(new hitbox(672, 32, 32, 96));
    staticSolidMap.push_back(new hitbox(704, 64, 128, 32));
    staticSolidMap.push_back(new hitbox(832, 96, 192, 32));
    staticSolidMap.push_back(new hitbox(576, 96, 32, 96));
    staticSolidMap.push_back(new hitbox(512, 160, 64, 32));
    staticSolidMap.push_back(new hitbox(704, 160, 64, 32));
    staticSolidMap.push_back(new hitbox(578, 32.5, 27.5, -9.5));

    //Leave points
    staticLeavePoints.push_back(new LeavePoint(hitbox{ 986, 127.5, 20.5, 64 }, 2, 0));

    //Triggers
    Trigger* trig;
    trig = new Trigger({ 800, 127.5, 20.5, 64 },

        //Enter function
        [this](Trigger* trig)
        {
            dialogueInt = new int(0);
        },

        //Leave function
        [this](Trigger* trig)
        {
            dialogueInt = new int(1);
            trig->enabled = false;
        }, true
    );
    staticTriggerList.push_back(trig);
}

void MapLevel0::uniqueLogic()
{
    //Dialogues chooses
    if (dialogueInt != NULL)
    {
        if (*dialogueInt == 0)
        {
            pushMessage({
                {"Beware, mah boe."},
                }, 5, 5, 10, 0);
        }
        else if (*dialogueInt == 1)
        {
            pushMessage({
                {"You passed the trial."},
                {"Now, go."}
                }, 5, 5, 10, 0);
        }
        delete dialogueInt;
        dialogueInt = NULL;
    }
}