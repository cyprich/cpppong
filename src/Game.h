#include "Ball.h"
#include "Paddle.h"

class Game {
private:
	Ball* ball;
	Paddle* paddles[2];
  int score[2] = {1, 1};
	void collisions();
  void updateScore();
public:
	Game();
	~Game();
	void update();
	void draw();
	void handleInput();
};
