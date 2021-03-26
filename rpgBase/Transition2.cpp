#include "Transition2.h"

Transition2::Transition2(Core* nCore) :
	Transition(nCore)
{
	target1 = 0;
}

bool Transition2::draw()
{
	if (!enabled)
		return true;

	Vector2 partSize = { core->targetResolution.x / bTransitionX, core->targetResolution.y / bTransitionY };

	int cnt = bTransitionX * bTransitionY;

	if (state == State::OUT)
	{
		float current = 0;

		for (int i = 0; i < bTransitionX; i++)
		{
			for (int k = 0; k < bTransitionY; k++)
			{
				++current;
				float n = max(target1 - current, 0.0f);
				if (n > length)
					n = length;
				Vector2 size = partSize * (n / length);
				Vector2 pos = { partSize.x * i + (partSize.x - size.x) / 2, partSize.y * k + (partSize.y - size.y) / 2 };
				core->drawFilledRect(pos, size, { 0, 0, 0, Uint8(255.0f * (n / length)) });
			}
		}
		if (target1 < cnt + length)
		{
			++target1;
			cout << "OUT goes on: " << target1 << endl;
			return false;
		}
		else
		{
			enabled = false;
			cout << "OUT finished!" << endl;
			return true;
		}
	}
	else
	{
		float current = cnt;

		for (int i = bTransitionX; i >= 0; --i)
		{
			for (int k = bTransitionY; k >= 0; --k)
			{
				--current;
				float n = max(target1 - current, 0.0f);
				if (n > length)
					n = length;
				Vector2 size = partSize * (n / length);
				Vector2 pos = { partSize.x * i + (partSize.x - size.x) / 2, partSize.y * k + (partSize.y - size.y) / 2 };
				core->drawFilledRect(pos, size, { 0, 0, 0, Uint8(255.0f * (n / length)) });
			}
		}
		//cout << target1 << endl;
		if (target1 + length + 2 > 0)
		{
			--target1;
			cout << "IN goes on: " << target1 << endl;
			return false;
		}
		else
		{
			enabled = false;
			cout << "IN finished!" << endl;
			return true;
		}
	}
	return false;
}

void Transition2::reset()
{
	cout << "Resetet transition\n";
	enabled = true;
	if (state == State::OUT)
		target1 = 0;
	else if (state == State::IN)
		target1 = bTransitionX * bTransitionY + length;
}
