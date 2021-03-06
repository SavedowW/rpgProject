#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_Mixer.h>
#include <SDL_TTF.h>
#include "Vector2.h"
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

extern const int LVLOFFSET;

class Core
{
public:
	Vector2 targetResolution;

	//System
	bool init();
	void close();

	//Primitives
	void drawFilledRect(Vector2 pos, Vector2 size, SDL_Color col);
	void drawPoint(Vector2 pos, float size, SDL_Color col);
	void drawLine(Vector2 p1, Vector2 p2, SDL_Color col);

	//Texture creation
	SDL_Texture* createTexture(int w, int h);
	SDL_Texture* createTexture(Vector2 size);
	SDL_Texture* loadTexture(const char* file);
	SDL_Texture* createTextureFromSurface(SDL_Surface* sur);

	//Texture render
	void renderTexture(SDL_Texture* tex, int x, int y, int w, int h);
	void renderTexture(SDL_Texture* tex, int x, int y);

	//Global render
	void fillRenderer(SDL_Color col);
	void updateScreen();
	void setFS(int mode);
	void setResolution(Vector2 res);
	void setResolutionForced(Vector2 res);
	
	//Render target settings
	void setRenderTarget(SDL_Texture* tex);
	void resetRenderTarget();

	//Fonts
	TTF_Font* createFont(const char* s, int fHeight);
	SDL_Texture* createText(const char* textureText, SDL_Color textColor, TTF_Font* font);

private:
	int fsMode;
	SDL_Renderer* renderer;
	SDL_Window* window;
	Vector2 currentResolution;
	string windowName;
};