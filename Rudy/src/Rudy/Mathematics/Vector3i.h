#pragma once
#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	/// <summary>
	/// Basic inting Vector2 structure
	/// </summary>
	struct RUDY_API Vector3i
	{
	public:
		Vector3i(int x, int y, int z);
		Vector3i(int value);
		Vector3i();
		~Vector3i() = default;

		/// <summary>
		/// Returns the magnitude of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE int GetLength() const;

		/// <summary>
		/// Returns the normalized version of this vector
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector3i GetNormalized() const;

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

		/// <summary>
		/// The depth axis component
		/// </summary>
		int Z;

		/*
		* Operators
		*/
		void operator=(const Vector3i& other);
		void operator=(const int other);
		void operator+=(const Vector3i& other);
		void operator-=(const Vector3i& other);
		void operator*=(const Vector3i& other);
		void operator/=(const Vector3i& other);
		void operator+=(const int other);
		void operator-=(const int other);
		void operator*=(const int other);
		void operator/=(const int other);
		//Vector3i operator+(const Vector3i& b);
		//Vector3i operator-(const Vector3i& b);
		//Vector3i operator/(const Vector3i& b);
		//Vector3i operator*(const Vector3i& b);
		//bool operator==(const Vector3i& b);
		//bool operator!=(const Vector3i& b);
	};
}