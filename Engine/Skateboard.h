#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Ball.h"


class Skateboard
{

private:

	static constexpr Color mainColor = Colors::Cyan;
	static constexpr Color secondColor = Colors::Green;
	static constexpr int height = 20;
	static constexpr int v = 5;
	static constexpr int y = Graphics::ScreenHeight - height - 6;
	int width = 100;
	int x = 150;

public:

	Skateboard(const int x);
	void drow(Graphics& gfx) const;
	void control(const MainWindow& wnd);
	void clampScreen();
	void ballCollision(Ball& ball) const;
	void update(const MainWindow& wnd, Ball& ball);



};
