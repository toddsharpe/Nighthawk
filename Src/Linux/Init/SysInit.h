#pragma once

#include "TelemetryWriter.h"
#include "Linux/Procfs.h"

#include <cstdint>
#include <string>
#include <vector>
#include <sys/types.h>

namespace Nighthawk
{
	class SysInit
	{
	public:
		static void Dispatch(void* sender) { ((SysInit*)sender)->Dispatch(); }

		SysInit();
		void Init(TelemetryWriter& telem);

	private:
		const std::string Process = "Init";

		void Dispatch();

		struct process
		{
			std::string name;
			uint32_t pid;
			Procfs::stats stats;
		};

		std::vector<process> _processes;
	};
}