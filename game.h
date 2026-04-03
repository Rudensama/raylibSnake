#pragma once
#include "raylib.h"
#include "food.h"
#include "snake.h"
#include "defaults.h"

class Game
{
	public:
		Game();
		~Game();
		void Draw();
		void HandleInput();
		void Update();
		void CheckCollisionWithFood();
		void CheckCollisionWithEdge();
		void CheckCollisionWithTail();
		
		bool running;
		int score;

	private:
		void GameOver();

		Snake snake;
		Food food;
		Sound eatSound;
		Sound wallSound;
};