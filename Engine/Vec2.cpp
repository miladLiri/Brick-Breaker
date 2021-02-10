#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float x, float y)
	:
	x(x),
	y(y)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	//*this = *this + rhs;
	//return *this;
	return *this = *this + rhs;
}

Vec2 Vec2::operator*(const float rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2& Vec2::operator*=(const float rhs)
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}

Vec2 Vec2::operator/(const float rhs) const
{
	return Vec2(x / rhs, y / rhs);
}

Vec2& Vec2::operator/=(const float rhs)
{
	return *this = *this / rhs;
}


float Vec2::lenSq() const
{
	return x * x + y * y;
}

float Vec2::len() const
{
	return std::sqrt(lenSq());
}

Vec2 Vec2::getNormalized() const
{
	const float length = len();

	if(length != 0.0f)
	{
		return *this / length;
	}

	return *this;
}

Vec2& Vec2::normalize()
{
	return *this = getNormalized();
}

