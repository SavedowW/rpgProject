#include "ElementMenuVSwitch.h"

ElementMenuVSwitch::ElementMenuVSwitch(GameCore* nGameCore, std::vector<string>* nOptions, const Vector2& nPos, int nFontSelected, int nFontUnselected, int nGap, int nSelectGap, int nAddDown, int nAddUp)
{
	gameCore = nGameCore;

	options = nOptions;
	pos = nPos;

	fontSelected = nFontSelected;
	fontUnselected = nFontUnselected;

	gap = nGap;
	selectGap = nSelectGap;

	toggle = 0;

	size = options->size()-1;
	additionalDown = nAddDown;
	additionalUp = nAddUp;

}

void ElementMenuVSwitch::inputUp()
{
	if (toggle > 0)
		toggle--;
}

void ElementMenuVSwitch::inputDown()
{
	if (toggle < size)
		toggle++;
}

int ElementMenuVSwitch::inputEnter()
{
	if (size >= 0)
		return toggle;
	else
		return -1;
}

void ElementMenuVSwitch::reset(int base)
{
	toggle = base;
	if (toggle > size)
		toggle = size;
	else if (toggle < 0)
		toggle = 0;
}

void ElementMenuVSwitch::draw()
{
	if (size < 0)
		return;
	for (int i = max(toggle - additionalUp, 0); i < toggle; i++)
	{
		gameCore->quickDrawText((*options)[i].c_str(), pos + Vector2{0, float(gap * (i - toggle + additionalUp))}, fontUnselected, GameCore::VCENTER, GameCore::LEFT);
	}

	Vector2 togglePos;
	if (additionalUp == 0)
		togglePos = pos;
	else
		togglePos = pos + Vector2{0, float(gap * (additionalUp - 1) + selectGap)};
	gameCore->quickDrawText((*options)[toggle].c_str(), togglePos, fontSelected, GameCore::VCENTER, GameCore::LEFT);

	togglePos += {0, (float)selectGap};
	for (int i = toggle + 1; i <= size && i <= toggle + additionalDown; i++)
	{
		gameCore->quickDrawText((*options)[i].c_str(), togglePos + Vector2{ 0, float(gap * (i - toggle - 1) )}, fontUnselected, GameCore::VCENTER, GameCore::LEFT);
	}
}

ElementMenuVSwitch::~ElementMenuVSwitch()
{
	delete options;
}