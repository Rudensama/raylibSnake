#include "game.h"

Game::Game() : snake(), food(snake.body), running(true), score(0)
{
	InitAudioDevice();
	eatSound = LoadSound("sounds/eat.mp3");
	wallSound = LoadSound("sounds/wall.mp3");
}

Game::~Game()
{
	UnloadSound(eatSound);
	UnloadSound(wallSound);
	CloseAudioDevice();
}

void  Game::Draw()
{
	food.Draw();
	snake.Draw();
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (!running && keyPressed != 0)
	{
		running = true;
	}

	if (keyPressed == KEY_UP && snake.direction.y != 1)
	{
		snake.direction = { 0, -1 };
	}

	if (keyPressed == KEY_DOWN && snake.direction.y != -1)
	{
		snake.direction = { 0, 1 };
	}

	if (keyPressed == KEY_LEFT && snake.direction.x != 1)
	{
		snake.direction = { -1, 0 };
	}

	if (keyPressed == KEY_RIGHT && snake.direction.x != -1)
	{
		snake.direction = { 1, 0 };
	}
}

void Game::Update()
{
	if(running)
	{
		snake.Update();
		CheckCollisionWithFood();
		CheckCollisionWithEdge();
		CheckCollisionWithTail();
	}
}

void Game::CheckCollisionWithFood()
{
	if (Vector2Equals(snake.body[0], food.position))
	{
		food.position = food.GenerateRandomPos(snake.body);
		snake.addSegment = true;
		score++;
		PlaySound(eatSound);
	}
}

void Game::CheckCollisionWithEdge()
{
	if (snake.body[0].x == cellCount || snake.body[0].x == -1)
	{
		GameOver();
	}

	if (snake.body[0].y == cellCount || snake.body[0].y == -1)
	{
		GameOver();
	}
}

void Game::CheckCollisionWithTail()
{
	std::deque<Vector2> headlessBody = snake.body;
	headlessBody.pop_front();
	if (ElementInDeque(snake.body[0], headlessBody))
	{
		GameOver();
	}
}

void Game::GameOver()
{
	snake.Reset();
	food.position = food.GenerateRandomPos(snake.body);
	running = false;
	score = 0;
	PlaySound(wallSound);
}




