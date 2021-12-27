#include "String.h"

namespace Rudy
{
	unsigned int GetCharPointerSize(const char* target)
	{
		unsigned int size = 0;
		while (target[size] != '\0')
			size++;
		return size;
	}

	String::String()
	{
		m_Source = nullptr;
		m_Cursor = 0;
	}

	String::String(const String& other)
	{
		/*
		* Allocate space for target string source
		*/
		const unsigned int targetSize = other.GetCursor();
		m_Cursor = targetSize;
		m_Source = new char[targetSize];

		/*
		* Copy
		*/
		for (unsigned int i = 0; i < targetSize; i++)
		{
			m_Source[i] = other.m_Source[i];
		}

		/*
		* Set escape char
		*/
		m_Source[targetSize] = '\0';
	}

	String::String(const char* other)
	{
		/*
		* Allocate space for target char source
		*/
		const unsigned int totalCharSize = GetCharPointerSize(other);
		m_Cursor = totalCharSize;
		m_Source = new char[totalCharSize + 1];

		/*
		* Copy other source data
		*/
		for (unsigned int i = 0; i < m_Cursor; i++)
			m_Source[i] = other[i];

		/*
		* Set escape
		*/
		m_Source[totalCharSize] = '\0';
	}

	String::~String()
	{
		m_Cursor = 0;
		delete[] m_Source;
		m_Source = nullptr;
	}

	unsigned int String::GetCursor() const
	{
		return m_Cursor;
	}
	char* String::GetSource() const
	{
		return m_Source;
	}
	const char* String::operator*() const
	{
		return m_Source;
	}

	void String::operator+=(const String& other)
	{
		/*
		* Get new length
		*/
		const unsigned int newLength = m_Cursor + other.GetCursor();

		/*
		* Allocate new source
		*/
		char* newSource = new char[newLength + 1];

		/*
		* Set former elements
		*/
		for (unsigned int i = 0; i < m_Cursor; i++)
			newSource[i] = m_Source[i];

		/*
		* Copy target
		*/
		{
			unsigned int targetIndex = 0;
			for (int i = m_Cursor; i < newLength; i++)
			{
				newSource[i] = other[targetIndex];
				targetIndex++;
			}
		}

		/*
		* Set escape
		*/
		newSource[newLength] = '\0';

		/*
		* Free old source
		*/
		delete[] m_Source;

		/*
		* Set new source
		*/
		m_Source = newSource;
	}

	void String::operator+=(const char* other)
	{
		/*
		* Get new length
		*/
		const unsigned int newLength = m_Cursor + GetCharPointerSize(other);

		/*
		* Allocate new source
		*/
		char* newSource = new char[newLength + 1];

		/*
		* Set former elements
		*/
		for (unsigned int i = 0; i < m_Cursor; i++)
			newSource[i] = m_Source[i];

		/*
		* Copy target
		*/
		{
			unsigned int targetIndex = 0;
			for (int i = m_Cursor; i < newLength; i++)
			{
				newSource[i] = other[targetIndex];
				targetIndex++;
			}
		}

		/*
		* Set escape
		*/
		newSource[newLength] = '\0';

		/*
		* Free old source
		*/
		delete[] m_Source;

		/*
		* Set new source
		*/
		m_Source = newSource;
	}

	void String::operator+=(char other)
	{
		/*
		* Get new length
		*/
		const unsigned int newLength = m_Cursor + +1;

		/*
		* Allocate new source
		*/
		char* newSource = new char[newLength + 1];

		/*
		* Set former elements
		*/
		for (unsigned int i = 0; i < m_Cursor; i++)
			newSource[i] = m_Source[i];

		/*
		* Copy target
		*/
		newSource[m_Cursor] = other;

		/*
		* Set escape
		*/
		newSource[newLength] = '\0';

		/*
		* Free old source
		*/
		delete[] m_Source;

		/*
		* Set new source
		*/
		m_Source = newSource;
	}

	void String::operator=(const String& other)
	{
		/*
		* Allocate space for target string source
		*/
		const unsigned int targetSize = other.GetCursor();
		m_Cursor = targetSize;
		m_Source = new char[targetSize];

		/*
		* Copy
		*/
		for (unsigned int i = 0; i < targetSize; i++)
		{
			m_Source[i] = other.m_Source[i];
		}

		/*
		* Set escape char
		*/
		m_Source[targetSize] = '\0';
	}
	char String::operator[](unsigned int index) const
	{
		return m_Source[index];
	}

}