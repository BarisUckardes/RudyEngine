#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	/// <summary>
	/// Basic floating Vector2 structure
	/// </summary>
	RUDY_API struct Vector2i
	{
	public:
		Vector2i(int x, int y);
		Vector2i(int value);
		Vector2i();
		~Vector2i() = default;

		/// <summary>
		/// Returns the magnitude of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE int GetLength() const;

		/// <summary>
		/// Returns the normalized version of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2i GetNormalized() const;

		/// <summary>
		/// Normalizes this vector
		/// </summary>
		void NormalizeThis();

		/// <summary>
		/// The horizontal axis component
		/// </summary>
		int X;

		/// <summary>
		/// The vertical axis component
		/// </summary>
		int Y;

		/*
		* Operators
		*/
		void operator=(const Vector2i& other);
		void operator=(const int other);
		void operator+=(const Vector2i& other);
		void operator-=(const Vector2i& other);
		void operator*=(const Vector2i& other);
		void operator/=(const Vector2i& other);
		void operator+=(const int other);
		void operator-=(const int other);
		void operator*=(const int other);
		void operator/=(const int other);
		//Vector2i operator+(const Vector2i& a, const Vector2i& b);
		//Vector2i operator-(const Vector2i& a, const Vector2i& b);
		//Vector2i operator/(const Vector2i& a, const Vector2i& b);
		//Vector2i operator*(const Vector2i& a, const Vector2i& b);
		//bool operator==(const Vector2i& a, const Vector2i& b);
		//bool operator!=(const Vector2i& a, const Vector2i& b);
	};
}