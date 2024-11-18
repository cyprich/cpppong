#include "raylib.h"
#include "Constants.h"
#include "Game.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main (int argc, char *argv[]) {
	srand(time(NULL));
	
	Game* game = new Game();

	InitWindow(SCREEN_W, SCREEN_H, "cpppong");
	std::cout << "running @" << my_constats::FPS << "fps" << std::endl;
	SetTargetFPS(my_constats::FPS);

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
