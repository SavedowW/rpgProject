#pragma once
#include "GameCore.h"

class AnimatedTextLine
{
public:
	AnimatedTextLine(string str, int nFont, GameCore::ALIGN_VER nVAlign, GameCore::ALIGN_HOR nHAlign, GameCore* nGameCore, int nPeriod, Mix_Chunk* nVoice = NULL);
	~AnimatedTextLine();
	void draw(const Vector2 &pos);
	void reset();
	void skip();

	bool isWritten;

private:
	GameCore* gameCore;
	string lineFull;
	string line;
	GameCore::ALIGN_VER vAlign;
	GameCore::ALIGN_HOR hAlign;
	int currentChar;
	int font;
	int period;
	int timer;
	Mix_Chunk* voice;
};