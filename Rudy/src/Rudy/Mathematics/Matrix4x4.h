#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Mathematics/Vector3f.h>
#include <Rudy/Memory/String.h>
namespace Rudy
{
	/// <summary>
	/// Class for matrix4x4 operations
	/// </summary>
	struct RUDY_API Matrix4x4
	{
		/// <summary>
		/// Returns an identity matrix
		/// </summary>
		/// <returns></returns>
		static Matrix4x4 IdentityMatrix();

		/// <summary>
		/// Returns a zero matrix
		/// </summary>
		/// <returns></returns>
		static Matrix4x4 ZeroMatrix();

		/// <summary>
		/// Creats a translation matrix
		/// </summary>
		/// <param name="position"></param>
		/// <returns></returns>
		static Matrix4x4 CreateTranslationMatrix(const Vector3f& position);

		/// <summary>
		/// Creates a translation matrix
		/// </summary>
		/// <param name="scale"></param>
		/// <returns></returns>
		static Matrix4x4 CreateScaleMatrix(const Vector3f& scale);

		/// <summary>
		/// Creates a rotation matrix with the x-axis
		/// </summary>
		/// <param name="rotation"></param>
		/// <returns></returns>
		static Matrix4x4 CreateRotationXMatrix(float rotation);

		/// <summary>
		/// Creates a rotation matrix with the x-axis
		/// </summary>
		/// <param name="rotation"></param>
		/// <returns></returns>
		static Matrix4x4 CreateRotationYMatrix(float rotation);

		/// <summary>
		/// Creats a rotation matrix with the y-axis
		/// </summary>
		/// <param name="rotation"></param>
		/// <returns></returns>
		static Matrix4x4 CreateRotationZMatrix(float rotation);

		/// <summary>
		/// Creates 2D ortho projection
		/// </summary>
		/// <param name="left"></param>
		/// <param name="right"></param>
		/// <param name="bottom"></param>
		/// <param name="top"></param>
		/// <param name=""></param>
		/// <param name=""></param>
		/// <param name="aspectRatio"></param>
		/// <returns></returns>
		static Matrix4x4 CreateOrthoProjection(float left, float right, float bottom, float top, float near, float far, float aspectRatio = 1.0f);

		/// <summary>
		/// Creates a 3D perspective projection
		/// </summary>
		/// <param name="fov"></param>
		/// <param name="nearPlane"></param>
		/// <param name="farPlane"></param>
		/// <param name="aspect"></param>
		/// <returns></returns>
		static Matrix4x4 CreatePerspective(float fov, float nearPlane, float farPlane, float aspect);

		/// <summary>
		/// Creates a view matrix
		/// </summary>
		/// <param name="observerPosition"></param>
		/// <param name="lookPosition"></param>
		/// <param name="relativeUpVector"></param>
		/// <returns></returns>
		static Matrix4x4 CreateView(const Vector3f& observerPosition, const Vector3f& lookPosition, const Vector3f& relativeUpVector);

		Matrix4x4();

		Matrix4x4(
			float a0, float a1, float a2, float a3,
			float b0, float b1, float b2, float b3,
			float c0, float c1, float c2, float c3,
			float d0, float d1, float d2, float d3);

		/// <summary>
		/// Returns whether this matrix has a reverse matrix or not
		/// </summary>
		/// <returns></returns>
		bool IsInvertable() const;

		/// <summary>
		/// Returns the determinant value of this matrix
		/// </summary>
		/// <returns></returns>
		float GetDeterminant() const;

		/// <summary>
		/// Returns the transpose matrix of this matrix
		/// </summary>
		/// <returns></returns>
		Matrix4x4 GetTranspose() const;

		/// <summary>
		/// Transposes this matrix
		/// </summary>
		void TransposeThis();

		/// <summary>
		/// Returns this matrix as string
		/// </summary>
		/// <returns></returns>
		String GetString() const;

		float A0, A1, A2, A3;
		float B0, B1, B2, B3;
		float C0, C1, C2, C3;
		float D0, D1, D2, D3;

		Matrix4x4 operator +(const Matrix4x4& a);

		Matrix4x4 operator -(const Matrix4x4& a);

		Matrix4x4 operator*(const Matrix4x4& a);
	};
}