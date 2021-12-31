#include "Vector3f.h"
#include <cmath>

namespace Rudy
{
	float Vector3f::DotPruduct(const Vector3f& a, const Vector3f& b)
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}
	Vector3f Vector3f::CrossProduct(const Vector3f& a, const Vector3f& b)
	{
		return Vector3f(
			a.Y * b.Z - a.Z * b.Y,
			a.Z * b.X - a.X * b.Z,
			a.X * b.Y - a.Y * b.X);
	}
	Vector3f::Vector3f(float x, float y,float z)
	{
		X = x;
		Y = y;
		Z = z;
	}
	Vector3f::Vector3f(float value)
	{
		X = Y = Z = value;
	}
	Vector3f::Vector3f()
	{
		X = Y = Z = 0;
	}
	float Vector3f::GetLength() const
	{
		return (sqrt((X * X)) + sqrt((Y * Y)) + sqrt(Z*Z));
	}
	Vector3f Vector3f::GetNormalized() const
	{
		/*
		* Get vector length
		*/
		const float length = GetLength();

		return Vector3f(X / length, Y / length,Z / length);
	}
	void Vector3f::NormalizeThis()
	{
		/*
		* Get length
		*/
		const float length = GetLength();

		/*
		* Normalize self components
		*/
		X /= length;
		Y /= length;
		Z /= length;
	}
	void Vector3f::operator=(const Vector3f& other)
	{
		X = other.X;
		Y = other.Y;
		Z = other.Z;
	}
	void Vector3f::operator=(const float other)
	{
		X = Y = Z = other;
	}
	void Vector3f::operator+=(const Vector3f& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;

	}
	void Vector3f::operator-=(const Vector3f& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
	}
	void Vector3f::operator*=(const Vector3f& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;
	}
	void Vector3f::operator/=(const Vector3f& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;
	}
	void Vector3f::operator+=(const float other)
	{
		X += other;
		Y += other;
		Z += other;
	}
	void Vector3f::operator-=(const float other)
	{
		X -= other;
		Y -= other;
		Z -= other;
	}
	void Vector3f::operator*=(const float other)
	{
		X *= other;
		Y *= other;
		Z *= other;
	}
	void Vector3f::operator/=(const float other)
	{
		X /= other;
		Y /= other;
		Z /= other;
	}
}