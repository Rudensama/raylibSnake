#pragma once
#include <raylib.h>
#include <raymath.h>
#include <deque>

extern const int cellSize;
extern const int cellCount;
extern const int offset;

extern const Color green;
extern const Color darkGreen;

static bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
{
	for (unsigned int i = 0; i < deque.size(); i++)
	{
		if (Vector2Equals(deque[i], element))
		{
			return true;
		}
	}
	return false;
}