#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Basic string implementation
	/// </summary>
	class RUDY_API String
	{
	public:
		String();
		String(const String& other);
		String(const char* other);
		~String();

		/// <summary>
		/// Returns the current char amount in this string
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetCursor() const;

		/// <summary>
		/// Returns a pointer to the source data
		/// </summary>
		/// <returns></returns>
		char* GetSource() const;

		/*
		* Operators
		*/
		const char* operator*() const;
		void operator+=(const String& other);
		void operator+=(const char* other);
		void operator+=(char other);
		char operator[](unsigned int index) const;
		void operator=(const String& other);
		
	private:
		char* m_Source;
		unsigned int m_Cursor;
		
	};

}
