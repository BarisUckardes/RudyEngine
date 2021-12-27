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
		//Vector3f operator+(const Vector3f& b);
		//Vector3f operator-(const Vector3f& b);
		//Vector3f operator/(const Vector3f& b);
		//Vector3f operator*(const Vector3f& b);
		//bool operator==(const Vector3f& b);
		//bool operator!=(const Vector3f& b);
	};
}