#pragma once
#include "Core.h"
#include "Transition1.h"
#include "Transition2.h"

class TransitionSystem
{
public:
	enum TransitionList { TR_MAPLEVEL, TR_BATTLELEVEL, TR_NONE } currentTransition;

	TransitionSystem(Core* nCore);
	bool draw();
	void setState(Transition::State nState);
	void setTransition(TransitionList nTrans);

private:
	Core* core;
	Transition* transitions[TR_NONE];

};