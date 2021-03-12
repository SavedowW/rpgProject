#pragma once
#include "Character.h"
#include "Object.h"

using namespace std;

struct Movement
{
public:
	Vector2 velocity;
	enum Dir {UP, DOWN, LEFT, RIGHT};
	float spd;
	void beginMovement(Dir dir)
	{
		switch (dir)
		{
		case (UP):
			velocity.y = -spd;
			break;

		case (DOWN):
			velocity.y = spd;
			break;

		case (LEFT):
			velocity.x = -spd;
			break;

		case (RIGHT):
			velocity.x = spd;
			break;
		}
	}
	void endMovement(Dir dir)
	{
		switch (dir)
		{
		case (UP):
			if (velocity.y < 0) velocity.y = 0;
			break;

		case (DOWN):
			if (velocity.y > 0) velocity.y = 0;
			break;

		case (LEFT):
			if (velocity.x < 0) velocity.x = 0;
			break;

		case (RIGHT):
			if (velocity.x > 0) velocity.x = 0;
			break;
		}
	}
private:
};

const int MAXLVL = 5;
struct PlayerLevel
{
	int lvl;
	int minExp;
	CharacterStats levelStats;
};

class Player : public Character, public Object
{
public:
	vector<Item*> inventory;

	Movement movement;
	hitbox hBox;

	int exp;
	int lvl;
	int money;

	PlayerLevel levels[MAXLVL + 1];

	Player(const Vector2 &nPos);

	int useItem(int id);
	int removeItem(int id);
	vector<PlayerLevel> gainExp(int nExp);
	void addMoney(int addM);

	SDL_Texture* getSprite();

	void update();
	void updateDepth();
	void updateHBox();
	void stop();


private:
	static SDL_Texture* spr_idle;
	int h;
	hitbox relativeHBox;

	void prepareLevels();
};