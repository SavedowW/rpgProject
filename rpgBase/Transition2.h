#pragma once
#include "Transition.h"
class Transition2 :
    public Transition
{
public:
    Transition2(Core* nCore);
    virtual bool draw();

protected:
    virtual void reset();
    float target1;
    const int bTransitionX = 8;
    const int bTransitionY = 4;
    const int length = 10;
};

