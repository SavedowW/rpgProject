#pragma once
#include "Background.h"

class Background2 :
    public Background
{
public:
    Background2(GameCore* nGameCore);

    void draw();

private:
    float timer;
    float scaler1;
    float scaler2;
};