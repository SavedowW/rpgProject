#include "TransitionSystem.h"

TransitionSystem::TransitionSystem(Core* nCore)
{
	core = nCore;
	currentTransition = TR_NONE;

	transitions[TR_MAPLEVEL] = new Transition1(core);
	transitions[TR_BATTLELEVEL] = new Transition2(core);
}

bool TransitionSystem::draw()
{
	if (currentTransition != TR_NONE)
	{
		return transitions[currentTransition]->draw();
	}
	return true;
}

void TransitionSystem::setState(Transition::State nState)
{
	transitions[currentTransition]->setState(nState);
}

void TransitionSystem::setTransition(TransitionList nTrans)
{
	currentTransition = nTrans;
}
