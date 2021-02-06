#pragma once
#include "Core.h"
#include <vector>

class AnimatedTexture
{

public:
	//Folder with data.txt, example "sprites/anim1"
	AnimatedTexture(const char* templateName, Core* core, float nT, int nCycles = -1, bool startFinished = false);
	SDL_Texture* getSprite();
	~AnimatedTexture();
	void update();
	void reset();
	SDL_Texture* operator[](const int& id);
private:
	std::vector<SDL_Texture*> sprites;
	int period;
	int timer;
	int completeIter;
	int cyclesMax;
	int cyclesDone;
};