#pragma once

#include "Vec2.h"

class Rect
{

private:

	float top;
	float bottom;
	float left;
	float right;

public:

	Rect() = default;
	Rect(float top, float bottom, float left, float right);
	Rect(Vec2 topRight, Vec2 bottomLeft);
	Rect(Vec2 topRight, float width, float height);

	bool checkOverlapping(const Rect& rect) const;

};

