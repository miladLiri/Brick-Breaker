#include "Rect.h"

Rect::Rect(float top, float bottom, float left, float right)
	:
	top(top),
	bottom(bottom),
	right(right),
	left(left)
{
}

Rect::Rect(Vec2 topLeft, Vec2 bottomRight)
	:
	Rect(topLeft.y, bottomRight.y, topLeft.x, bottomRight.x)
{
}

Rect::Rect(Vec2 topLeft, float width, float height)
	:
	Rect(topLeft, topLeft + Vec2(width, height))
{
}

bool Rect::checkOverlapping(const Rect& other) const
{
	return
		left >= other.left && 
		right <= other.right &&
		top >= other.top && 
		bottom <= other.bottom;
}

Rect Rect::getRect(const Vec2 center, const float width, const float height)
{
	const Vec2 half(width, height);
	return Rect(center - half, center + half);
}


