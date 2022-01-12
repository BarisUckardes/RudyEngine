#pragma once
#include <Rudy/Memory/String.h>
namespace Rudy
{
	// <summary>
	/// Contains a 128 bit unique id
	/// </summary>
	class RUDY_API Guid
	{
	public:
		/// <summary>
		/// Returns the zero guid
		/// </summary>
		/// <returns></returns>
		static Guid GetZero();

		/// <summary>
		/// Creates a new platform agnostic guid
		/// </summary>
		/// <returns></returns>
		static Guid Create();

		/// <summary>
		/// Returns a guid from string
		/// </summary>
		/// <param name="targetString"></param>
		/// <returns></returns>
		static bool GetFromString(const String& targetString, Guid& idOut);
	private:
		static char* GuidToStrCore(const Guid* id, char* out);
		static Guid StringToGuidCore(const String& guid);
	public:
		Guid(unsigned long a, unsigned short b, unsigned short c, unsigned char d[8]);
		Guid();

		/// <summary>
		/// Returns this guid as string
		/// </summary>
		/// <returns></returns>
		String GetAsString() const;

		unsigned long A;
		unsigned short B;
		unsigned short C;
		unsigned char D[8];

	};
	RUDY_API bool operator==(const Guid& a, const Guid& b);
	RUDY_API bool operator!=(const Guid& a, const Guid& b);
}