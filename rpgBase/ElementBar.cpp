#include "ElementBar.h"

ElementBar::ElementBar(const Vector2& nPos, const Vector2& nSize, GameCore* nGameCore, int* nVal, int* nMaxVal, const SDL_Color& nCol_bar, const SDL_Color& nCol_back, int nfont)
{
	pos = nPos;
	size = nSize;
	gameCore = nGameCore;
	value = nVal;
	maxValue = nMaxVal;
	col_bar = nCol_bar;
	col_back = nCol_back;
	font = nfont;
}

void ElementBar::draw()
{
	gameCore->drawFilledRect(pos, size, col_bar);
	gameCore->drawFilledRect(pos + Vector2{ 1, 1 }, size - Vector2{2, 2}, col_back);
	gameCore->drawFilledRect(pos + Vector2{ 2, 2 }, Vector2{(size.x - 4) * (float(*value) / float(*maxValue)), size.y - 4}, col_bar);
	string line = gameCore->intToString(*value) + "/" + gameCore->intToString(*maxValue);
	gameCore->quickDrawText(line.c_str(), pos + (size / 2), font, GameCore::VCENTER, GameCore::HCENTER);
}