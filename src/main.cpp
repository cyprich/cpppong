#include "raylib.h"
#include "Constants.h"
#include "Game.h"

int main (int argc, char *argv[]) {
	InitWindow(SCREEN_W, SCREEN_H, "cpppong");
	SetTargetFPS(60);
	Game* game = new Game();

	while (WindowShouldClose() == false) {
		game->handleInput();
		game->update();

		BeginDrawing();
		ClearBackground(COLOR_BG);
		game->draw();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
