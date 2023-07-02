#include "pch.h"
#include "SKCModLoader.h"

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{

	}

	__declspec(dllexport) ModInfo SKCModInfo = { ModLoaderVer };
}