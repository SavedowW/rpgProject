//========================
//
//		Enemy.h
//		Base class with variables and functions, required to represent enemy in battle
//		Must be used in pair with Character, with an exception of Player
//
//========================
#pragma once
#include "Character.h"
#include "GameCore.h"

class Enemy : public Character
{
public:
	virtual void draw() = 0;
	virtual vector<vector<string>> appearanceText() = 0;

protected:
	GameCore* gameCore;
	Vector2 pos;
	Vector2 offset;
	float timer;
	float period;
};