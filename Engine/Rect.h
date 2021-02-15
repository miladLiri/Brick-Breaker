#pragma once

#include "Vec2.h"

class Rect
{

public:

	float top;
	float bottom;
	float left;
	float right;

public:

	Rect() = default;
	Rect(float top, float bottom, float left, float right);
	Rect(Vec2 topLeft, Vec2 bottomRight);
	Rect(Vec2 topLeft, float width, float height);

	bool checkOverlapping(const Rect& rect) const;

	static Rect getRect(const Vec2 center, const float width, const float height);

};

