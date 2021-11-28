#include "Math.h"

Vector2f::~Vector2f()
{

}

void fSetPos(Vector2f& vec, float x, float y)
{
		vec.x = x;
		vec.y = y;
}

Vector2i::~Vector2i()
{

}

void iSetPos(Vector2i& vec, int x, int y)
{
	vec.x = x;
	vec.y = y;
}