#include "Font.h"

Font::Font(Core* core, const char* s, int fHeight, const SDL_Color& col)
{
	font = core->createFont(s, fHeight);
	for (int i = 0; i < 256; i++)
	{
		symbols[i] = new Symbol(core, char(i), font, col);
	}
	h = fHeight;
}

Symbol* Font::getSymbol(char ch)
{
	return symbols[ch];
}
