#include "LevelsH.h"

std::vector<AnimatedTexture*> *MapLevel::textureList = NULL;
Core * Object::core = NULL;
SDL_Texture* Player::spr_idle = NULL;
Player* Level::player = NULL;
GameCore* Level::gameCore = NULL;
SDL_Texture* MapLevel::spr_transition = NULL;
BattleRequest Level::battleRequest = {NULL, 0, 0};
LevelHUD* MapLevel::levelHud = NULL;
Player* Trigger::player = NULL;
SDL_Texture* Wyvern::spr_idle = NULL;

//In-battle enemies sprites 
//<add here>

SDL_Texture* Floor_cLeft::spr_idle = NULL;
SDL_Texture* Floor_cRight::spr_idle = NULL;
SDL_Texture* Floor::spr_idle = NULL;
SDL_Texture* Wall_bottom::spr_idle = NULL;
SDL_Texture* Wall_cLeftIn_bottom::spr_idle = NULL;
SDL_Texture* Wall_cLeftIn_middle::spr_idle = NULL;
SDL_Texture* Wall_cLeftIn_top::spr_idle = NULL;
SDL_Texture* Wall_cLeftOut_bottom::spr_idle = NULL;
SDL_Texture* Wall_cLeftOut_middle::spr_idle = NULL;
SDL_Texture* Wall_cLeftOut_top::spr_idle = NULL;
SDL_Texture* Wall_cRightIn_bottom::spr_idle = NULL;
SDL_Texture* Wall_cRightIn_middle::spr_idle = NULL;
SDL_Texture* Wall_cRightIn_top::spr_idle = NULL;
SDL_Texture* Wall_cRightOut_bottom::spr_idle = NULL;
SDL_Texture* Wall_cRightOut_middle::spr_idle = NULL;
SDL_Texture* Wall_cRightOut_top::spr_idle = NULL;
SDL_Texture* Wall_high_bLeft::spr_idle = NULL;
SDL_Texture* Wall_high_bottom::spr_idle = NULL;
SDL_Texture* Wall_high_bRight::spr_idle = NULL;
SDL_Texture* Wall_high_lBottom::spr_idle = NULL;
SDL_Texture* Wall_high_left::spr_idle = NULL;
SDL_Texture* Wall_high_lTop::spr_idle = NULL;
SDL_Texture* Wall_high_rBottom::spr_idle = NULL;
SDL_Texture* Wall_high_right::spr_idle = NULL;
SDL_Texture* Wall_high_rTop::spr_idle = NULL;
SDL_Texture* Wall_high_top::spr_idle = NULL;
SDL_Texture* Wall_in_duo_bottom::spr_idle = NULL;
SDL_Texture* Wall_in_duo_middle::spr_idle = NULL;
SDL_Texture* Wall_in_duo_top::spr_idle = NULL;
SDL_Texture* Wall_middle::spr_idle = NULL;
SDL_Texture* Wall_top::spr_idle = NULL;
SDL_Texture* Chest1::spr_idle = NULL;
SDL_Texture* Trashcan1::spr_idle = NULL;
SDL_Texture* Floor_cBottomDuo::spr_idle = NULL;
SDL_Texture* Darkness::spr_idle = NULL;
SDL_Texture* Wall_high_bDuo::spr_idle = NULL;
AnimatedTexture* Monitor::spr_idle = NULL;
SDL_Texture* Blader::spr_idle = NULL;
