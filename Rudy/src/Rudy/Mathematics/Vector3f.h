#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	/// <summary>
	/// Basic floating Vector2 structure
	/// </summary>
	struct RUDY_API Vector3f
	{
	public:
		/// <summary>
		/// Returns the dot product value of the two give vector
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		static float DotPruduct(const Vector3f& a, const Vector3f& b);

		/// <summary>
		/// Returns the perpendicalar vector to the two given vector
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		/// <see cref="https://www.mathsisfun.com/algebra/vectors-cross-product.html"/>
		static Vector3f CrossProduct(const Vector3f& a, const Vector3f& b);

		Vector3f(float x, float y,float z);
		Vector3f(float value);
		Vector3f();
		~Vector3f() = default;

		/// <summary>
		/// Returns the magnitude of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE float GetLength() const;

		/// <summary>
		/// Returns the normalized version of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector3f GetNormalized() const;

		/// <summary>
		/// Normalizes this vector
		/// </summary>
		void NormalizeThis();

		/// <summary>
		/// The horizontal axis component
		/// </summary>
		float X;

		/// <summary>
		/// The vertical axis component
		/// </summary>
		float Y;

		/// <summary>
		/// The depth axis component
		/// </summary>
		float Z;

		/*
		* Operators
		*/
		void operator=(const Vector3f& other);
		void operator=(const float other);
		void operator+=(const Vector3f& other);
		void operator-=(const Vector3f& other);
		void operator*=(const Vector3f& other);
		void operator/=(const Vector3f& other);
		void operator+=(const float other);
		void operator-=(const float other);
		void operator*=(const float other);
		void operator/=(const float other);

		
	};

	static Vector3f operator+(const Vector3f& a, const Vector3f& b)
	{
		return Vector3f(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
	}
	static Vector3f operator-(const Vector3f& a, const Vector3f& b)
	{
		return Vector3f(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
	}
	static Vector3f operator*(const Vector3f& a, const Vector3f& b)
	{
		return Vector3f(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
	}
	static Vector3f operator/(const Vector3f& a, const Vector3f& b)
	{
		return Vector3f(a.X / b.X, a.Y / b.Y, a.Z / b.Z);
	}
	static Vector3f operator+(const Vector3f& a, float value)
	{
		return Vector3f(a.X + value, a.Y + value, a.Z + value);
	}
	static Vector3f operator-(const Vector3f& a, float value)
	{
		return Vector3f(a.X - value, a.Y - value, a.Z - value);
	}
	static Vector3f operator*(const Vector3f& a, float value)
	{
		return Vector3f(a.X * value, a.Y * value, a.Z * value);
	}
	static Vector3f operator/(const Vector3f& a, float value)
	{
		return Vector3f(a.X / value, a.Y / value, a.Z / value);
	}
}