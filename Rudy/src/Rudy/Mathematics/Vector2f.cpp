#include "Vector2f.h"
#include <cmath>

namespace Rudy
{
	Vector2f::Vector2f(float x, float y)
	{
		X = x;
		Y = y;
	}
	Vector2f::Vector2f(float value)
	{
		X = Y = value;
	}
	Vector2f::Vector2f()
	{
		X = Y = 0;
	}
	float Vector2f::GetLength() const
	{
		return (sqrt((X * X)) +sqrt((Y * Y)));
	}
	Vector2f Vector2f::GetNormalized() const
	{
		/*
		* Get vector length
		*/
		const float length = GetLength();

		return Vector2f(X / length,Y / length);
	}
	void Vector2f::NormalizeThis()
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
	}
	void Vector2f::operator=(const Vector2f& other)
	{
		X = other.X;
		Y = other.Y;
	}
	void Vector2f::operator=(const float other)
	{
		X = Y = other;
	}
	void Vector2f::operator+=(const Vector2f& other)
	{
		X += other.X;
		Y += other.Y;
	}
	void Vector2f::operator-=(const Vector2f& other)
	{
		X -= other.X;
		Y -= other.Y;
	}
	void Vector2f::operator*=(const Vector2f& other)
	{
		X *= other.X;
		Y *= other.Y;
	}
	void Vector2f::operator/=(const Vector2f& other)
	{
		X /= other.X;
		Y /= other.Y;
	}
	void Vector2f::operator+=(const float other)
	{
		X += other;
		Y += other;
	}
	void Vector2f::operator-=(const float other)
	{
		X -= other;
		Y -= other;
	}
	void Vector2f::operator*=(const float other)
	{
		X *= other;
		Y *= other;
	}
	void Vector2f::operator/=(const float other)
	{
		X /= other;
		Y /= other;
	}
}