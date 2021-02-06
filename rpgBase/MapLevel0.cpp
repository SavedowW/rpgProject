#include "MapLevel0.h"

MapLevel0::MapLevel0() :
    MapLevel({ 640, 360 }, { 640, 360 })
{
	//Spawn points
	spawnPoints.push_back({ 189.5, 134.5 });

    //Objects
    Object* obj;
    activeObjects.push_back(player);

    obj = new Floor1({ 352, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 416, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 96 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 64 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 32 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 0 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 320, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 160, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 192, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 224, 128 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 224, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 192, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 160, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 160, 192 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 192, 192 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 224, 192 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 224, 224 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 192, 224 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 256, 224 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 288, 224 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 320, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 352, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 416, 160 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 384, 192 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 352, 192 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 320, 192 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 320, 224 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 352, 224 });
    staticObjects.push_back(obj);
    obj = new Floor1({ 448, 128 });
    staticObjects.push_back(obj);
    obj = new Floor_cLeft({ 160, 224 });
    staticObjects.push_back(obj);
    obj = new Floor_cRight({ 384, 224 });
    staticObjects.push_back(obj);
    obj = new Floor_cRight({ 448, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 416, 0 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 352, 0 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 416, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 352, 32 });
    staticObjects.push_back(obj);
    obj = new Wall_in_left_top({ 320, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_middle_top({ 192, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_out_right_top({ 416, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_in_left_top({ 160, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_rTop({ 256, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_in_right_top({ 224, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_lTop({ 288, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_out_left_top({ 352, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_in_right_top({ 448, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_lTop({ 128, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_rTop({ 480, 64 });
    staticObjects.push_back(obj);
    obj = new Wall_middle_bottom({ 192, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_in_left_bottom({ 160, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_out_right_bottom({ 352, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_in_right_bottom({ 448, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 288, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_in_left_bottom({ 320, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_out_left_bottom({ 416, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 256, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 480, 96 });
    staticObjects.push_back(obj);
    obj = new Wall_in_right_bottom({ 224, 96 });
    staticObjects.push_back(obj);
    obj = new Chest1({ 334, 123 }, { BuildItem(ITEMLIST::ITEM_EXCALIBUR), BuildItem(ITEMLIST::ITEM_APPLE), BuildItem(ITEMLIST::ITEM_NOTHINGNESS) });
    staticObjects.push_back(obj);
    chests.push_back((Chest*)obj);
    obj = new Wall_high_left({ 256, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 480, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 288, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 128 });
    staticObjects.push_back(obj);
    obj = new Wall_out_left_top({ 288, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_rBottom({ 480, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_out_right_top({ 256, 160 });
    staticObjects.push_back(obj);
    obj = new Wall_out_right_bottom({ 288, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_right({ 128, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_left({ 416, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 416, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bRight({ 448, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_out_left_bottom({ 256, 192 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_lBottom({ 128, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_out_rBottom({ 416, 224 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bRight({ 384, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_bLeft({ 160, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 192, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 224, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 256, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 288, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 320, 256 });
    staticObjects.push_back(obj);
    obj = new Wall_high_top({ 352, 256 });
    staticObjects.push_back(obj);

    sort(staticObjects.begin(), staticObjects.end(), isLower);

    //Hitboxes
    staticSolidMap.push_back(new hitbox(160, 124, 96.5, -72));
    staticSolidMap.push_back(new hitbox(257.5, 218.5, 61.5, -178));
    staticSolidMap.push_back(new hitbox(156.5, 260, 263.5, 66.5));
    staticSolidMap.push_back(new hitbox(158, 257, -54, -218.5));
    staticSolidMap.push_back(new hitbox(154, 257.5, 13.5, -9));
    staticSolidMap.push_back(new hitbox(319.5, 123.5, 63, -124.5));
    staticSolidMap.push_back(new hitbox(417, 123, 67.5, -122.5));
    staticSolidMap.push_back(new hitbox(420.5, 260, -11, -10));
    staticSolidMap.push_back(new hitbox(416, 197, 71, 61));
    staticSolidMap.push_back(new hitbox(480, 74.5, 81.5, 129));
    staticSolidMap.push_back(new hitbox(473.5, 186, 19.5, 15));

    //Leave points

    //Triggers
    Trigger* trig;
}

void MapLevel0::uniqueLogic()
{
    
}
