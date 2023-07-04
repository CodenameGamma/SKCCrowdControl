#include "pch.h"
#include "SKCModLoader.h"
#include "include/ccpp.hpp"
extern "C"
{
	bool shutdown = false;
	ccpp crowdcontrol;

	bool Ring(int thing)
	{
		printf("DidRing!");
		return false;
	}

	ccpp::status_t test_effect()
	{
		return ccpp::status_t::success;
	}

	bool RegisterFunctions()
	{
		crowdcontrol.register_trigger("ring", []()
		{
			std::printf("\n\n\nRing\n\n\n");
			return ccpp::status_t::success;
		});

		return true;
	}

	__declspec(dllexport) void OnFrame(const char* path, const HelperFunctions& helperFunctions)
	{
		crowdcontrol.update();
	};

	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		if (crowdcontrol.initialize_ex("127.0.0.1", 58430, false))
		{
			RegisterFunctions();
		}
	}

	__declspec(dllexport) ModInfo SKCModInfo = { ModLoaderVer };
}