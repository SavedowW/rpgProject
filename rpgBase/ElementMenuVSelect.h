#pragma once
#include "GameCore.h"

class ElementMenuVSelect
{
public:
	ElementMenuVSelect(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos, int nFontSelected, int nFontUnselected, int nGap, int nLinesToPrint);

	void inputUp();
	void inputDown();
	int inputEnter();

	void reset(int base = 0);
	void draw();

	~ElementMenuVSelect();

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