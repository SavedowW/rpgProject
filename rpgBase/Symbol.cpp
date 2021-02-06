#include "Symbol.h"

Symbol::Symbol(Core* core, char ch, TTF_Font* font, const SDL_Color& col)
{
	tex = core->createText(&ch, col, font);
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
}

SDL_Texture* Symbol::getTexture()
{
	return tex;
}
