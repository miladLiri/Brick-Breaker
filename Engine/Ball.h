#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Rect.h"
#include <random>

class Ball
{

private:

	static constexpr Color color = Colors::Blue;
	static constexpr int radius = 10;
	Vec2 pos;
	Vec2 v;

public:

	Ball(Vec2 pos, Vec2 v);
	void draw(Graphics& gfx) const;
	void resetvy();
	void resetvx();
	void wallCollision();
	void update();
	bool checkBaseCollision();
	
	Rect getRect() const;
};
