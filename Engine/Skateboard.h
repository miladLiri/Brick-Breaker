#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Ball.h"
#include "Rect.h"


class Skateboard
{

private:

	static constexpr Color color = Colors::Cyan;
	static constexpr int height = 20;
	static constexpr int width = 150;

	Vec2 v = { 10,0 };
	Vec2 pos = { 150, Graphics::ScreenHeight - height - 6 };

public:

	Skateboard() = default;
	Skateboard(const int x);
	void draw(Graphics& gfx) const;
	void control(const MainWindow& wnd);
	void clampScreen();
	void ballCollision(Ball& ball) const;
	void update(const MainWindow& wnd, Ball& ball);

};
