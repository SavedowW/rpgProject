#pragma once
#include "Background.h"

class Background1 :
    public Background
{
public:
    Background1(GameCore* nGameCore);

    void draw();

private:
    float timer;
    float scaler1;
    float scaler2;
};