#include "Core.h"

bool Core::init()
{
	targetResolution = { 640, 360 };
	currentResolution = targetResolution;

	windowName = "SDL core test";

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization error: " << SDL_GetError() << endl;
		return false;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cout << "IMG initialization error: " << SDL_GetError() << endl;
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 0, 512))
	{
		cout << "MIX ititialization error: " << Mix_GetError() << endl;
	}

	if (TTF_Init() == -1)
	{
		cout << "TTF initialization error: " << TTF_GetError() << endl;
	}

	window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, targetResolution.x, targetResolution.y, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		cout << "Window creation error: " << SDL_GetError() << endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == nullptr) {
		cout << "Renderer creation error: " << SDL_GetError() << endl;
		return false;
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	fsMode = 0;

	return true;
}

void Core::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	IMG_Quit();
	SDL_Quit();
}

void Core::drawFilledRect(Vector2 pos, Vector2 size, SDL_Color col)
{
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
	SDL_Rect rect = { pos.x, pos.y, size.x, size.y };
	SDL_RenderFillRect(renderer, &rect);
}

void Core::drawPoint(Vector2 pos, float size, SDL_Color col)
{
	drawFilledRect({ pos.x - size / 2, pos.y - size / 2 }, { size, size }, col);
}

void Core::drawLine(Vector2 p1, Vector2 p2, SDL_Color col)
{
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
}

SDL_Texture* Core::createTexture(int w, int h)
{
	return SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
}

SDL_Texture* Core::createTexture(Vector2 size)
{
	return SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size.x, size.y);
}

SDL_Texture* Core::loadTexture(const char* file)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, file);
	if (!texture) {
		std::cout << "Texture loading problem: " << file << "  |  " << IMG_GetError() << std::endl;
	}
	return texture;
}

SDL_Texture* Core::createTextureFromSurface(SDL_Surface* sur)
{
	return SDL_CreateTextureFromSurface(renderer, sur);
}

void Core::renderTexture(SDL_Texture* tex, int x, int y, int w, int h)
{
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;

	SDL_RenderCopy(renderer, tex, NULL, &dst);
}

void Core::renderTexture(SDL_Texture* tex, int x, int y)
{
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTexture(tex, x, y, w, h);
}

void Core::renderTextureHorPart(SDL_Texture* tex, int x, int y, int w, int h, float part)
{
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = w * part;
	dst.h = h;

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = w * part;
	src.h = h;

	//cout << "Rendering from " << src.w << " to " << dst.w << endl;

	SDL_RenderCopy(renderer, tex, &src, &dst);
}

void Core::renderTextureHorPart(SDL_Texture* tex, int x, int y, float part)
{
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTextureHorPart(tex, x, y, w, h, part);
}

void Core::fillRenderer(SDL_Color col)
{
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
	SDL_RenderClear(renderer);
}

void Core::updateScreen()
{
	SDL_RenderPresent(renderer);
}

void Core::setFS(int mode)
{
	fsMode = mode;

	if (mode == 1)
	{
		setResolutionForced({640, 360});
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		setResolutionForced(currentResolution);
	}
	else if (mode == 2)
	{
		setResolutionForced({ 640, 360 });
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		setResolutionForced(currentResolution);
	}
	else
	{
		SDL_SetWindowFullscreen(window, 0);
	}
}

void Core::setResolution(Vector2 res)
{
	int mode = fsMode;

	setFS(0);

	currentResolution = res;
	setResolutionForced(res);

	setFS(mode);
}

void Core::setResolutionForced(Vector2 res)
{
	SDL_RenderSetScale(renderer, res.x / targetResolution.x, res.y / targetResolution.y);
	SDL_SetWindowSize(window, res.x, res.y);
}

void Core::setRenderTarget(SDL_Texture* tex)
{
	int i = SDL_SetRenderTarget(renderer, tex);
	if (i != 0)
		std::cout << i << std::endl;
}

void Core::resetRenderTarget()
{
	int i = SDL_SetRenderTarget(renderer, NULL);
	if (i != 0)
		cout << i << endl;
}

TTF_Font* Core::createFont(const char* s, int fHeight)
{
	return TTF_OpenFont(s, fHeight);
}

SDL_Texture* Core::createText(const char* textureText, SDL_Color textColor, TTF_Font* font)
{
	SDL_Surface* textSurface = NULL;
	textSurface = TTF_RenderText_Solid(font, textureText, textColor);
	if (textSurface == NULL)
	{
		std::cout << "textSurface creating error | " << TTF_GetError() << std::endl;
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (texture == NULL)
	{
		cout << "Text texture creating error | " << SDL_GetError() << std::endl;
		return NULL;
	}
	SDL_FreeSurface(textSurface);
	return texture;
}
