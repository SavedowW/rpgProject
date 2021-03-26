#include "Transition1.h"

Transition1::Transition1(Core* nCore) :
	Transition(nCore)
{
	timer = 0;

	spr_transition = core->loadTexture("Sprites/HUD/s_lvlTransition.png");
	SDL_SetTextureBlendMode(spr_transition, SDL_BLENDMODE_BLEND);
}

bool Transition1::draw()
{
	if (!enabled)
		return true;

	if (state == State::IN)
	{
		--timer;
		SDL_SetTextureAlphaMod(spr_transition, 255.0 * float(timer) / transitionPeriod);
		core->renderTexture(spr_transition, 0, 0);
		if (timer == 0)
		{
			enabled = false;
			return true;
		}
	}
	else if (state == State::OUT)
	{
		++timer;
		SDL_SetTextureAlphaMod(spr_transition, 255.0 * float(timer) / transitionPeriod);
		core->renderTexture(spr_transition, 0, 0);
		if (timer == transitionPeriod)
		{
			enabled = false;
			return true;
		}
	}
	return false;
}

void Transition1::reset()
{
	enabled = true;
	if (state == State::IN)
	{
		timer = transitionPeriod + 1;
	}
	else if (state == State::OUT)
	{
		timer = 0;
	}
}
