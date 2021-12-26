#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	/// <summary>
	/// Basic floating Vector2 structure
	/// </summary>
	RUDY_API struct Vector2f
	{
	public:
		Vector2f(float x, float y);
		Vector2f(float value);
		Vector2f();
		~Vector2f() = default;

		/// <summary>
		/// Returns the magnitude of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE float GetLength() const;

		/// <summary>
		/// Returns the normalized version of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2f GetNormalized() const;

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

		/*
		* Operators
		*/
		void operator=(const Vector2f& other);
		void operator=(const float other);
		void operator+=(const Vector2f& other);
		void operator-=(const Vector2f& other);
		void operator*=(const Vector2f& other);
		void operator/=(const Vector2f& other);
		void operator+=(const float other);
		void operator-=(const float other);
		void operator*=(const float other);
		void operator/=(const float other);
		//Vector2f operator+(const Vector2f& b);
		//Vector2f operator-(const Vector2f& b);
		//Vector2f operator/(const Vector2f& b);
		//Vector2f operator*(const Vector2f& b);
		//bool operator==(const Vector2f& b);
		//bool operator!=(const Vector2f& b);
	};
}