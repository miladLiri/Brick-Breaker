#include "Skateboard.h"

Skateboard::Skateboard(const int in_x)
{
	pos.x = in_x;
}

void Skateboard::draw(Graphics& gfx) const
{
	gfx.DrawRect(pos.x, pos.y, width, height, color);
}

void Skateboard::control(const MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) 
	{
		pos.x += v.x;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= v.x;
	}
}

void Skateboard::clampScreen()
{
	if (pos.x <= 0)
	{
		pos.x = 0;
	}

	if (pos.x + width >= Graphics::ScreenWidth - 1) {
		pos.x = Graphics::ScreenWidth - width - 1;
	}
}

void Skateboard::ballCollision(Ball& ball) const
{
	Rect ballRect = ball.getRect();

	if(ballRect.bottom >= pos.y && ballRect.left >= pos.x && ballRect.right <= pos.x + width)
	{
		ball.resetvy();
	}
}

void Skateboard::update(const MainWindow& wnd, Ball& ball)
{
	control(wnd);
	clampScreen();
	ballCollision(ball);
}
