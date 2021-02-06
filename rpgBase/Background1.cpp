#include "Background1.h"

Background1::Background1(GameCore* nGameCore) :
	Background(nGameCore)
{
	timer = 0;

	scaler1 = 8.0f;
	scaler2 = 8.0f;

	//scaler1 = 1.0f;
	//scaler2 = 8.0f;

	//scaler1 = 3.0f;
	//scaler2 = 3.0f;
}

void Background1::draw()
{
	timer += PI / 120;
	if (timer >= PI * 2)
		timer = 0;
	for (int i = 0; i <= 15; i++)
		for (int k = 0; k <= 9; k++)
		{
			gameCore->drawPoint(Vector2(float(20 + 40 * i), float(20 + 40 * k)), 35, {Uint8(abs(sin(timer + (k / scaler2) * PI/2)) * 25.0f), 0, 0, 255});

			//gameCore->drawPoint(Vector2(float(20 + 40 * i), float(20 + 40 * k)), 35, {Uint8(abs(sin(timer + (i / scaler1) * PI/2)) * 25.0f + abs(sin(timer + (k / scaler1) * PI / 2)) * 25.0f), 0, Uint8(abs(sin(timer + (i / scaler2) * PI / 2)) * 25.0f + abs(sin(timer + (k / scaler2) * PI / 2)) * 25.0f), 255});

			//gameCore->drawPoint(Vector2(float(20 + 40 * i), float(20 + 40 * k)), 35, {Uint8(abs(sin(timer + (k / scaler2) * PI/2) * sin(timer + (i / scaler2) * PI / 2)) * 25.0f), 0, 0, 255});

		}
}