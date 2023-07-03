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
	bool RegisterFunctions()
	{
        crowdcontrol.register_trigger("ring", []() {
            printf("Effect Ring\n");
            if (Ring(1))
                return ccpp::status_t::success;

            else
                return ccpp::status_t::retry;
            });
			return true;
	}
	int CCWait = 0;
	bool CCInitDone = false;
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		printf("Registering Funcs\n");
		RegisterFunctions();
		printf("Registeration finished\n");

		if (CCWait < 600 && CCInitDone == false) {
			CCWait++;
			if (CCWait == 599) {
				CCInitDone = true;
				printf("init-finsiehd \n");
				crowdcontrol.initialize(true);
			}
		}
		printf("Doing Init\n");
		crowdcontrol.initialize(true);
		printf("Init Finished. \n");
		//crowdcontrol.update();
	}

	__declspec(dllexport) ModInfo SKCModInfo = { ModLoaderVer };
}