#pragma once
#include "GameCore.h"

class Background
{
public:
	Background(GameCore* nGameCore);

	virtual void draw() = 0;

protected:
	GameCore* gameCore;
};