#include "Paddle.h"
#include "Constants.h"
#include <raylib.h>

Paddle::Paddle(int x) {
	this->x = x;
}

void Paddle::update() {
	this->ableToGoUp = this->y <= 0 ? false : true;
	this->ableToGoDown = this->y + this->length >= SCREEN_H ? false : true;
}

void Paddle::draw() {
	DrawRectangle(this->x, this->y, this->thickness, this->length, this->color);
}

void Paddle::move(DIRECTION direction) {
	if (direction == UP && this->ableToGoUp) {
		this->y -= this->speed * 60/my_constats::FPS;
	} else if (direction == DOWN && this->ableToGoDown) {
		this->y += this->speed * 60/my_constats::FPS;
	}
}
