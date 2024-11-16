#include "Paddle.h"
#include "Constants.h"
#include <raylib.h>

Paddle::Paddle(int x, int y, int w, int h, float speed) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->speed = speed;
	this->color = COLOR_WHITE;
}

void Paddle::update() {
	this->ableToGoLeft = this->x <= 0 ? false : true;
	this->ableToGoRight = this->x + this->w >= SCREEN_W ? false : true;
}

void Paddle::draw() {
	DrawRectangle(this->x, this->y, this->w, this->h, this->color);
}

void Paddle::move(DIRECTION direction) {
	if (direction == LEFT && this->ableToGoLeft) {
		this->x -= this->speed;
	} else if (direction == RIGHT && this->ableToGoRight) {
		this->x += this->speed;
	}
}
