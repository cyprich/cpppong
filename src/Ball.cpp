#include "Ball.h"
#include "Constants.h"
#include "raylib.h"
#include <cstdlib>

Ball::Ball(int x, int y, int r, float speed) {
  this->x = x;
  this->y = y;
  this->r = r;
  this->speed = speed;
  this->initialSpeed = speed;
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

// collisions with top and bottom
void Ball::collisions() {
  if (this->y - this->r <= 0) {
    this->y = this->r;
    this->changeDirectionY();
  }
  if (this->y + this->r >= SCREEN_H) {
    this->y = SCREEN_H - this->r;
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

void Ball::reset() {
  int maxDeltaX = 100;
  int maxDeltaY = SCREEN_H / 3;

  this->x = SCREEN_W / 2 + this->getRandomDelta(maxDeltaX);
  this->y = SCREEN_H / 2 + this->getRandomDelta(maxDeltaY);

  this->directionX = rand() % 2;
  this->directionY = rand() % 2;

  this->speed = this->initialSpeed;
}

int Ball::getRandomDelta(int max) { return rand() % (max * 2) - max; }
