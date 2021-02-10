#pragma once

#include "Graphics.h"
#include "Colors.h"
#include <random>

class Ball
{

private:

	static constexpr Color color = Colors::Blue;
	static constexpr int radius = 10;
	int x; //center.x
	int y; //center.y
	int vx;
	int vy;

public:

	Ball(int x, int y, int vx, int vy);
	void drow(Graphics& gfx) const;
	int accuracyBreaker() const;
	void resetvy();
	void resetvx();
	void wallCollision();
	void update();
	int getTop() const;
	int getBottom() const;
	int getRight() const;
	int getLeft() const;

};
