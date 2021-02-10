#include "Background2.h"

Background2::Background2(GameCore* nGameCore) :
	Background(nGameCore)
{
	timer = 0;

	scaler1 = 8.0f;
	scaler2 = 8.0f;
}

void Background2::draw()
{
	timer += PI / 50;
	if (timer >= PI * 2)
		timer = 0;
	for (int i = 0; i <= 15; i++)
		for (int k = 0; k <= 9; k++)
		{
			//It just works
			gameCore->drawPoint(Vector2(float(20 + 40 * i), float(20 + 40 * k + 50 * sin(timer + (i)))), 35, {Uint8(abs(sin(timer + (k / scaler2) * PI/2) * sin(timer + (i / scaler2) * PI / 2)) * 255.0f), 0, Uint8(abs(sin(timer * 1.5 + PI/4.0f + i)) * 100.0f), 255});

		}
}