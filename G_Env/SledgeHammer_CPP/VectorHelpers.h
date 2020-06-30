#pragma once
#include "Vector2D.h"
namespace VectorHelpers
{
	/// <summary>
	/// Returns the addition of 2 vectors as a new vector.
	/// Vector addition maps the second vector onto the end of the first vector.
	/// </summary>
	Vector2D VectorAddition(const Vector2D& vec1, const Vector2D& vec2);

	/// <summary>
	/// Returns the substraction of 2 vectors as a new vector.
	/// Vector substraction results in the vector going from the end of the second vector to the end of the first vector.
	/// </summary>
	Vector2D VectorSubstraction(const Vector2D& vec1, const Vector2D& vec2);

	/// <summary>
	/// Returns the scalar multiplication of a vector as a new vector.
	/// Scalar multiplication lengthens, shortens or flips a vector.
	/// - a scalar larger than 1 will lengthen.
	/// - a scalar smaller than 1 but larger than 0 will shorten.
	/// - a negative scalar will flip the direction.
	/// - multiplying with 0 will create a zero vector.
	/// </summary>
	Vector2D ScalarMultiplication(const Vector2D& vec, float scalar);

	/// <summary>
	/// Returns the magnituted of a vector (i.e. the length of a vector).
	/// The magnitude of a 2D vector is calculated by applying Pythagorean on the x and y of the vector.
	/// - Magnitude = Sqrt(x² + y²)
	/// </summary>
	float GetVectorMagnitude(const Vector2D& vec);

	/// <summary>
	///  Normalizes a vector and returns it as a new vector.
	/// Normalizing a vector is converting a vector to have a agnitude of 1.
	/// Normalizing is done by dividing both the x and the y conponent by the vectors magnitude.
	/// </summary>
	Vector2D GetNormalizedVector(const Vector2D& vec);

	/// <summary>
	/// Returns a scalar that is the direct result of vector multiplication.
	/// - DotProd = vec1 * vec2 = (vec1.x * vec2.x) + (vec1.y * vec2.y)
	/// </summary>
	float DotProduct(const Vector2D& vec1, const Vector2D& vec2);

	/// <summary>
	/// Returns the angle between 2 vectors.
	/// The angle is returned in radians.
	/// Specify the optional 'inDegrees' parameter to true, to get the result in degrees.
	/// The angle is calculated by using trigonometry: the inverse cosine of the ratio of the dotproduct over the product of the vectors magnitudes.
	/// angle = acos((vec1 * vec2) / (magnitudeVec1 * magnitudeVec2))
	/// </summary>
	float GetVectorsAngle(const Vector2D& vec1, const Vector2D& vec2, bool inDegrees = false);

	/// <summary>
	/// Checks if 2 vectors are equal.
	/// Equality is true if the both vectors have the same direction and magnitude.
	/// </summary>
	bool VectorEquality(const Vector2D& vec1, const Vector2D& vec2);

	/// <summary>
	/// Returns the perpendicular vector of the given 2D vector as a new vector.
	/// </summary>
	Vector2D GetPerpendicularVector(const Vector2D& vec);
};