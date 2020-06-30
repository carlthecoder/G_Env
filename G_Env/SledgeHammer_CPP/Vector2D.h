#pragma once

struct Vector2D
{
	float x;
	float y;

	Vector2D() = default;
	Vector2D(float x, float y) : x(x), y(y) {}

	Vector2D(const Vector2D& other)
	{
		x = other.x;
		y = other.y;
	}

	void operator=(const Vector2D& other)
	{
		x = other.x;
		y = other.y;
	}
};