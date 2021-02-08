#include "ElementMessageBox.h"

ElementMessageBox::ElementMessageBox(GameCore* nGameCore, const Vector2& nPos, const vector<Mix_Chunk*>& nSymbolSfx)
{
	pos = nPos;
	size.x = 640 - pos.x * 2 - 16;
	size.y = 54;

	gameCore = nGameCore;
	enabled = false;
	currentMessage = NULL;
	symbolSfx = nSymbolSfx;
}

void ElementMessageBox::pushMessages(const vector<vector<string>> &multilines, int font, int nPeriod, int nLinePeriod, int voiceId)
{
	for (int i = 0; i < multilines.size(); i++)
	{
		messages.push(new Message(Message::RQ_MESSAGE, new AnimatedTextMultiline(multilines[i], font, GameCore::TOP, GameCore::LEFT, gameCore, nPeriod, nLinePeriod, 20, symbolSfx[voiceId])));
	}

	if (enabled == false)
	{
		enabled = true;
		peekNextMessage();
	}
}

void ElementMessageBox::pushQuestionMultiselect(vector<string>* options, int** nTarget)
{
	ElementMenuVSelect* meh = new ElementMenuVSelect(gameCore, options, pos + Vector2{ 12.0f, 7.0f }, 13, 12, 20, 3);
	Message* msg = new Message(Message::RQ_QUESTION_MULTISELECT, meh, nTarget);
	messages.push(msg);

	if (enabled == false)
	{
		enabled = true;
		peekNextMessage();
	}
}

void ElementMessageBox::draw()
{
	if (enabled)
	{
		gameCore->drawDarkWindow(pos, size);
		if (currentMessage->request == Message::RQ_MESSAGE)
		{
			currentMessage->text->draw(pos + Vector2{ 12.0f, 7.0f });
		}
		else if (currentMessage->request == Message::RQ_QUESTION_MULTISELECT)
		{
			currentMessage->options->draw();
		}
	}
}

void ElementMessageBox::inputUp()
{
	if (!enabled) return;
	if (currentMessage->request == Message::RQ_QUESTION_MULTISELECT)
	{
		currentMessage->options->inputUp();
	}
}

void ElementMessageBox::inputDown()
{
	if (!enabled) return;
	if (currentMessage->request == Message::RQ_QUESTION_MULTISELECT)
	{
		currentMessage->options->inputDown();
	}
}

void ElementMessageBox::inputEnter()
{
	if (!enabled) return;
	if (currentMessage->request == Message::RQ_MESSAGE && !currentMessage->text->isWritten)
		currentMessage->text->skip();
	else if (currentMessage->request == Message::RQ_MESSAGE)
	{
		delete currentMessage;
		peekNextMessage();
	}
	else if (currentMessage->request == Message::RQ_QUESTION_MULTISELECT)
	{
		*(currentMessage->target) = new int(currentMessage->options->inputEnter());
		delete currentMessage;
		peekNextMessage();
	}
}

void ElementMessageBox::peekNextMessage()
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