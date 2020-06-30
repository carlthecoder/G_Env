#define _USE_MATH_DEFINES

#include "VectorHelpers.h"
#include <cmath>
#include <limits>

using std::pow;
using std::sqrt;
using std::acos;

namespace VectorHelpers
{
	Vector2D VectorAddition(const Vector2D& vec1, const Vector2D& vec2)
	{
		Vector2D tempVec;
		tempVec.x = vec1.x + vec2.x;
		tempVec.y = vec1.y + vec2.y;

		return tempVec;
	}

	Vector2D VectorSubstraction(const Vector2D& vec1, const Vector2D& vec2)
	{
		Vector2D tempVec;
		tempVec.x = vec1.x - vec2.x;
		tempVec.y = vec1.y - vec2.y;

		return tempVec;
	}

	Vector2D ScalarMultiplication(const Vector2D& vec, float scalar)
	{
		Vector2D tempVec;
		tempVec.x = vec.x * scalar;
		tempVec.y = vec.y * scalar;

		return tempVec;
	}

	float GetVectorMagnitude(const Vector2D& vec)
	{
		return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	}

	Vector2D GetNormalizedVector(const Vector2D& vec)
	{
		float magnitude = GetVectorMagnitude(vec);

		Vector2D tempVec;
		tempVec.x = vec.x / magnitude;
		tempVec.y = vec.y / magnitude;
		return tempVec;
	}

	float DotProduct(const Vector2D& vec1, const Vector2D& vec2)
	{
		float result = (vec1.x * vec2.x) + (vec1.y * vec2.y);
		return result;
	}

	float GetVectorsAngle(const Vector2D& vec1, const Vector2D& vec2, bool inDegrees)
	{
		float dotProd = DotProduct(vec1, vec2);
		float vec1Magnitude = GetVectorMagnitude(vec1);
		float vec2Magnitude = GetVectorMagnitude(vec2);
		float angle = acos(dotProd / (vec1Magnitude * vec2Magnitude));

		return inDegrees ? angle * static_cast<float>(180 / M_PI) : angle;
	}

	bool VectorEquality(const Vector2D& vec1, const Vector2D& vec2)
	{
		return (vec1.x == vec2.x) && (vec1.y == vec2.y);
	}

	Vector2D GetPerpendicularVector(const Vector2D& vec)
	{
		return Vector2D(-vec.y, vec.x);
	}
}
