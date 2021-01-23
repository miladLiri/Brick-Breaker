#include "Ball.h"

Ball::Ball(int x, int y, int vx, int vy)
	:
	x(x),
	y(y),
	vx(vx),
	vy(vy)
{
}

void Ball::drow(Graphics& gfx) const
{
	const int cornerx = x - radius;
	const int cornery = y - radius;

	gfx.DrowCircle(cornerx, cornery, radius, color);
}

void Ball::resetvy()
{
	vy = -vy;
}

void Ball::resetvx()
{
	vx = -vx;
}

void Ball::wallCollision()
{
	const int top = y - radius;
	const int bottom = y + radius;
	const int right = x + radius;
	const int left = x - radius;

	if (top <= 0) 
	{
		y = radius;
		resetvy();
	}
	else if (left <= 0)
	{
		x = radius;
		resetvx();
	}
	else if (right >= Graphics::ScreenWidth - 1)
	{
		x = Graphics::ScreenWidth - 1 - radius;
		resetvx();
	}

	//test
	else if (bottom >= Graphics::ScreenHeight -1)
	{
		y = Graphics::ScreenHeight - 1 - radius;
		resetvy();
	}

}

void Ball::update()
{
	x += vx;
	y += vy;

	wallCollision();
}

int Ball::getTop() const
{
	return y - radius;
}

int Ball::getBottom() const
{
	return y + radius;
}

int Ball::getRight() const
{
	return x + radius;
}

int Ball::getLeft() const
{
	return x - radius;
}
