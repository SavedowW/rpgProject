#include "ElementMenuHSelect.h"

ElementMenuHSelect::ElementMenuHSelect(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos, int nFontSelected, int nFontUnselected, int nGap, int nLinesToPrint)
{
	gameCore = nGameCore;

	options = nOptions;
	pos = nPos;

	fontSelected = nFontSelected;
	fontUnselected = nFontUnselected;

	gap = nGap;
	linesToPrint = nLinesToPrint;

	toggle = 0;
	firstLine = 0;

	size = options->size() - 1;

}

void ElementMenuHSelect::inputLeft()
{
	if (toggle > 0)
	{
		--toggle;
		if (toggle < firstLine)
			firstLine = toggle;
	}
}

void ElementMenuHSelect::inputRight()
{
	if (toggle < size)
	{
		++toggle;
		if (toggle > firstLine + linesToPrint - 1)
			firstLine++;
	}
}

int ElementMenuHSelect::inputEnter()
{
	return toggle;
}

void ElementMenuHSelect::reset(int base)
{
	toggle = base;
	firstLine = base;
}

void ElementMenuHSelect::draw()
{
	Vector2 aPos = pos;
	for (int i = firstLine; i <= size && i < firstLine + linesToPrint; i++)
	{
		if (toggle == i)
			gameCore->quickDrawText((*options)[i].c_str(), aPos, fontSelected, GameCore::VCENTER, GameCore::HCENTER);
		else
			gameCore->quickDrawText((*options)[i].c_str(), aPos, fontUnselected, GameCore::VCENTER, GameCore::HCENTER);
		aPos += {(float)gap, 0};
	}
}

ElementMenuHSelect::~ElementMenuHSelect()
{
	delete options;
}