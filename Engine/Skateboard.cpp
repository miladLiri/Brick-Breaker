#include "Skateboard.h"

Skateboard::Skateboard(const int x)
	:
	x(x)
{
}

void Skateboard::drow(Graphics& gfx) const
{
	gfx.DrowRect(x, y, width, height, mainColor);
}

void Skateboard::control(const MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) 
	{
		x += v;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= v;
	}
}

void Skateboard::clampScreen()
{
	if (x <= 0)
	{
		x = 0;
	}

	if (x + width >= Graphics::ScreenWidth - 1) {
		x = Graphics::ScreenWidth - width - 1;
	}
}

void Skateboard::update(const MainWindow& wnd)
{
	control(wnd);
	clampScreen();
}
