#pragma once
#include "Core.h"
#include <stack>

class Camera
{
public:
	struct CamMovementConfig
	{
		bool smooth;
		float maxSpd;
		float smoothDist;
		CamMovementConfig(bool nSmooth = false, float nMaxSpd = 0, float nSmoothDist = 0)
		{
			smooth = nSmooth;
			maxSpd = nMaxSpd;
			smoothDist = nSmoothDist;
		}
		Vector2 getNextPos(const Vector2 &src, const Vector2 &dst)
		{
			if (!smooth)
				return dst;
			Vector2 tarPos;
			Vector2 dir = dst - src;
			float dist = dir.getLen();
			if (dist == 0)
				return dst;
			dir.normalise();
			float spd = maxSpd;
			if (dist < smoothDist)
			{
				spd = maxSpd * dist / smoothDist;
			}
			if (spd > dist)
				tarPos = dst;
			else
				tarPos = src + dir * spd;
			return tarPos;
		}
	};

	enum CAM_MODE { SET, LOCK } camMode;

	Camera(const Vector2 &nPos, const Vector2& nSize, const Vector2& nLvlSize, CAM_MODE nCamMode);
	void setSpeedCfg(const CamMovementConfig& cfg);
	Vector2 getCameraPos();
	void update(const Vector2 &nPos);
	void shake(float nvAmp, float nhAmp, int iters);
	void setLimited(bool nVLimited, bool nHLimited);

private:
	Vector2 pos;
	Vector2 size;
	Vector2 lvlSize;

	bool vlimited;
	bool hlimited;

	bool isShaking;
	int sign;
	float vAmp;
	float hAmp;
	float vShakeDelta;
	float hShakeDelta;

	CamMovementConfig speedCfg;
};