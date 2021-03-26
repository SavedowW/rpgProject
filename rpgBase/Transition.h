#pragma once
#include "Core.h"

class Transition
{
public:
	enum class State { IN, OUT } state;

	Transition(Core* nCore);
	virtual bool draw() = 0; //True when finished
	virtual void setState(State nState);

protected:
	Core* core;
	bool enabled;
	virtual void reset() = 0;
};