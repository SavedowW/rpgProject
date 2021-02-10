#pragma once
#include "GameCore.h"

class ElementBar
{
public:
	ElementBar(const Vector2 &nPos, const Vector2& nSize, GameCore* nGameCore, int *nVal, int *nMaxVal, const SDL_Color& nCol_bar, const SDL_Color& nCol_back, int nfont);

	void draw();

private:
	Vector2 pos;
	Vector2 size;
	GameCore* gameCore;
	int* value;
	int* maxValue;
	SDL_Color col_bar;
	SDL_Color col_back;
	int font;
};