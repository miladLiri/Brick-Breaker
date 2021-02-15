#include "Bricks.h"
#include <random>

Bricks::Bricks()
{
	init();
}

void Bricks::draw(Graphics& gfx)
{
	for (int i = 0; i < nBricks; i++)
	{
		bricks[i].draw(gfx);
	}
}

void Bricks::init()
{
	const int width = (Graphics::ScreenWidth - padding * (columns + 3)) / columns;
	
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < columns; i++)
		{
			Vec2 pos = { float(padding + i * (width + padding)), float(padding + j * (height + padding)) };
			bricks[j*columns + i] = Brick(Rect(pos, width, height), color);
		}
	}

	
}

void Bricks::update(Ball& ball)
{
	for (int i = 0; i < nBricks; i++)
	{
		bricks[i].BallCollision(ball);
	}
}

bool Bricks::isAllBricksDestroyed() const
{
	for (int i = 0; i < nBricks; i++)
	{
		if (!bricks[i].isDestroyed()) {
			return false;
		}
	}
	return true;
}

