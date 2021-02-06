#pragma once
#include "Core.h"
#include "ItemTypeH.h"
#include "Spell.h"
#include "AnimatedTexture.h"
#define Public public

class Object
{
public:
	Vector2 pos;
	float depth;
	bool drawn;

	Object(const Vector2& nPos);
	virtual void update();
	virtual void updateDepth();

	virtual SDL_Texture* getSprite() = 0;

	static Core* core;

protected:
};