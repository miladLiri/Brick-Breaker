#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 v)
	:
	pos(pos),
	v(v)
{
}

void Ball::draw(Graphics& gfx) const
{
	const int cornerx = pos.x - radius;
	const int cornery = pos.y - radius;

	gfx.DrawCircle(cornerx, cornery, radius, color);
}

void Ball::resetvy()
{
	v.y = -v.y;
}

void Ball::resetvx()
{
	v.x = -v.x;
}

void Ball::wallCollision()
{
	const int top = pos.y - radius;
	const int bottom = pos.y + radius;
	const int right = pos.x + radius;
	const int left = pos.x - radius;

	if (top <= 0) 
	{
		pos.y = radius;
		resetvy();
	}
	else if (left <= 0)
	{
		pos.x = radius;
		resetvx();
	}
	else if (right >= Graphics::ScreenWidth - 1)
	{
		pos.x = Graphics::ScreenWidth - 1 - radius;
		resetvx();
	}

	//test
	else if (bottom >= Graphics::ScreenHeight -1)
	{
		pos.y = Graphics::ScreenHeight - 1 - radius;
		resetvy();
	}

}

void Ball::update()
{
	pos += v;

	wallCollision();
}

Rect Ball::getRect() const
{
	return Rect(pos - Vec2(radius, radius), pos + Vec2(radius, radius));
}

