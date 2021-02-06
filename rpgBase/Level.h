//==================================
//
//		Level.h
//		Global interface for all levels
//		Every level in the game must be inherited from this class
//
//==================================
#pragma once
#include "GameCore.h"
#include "ObjectsH.h"
#include "EnemiesH.h"
#include "DelayedAction.h"

struct LevelResult
{
	int nextLvl;
	int entrance;
};

struct LeavePoint
{
	hitbox hBox;
	int nextLvl;
	int entrance;
	LeavePoint(const hitbox& nHBox, const int& nNextLvl, const int& nEntrance)
	{
		hBox = nHBox;
		nextLvl = nNextLvl;
		entrance = nEntrance;
	}
};

struct Trigger
{
	hitbox hBox;
	bool enabled;
	bool lastState;
	static Player* player;
	std::function<void(Trigger*)> playerEnter;
	std::function<void(Trigger*)> playerLeave;
	Trigger(const hitbox& nHBox, std::function<void(Trigger*)> fEnter = NULL, std::function<void(Trigger*)> fLeave = NULL, bool nEnabled = true)
	{
		hBox = nHBox;
		playerEnter = fEnter;
		playerLeave = fLeave;
		enabled = nEnabled;
		lastState = hBox.isCollideWith(player->hBox);
	}
	void update()
	{
		bool state = hBox.isCollideWith(player->hBox);
		if (!enabled)
			return;

		if (!lastState && state && playerEnter)
		{
			playerEnter(this);
		}

		else if (lastState && !state && playerLeave)
		{
			playerLeave(this);
		}

		lastState = state;
	}
};

struct BattleRequest
{
	Enemy* enemy;
	int srcLevel;
	int battleId; //for specific battles

};

class Level
{
public:
	Level(const Vector2 &nSize, Camera* nCam);

	virtual void enter(int entrance) = 0;
	virtual LevelResult levelProcess() = 0;

	static Player* player;
	static GameCore* gameCore;

protected:
	LevelResult returnVal;
	virtual void renderLevel() = 0;
	virtual void processInput(const SDL_Event& e) = 0;
	virtual void handleDelayedActions();
	
	enum InputMethod { INPUT_DEFAULT, INPUT_HUD, INPUT_NOINPUT } inputMethod;

	vector<DelayedAction*> actionList;
	static BattleRequest battleRequest;

	bool isRunning;
	Vector2 size;
	Camera* cam;

	static bool isLower(const Object* lhs, const Object* rhs);
};