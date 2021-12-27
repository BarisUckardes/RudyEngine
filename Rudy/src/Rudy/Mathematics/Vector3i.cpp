#include "Vector3i.h"
#include <cmath>

namespace Rudy
{
	Vector3i::Vector3i(int x, int y, int z)
	{
		X = x;
		Y = y;
		Z = z;
	}
	Vector3i::Vector3i(int value)
	{
		X = Y = Z = value;
	}
	Vector3i::Vector3i()
	{
		X = Y = Z = 0;
	}
	int Vector3i::GetLength() const
	{
		return (sqrt((X * X)) + sqrt((Y * Y)) + sqrt(Z * Z));
	}
	Vector3i Vector3i::GetNormalized() const
	{
		/*
		* Get vector length
		*/
		const int length = GetLength();

		return Vector3i(X / length, Y / length, Z / length);
	}
	void Vector3i::NormalizeThis()
	{
		/*
		* Get length
		*/
		const int length = GetLength();

		/*
		* Normalize self components
		*/
		X /= length;
		Y /= length;
		Z /= length;
	}
	void Vector3i::operator=(const Vector3i& other)
	{
		X = other.X;
		Y = other.Y;
		Z = other.Z;
	}
	void Vector3i::operator=(const int other)
	{
		X = Y = Z = other;
	}
	void Vector3i::operator+=(const Vector3i& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;

	}
	void Vector3i::operator-=(const Vector3i& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
	}
	void Vector3i::operator*=(const Vector3i& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;
	}
	void Vector3i::operator/=(const Vector3i& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;
	}
	void Vector3i::operator+=(const int other)
	{
		X += other;
		Y += other;
		Z += other;
	}
	void Vector3i::operator-=(const int other)
	{
		X -= other;
		Y -= other;
		Z -= other;
	}
	void Vector3i::operator*=(const int other)
	{
		X *= other;
		Y *= other;
		Z *= other;
	}
	void Vector3i::operator/=(const int other)
	{
		X /= other;
		Y /= other;
		Z /= other;
	}
}