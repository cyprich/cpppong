#include "Ball.h"
#include "Paddle.h"
#include "raylib.h"
#include "Constants.h"

int main (int argc, char *argv[]) {
	InitWindow(SCREEN_W, SCREEN_H, "cpppong");
	SetTargetFPS(60);

	Ball* ball = new Ball(SCREEN_W/2, SCREEN_H/2, 20, 7);
	Paddle* paddle = new Paddle(10, 10, 150, 15, 5);
		
	while (WindowShouldClose() == false) {
		ball->update();
		paddle->update();

		BeginDrawing();
		ClearBackground(COLOR_BG);
		ball->draw();
		paddle->draw();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
