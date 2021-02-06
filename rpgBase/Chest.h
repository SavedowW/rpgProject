#pragma once
#include "Object.h"
#include "ItemTypeH.h"

class Chest: public Object
{
public:
	Chest(const Vector2& nPos, const vector<Item*> &nInv);

	bool isCollide(const hitbox& pHBox);

	hitbox hBox;

	vector<Item*> inventory;
};