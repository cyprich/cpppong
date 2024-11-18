#include "Paddle.h"
#include "Constants.h"
#include <raylib.h>

Paddle::Paddle(int x) { this->x = x; }

void Paddle::update() {
  if (this->y < PADDING) {
    this->y = PADDING;
    this->ableToGoUp = false;
  } else {
    this->ableToGoUp = true;
  }

  if (this->y + this->length > SCREEN_H - PADDING) {
    this->y = SCREEN_H - this->length - PADDING;
    this->ableToGoDown = false;
  } else {
    this->ableToGoDown = true;
  }
}

void Paddle::draw() {
  DrawRectangle(this->x, this->y, this->thickness, this->length, this->color);
}

void Paddle::move(DIRECTION direction) {
  if (direction == UP && this->ableToGoUp) {
    this->y -= this->speed * 60 / my_constats::FPS;
  } else if (direction == DOWN && this->ableToGoDown) {
    this->y += this->speed * 60 / my_constats::FPS;
  }
}
