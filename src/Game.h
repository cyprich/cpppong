#include "Ball.h"
#include "Paddle.h"

class Game {
private:
	Ball* ball;
	Paddle* paddles[2];
	void collisions();
public:
	Game();
	~Game();
	void update();
	void draw();
	void handleInput();
};
