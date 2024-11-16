#include "Ball.h"
#include "Paddle.h"

class Game {
private:
	Ball* ball;
	Paddle* paddles[2];
public:
	Game();
	~Game();
	void update();
	void draw();
	void handleInput();
};
