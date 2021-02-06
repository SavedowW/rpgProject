#pragma once
#include <cmath>
#include <iostream>

const float PI = 3.1415;

struct Vector2
{
	float x, y;
	Vector2(float nx = 0, float ny = 0);
	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(const float& num) const;
	Vector2 operator/(const float& num) const;
	void operator+=(const Vector2& rhs);
	void operator-=(const Vector2& rhs);
	void operator*=(const float& num);
	void operator/=(const float& num);
	float getLen() const;
	void normalise();
};

std::ostream& operator<< (std::ostream& out, const Vector2& vec);

struct hitbox
{
	float x, y, w, h;
	hitbox(float nx = 0, float ny = 0, float nw = 0, float nh = 0)
	{
		x = nx;
		y = ny;
		w = nw;
		h = nh;
	}
	const hitbox operator+(const Vector2& rhs)
	{
		return { x + rhs.x, y + rhs.y, w, h };
	}
	const int isCollideWith_x(const hitbox& hbox)
	{
		if (x <= hbox.x && x + w > hbox.x)
			return 1;
		if (x + w >= hbox.x + hbox.w && x < hbox.x + hbox.w)
			return 2;
		if (x >= hbox.x && x + w <= hbox.x + hbox.w)
			return 4;
		else
			return 0;
	}
	const int isCollideWith_y(const hitbox& hbox)
	{
		if (y <= hbox.y && y + h > hbox.y)
			return 1;
		if (y + h >= hbox.y + hbox.h && y < hbox.y + hbox.h)
			return 2;
		if (y >= hbox.y && y + h <= hbox.y + hbox.h)
			return 4;
		else
			return 0;
	}
	const bool isCollideWith(const hitbox& hbox)
	{
		return isCollideWith_x(hbox) && isCollideWith_y(hbox);
	}
};