#pragma once
#include "Transition.h"

class Transition1 :
    public Transition
{
public:
    Transition1(Core* nCore);
    virtual bool draw();

protected:
    virtual void reset();
    int timer;
    SDL_Texture* spr_transition;
    const int transitionPeriod = 30;
};