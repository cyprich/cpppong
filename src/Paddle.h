#pragma once
#include <raylib.h>
#include "Constants.h"

class Paddle {
private:
	int x, y, w, h;
	float speed;
	Color color;
	bool ableToGoRight = true;
	bool ableToGoLeft = true;
	
public:
	Paddle(int x, int y, int w, int h, float speed);
	void update();
	void draw();
	void move(DIRECTION direction);
};

