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

bool Rect::checkOverlapping(const Rect& rect) const
{
	return
		right > rect.left && left < rect.right ||
		bottom > rect.top && top < rect.bottom;
}
