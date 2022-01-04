#pragma once

namespace Bite
{
	#pragma once
	#ifdef BITE_BUILD
	#define BITE_API __declspec(dllexport)
	#else
	#define BITE_API __declspec(dllimport)
	#endif // BITE_BUILD FOR IMPORT EXPORT DLL

	#define BITE_EXPORT __declspec(dllexport)

	#if BITE_WINDOWS
	#define BITE_DEBUG_BREAK __debugbreak();
	#endif // BITE_WINDOWS FOR PLATFORM DECLARATIONS
	#define FORCEINLINE __forceinline
}