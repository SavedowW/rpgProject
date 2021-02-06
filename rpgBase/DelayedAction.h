#pragma once
#include <functional>

class DelayedAction
{
public:
	virtual bool update() = 0;
};

class TimerAction : public DelayedAction
{
public:
	TimerAction(int nLimit, std::function<void()> nFunc, bool nLoop = false, int nTimer = 0)
	{
		limit = nLimit;
		timer = nTimer;
		loop = nLoop;
		enabled = true;
		func = nFunc;
	}

	//false if finished
	bool update()
	{
		if (!enabled)
			return enabled;

		++timer;
		if (timer >= limit)
		{
			//Do stuff
			func();

			if (loop)
				timer = 0;
			else
				enabled = false;
		}

		return enabled;
	}

private:
	int timer;
	int limit;
	bool loop;
	bool enabled;
	std::function<void()> func;
};

class FlagAction : public DelayedAction
{
public:
	FlagAction(bool * nFlag, std::function<void()> nFunc)
	{
		enabled = true;
		func = nFunc;
		flag = nFlag;
	}

	//false if finished
	bool update()
	{
		if (!enabled)
			return enabled;

		if (*flag)
		{
			//Do stuff
			func();

			enabled = false;
		}

		return enabled;
	}

private:
	bool* flag;
	bool enabled;
	std::function<void()> func;
};

class ReverseFlagAction : public DelayedAction
{
public:
	ReverseFlagAction(bool* nFlag, std::function<void()> nFunc)
	{
		enabled = true;
		func = nFunc;
		flag = nFlag;
	}

	//false if finished
	bool update()
	{
		if (!enabled)
			return enabled;

		if (!*flag)
		{
			//Do stuff
			func();

			enabled = false;
		}

		return enabled;
	}

private:
	bool* flag;
	bool enabled;
	std::function<void()> func;
};