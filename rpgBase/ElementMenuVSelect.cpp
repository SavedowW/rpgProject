#include "ElementMenuVSelect.h"

ElementMenuVSelect::ElementMenuVSelect(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos,
	int nFontSelected, int nFontUnselected, int nGap, int nLinesToPrint,
	GameCore::ALIGN_VER nVAl, GameCore::ALIGN_HOR nHAl)
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

	vAl = nVAl;
	hAl = nHAl;
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
			gameCore->quickDrawText((*options)[i].c_str(), aPos, fontSelected, vAl, hAl);
		else
			gameCore->quickDrawText((*options)[i].c_str(), aPos, fontUnselected, vAl, hAl);
		aPos += {0, (float)gap};
	}
}

ElementMenuVSelect::~ElementMenuVSelect()
{
	delete options;
}