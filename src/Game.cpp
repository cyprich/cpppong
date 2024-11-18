#include "Game.h"
#include "Constants.h"
#include <raylib.h>

Game::Game() {
  this->ball = new Ball(SCREEN_W / 2, SCREEN_H / 2, 15, 7);
  this->paddles[0] = new Paddle(PADDING);
  this->paddles[1] = new Paddle(SCREEN_W - PADDING * 2);
}

void Game::update() {
  this->collisions();

  this->ball->update();
  this->ball->addSpeed(GetFrameTime() * 0.25); // add speed to ball every second

  this->paddles[0]->update();
  this->paddles[1]->update();
  this->updateScore();
}

void Game::draw() {
  this->ball->draw();
  this->paddles[0]->draw();
  this->paddles[1]->draw();

  DrawLine(SCREEN_W / 2, 0, SCREEN_W / 2, SCREEN_H,
           COLOR_FG); // line in the middle

  int textWidth = MeasureText(TextFormat("%i", score[0]), 48);

  DrawText(TextFormat("%i", score[0]), SCREEN_W / 2 - PADDING - textWidth,
           PADDING, 48, COLOR_FG);
  DrawText(TextFormat("%i", score[1]), SCREEN_W / 2 + PADDING, PADDING, 48,
           COLOR_FG);
}

void Game::handleInput() {
  if (IsKeyDown(KEY_W)) {
    paddles[0]->move(UP);
  }
  if (IsKeyDown(KEY_S)) {
    paddles[0]->move(DOWN);
  }
  if (IsKeyDown(KEY_UP)) {
    paddles[1]->move(UP);
  }
  if (IsKeyDown(KEY_DOWN)) {
    paddles[1]->move(DOWN);
  }
}

// ball - paddle collisions
void Game::collisions() {
  int bx = this->ball->getX();
  int by = this->ball->getY();
  int br = this->ball->getR();

  if (bx - br <= paddles[0]->getX() + paddles[0]->getThickness() &&
      bx + br >= paddles[0]->getX() && 
      by >= paddles[0]->getY() &&
      by <= paddles[0]->getY() + paddles[0]->getLength()) {

    this->ball->setX(paddles[0]->getX() + paddles[0]->getThickness() + br);
    this->ball->changeDirectionX();
  }
  if (bx + br >= paddles[1]->getX() &&
      bx - br <= paddles[1]->getX() + paddles[1]->getThickness() &&
      by >= paddles[1]->getY() &&
      by <= paddles[1]->getY() + paddles[1]->getLength()) {
    this->ball->setX(paddles[1]->getX() - br);
    this->ball->changeDirectionX();
  }
}

void Game::updateScore() {
  if (this->ball->getX() + this->ball->getR() <= 0) {
    score[1]++;
    this->ball->reset();
  } else if (this->ball->getX() - this->ball->getR() >= SCREEN_W) {
    score[0]++;
    this->ball->reset();
  }
}
