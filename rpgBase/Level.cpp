#include "Level.h"

Level::Level(const Vector2& nSize, Camera* nCam, int nLevelId)
{
	size = nSize;
	cam = nCam;
	isRunning = false;
	inputMethod = INPUT_DEFAULT;
	levelId = nLevelId;
	if (fpsManager == NULL)
		fpsManager = new FPSManager(60);
}

void Level::handleDelayedActions()
{
	for (int i = 0; i < actionList.size(); i++)
	{
		while (i < actionList.size() && !actionList[i]->update())
		{
			delete actionList[i];
			actionList.erase(actionList.begin() + i);
		}
	}
}

bool Level::isLower(const Object* lhs, const Object* rhs)
{
	return lhs->depth < rhs->depth;
}
