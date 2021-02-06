#include "AnimatedTextLine.h"

AnimatedTextLine::AnimatedTextLine(string str, int nFont, GameCore::ALIGN_VER nVAlign, GameCore::ALIGN_HOR nHAlign, GameCore* nGameCore, int nPeriod, Mix_Chunk* nVoice)
{
	gameCore = nGameCore;
	line = "";
	lineFull = str;
	font = nFont;

	vAlign = nVAlign;
	hAlign = nHAlign;

	voice = nVoice;

	period = nPeriod;
	reset();
}

AnimatedTextLine::~AnimatedTextLine()
{

}

void AnimatedTextLine::draw(const Vector2& pos)
{
	if (!isWritten)
	{
		++timer;
		if (timer == period)
		{
			line += lineFull[currentChar];
			Mix_PlayChannel(-1, voice, 0);
			++currentChar;
			timer = 0;
		}
		if (lineFull[currentChar] == '\0')
		{
			isWritten = true;
		}
	}
	gameCore->quickDrawText(line.c_str(), pos, font, vAlign, hAlign);
}

void AnimatedTextLine::reset()
{
	isWritten = false;
	currentChar = 0;
	line = "";
	timer = 0;
}

void AnimatedTextLine::skip()
{
	isWritten = true;
	currentChar = lineFull.size();
	line = lineFull;
	timer = 0;
}