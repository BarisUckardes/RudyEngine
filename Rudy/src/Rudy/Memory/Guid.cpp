#include "Guid.h"
#include <stdio.h>
#include <Rudy/Platform/OS/PlatformOSType.h>
#include <Rudy/Platform/OS/PlatformOSDetection.h>
#include <Rudy/Platform/OS/Windows/Memory/WindowsGuid.h>
#include <Rudy/Memory/Memory.h>
namespace Rudy
{
	Guid Guid::Create()
	{
		/*
		* Get current os type
		*/
		PlatformOSType osType = GetCurrentPlatform();

		/*
		* Get platform agnostic guid
		*/
		switch (osType)
		{
		case PlatformOSType::Undefined:
			break;
		case PlatformOSType::Windows:
			return WindowsGuid::CreateGuid();
			break;
		case PlatformOSType::Linux:
			break;
		default:
			break;
		}
	}
	Guid::Guid()
	{
		A = B = C = 0;
		D[0] = D[1] = D[2] = D[3] = D[4] = D[5] = D[6] = D[7] = 0;

	}
	Guid::Guid(unsigned long a, unsigned short b, unsigned short c, unsigned char d[8])
	{
		A = a;
		B = b;
		C = c;
		Memory::MemoryCopy(&D, &d, 8);
	}
	String Guid::GetAsString() const
	{
		char* b = new char[37];
		char* c = GuidToStrCore(this, b);
		return c;
	}

	bool Guid::GetFromString(const String& targetString, Guid& idOut)
	{
		idOut = StringToGuidCore(targetString);

		return true;
	}


	char* Guid::GuidToStrCore(const Guid* id, char* out) {
		int i;
		char* ret = out;
		out += sprintf(out, "%.8lX%.4hX%.4hX", id->A, id->B, id->C);
		for (i = 0; i < sizeof(id->D); ++i) {
			out += sprintf(out, "%.2hhX", id->D[i]);
		}
		return ret;
	}
	Guid Guid::StringToGuidCore(const String& guid) {
		Guid output;
		sscanf(guid.GetSource(),
			"{%8x%4hx%4hx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx}",
			&output.A, &output.B, &output.C,
			&output.D[0], &output.D[1], &output.D[2], &output.D[3],
			&output.D[4], &output.D[5], &output.D[6], &output.D[7]);
		return output;
	}
	bool operator==(const Guid& a, const Guid& b)
	{
		return a.A == b.A && a.B == b.B && a.C == b.C && a.D[0] == b.D[0];
	}
	bool operator!=(const Guid& a, const Guid& b)
	{
		return a.A != b.A || a.B != b.B || a.C != b.C >> a.D[0] != b.D[0];
	}
}