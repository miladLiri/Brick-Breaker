#pragma once

class Vec2
{

public:

	float x;
	float y;

public:

	Vec2() = default;
	Vec2(float x, float y);

	Vec2 operator + (const Vec2& rhs) const;
	Vec2& operator += (const Vec2& rhs);

	Vec2 operator * (const float rhs) const;
	Vec2& operator *= (const float rhs);

	Vec2 operator - (const Vec2& rhs) const;
	Vec2& operator -= (const Vec2& rhs);

	Vec2 operator / (const float rhs) const;
	Vec2& operator /= (const float rhs);

	float lenSq() const;
	float len() const;

	Vec2 getNormalized() const;
	Vec2& normalize();

};

