#include "Ball.h"
#include "Constants.h"
#include "raylib.h"
#include <cstdlib>

Ball::Ball(int x, int y, int r, float speed) {
  this->x = x;
  this->y = y;
  this->r = r;
  this->speed = speed;
}

void Ball::move() {
  if (this->directionX) {
    this->x += this->speed;
  } else {
    this->x -= this->speed;
  }

  if (this->directionY) {
    this->y += this->speed;
  } else {
    this->y -= this->speed;
  }
}

void Ball::collisions() {
  /*if (this->x - this->r <= 0 || this->x + this->r >= SCREEN_W) {*/
  /* this->changeDirectionX();*/
  /*}*/

  if (this->y - this->r <= 0 || this->y + this->r >= SCREEN_H) {
    this->changeDirectionY();
  }
}

void Ball::update() {
  collisions();
  move();
}

void Ball::draw() {
  DrawEllipse(this->x, this->y, this->r, this->r, this->color);
}

void Ball::resetPosition() {
	int maxDelta = 50;
	this->x = SCREEN_W / 2 + this->getRandomDelta(maxDelta);
	this->y = SCREEN_H / 2 + this->getRandomDelta(maxDelta);
	this->directionX = rand() % 2;
	this->directionY = rand() % 2;
	
}

int Ball::getRandomDelta(int max) {
	return rand() % (max * 2) - max;
}
