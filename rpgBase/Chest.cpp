#include "Chest.h"

Chest::Chest(const Vector2& nPos, const vector<Item*>& nInv) :
	Object(nPos)
{
	hBox = hitbox{0, 16, 32, 32} + pos;
	inventory = nInv;
}

bool Chest::isCollide(const hitbox& pHBox)
{
	return hBox.isCollideWith(pHBox);
}
