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

SDL_Texture* Wall_out_right_bottom::spr_idle = NULL;
SDL_Texture* Floor1::spr_idle = NULL;
SDL_Texture* Wall_out_left_bottom::spr_idle = NULL;
SDL_Texture* Wall_out_right_top::spr_idle = NULL;
SDL_Texture* Wall_out_left_top::spr_idle = NULL;
SDL_Texture* Wall_high_right::spr_idle = NULL;
SDL_Texture* Wall_high_left::spr_idle = NULL;
SDL_Texture* Wall_in_left_bottom::spr_idle = NULL;
SDL_Texture* Wall_in_left_top::spr_idle = NULL;
SDL_Texture* Wall_high_out_lTop::spr_idle = NULL;
SDL_Texture* Wall_high_out_rTop::spr_idle = NULL;
SDL_Texture* Wall_high_out_lBottom::spr_idle = NULL;
SDL_Texture* Wall_in_right_bottom::spr_idle = NULL;
SDL_Texture* Wall_in_right_top::spr_idle = NULL;
SDL_Texture* Wall_middle_bottom::spr_idle = NULL;
SDL_Texture* Wall_middle_top::spr_idle = NULL;
SDL_Texture* Floor_cLeft::spr_idle = NULL;
SDL_Texture* Floor_cRight::spr_idle = NULL;
SDL_Texture* Wall_high_out_rBottom::spr_idle = NULL;
SDL_Texture* Wall_high_top::spr_idle = NULL;
SDL_Texture* Wall_high_bRight::spr_idle = NULL;
SDL_Texture* Wall_high_bLeft::spr_idle = NULL;
SDL_Texture* Chest1::spr_idle = NULL;
