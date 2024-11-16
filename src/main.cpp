#include "raylib.h"

int main (int argc, char *argv[]) {
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "cpppong");
	SetTargetFPS(60);

	Color backgroung = {29, 29, 29, 255};

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(backgroung);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
