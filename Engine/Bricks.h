#pragma once
#include "Brick.h"

class Bricks
{
private:
	
	static constexpr int rows = 5;
	static constexpr int columns = 10;
	static constexpr int height = 40;
	static constexpr int padding = 1;
	static constexpr int nBricks = rows * columns;
	Color color = Colors::Yellow;
	Brick bricks[nBricks];
	static constexpr Color c = Colors::LightGray;
	
public:

	Bricks();
	void draw(Graphics& gfx);
	void init();
	void update(Ball& ball);
	bool isAllBricksDestroyed() const;

};