#include "Transition.h"

Transition::Transition(Core* nCore)
{
	core = nCore;
	state = State::IN;
	enabled = false;
}

void Transition::setState(State nState)
{
	state = nState;
	reset();
}