#include "Camera.h"

Camera::Camera(const Vector2& nPos, const Vector2& nSize, const Vector2& nLvlSize, CAM_MODE nCamMode)
{
	pos = nPos;
	size = nSize;
	camMode = nCamMode;
	lvlSize = nLvlSize;

	isShaking = false;
	sign = 1;
	vAmp = 0;
	hAmp = 0;
	vShakeDelta = 0;
	hShakeDelta = 0;
}

Vector2 Camera::getCameraPos()
{
	if (isShaking)
		return pos = { vAmp * sign, hAmp * sign };
	else
		return pos;
}

void Camera::update(const Vector2& nPos)
{
	if (camMode == SET)
	{
		pos = nPos;
	}
	else if (camMode == LOCK)
	{
		pos = nPos - size / 2;
	}

	if (pos.x < 0) pos.x = 0;
	if (pos.y < 0) pos.y = 0;

	if (pos.x > lvlSize.x - size.x) pos.x = lvlSize.x - size.x;
	if (pos.y > lvlSize.y - size.y) pos.y = lvlSize.y - size.y;

	if (isShaking)
	{
		sign *= -1;
		hAmp -= hShakeDelta;
		vAmp -= vShakeDelta;
		if (hAmp <= 0 && vAmp <= 0)
		{
			isShaking = false;
			vAmp = 0;
			hAmp = 0;
			vShakeDelta = 0;
			hShakeDelta = 0;
		}
	}
}

void Camera::shake(float nvAmp, float nhAmp, int iters)
{
	vAmp = nvAmp;
	hAmp = nhAmp;
	hShakeDelta = hAmp / iters;
	vShakeDelta = vAmp / iters;
	isShaking = true;
}