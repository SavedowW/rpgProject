#include "FPSManager.h"

FPSManager::FPSManager(int targetFPS)
{
	targetPeriod = 1.0f / targetFPS * 1000.0f;
	timeBegin = 0;
}

void FPSManager::beginFrame()
{
	timeBegin = SDL_GetTicks();
}

Uint32 FPSManager::delayFrame()
{
	float delay = targetPeriod - (SDL_GetTicks() - timeBegin);
	if (delay < 0)
		return 0;
	else
		return delay;
}
