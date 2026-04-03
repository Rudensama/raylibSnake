#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "raylib Snake");
	SetTargetFPS(60);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		game.HandleInput();

		if (EventTriggered(0.2))
		{
			game.Update();
		}
		
		ClearBackground(green);
		Rectangle outline = { (float)offset - 5, (float)offset - 5 , (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10 };
		DrawRectangleLinesEx(outline, 5, darkGreen);

		DrawText("raylib Snake", offset - 5, 20, 40, darkGreen);
		DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);

		game.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}