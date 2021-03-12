#pragma once
#include "GameCore.h"

class ElementMenuVSelect
{
public:
	ElementMenuVSelect(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos,
		int nFontSelected, int nFontUnselected, int nGap, int nLinesToPrint,
		GameCore::ALIGN_VER nVAl = GameCore::TOP, GameCore::ALIGN_HOR nHAl = GameCore::LEFT);

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

	GameCore::ALIGN_VER vAl;
	GameCore::ALIGN_HOR hAl;
};