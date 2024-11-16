#include "Paddle.h"
#include "Constants.h"
#include <raylib.h>

Paddle::Paddle(int x) {
	this->x = x;
}

void Paddle::update() {
	this->ableToGoLeft = this->x <= 0 ? false : true;
	this->ableToGoRight = this->x + this->thickness >= SCREEN_W ? false : true;
}

void Paddle::draw() {
	DrawRectangle(this->x, this->y, this->thickness, this->length, this->color);
}

void Paddle::move(DIRECTION direction) {
	if (direction == LEFT && this->ableToGoLeft) {
		this->x -= this->speed;
	} else if (direction == RIGHT && this->ableToGoRight) {
		this->x += this->speed;
	}
}
