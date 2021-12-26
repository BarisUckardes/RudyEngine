#include "Vector2i.h"
#include <cmath>

namespace Rudy
{
	Vector2i::Vector2i(int x, int y)
	{
		X = x;
		Y = y;
	}
	Vector2i::Vector2i(int value)
	{
		X = Y = value;
	}
	Vector2i::Vector2i()
	{
		X = Y = 0;
	}
	int Vector2i::GetLength() const
	{
		return (sqrt((X * X)) + sqrt((Y * Y)));
	}
	Vector2i Vector2i::GetNormalized() const
	{
		/*
		* Get vector length
		*/
		const int length = GetLength();

		return Vector2i(X / length, Y / length);
	}
	void Vector2i::NormalizeThis()
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
	}
	void Vector2i::operator=(const Vector2i& other)
	{
		X = other.X;
		Y = other.Y;
	}
	void Vector2i::operator=(const int other)
	{
		X = Y = other;
	}
	void Vector2i::operator+=(const Vector2i& other)
	{
		this->X += other.X;
		this->Y += other.Y;
	}
	void Vector2i::operator-=(const Vector2i& other)
	{
		this->X -= other.X;
		this->Y -= other.Y;
	}
	void Vector2i::operator*=(const Vector2i& other)
	{
		X *= other.X;
		Y *= other.Y;
	}
	void Vector2i::operator/=(const Vector2i& other)
	{
		X /= other.X;
		Y /= other.Y;
	}
	void Vector2i::operator+=(const int other)
	{
		X += other;
		Y += other;
	}
	void Vector2i::operator-=(const int other)
	{
		this->X -= other;
		this->Y -= other;
	}
	void Vector2i::operator*=(const int other)
	{
		this->X *= other;
		this->Y *= other;
	}
	void Vector2i::operator/=(const int other)
	{
		this->X /= other;
		this->Y /= other;
	}
	//Vector2i Vector2i::operator+(const Vector2i& a, const Vector2i& b)
	//{
	//	return Vector2i(a.X + b.X, a.Y + b.Y);
	//}
	//Vector2i Vector2i::operator-(const Vector2i& a, const Vector2i& b)
	//{
	//	return Vector2i(a.X - b.X, a.Y - b.Y);
	//}
	//Vector2i Vector2i::operator/(const Vector2i& a, const Vector2i& b)
	//{
	//	return Vector2i(a.X / b.X, a.Y / b.Y);
	//}
	//Vector2i Vector2i::operator*(const Vector2i& a, const Vector2i& b)
	//{
	//	return Vector2i(a.X * b.X, a.Y * b.Y);
	//}
	//bool Vector2i::operator==(const Vector2i& a, const Vector2i& b)
	//{
	//	return a.X == b.X && a.Y == b.Y;
	//}
	//bool Vector2i::operator!=(const Vector2i& a, const Vector2i& b)
	//{
	//	return a.X != b.X || a.Y != b.Y;
	//}
}