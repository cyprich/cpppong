#pragma once
#include "Constants.h"
#include "raylib.h"

class Ball {
private:
  int x, y, r;
  float speed;
  float initialSpeed;
  bool directionX = true;
  bool directionY = true;
  Color color = COLOR_FG;
  void move();
  void collisions();
  int getRandomDelta(int max);

public:
  Ball(int x, int y, int r, float speed);
  void update();
  void draw();
  void reset();
  void addSpeed(float value) { this->speed += value; };
  void changeDirectionX() { directionX = !directionX; };
  void changeDirectionY() { directionY = !directionY; };

  float getX() { return x; };
  float getY() { return y; };
  int getR() { return r; };
  void setX(int newX) { this->x = newX; };
};
