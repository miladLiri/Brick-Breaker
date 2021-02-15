#include "Brick.h"

Brick::Brick(Rect rect, Color color)
	:
	rect(rect),
	color(color)
{
}

void Brick::draw(Graphics& gfx)
{
	if (!destroyed) {
		gfx.DrawRect(rect, color);
	}
}

void Brick::init(Rect in_rect, Color in_color)
{
	rect = in_rect;
	color = in_color;
}

bool Brick::checkBallCollision(const Ball& ball) const
{
	return ball.getRect().checkOverlapping(rect) && !destroyed;
}

void Brick::BallCollision(Ball& ball)
{
	if (ball.getRect().checkOverlapping(rect) && !destroyed) {
		destroyed = true;
		ball.resetvy();
	}
}

Rect Brick::getRect() const
{
	return rect;
}

bool Brick::isDestroyed() const
{
	return destroyed;
}
