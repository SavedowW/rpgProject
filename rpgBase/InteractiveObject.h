#pragma once
#include "Object.h"

class InteractiveObject :
    public Object
{
public:
    InteractiveObject(const Vector2& nPos, const hitbox& nHBox, int** nTarget);

    bool checkCollision(const hitbox& pHBox);

    hitbox hBox;

protected:
    int** target;
    int targetScene;
};