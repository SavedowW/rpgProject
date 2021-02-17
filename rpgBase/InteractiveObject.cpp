#include "InteractiveObject.h"

InteractiveObject::InteractiveObject(const Vector2& nPos, const hitbox& nHBox, int** nTarget) :
	Object(nPos)
{
	hBox = nHBox;
	target = nTarget;
}

bool InteractiveObject::checkCollision(const hitbox& pHBox)
{
	bool cond = hBox.isCollideWith(pHBox);
	if (cond)
	{
		*target = new int(targetScene);
	}
	return cond;
}