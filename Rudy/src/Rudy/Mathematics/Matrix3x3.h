#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	/// <summary>
	/// Class for matrix3x3 opearations
	/// </summary>
	struct RUDY_API Matrix3x3
	{

		/// <summary>
		/// Returns a 3x3 identity matrix
		/// </summary>
		/// <returns></returns>
		static Matrix3x3 IdentityMatrix();

		Matrix3x3();
		Matrix3x3(float a0, float a1, float a2,
			float b0, float b1, float b2,
			float c0, float c1, float c2);

		/// <summary>
		/// Returns whether this matrix can be reversed or not
		/// </summary>
		/// <returns></returns>
		bool IsInvertable() const;

		/// <summary>
		/// Returns the detminant value of this matrix
		/// </summary>
		/// <returns></returns>
		float GetDeterminant() const;

		/// <summary>
		/// Returns the inverse matrix of this matrix
		/// </summary>
		/// <returns></returns>
		Matrix3x3 GetInverse() const;

		/// <summary>
		/// Returns the transpose matrix of this matrix
		/// </summary>
		/// <returns></returns>
		Matrix3x3 GetTranspose() const;

		/// <summary>
		/// Transposes this matrix
		/// </summary>
		void TransposeThis();

		float A0, A1, A2;
		float B0, B1, B2;
		float C0, C1, C2;


		Matrix3x3 operator*(float a);
		Matrix3x3 operator +(const Matrix3x3& a);

		Matrix3x3 operator -(const Matrix3x3& a);

		Matrix3x3 operator*(const Matrix3x3& a);
	};
}