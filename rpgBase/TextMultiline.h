#pragma once
#include "GameCore.h"

class TextMultiline
{
public:
	TextMultiline(GameCore *nGameCore, vector<string>* nLines, int nFont, int nGap, int nLinesToShow);

	void inputUp();
	void inputDown();

	void draw(const Vector2& pos);

	~TextMultiline();
private:
	GameCore *gameCore;
	vector<string>* lines;
	int font;
	int gap;
	int size;
	int currentLine;
	int linesToShow;
};