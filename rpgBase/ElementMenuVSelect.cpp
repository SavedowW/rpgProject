#include "ElementMenuVSelect.h"

ElementMenuVSelect::ElementMenuVSelect(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos, int nFontSelected, int nFontUnselected, int nGap, int nLinesToPrint)
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

void ElementMenuVSelect::inputUp()
{
	if (toggle > 0)
	{
		--toggle;
		if (toggle < firstLine)
			firstLine = toggle;
	}
}

void ElementMenuVSelect::inputDown()
{
	if (toggle < size)
	{
		++toggle;
		if (toggle > firstLine + linesToPrint - 1)
			firstLine++;
	}
}

int ElementMenuVSelect::inputEnter()
{
	return toggle;
}

void ElementMenuVSelect::reset(int base)
{
	toggle = base;
	firstLine = base;
}

void ElementMenuVSelect::draw()
{
	Vector2 aPos = pos;
	for (int i = firstLine; i <= size && i < firstLine + linesToPrint; i++)
	{
		if (toggle == i)
			gameCore->quickDrawText((*options)[i].c_str(), aPos, fontSelected, GameCore::TOP, GameCore::LEFT);
		else
			gameCore->quickDrawText((*options)[i].c_str(), aPos, fontUnselected, GameCore::TOP, GameCore::LEFT);
		aPos += {0, (float)gap};
	}
}

ElementMenuVSelect::~ElementMenuVSelect()
{
	delete options;
}