#include "Ball.h"
#include "raylib.h"
#include "Constants.h"

int main (int argc, char *argv[]) {
	InitWindow(SCREEN_W, SCREEN_H, "cpppong");
	SetTargetFPS(60);

	Ball* ball = new Ball(SCREEN_W/2, SCREEN_H/2, 20, 7);
		
	while (WindowShouldClose() == false) {
		ball->update();

		BeginDrawing();
		ClearBackground(COLOR_BG);
		ball->draw();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
