#pragma once
#include "GameCore.h"

class ElementMenuVSwitch
{
public:
	ElementMenuVSwitch(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2 &nPos, int nFontSelected, int nFontUnselected, int nGap, int nSelectGap, int nAddDown, int nAddUp);

	void inputUp();
	void inputDown();
	int inputEnter();

	void reset(int base = 0);
	void draw();

	~ElementMenuVSwitch();

	int toggle;
private:
	GameCore* gameCore;

	std::vector<string> *options;
	Vector2 pos;

	int fontSelected;
	int fontUnselected;

	int gap;
	int selectGap;


	int size;
	int additionalDown;
	int additionalUp;
};