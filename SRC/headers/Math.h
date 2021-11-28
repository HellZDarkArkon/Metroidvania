#pragma once

#include <iostream>

struct Vector2f
{
	Vector2f() : x(0.0f), y(0.0f)
	{}
	Vector2f(float pfX, float pfY) : x(pfX), y(pfY)
	{}

	~Vector2f();

	void Print()
	{
		std::cout<<x<<", "<<y<<std::endl;
	}

	void fSetPos(Vector2f& vec, float x, float y);

	float x, y;
};

struct Vector2i
{
	Vector2i() : x(0), y(0)
	{}
	Vector2i(int piX, int piY) : x(piX), y(piY)
	{}

	~Vector2i();

	void iPrint()
	{
		std::cout<<x<<", "<<y<<std::endl;
	}

	void iSetPos(Vector2i& vec, int x, int y);

	int x, y;
};