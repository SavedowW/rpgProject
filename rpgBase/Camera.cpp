#include "Camera.h"

Camera::Camera(const Vector2& nPos, const Vector2& nSize, const Vector2& nLvlSize, CAM_MODE nCamMode)
{
	pos = nPos;
	size = nSize;
	camMode = nCamMode;
	lvlSize = nLvlSize;
	setLimited(true, true);

	isShaking = false;
	sign = 1;
	vAmp = 0;
	hAmp = 0;
	vShakeDelta = 0;
	hShakeDelta = 0;
}

void Camera::setSpeedCfg(const CamMovementConfig& cfg)
{
	speedCfg = cfg;
}

Vector2 Camera::getCameraPos()
{
	if (isShaking)
		return (pos = { vAmp * sign, hAmp * sign }).getIntCords();
	else
		return pos.getIntCords();
}

void Camera::update(const Vector2& nPos)
{
	Vector2 tarPos;
	if (camMode == SET)
	{
		tarPos = nPos;
	}
	else if (camMode == LOCK)
	{
		tarPos = nPos - size / 2;
	}

	if (hlimited)
	{
		if (tarPos.x < 0) tarPos.x = 0;
		if (tarPos.x > lvlSize.x - size.x) tarPos.x = lvlSize.x - size.x;
	}

	if (vlimited)
	{
		if (tarPos.y < 0) tarPos.y = 0;
		if (tarPos.y > lvlSize.y - size.y) tarPos.y = lvlSize.y - size.y;
	}

	pos = speedCfg.getNextPos(pos, tarPos);

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

void Camera::setLimited(bool nVLimited, bool nHLimited)
{
	vlimited = nVLimited;
	hlimited = nHLimited;
}
