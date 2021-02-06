#pragma once
#include "Core.h"

class Camera
{
public:
	enum CAM_MODE { SET, LOCK } camMode;

	Camera(const Vector2 &nPos, const Vector2& nSize, const Vector2& nLvlSize, CAM_MODE nCamMode);
	Vector2 getCameraPos();
	void update(const Vector2 &nPos);
	void shake(float nvAmp, float nhAmp, int iters);

private:
	Vector2 pos;
	Vector2 size;
	Vector2 lvlSize;

	bool isShaking;
	int sign;
	float vAmp;
	float hAmp;
	float vShakeDelta;
	float hShakeDelta;
};