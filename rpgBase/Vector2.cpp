#include "Vector2.h"

std::ostream& operator<< (std::ostream& out, const Vector2& vec)
{
	out << vec.x << " " << vec.y;
	return out;
}

Vector2::Vector2(float nx, float ny)
{
	x = nx;
	y = ny;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

Vector2 Vector2::operator*(const float& num) const
{
	return { x * num, y * num };
}

Vector2 Vector2::operator/(const float& num) const
{
	return { x / num, y / num };
}

void Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

void Vector2::operator*=(const float& num)
{
	x *= num;
	y *= num;
}

void Vector2::operator/=(const float& num)
{
	x /= num;
	y /= num;
}

float Vector2::getLen() const
{
	return sqrt(x * x + y * y);
}

void Vector2::normalise()
{
	float l = sqrt(x * x + y * y);
	x = x / l;
	y = y / l;
}
