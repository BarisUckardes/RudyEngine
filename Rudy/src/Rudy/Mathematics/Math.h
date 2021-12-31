#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	#define PI 3.14159265359
	#define DegToRadCoef 0.01745329252f
	#define RadToDegCoef 357.295779513f
	/// <summary>
	/// General purpose math library interface
	/// </summary>
	class RUDY_API Math
	{
	public:
		Math() = default;
		~Math() = default;

		/// <summary>
		/// Returns the square root of a flaot value
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static FORCEINLINE float SquareRoot(float value);

		/// <summary>
		/// Returns the square root of a integer value
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static FORCEINLINE int SquareRoot(int value);

		/// <summary>
		/// Returns the sin value of the given radians
		/// </summary>
		/// <param name="rads"></param>
		/// <returns></returns>
		static FORCEINLINE float Sin(float rads);

		/// <summary>
		/// Returns the cos value of the given radians
		/// </summary>
		/// <param name="rads"></param>
		/// <returns></returns>
		static FORCEINLINE float Cos(float rads);

		/// <summary>
		/// Returns the tangent value of the given radians
		/// </summary>
		/// <param name="rads"></param>
		/// <returns></returns>
		static FORCEINLINE float Tan(float rads);

		/// <summary>
		/// Lerps two floats between them
		/// </summary>
		/// <param name="from"></param>
		/// <param name="to"></param>
		/// <param name="alpha"></param>
		/// <returns></returns>
		static FORCEINLINE float Lerp(float from, float to, float alpha);

		/// <summary>
		/// Returns the absolute value of a float
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static FORCEINLINE float Abs(float value);

		/// <summary>
		/// Clamps a value between min and max
		/// </summary>
		/// <param name="value"></param>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		static FORCEINLINE float Clamp(float value, float min, float max);

		/// <summary>
		/// Returns the min value of the two given values
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		static FORCEINLINE float Min(float a, float b);

		/// <summary>
		/// Retunrs the max value of the two given values
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		static FORCEINLINE float Max(float a, float b);

	};
}