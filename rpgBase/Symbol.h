#pragma once
#include "Core.h"

class Symbol
{
public:
	Symbol(Core* core, char ch, TTF_Font* font, const SDL_Color& col);
	SDL_Texture* getTexture();
	int w, h;

private:
	SDL_Texture* tex;
};