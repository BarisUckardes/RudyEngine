#include "Memory.h"

void Rudy::Memory::MemoryCopy(void* destination, void* source, unsigned long byteCount)
{
	/*
	* Convert source and destination
	*/
	const Byte* cSource = (Byte*)source;
	Byte* cDestination = (Byte*)destination;

	/*
	* Copy
	*/
	for (unsigned long i = 0; i < byteCount; i++)
		cDestination[i] = cSource[i];
}
