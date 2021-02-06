#include "ElementBattleMessageBox.h"

ElementBattleMessageBox::ElementBattleMessageBox(GameCore* nGameCore, const Vector2& nPos, const vector<Mix_Chunk*>& nSymbolSfx)
{
	pos = nPos;
	size.x = 640 - pos.x * 2 - 16;
	size.y = 54;

	gameCore = nGameCore;
	enabled = false;
	currentMessage = NULL;
	symbolSfx = nSymbolSfx;
}

void ElementBattleMessageBox::pushMessages(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId)
{
	for (int i = 0; i < multilines.size(); i++)
	{
		messages.push(new AnimatedTextMultiline(multilines[i], font, GameCore::TOP, GameCore::LEFT, gameCore, nPeriod, nLinePeriod, 20, symbolSfx[voiceId]));
	}
	enabled = true;
	peekNextMessage();
}

void ElementBattleMessageBox::draw()
{
	if (enabled)
	{
		gameCore->drawDarkWindow(pos, size);
		currentMessage->draw(pos + Vector2{ 12.0f, 7.0f });
	}
}

void ElementBattleMessageBox::input()
{
	if (!enabled) return;
	if (!currentMessage->isWritten)
		currentMessage->skip();
	else
	{
		delete currentMessage;
		peekNextMessage();
	}
}

void ElementBattleMessageBox::peekNextMessage()
{
	if (!messages.empty())
	{
		currentMessage = messages.front();
		messages.pop();
	}
	else
	{
		enabled = false;
	}
}