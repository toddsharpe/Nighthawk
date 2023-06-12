#pragma once

#include "TelemetryWriter.h"
#include "Linux/Procfs.h"
#include <cstdint>

namespace Nighthawk
{
	class Monitor
	{
	public:
		static void Dispatch(void* sender) { ((Monitor*)sender)->Dispatch(); }

		Monitor();
		void Init(TelemetryWriter& telem);

	private:
		const std::string Process = "Monitor";
		void Dispatch();

		uint32_t uptime;
		uint32_t memTotal;
		uint32_t memFree;
		uint32_t procs;

		Procfs::sys_kernel sys;
	};
}