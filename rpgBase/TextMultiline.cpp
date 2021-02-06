#include "TextMultiline.h"

TextMultiline::TextMultiline(GameCore* nGameCore, vector<string>* nLines, int nFont, int nGap, int nLinesToShow)
{
	gameCore = nGameCore;
	lines = nLines;

	font = nFont;
	gap = nGap;

	size = lines->size() - 1;
	currentLine = 0;
	linesToShow = nLinesToShow;
}

void TextMultiline::inputUp()
{
	if (currentLine > 0)
		currentLine--;
}

void TextMultiline::inputDown()
{
	if (currentLine + linesToShow - 1 < size)
		currentLine++;
}

void TextMultiline::draw(const Vector2& pos)
{
	Vector2 cpos = pos;
	for (int i = currentLine; i <= size && i <= currentLine + linesToShow - 1; i++)
	{
		gameCore->quickDrawText((*lines)[i].c_str(), cpos, font, GameCore::TOP, GameCore::LEFT);
		cpos += {0, (float)gap};
	}
}

TextMultiline::~TextMultiline()
{
	delete lines;
}