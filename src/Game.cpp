#include "Game.h"
#include "Constants.h"

Game::Game() {
	this->ball = new Ball(SCREEN_W/2, SCREEN_H/2, 20, 7);
	this->paddles[0] = new Paddle(PADDING);
	this->paddles[1] = new Paddle(SCREEN_W - PADDING*2);
}

void Game::update() {
	this->ball->update();
	this->paddles[0]->update();
	this->paddles[1]->update();
}

void Game::draw() {
	this->ball->draw();
	this->paddles[0]->draw();
	this->paddles[1]->draw();
}
