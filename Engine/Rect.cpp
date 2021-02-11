#include "Rect.h"

Rect::Rect(float top, float bottom, float left, float right)
	:
	top(top),
	bottom(bottom),
	right(right),
	left(left)
{
}

Rect::Rect(Vec2 topRight, Vec2 bottomLeft)
	:
	Rect(topRight.y, bottomLeft.y, topRight.x, bottomLeft.x)
{
}

Rect::Rect(Vec2 topRight, float width, float height)
	:
	Rect(topRight, topRight + Vec2(width, height))
{
}

bool Rect::checkOverlapping(const Rect& rect) const
{
	return
		right > rect.left && left < rect.right ||
		bottom > rect.top && top < rect.bottom;
}
