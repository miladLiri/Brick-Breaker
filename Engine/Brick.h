#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
#include "Rect.h"

class Brick 
{

private:

	Rect rect;
	Color color;
	bool destroyed = false;
	
public:

	Brick() = default;
	Brick(Rect rect, Color color);
	void draw(Graphics& gfx);
	void init(Rect in_rect, Color in_color);
	bool checkBallCollision(const Ball& ball) const;
	void BallCollision(Ball& ball);
	Rect getRect() const;
	bool isDestroyed() const;
};