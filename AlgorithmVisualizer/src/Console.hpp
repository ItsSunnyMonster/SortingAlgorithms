#pragma once
#include <stdio.h>

#include <windows.h>

FILE* g_ic_file_cout_stream; FILE* g_ic_file_cin_stream;

// Success: true , Failure: false
bool initConsole()
{
#ifdef AL_DEBUG
	if (!AllocConsole()) { return false; }
	if (freopen_s(&g_ic_file_cout_stream, "CONOUT$", "w", stdout) != 0) { return false; } // For std::cout 
	if (freopen_s(&g_ic_file_cin_stream, "CONIN$", "w+", stdin) != 0) { return false; } // For std::cin
	return true;
#else
	return true;
#endif
}

bool freeConsole()
{
#ifdef AL_DEBUG
	return FreeConsole();
#else
	return true;
#endif
}
