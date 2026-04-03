#pragma once
#include "raylib.h"
#include "defaults.h"
#include <iostream>
#include <deque>
#include <raymath.h>

class Food
{
public:
	Food(std::deque<Vector2> snakeBody);
	~Food();
	void Draw();
	Vector2 GenerateRandomCell();
	Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);

	Vector2 position;
	Texture2D texture;

private:
};