#pragma once
#include <raylib.h>
#include "Constants.h"

class Paddle {
private:
	int thickness = PADDING;
	int length = PADDING * 10;
	int x;
	int y = (SCREEN_H / 2) - (this->length / 2);
	float speed = 5;
	Color color = COLOR_FG;
	bool ableToGoDown = true;
	bool ableToGoUp = true;
	
public:
	Paddle(int x);
	void update();
	void draw();
	void move(DIRECTION direction);

	float getX() {return x;};
	float getY() {return y;};
	int getThickness() {return thickness;};
	int getLength() {return length;};
};

