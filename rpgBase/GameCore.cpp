#include "GameCore.h"

GameCore::GameCore(Core* nCore)
{
	core = nCore;

	renderMode = RM_LEVEL;

	rm_level = core->createTexture(core->targetResolution);
	rm_quickHud = core->createTexture(core->targetResolution);
	rm_hud = core->createTexture(core->targetResolution);

	SDL_SetTextureBlendMode(rm_level, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(rm_quickHud, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(rm_hud, SDL_BLENDMODE_BLEND);

	//Light box setup
	s_cornerTL = loadTexture("Sprites/HUD/s_cornerTL.png");
	s_cornerTR = loadTexture("Sprites/HUD/s_cornerTR.png");
	s_cornerBL = loadTexture("Sprites/HUD/s_cornerBL.png");
	s_cornerBR = loadTexture("Sprites/HUD/s_cornerBR.png");

	int ph;
	SDL_QueryTexture(s_cornerTL, NULL, NULL, &cornerSize, &ph);
	borderWidth = 2;

	borderColor.r = 0x3B;
	borderColor.g = 0x1F;
	borderColor.b = 0x2B;
	borderColor.a = 255;

	innerColor.r = 0xFF;
	innerColor.g = 0xDD;
	innerColor.b = 0xB2;
	innerColor.a = 255;

	//Dark box setup
	s_darkCornerTL = loadTexture("Sprites/HUD/s_darkCornerTL.png");
	s_darkCornerTR = loadTexture("Sprites/HUD/s_darkCornerTR.png");
	s_darkCornerBL = loadTexture("Sprites/HUD/s_darkCornerBL.png");
	s_darkCornerBR = loadTexture("Sprites/HUD/s_darkCornerBR.png");

	SDL_QueryTexture(s_darkCornerTL, NULL, NULL, &darkCornerSize, &ph);
	darkBorderWidth = 2;

	darkBorderColor.r = 0xFF;
	darkBorderColor.g = 0xDD;
	darkBorderColor.b = 0xB2;
	darkBorderColor.a = 255;

	darkInnerColor.r = 0x00;
	darkInnerColor.g = 0x00;
	darkInnerColor.b = 0x00;
	darkInnerColor.a = 255;

	resetTransition();

	shakeRate = 1500;

	//sfx list setup

	soundlist[SFX_HIT1] = loadSfx("SFX/battle/sfx_hit1.wav", 128);
	soundlist[SFX_HIT2] = loadSfx("SFX/battle/sfx_hit2.wav", 128);
	soundlist[SFX_HEAL] = loadSfx("SFX/battle/sfx_heal.wav", 128);
	soundlist[SFX_BATTLEBEGIN_P1] = loadSfx("SFX/sfx_beginBattle_p1.wav", 128);
	soundlist[SFX_BATTLEBEGIN_P2] = loadSfx("SFX/sfx_beginBattle_p2.wav", 128);
}

void GameCore::setRenderMode(RENDERMODE nRenderMode)
{
	renderMode = nRenderMode;
	switch (nRenderMode)
	{
	case (RM_LEVEL):
		core->setRenderTarget(rm_level);
		break;

	case (RM_QUICKHUD):
		core->setRenderTarget(rm_quickHud);
		break;

	case (RM_HUD):
		core->setRenderTarget(rm_hud);
		break;
	}
}

void GameCore::setCam(Camera *nCam)
{
	cam = nCam;

}

void GameCore::deleteCam()
{
	cam = NULL;
}

SDL_Texture* GameCore::loadTexture(const char* file)
{
	return core->loadTexture(file);
}

SDL_Texture* GameCore::createText(const char* textureText, SDL_Color textColor, int fontId)
{
	return core->createText(textureText, textColor, fonts[fontId]->font);
}

SDL_Texture* GameCore::createTextureFromSurface(SDL_Surface* sur)
{
	return core->createTextureFromSurface(sur);
}

Mix_Chunk* GameCore::loadSfx(const char* file, int volume)
{
	Mix_Chunk* sfx = Mix_LoadWAV(file);
	if (sfx == NULL)
	{
		std::cout << "SFX loading problem: " << file << "  |  " << Mix_GetError() << std::endl;
	}
	else sfx->volume = volume;
	return sfx;
}

void GameCore::playSfx(Sounds snd)
{
	Mix_PlayChannel(-1, soundlist[snd], 0);
}

void GameCore::drawObject(Object* object)
{
	if (renderMode == RM_LEVEL && cam != NULL)
	{
		core->renderTexture(object->getSprite(), object->pos.x - cam->getCameraPos().x, object->pos.y - cam->getCameraPos().y);
	}
	else
	{
		core->renderTexture(object->getSprite(), object->pos.x, object->pos.y);
	}
}

void GameCore::drawHBox(const hitbox& hBox, const SDL_Color& col)
{
	if (cam != NULL)
	{
		core->drawFilledRect(Vector2( hBox.x, hBox.y ) - cam->getCameraPos() , { hBox.w, hBox.h }, col);
	}
	else
	{
		core->drawFilledRect({hBox.x, hBox.y}, { hBox.w, hBox.h }, col);
	}
}

void GameCore::drawTexture(SDL_Texture* tex, const Vector2& pos)
{
	if (renderMode == RM_LEVEL && cam != NULL)
	{
		core->renderTexture(tex, pos.x - cam->getCameraPos().x, pos.y - cam->getCameraPos().y);
	}
	else
	{
		core->renderTexture(tex, pos.x, pos.y);
	}
}

void GameCore::drawWindow(const Vector2& pos, const Vector2& size)
{
	core->renderTexture(s_cornerTL, pos.x, pos.y);
	core->renderTexture(s_cornerTR, pos.x + cornerSize + size.x, pos.y);
	core->renderTexture(s_cornerBR, pos.x + cornerSize + size.x, pos.y + cornerSize + size.y);
	core->renderTexture(s_cornerBL, pos.x, pos.y + cornerSize + size.y);

	core->drawFilledRect(Vector2(pos.x + cornerSize, pos.y), Vector2(size.x, size.y + cornerSize * 2), innerColor);
	core->drawFilledRect(Vector2(pos.x, pos.y + cornerSize), Vector2(size.x + cornerSize * 2, size.y), innerColor);

	core->drawFilledRect(Vector2(pos.x + cornerSize, pos.y ), Vector2(size.x, borderWidth), borderColor);
	core->drawFilledRect(Vector2(pos.x + cornerSize, pos.y + cornerSize * 2 + size.y - borderWidth), Vector2(size.x, borderWidth), borderColor);
	core->drawFilledRect(Vector2(pos.x, pos.y + cornerSize), Vector2(borderWidth, size.y), borderColor);
	core->drawFilledRect(Vector2(pos.x + cornerSize * 2 + size.x - borderWidth, pos.y + cornerSize), Vector2(borderWidth, size.y), borderColor);
}

void GameCore::drawDarkWindow(const Vector2& pos, const Vector2& size)
{
	core->renderTexture(s_darkCornerTL, pos.x, pos.y);
	core->renderTexture(s_darkCornerTR, pos.x + darkCornerSize + size.x, pos.y);
	core->renderTexture(s_darkCornerBR, pos.x + darkCornerSize + size.x, pos.y + darkCornerSize + size.y);
	core->renderTexture(s_darkCornerBL, pos.x, pos.y + darkCornerSize + size.y);

	core->drawFilledRect(Vector2(pos.x + darkCornerSize, pos.y), Vector2(size.x, size.y + darkCornerSize * 2), darkInnerColor);
	core->drawFilledRect(Vector2(pos.x, pos.y + darkCornerSize), Vector2(size.x + darkCornerSize * 2, size.y), darkInnerColor);

	core->drawFilledRect(Vector2(pos.x + darkCornerSize, pos.y), Vector2(size.x, darkBorderWidth), darkBorderColor);
	core->drawFilledRect(Vector2(pos.x + darkCornerSize, pos.y + darkCornerSize * 2 + size.y - darkBorderWidth), Vector2(size.x, darkBorderWidth), darkBorderColor);
	core->drawFilledRect(Vector2(pos.x, pos.y + darkCornerSize), Vector2(darkBorderWidth, size.y), darkBorderColor);
	core->drawFilledRect(Vector2(pos.x + darkCornerSize * 2 + size.x - darkBorderWidth, pos.y + darkCornerSize), Vector2(darkBorderWidth, size.y), darkBorderColor);
}

void GameCore::quickDrawText(const char* s, const Vector2& pos, int font, ALIGN_VER vAlign, ALIGN_HOR hAlign, int hAmp, int vAmp)
{
	float w = 0;
	for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != '\r'; i++)
	{
		w += float(fonts[font]->getSymbol(s[i])->w);
	}
	float h = float(fonts[font]->getSymbol(s[0])->h);

	Vector2 offset;
	if (vAlign == TOP)
		offset.y = 0;
	else if (vAlign == VCENTER)
		offset.y = h / 2;
	else if (vAlign == BOTTOM)
		offset.y = h;

	if (hAlign == LEFT)
		offset.x = 0;
	else if (hAlign == HCENTER)
		offset.x = w / 2;
	else if (hAlign == RIGHT)
		offset.x = w;

	Vector2 curPos = pos - offset;

	for (int i = 0; s[i] != '\0' && s[i] != '\r'; i++)
	{
		if (s[i] == '\n')
		{
			curPos.x = pos.x - offset.x;
			curPos.y += h;
			continue;
		}
		Vector2 shakeOffset;
		if (hAmp != 0 && vAmp != 0)
			shakeOffset = Vector2(rand() % hAmp - hAmp / 2, rand() % vAmp - vAmp / 2);
		else if (hAmp != 0 && vAmp == 0)
			shakeOffset = Vector2(rand() % hAmp - hAmp / 2, 0);
		else if (hAmp == 0 && vAmp != 0)
			shakeOffset = Vector2(0, rand() % vAmp - vAmp / 2);

		if (rand() % shakeRate == 0)
			shakeOffset += Vector2((rand() % 4 / 2) * (rand() % 100) / 50.0f, (rand() % 4 / 2) * (rand() % 100) / 50.0f);

		drawTexture(fonts[font]->getSymbol(s[i])->getTexture(), curPos + shakeOffset);
		curPos += Vector2{ float(fonts[font]->getSymbol(s[i])->w), 0};
	}
}

string GameCore::floatToString(float val, int nums)
{
	std::ostringstream ss;
	ss.precision(nums);
	ss << val;
	return ss.str();
}

string GameCore::intToString(int val)
{
	ostringstream ss;
	ss << val;
	return ss.str();
}

void GameCore::resetScreen()
{
	renderMode = RM_LEVEL;

	core->resetRenderTarget();
	core->fillRenderer({ 0, 0, 0, 255 });

	core->setRenderTarget(rm_hud);
	core->fillRenderer({0, 0, 0, 0});

	core->setRenderTarget(rm_quickHud);
	core->fillRenderer({ 0, 0, 0, 0 });

	core->setRenderTarget(rm_level);
	core->fillRenderer({ 0, 0, 0, 0 });
}

void GameCore::updateScreen()
{
	core->resetRenderTarget();

	core->renderTexture(rm_level, 0, 0);
	core->renderTexture(rm_quickHud, 0, 0);
	core->renderTexture(rm_hud, 0, 0);

	core->updateScreen();

	setRenderMode(RM_LEVEL);
}

int GameCore::registerFont(const char* s, int fHeight, const SDL_Color& col)
{
	fonts.push_back(new Font(core, s, fHeight, col));
	return fonts.size() - 1;
}

void GameCore::drawFilledRect(Vector2 pos, Vector2 size, SDL_Color col)
{
	if (cam != NULL || renderMode == RM_HUD)
	{
		core->drawFilledRect(pos - cam->getCameraPos(), size, col);
	}
	else
	{
		core->drawFilledRect(pos, size, col);
	}
}

void GameCore::drawPoint(Vector2 pos, float size, SDL_Color col)
{
	if (cam != NULL || renderMode == RM_HUD)
	{
		core->drawPoint(pos - cam->getCameraPos(), size, col);
	}
	else
	{
		core->drawPoint(pos, size, col);
	}
}

void GameCore::drawLine(Vector2 p1, Vector2 p2, SDL_Color col)
{
	if (cam != NULL || renderMode == RM_HUD)
	{
		core->drawLine(p1 - cam->getCameraPos(), p2 - cam->getCameraPos(), col);
	}
	else
	{
		core->drawLine(p1, p2, col);
	}
}

bool GameCore::drawTransitionBattle(bool in)
{
	setRenderMode(RM_HUD);

	Vector2 partSize = {core->targetResolution.x / bTransitionX, core->targetResolution.y / bTransitionY };

	int cnt = bTransitionX * bTransitionY;

	float length = 10;


	if (in)
	{
		float current = 0;

		for (int i = 0; i < bTransitionX; i++)
		{
			for (int k = 0; k < bTransitionY; k++)
			{
				++current;
				float n = max(target1 - current, 0.0f);
				if (n > length)
					n = length;
				Vector2 size = partSize * (n / length);
				Vector2 pos = { partSize.x * i + (partSize.x - size.x) / 2, partSize.y * k + (partSize.y - size.y) / 2 };
				core->drawFilledRect(pos, size, { 0, 0, 0, Uint8(255.0f * (n / length)) });
			}
		}
		//cout << target1 << endl;
		if (target1 < cnt + length)
		{
			++target1;
			return false;
		}
		else return true;
	}
	else
	{
		float current = cnt;

		for (int i = bTransitionX; i >= 0 ; --i)
		{
			for (int k = bTransitionY; k >= 0; --k)
			{
				--current;
				float n = max(target1 - current, 0.0f);
				if (n > length)
					n = length;
				Vector2 size = partSize * (n / length);
				Vector2 pos = { partSize.x * i + (partSize.x - size.x) / 2, partSize.y * k + (partSize.y - size.y) / 2 };
				core->drawFilledRect(pos, size, { 0, 0, 0, Uint8(255.0f * (n / length)) });
			}
		}
		//cout << target1 << endl;
		if (target1 + length + 2 > 0)
		{
			--target1;
			return false;
		}
		else
		{
			return true;
			target1 = 0;
		}
	}
}

void GameCore::resetTransition()
{
	target1 = 0;
}