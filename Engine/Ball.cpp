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

	Rect ball = getRect();

	if (ball.top <= 0) 
	{
		pos.y = radius + 1;
		resetvy();
	}
	else if (ball.left <= 0)
	{
		pos.x = radius + 1;
		resetvx();
	}
	else if (ball.right >= Graphics::ScreenWidth - 1)
	{
		pos.x = Graphics::ScreenWidth - 1 - radius;
		resetvx();
	}
	else if (ball.bottom >= Graphics::ScreenHeight - 1)
	{
		pos.y = Graphics::ScreenHeight - 1 - radius;
	}

}

void Ball::update()
{
	pos += v;

	wallCollision();
}

bool Ball::checkBaseCollision()
{
	Rect ball = getRect();

	if (ball.bottom >= Graphics::ScreenHeight - 1)
	{
		pos.y = Graphics::ScreenHeight - 1 - radius;
		return true;
	}
	return false;
}

Rect Ball::getRect() const
{
	return Rect::getRect(pos, radius, radius);
}

