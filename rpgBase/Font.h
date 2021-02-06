#pragma once
#include "Symbol.h"

class Font
{
public:
	Font(Core* core, const char* s, int fHeight, const SDL_Color& col);
	Symbol* getSymbol(char ch);
	TTF_Font* font;
	int h;

private:
	Symbol* symbols[256];
};