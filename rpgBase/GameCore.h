#pragma once
#include "Core.h"
#include "Player.h"
#include "Camera.h"
#include "AnimatedTexture.h"
#include "Font.h"
#include <sstream>

class GameCore
{
public:
	GameCore(Core* nCore);

	//Render target control
	enum RENDERMODE {RM_LEVEL = 0, RM_QUICKHUD = 1, RM_HUD = 2} renderMode;
	void setRenderMode(RENDERMODE nRenderMode);
	void setCam(Camera* nCam);
	void deleteCam();

	//Texture load
	SDL_Texture* loadTexture(const char* file);
	SDL_Texture* createText(const char* textureText, SDL_Color textColor, int fontId);
	SDL_Texture* createTextureFromSurface(SDL_Surface* sur);

	//Drawing
	void drawObject(Object* object);
	void drawHBox(const hitbox &hBox, const SDL_Color &col);
	void drawTexture(SDL_Texture* tex, const Vector2 &pos);
	void drawWindow(const Vector2 &pos, const Vector2 &size);
	void drawDarkWindow(const Vector2 &pos, const Vector2 &size);
	void resetScreen();
	void updateScreen();
	int registerFont(const char* s, int fHeight, const SDL_Color& col);

	//Primitives
	void drawFilledRect(Vector2 pos, Vector2 size, SDL_Color col);
	void drawPoint(Vector2 pos, float size, SDL_Color col);
	void drawLine(Vector2 p1, Vector2 p2, SDL_Color col);

	//Text
	enum ALIGN_VER { TOP, VCENTER, BOTTOM };
	enum ALIGN_HOR { LEFT, HCENTER, RIGHT };
	void quickDrawText(const char* s, const Vector2& pos, int font, ALIGN_VER vAlign, ALIGN_HOR hAlign, int hAmp = 0, int vAmp = 0);

	//Type functions
	string floatToString(float val, int nums);
	string intToString(int val);

	//Transition control
	bool drawTransitionBattle(bool in);
	void resetTransition();

	//Sounds
	enum Sounds {SFX_HIT1, SFX_HIT2, SFX_HEAL, SFX_BATTLEBEGIN_P1, SFX_BATTLEBEGIN_P2, SND_NONE};
	Mix_Chunk* loadSfx(const char* file, int volume);
	void playSfx(Sounds snd);

	//Music
	enum Music { 
		MUS_DUNGEON, 
		MUS_MAP1,
		MUS_BATTLE1,
		MUS_BATTLE2,
		MUS_NONE };
	Music currentTheme;
	void playMusic(Music musToPlay, bool forceRestart = false);
	void playMusicFaded(Music musToPlay, int ms, bool forceRestart = false);
	void stopMusic(int fadeOut = 1);

private:
	Core* core;
	SDL_Texture* rm_level;
	SDL_Texture* rm_quickHud;
	SDL_Texture* rm_hud;
	Camera* cam;
	vector<Font*> fonts;
	int shakeRate;

	int cornerSize;
	int borderWidth;

	SDL_Texture* s_cornerTL;
	SDL_Texture* s_cornerTR;
	SDL_Texture* s_cornerBL;
	SDL_Texture* s_cornerBR;
	SDL_Color borderColor;
	SDL_Color innerColor;

	int darkCornerSize;
	int darkBorderWidth;

	SDL_Texture* s_darkCornerTL;
	SDL_Texture* s_darkCornerTR;
	SDL_Texture* s_darkCornerBL;
	SDL_Texture* s_darkCornerBR;
	SDL_Color darkBorderColor;
	SDL_Color darkInnerColor;

	float target1;
	const int bTransitionX = 8;
	const int bTransitionY = 4;

	Mix_Chunk* soundlist[SND_NONE];
	Mix_Music* musiclist[MUS_NONE];
};