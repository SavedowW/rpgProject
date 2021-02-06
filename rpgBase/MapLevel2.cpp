#include "MapLevel2.h"

MapLevel2::MapLevel2() :
    MapLevel({ 640, 360 }, { 640, 360 })
{
	//Spawn points
	spawnPoints.push_back({ 143.5, 19 });

    //Objects
    Object* obj;
    activeObjects.push_back(player);

obj = new Grass1(128, 0);
    staticObjects.push_back(obj);
obj = new Grass1(160, 0);
    staticObjects.push_back(obj);
obj = new Grass1(160, 32);
    staticObjects.push_back(obj);
obj = new Grass1(128, 32);
    staticObjects.push_back(obj);
obj = new Grass1(128, 64);
    staticObjects.push_back(obj);
obj = new Grass1(160, 64);
    staticObjects.push_back(obj);
obj = new Grass1(160, 96);
    staticObjects.push_back(obj);
obj = new Grass1(128, 96);
    staticObjects.push_back(obj);
obj = new Grass1(128, 128);
    staticObjects.push_back(obj);
obj = new Grass1(160, 128);
    staticObjects.push_back(obj);
obj = new Grass1(160, 160);
    staticObjects.push_back(obj);
obj = new Grass1(128, 160);
    staticObjects.push_back(obj);
obj = new Grass1(192, 160);
    staticObjects.push_back(obj);
obj = new Grass1(192, 128);
    staticObjects.push_back(obj);
obj = new Grass1(224, 128);
    staticObjects.push_back(obj);
obj = new Grass1(224, 160);
    staticObjects.push_back(obj);
obj = new Grass1(256, 128);
    staticObjects.push_back(obj);
obj = new Grass1(256, 160);
    staticObjects.push_back(obj);
obj = new Grass1(288, 160);
    staticObjects.push_back(obj);
obj = new Grass1(288, 128);
    staticObjects.push_back(obj);
obj = new Grass1(320, 128);
    staticObjects.push_back(obj);
obj = new Grass1(320, 160);
    staticObjects.push_back(obj);
obj = new Grass1(352, 160);
    staticObjects.push_back(obj);
obj = new Grass1(352, 128);
    staticObjects.push_back(obj);
obj = new Grass1(384, 128);
    staticObjects.push_back(obj);
obj = new Grass1(384, 160);
    staticObjects.push_back(obj);
    obj = new Chest1({ 381.5, 125 }, { BuildItem(ITEMLIST::ITEM_EMPTINESS) });
    staticObjects.push_back(obj);
    chests.push_back((Chest*)obj);

    sort(staticObjects.begin(), staticObjects.end(), isLower);

    //Hitboxes
    staticSolidMap.push_back(new hitbox(383.5, 155.5, 27.5, -9));
    staticSolidMap.push_back(new hitbox(192, 0, 224, 128));
    staticSolidMap.push_back(new hitbox(416, 128, 32, 64));
    staticSolidMap.push_back(new hitbox(128, 192, 288, 32));
    staticSolidMap.push_back(new hitbox(96, 0, 32, 192));

    //Leave points
    staticLeavePoints.push_back(new LeavePoint(hitbox{ 128, -6, 65, 15 }, 2, 1));
}