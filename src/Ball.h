#pragma once
#include "Constants.h"
#include "raylib.h"

class Ball {
private:
  int x, y, r;
  float speed;
  bool directionX = true;
  bool directionY = true;
  Color color = COLOR_WHITE;
  void move();
  void collisions();

public:
  Ball(int x, int y, int r, float speed);
  void update();
  void draw();
  void addSpeed(float value);
};
