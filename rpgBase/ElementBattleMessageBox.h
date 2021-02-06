#pragma once
#include "AnimatedTextMultiline.h"
#include <queue>

class ElementBattleMessageBox
{
public:
	ElementBattleMessageBox(GameCore* nGameCore, const Vector2& nPos, const vector<Mix_Chunk*>& nSymbolSfx);
	void pushMessages(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);
	void draw();
	void input();
	bool enabled;

private:
	void peekNextMessage();
	Vector2 pos;
	Vector2 size;
	GameCore* gameCore;
	queue<AnimatedTextMultiline*> messages;
	AnimatedTextMultiline* currentMessage;
	vector<Mix_Chunk*> symbolSfx;

};