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

//In-battle enemies sprites 
SDL_Texture* Wyvern::spr_idle = NULL;

AnimatedTexture* Monitor::spr_idle = NULL;
SDL_Texture* Grass1::spr_idle = NULL;
SDL_Texture* Chest1::spr_idle = NULL;
