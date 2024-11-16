#include "Ball.h"
#include "raylib.h"

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
  if (this->x - this->r <= 0 || this->x + this->r >= SCREEN_W) {
    this->directionX = !this->directionX;
  }

  if (this->y - this->r <= 0 || this->y + this->r >= SCREEN_H) {
    this->directionY = !this->directionY;
  }
}

void Ball::update() {
  collisions();
  move();
}

void Ball::draw() {
  DrawEllipse(this->x, this->y, this->r, this->r, this->color);
}

void Ball::addSpeed(float value) { this->speed += value; }
