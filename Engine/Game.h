#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Skateboard.h"
#include "Ball.h"
#include "Bricks.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void drawGameover(int x, int y);
	void drawWin(int x, int y);

private:

	MainWindow& wnd;
	Graphics gfx;

	Skateboard skate;
	Ball ball;
	Bricks bricks;

	bool isGameStarted = false;
	
};