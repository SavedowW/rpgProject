#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture(const char* templateName, Core* core, float nT, int nCycles, bool startFinished)
{
	int cnt;
	//std::cout << std::string(templateName + std::string("/data.txt")) << std::endl;
	std::ifstream dataFile(std::string(templateName + std::string("/data.txt")));
	std::string templateSprite;
	dataFile >> templateSprite;
	dataFile >> cnt;
	dataFile.close();
	AnimatedTexture::period = nT * 60;
	for (int i = 1; i <= cnt; i++) {
		SDL_Texture* temp = core->loadTexture(std::string(templateName + templateSprite + std::to_string(i) + ".png").c_str());
		sprites.push_back(temp);
	}
	timer = 0;
	completeIter = period * sprites.size();
	cyclesMax = nCycles;
	cyclesDone = 0;
	if (startFinished)
		cyclesDone = cyclesMax;
}

SDL_Texture* AnimatedTexture::getSprite()
{
	if (cyclesMax == -1 || cyclesDone < cyclesMax)
		return sprites[int(timer / period)];
	else
		return sprites[sprites.size() - 1];
}

AnimatedTexture::~AnimatedTexture()
{
	for (int i = 0; i < sprites.size(); i++) {
		if (sprites[i] != nullptr) {
			SDL_DestroyTexture(sprites[i]);
			sprites[i] = nullptr;
		}
	}
}

void AnimatedTexture::update()
{
	if (cyclesMax == -1 || cyclesDone < cyclesMax)
		timer++;
	if (timer == completeIter)
	{
		timer = 0;
		cyclesDone++;
	}
}

void AnimatedTexture::reset()
{
	timer = 0;
	cyclesDone = 0;
}

SDL_Texture* AnimatedTexture::operator[](const int& id)
{
	if (id < sprites.size())
		return sprites[id];
	else
		return NULL;
}
