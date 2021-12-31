#include "Math.h"
#include <cmath>
namespace Rudy
{
	FORCEINLINE float Math::SquareRoot(float value)
	{
		return sqrt(value);
	}
	FORCEINLINE int Math::SquareRoot(int value)
	{
		return sqrt(value);
	}
	FORCEINLINE float Math::Cos(float rads)
	{
		return cos(rads);
	}
	FORCEINLINE float Math::Sin(float rads)
	{
		return sin(rads);
	}
	FORCEINLINE float Math::Tan(float rads)
	{
		return tan(rads);
	}
	FORCEINLINE float Math::Lerp(float from, float to, float alpha)
	{
		const float direction = to - from;
		return from + direction * alpha;
	}
	FORCEINLINE float Math::Abs(float value)
	{
		return (value > 0) ? value : -value;
	}
	FORCEINLINE float Math::Clamp(float value, float min, float max)
	{
		return value > max ? max : value < min ? min : value;
	}
	FORCEINLINE float Math::Min(float a, float b)
	{
		return a > b ? b : a;
	}
	FORCEINLINE float Math::Max(float a, float b)
	{
		return a > b ? a : b;
	}
}