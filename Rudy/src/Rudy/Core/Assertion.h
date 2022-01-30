#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Platform/Assert/PlatformAssert.h>

#define RUDY_ASSERT(condition) if(!condition) {RUDY_ASSERT_IMPLEMENTATION}