#include "MapLevel1.h"

MapLevel1::MapLevel1() :
    MapLevel({ 640, 360 }, { 640, 360 })
{
	//Spawn points
	spawnPoints.push_back({ 18.5, 143 });
	spawnPoints.push_back({ 175.5, 293 });

    //Objects
    Object* obj;
    activeObjects.push_back(player);

    obj = new Grass1( 0, 128 );
    staticObjects.push_back(obj);
obj = new Grass1(0, 160);
    staticObjects.push_back(obj);
obj = new Grass1(32, 160);
    staticObjects.push_back(obj);
obj = new Grass1(32, 128);
    staticObjects.push_back(obj);
obj = new Grass1(64, 128);
    staticObjects.push_back(obj);
obj = new Grass1(64, 160);
    staticObjects.push_back(obj);
obj = new Grass1(96, 160);
    staticObjects.push_back(obj);
obj = new Grass1(96, 128);
    staticObjects.push_back(obj);
obj = new Grass1(128, 128);
    staticObjects.push_back(obj);
obj = new Grass1(128, 160);
    staticObjects.push_back(obj);
obj = new Grass1(160, 160);
    staticObjects.push_back(obj);
obj = new Grass1(160, 128);
    staticObjects.push_back(obj);
obj = new Grass1(192, 128);
    staticObjects.push_back(obj);
obj = new Grass1(192, 160);
    staticObjects.push_back(obj);
obj = new Grass1(192, 192);
    staticObjects.push_back(obj);
obj = new Grass1(192, 224);
    staticObjects.push_back(obj);
obj = new Grass1(192, 256);
    staticObjects.push_back(obj);
obj = new Grass1(192, 288);
    staticObjects.push_back(obj);
    obj = new Grass1(192, 320);
    staticObjects.push_back(obj);
    obj = new Grass1(192, 352);
    staticObjects.push_back(obj);
    obj = new Grass1(160, 352);
    staticObjects.push_back(obj);
    obj = new Grass1(160, 320);
    staticObjects.push_back(obj);
    obj = new Grass1(160, 288);
    staticObjects.push_back(obj);
    obj = new Grass1(160, 256);
    staticObjects.push_back(obj);
    obj = new Grass1(160, 224);
    staticObjects.push_back(obj);
    obj = new Grass1(160, 192);
    staticObjects.push_back(obj);
    obj = new Monitor({ 92.5, 69 }, *textureList);
    staticObjects.push_back(obj);

    sort(staticObjects.begin(), staticObjects.end(), isLower);

    //Hitboxes
    staticSolidMap.push_back(new hitbox(0, 192, 160, 192));
    staticSolidMap.push_back(new hitbox(0, 96, 256, 32));
    staticSolidMap.push_back(new hitbox(224, 128, 32, 256));

    //Leave points
    staticLeavePoints.push_back(new LeavePoint(hitbox{ -8, 127.5, 17, 64 }, 1, 1));
    staticLeavePoints.push_back(new LeavePoint(hitbox{ 159.5, 352.5, 64.5, 15 }, 3, 0));
}