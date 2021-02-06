#pragma once
#include "AnimatedTextMultiline.h"
#include <queue>
#include "ElementMenuVSelect.h"

struct Message
{
	enum RQType {RQ_MESSAGE, RQ_QUESTION_MULTISELECT} request;
	AnimatedTextMultiline* text;
	ElementMenuVSelect* options;
	int** target;
	Message(RQType nRequest, AnimatedTextMultiline* nText)
	{
		request = nRequest;
		text = nText;
		options = NULL;
		target = NULL;
	}
	Message(RQType nRequest, ElementMenuVSelect* nOptions, int** nTarget)
	{
		request = nRequest;
		text = NULL;
		options = nOptions;
		target = nTarget;
	}
	~Message()
	{
		if (text != NULL)
			delete text;
		if (options != NULL)
			delete options;
	}
};

class ElementMessageBox
{
public:
	ElementMessageBox(GameCore *nGameCore, const Vector2 &nPos, const vector<Mix_Chunk*> &nSymbolSfx);
	void pushMessages(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);
	void pushQuestionMultiselect(vector<string>* options, int** nTarget);
	void draw();
	void inputEnter();
	void inputUp();
	void inputDown();
	bool enabled;

private:
	void peekNextMessage();
	Vector2 pos;
	Vector2 size;
	GameCore *gameCore;
	Message* currentMessage;
	queue<Message*> messages;
	vector<Mix_Chunk*> symbolSfx;
};