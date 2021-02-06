#include "AnimatedTextMultiline.h"

AnimatedTextMultiline::AnimatedTextMultiline(vector<string> strs, int font, GameCore::ALIGN_VER nVAlign, GameCore::ALIGN_HOR nHAlign, GameCore* nGameCore, int nPeriod, int nLinePeriod, int nGap, Mix_Chunk* nVoice)
{
	linePeriod = nLinePeriod;
	gap = nGap;
	size = strs.size();
	for (int i = 0; i < strs.size(); i++)
	{
		lines.push_back(new AnimatedTextLine(strs[i], font, nVAlign, nHAlign, nGameCore, nPeriod, nVoice));
	}
	reset();
}

AnimatedTextMultiline::~AnimatedTextMultiline()
{
	for (int i = 0; i < size; i++)
	{
		delete lines[i];
	}
}

void AnimatedTextMultiline::draw(const Vector2& pos)
{
	for (int i = 0; i <= currentLine; i++)
	{
		if (i == currentLine && timer < linePeriod && !isWritten)
		{
			++timer;
			break;
		}
		lines[i]->draw({ pos + Vector2{0, float(i * gap)} });
	}
	if (lines[currentLine]->isWritten)
	{
		if (currentLine < size - 1)
			++currentLine;
		else
			isWritten = true;
		timer = 0;
	}
	//cout << isWritten << endl;
}

void AnimatedTextMultiline::reset()
{
	isWritten = false;
	timer = linePeriod;
	for (int i = 0; i < size; i++)
	{
		lines[i]->reset();
	}
	currentLine = 0;
}

void AnimatedTextMultiline::skip()
{
	isWritten = true;
	timer = linePeriod;
	for (int i = 0; i < size; i++)
	{
		lines[i]->skip();
	}
	currentLine = size - 1;
}