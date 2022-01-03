#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	/// <summary>
	/// Basic string implementation
	/// </summary>
	class RUDY_API String
	{
	public:
		/// <summary>
		/// Returns a string representation of the float variable
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static String GetFromFloat(float value);

		/// <summary>
		/// Returns an string represetntation of the integer variable
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static String GetFromInteger(int value);

		/// <summary>
		/// Returns a float from the string
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static float ToFloat(const String& value);

		/// <summary>
		/// Returns an integer from the string
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		static int ToInteger(const String& value);

		String();
		String(const String& other);
		String(const char* other);
		String(unsigned int size);
		String(const char* target, unsigned int size);
		
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

		/// <summary>
		/// Finds the starting index of the target string
		/// </summary>
		int FindIndex(const String& targetString, unsigned int startIndex) const;

		/// <summary>
		/// Splits the string by the target char and returns the splitted fragments
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		Array<String> SplitByChar(char targetChar) const;

		/// <summary>
		/// Returns the target chars index
		/// </summary>
		int FindIndex(char targetChar) const;

		/// <summary>
		/// Returns a subset
		/// </summary>
		String GetSubset(unsigned int start, unsigned  int length) const;

	    /// <summary>
	    /// Clears the memory of the string
	    /// </summary>
	    void Clear();

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

	RUDY_API String operator+(const String& target0, const String& target1);
	RUDY_API bool operator==(const String& target0, const String& target1);
	RUDY_API bool operator!=(const String& target0, const String& target1);
}
