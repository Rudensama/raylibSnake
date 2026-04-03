#pragma once
#include <iostream>
#include <deque>
#include <raylib.h>
#include "defaults.h"
#include <raymath.h>

class Snake
{
	public:
		Snake();
		void Draw();
		void Update();
		void Reset();

		std::deque<Vector2> body;
		Vector2 direction = { 1, 0 };
		bool addSegment = false;
};