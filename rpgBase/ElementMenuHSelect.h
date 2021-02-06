#pragma once
#include "GameCore.h"

class ElementMenuHSelect
{
public:
	ElementMenuHSelect(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos, int nFontSelected, int nFontUnselected, int nGap, int nLinesToPrint);

	void inputLeft();
	void inputRight();
	int inputEnter();

	void reset(int base = 0);
	void draw();

	~ElementMenuHSelect();

	int toggle;

private:

	GameCore* gameCore;

	std::vector<string>* options;
	Vector2 pos;

	int fontSelected;
	int fontUnselected;

	int gap;
	int linesToPrint;

	int size;
	int firstLine;
};