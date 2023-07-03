#include "pch.h"
#include "SKCModLoader.h"
#include "include/ccpp.hpp"
extern "C"
{
	bool shutdown = false;
	ccpp crowdcontrol;

	bool Ring()
	{
		printf("DidRing!");
		return false;
	}
	int CCWait = 0;
	bool CCInitDone = false;
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		printf("Registering Funcs\n");
		crowdcontrol.register_trigger("ring", []() {
			printf("Effect Ring\n");
			if (true)
				return ccpp::status_t::success;

			else
				return ccpp::status_t::retry;
			});


		if (CCWait < 600 && CCInitDone == false) {
			CCWait++;
			if (CCWait == 599) {
				CCInitDone = true;
				printf("init-finsiehd \n");
				crowdcontrol.initialize(true);
			}
		}
		crowdcontrol.initialize(true);
		//crowdcontrol.update();
	}

	__declspec(dllexport) ModInfo SKCModInfo = { ModLoaderVer };
}