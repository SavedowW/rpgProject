#pragma once
#include "GameCore.h"

class FPSManager
{
public:
	FPSManager(int targetFPS);
	void beginFrame();
	Uint32 delayFrame();

private:
	float targetPeriod;
	Uint32 timeBegin;
};