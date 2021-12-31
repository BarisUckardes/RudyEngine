#pragma once
#include <Rudy/Core/Symbols.h>
namespace Rudy
{
	/// <summary>
	/// A color struct holds 32-bit float r,g,b,a
	/// </summary>
	struct RUDY_API ColorRgba
	{
		static ColorRgba CornFlowerBlue()
		{
			return ColorRgba(100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f);
		}
		static ColorRgba Crimson()
		{
			return ColorRgba(220.0f / 255.0f, 20.0f / 255.0f, 60.0f / 255.0f);
		}
		/*static RUDY_EXPORT const Color CornFlowerBlue;
		static RUDY_EXPORT const Color Crimson;
		static RUDY_EXPORT const Color IndianRed;
		static RUDY_EXPORT const Color Pink;
		static RUDY_EXPORT const Color PaleVioletred;
		static RUDY_EXPORT const Color Hotpink;
		static RUDY_EXPORT const Color Deeppink;
		static RUDY_EXPORT const Color Maroon;
		static RUDY_EXPORT const Color Orchid;
		static RUDY_EXPORT const Color Plum;
		static RUDY_EXPORT const Color Magenta;
		static RUDY_EXPORT const Color Purple;
		static RUDY_EXPORT const Color Indigo;
		static RUDY_EXPORT const Color SlateBlue;
		static RUDY_EXPORT const Color Blue;
		static RUDY_EXPORT const Color Navy;
		static RUDY_EXPORT const Color MidnightBlue;
		static RUDY_EXPORT const Color Cobalt;
		static RUDY_EXPORT const Color RoyalBlue;
		static RUDY_EXPORT const Color DodgerBlue;
		static RUDY_EXPORT const Color SteelBlue;
		static RUDY_EXPORT const Color SkyBlue;
		static RUDY_EXPORT const Color DeepSkyBlue;
		static RUDY_EXPORT const Color Peacock;
		static RUDY_EXPORT const Color LightBlue;
		static RUDY_EXPORT const Color PowderBlue;
		static RUDY_EXPORT const Color CadetBlue;
		static RUDY_EXPORT const Color Turquoise;
		static RUDY_EXPORT const Color Azure;
		static RUDY_EXPORT const Color LightCyan;
		static RUDY_EXPORT const Color Cyan;
		static RUDY_EXPORT const Color Aquamarine;
		static RUDY_EXPORT const Color MediumSpringGreen;
		static RUDY_EXPORT const Color SpringGreen;
		static RUDY_EXPORT const Color Seagreen;
		static RUDY_EXPORT const Color EmeraldGreen;
		static RUDY_EXPORT const Color Mint;
		static RUDY_EXPORT const Color Honeydew;
		static RUDY_EXPORT const Color Palegreen;
		static RUDY_EXPORT const Color Limegreen;
		static RUDY_EXPORT const Color Green;
		static RUDY_EXPORT const Color Lawngreen;
		static RUDY_EXPORT const Color Chartreuse;
		static RUDY_EXPORT const Color Olivedrab;
		static RUDY_EXPORT const Color Ivory;
		static RUDY_EXPORT const Color Beige;
		static RUDY_EXPORT const Color LightYellow;
		static RUDY_EXPORT const Color Yellow;
		static RUDY_EXPORT const Color Khaki;
		static RUDY_EXPORT const Color Palegoldenrod;
		static RUDY_EXPORT const Color Banana;
		static RUDY_EXPORT const Color Golden;
		static RUDY_EXPORT const Color Orange;
		static RUDY_EXPORT const Color Cornsilk;
		static RUDY_EXPORT const Color FloralWhite;
		static RUDY_EXPORT const Color Oldlace;
		static RUDY_EXPORT const Color Wheat;
		static RUDY_EXPORT const Color Moccasin;
		static RUDY_EXPORT const Color Papayawhip;
		static RUDY_EXPORT const Color NavojoWhite;
		static RUDY_EXPORT const Color Eggshell;
		static RUDY_EXPORT const Color Tan;
		static RUDY_EXPORT const Color Brick;
		static RUDY_EXPORT const Color CadmiumYellow;
		static RUDY_EXPORT const Color AntiqueWhite;
		static RUDY_EXPORT const Color Bisque;
		static RUDY_EXPORT const Color Melon;
		static RUDY_EXPORT const Color Carrow;
		static RUDY_EXPORT const Color DarkOrange;
		static RUDY_EXPORT const Color Linen;
		static RUDY_EXPORT const Color Chocolate;
		static RUDY_EXPORT const Color Chocolate1;
		static RUDY_EXPORT const Color Chocolate2;
		static RUDY_EXPORT const Color Chocolate3;
		static RUDY_EXPORT const Color IvoryBlack;
		static RUDY_EXPORT const Color Sienna;
		static RUDY_EXPORT const Color OrangeRed;
		static RUDY_EXPORT const Color Sepia;
		static RUDY_EXPORT const Color Darksalmon;
		static RUDY_EXPORT const Color Coral;
		static RUDY_EXPORT const Color Burntumber;
		static RUDY_EXPORT const Color Tamato;
		static RUDY_EXPORT const Color Mistyrose;
		static RUDY_EXPORT const Color Snow;
		static RUDY_EXPORT const Color RosyBrown;
		static RUDY_EXPORT const Color Brown;
		static RUDY_EXPORT const Color Firebrick;
		static RUDY_EXPORT const Color Silver;*/

		ColorRgba()
		{
			R = G = B = A = 0.0f;
		}

		ColorRgba(float r, float g, float b, float a = 1.0f)
		{
			R = r;
			G = g;
			B = b;
			A = a;

		}

		/// <summary>
		/// The red component of the color
		/// </summary>
		float R;

		/// <summary>
		/// Green component of the color
		/// </summary>
		float G;

		/// <summary>
		/// Blue component of the color
		/// </summary>
		float B;

		/// <summary>
		/// Alpha component of the color
		/// </summary>
		float A;
	};
}