#include "Memory.h"
#include <stdio.h>

void Rudy::Memory::MemoryCopy(void* destination, void* source, unsigned long byteCount)
{

	/*
	* Convert source and destination
	*/
	const Byte* bSource = (const Byte*)source;
	Byte* bDestination = (Byte*)destination;

	/*
	* Copy
	*/
	for (unsigned long i = 0; i < byteCount; i++)
	{
		bDestination[i] = bSource[i];
	}
}
