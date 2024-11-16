#include "Game.h"
#include "Constants.h"
#include <raylib.h>

Game::Game() {
	this->ball = new Ball(SCREEN_W/2, SCREEN_H/2, 20, 7);
	this->paddles[0] = new Paddle(SCREEN_W - PADDING*2);
	this->paddles[1] = new Paddle(PADDING);
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

void Game::handleInput() {
	if (IsKeyDown(KEY_UP)) {
		paddles[0]->move(UP);
	}
	if (IsKeyDown(KEY_DOWN)) {
		paddles[0]->move(DOWN);
	}
	if (IsKeyDown(KEY_W)) {
		paddles[1]->move(UP);
	}
	if (IsKeyDown(KEY_S)) {
		paddles[1]->move(DOWN);
	}
}
