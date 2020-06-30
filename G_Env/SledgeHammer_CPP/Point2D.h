#pragma once
#ifndef ISOMETRIA_POINT2D_H
#define ISOMETRIA_POINT2D_H

struct Point2D
{
	float x;
	float y;

	Point2D() = default;
	Point2D(float x, float y) : x(x), y(y) {}
};

#endif