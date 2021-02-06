#pragma once
#include "AnimatedTextLine.h"

class AnimatedTextMultiline
{
public:
	AnimatedTextMultiline(vector<string> strs, int font, GameCore::ALIGN_VER nVAlign, GameCore::ALIGN_HOR nHAlign, GameCore* nGameCore, int nPeriod, int nLinePeriod, int nGap, Mix_Chunk* nVoice = NULL);
	~AnimatedTextMultiline();
	void draw(const Vector2& pos);
	void reset();
	void skip();

	bool isWritten;

private:
	vector<AnimatedTextLine*> lines;
	int gap;
	int size;
	int printedChars;
	int linePeriod;
	int timer;
	int currentLine;
};