#include "Monitor.h"
#include "Nighthawk.h"
#include "Assert.h"

//#include <fstream>
//#include <sstream>
#include <sys/sysinfo.h>
#include <iostream>

using namespace Nighthawk;

Monitor::Monitor() : 
	uptime(),
	memTotal(),
	memFree(),
	procs(),
	sys()
{

}

void Monitor::Init(TelemetryWriter& telem)
{
	telem.Add("sys.uptime", uptime);
	telem.Add("sys.memtotal", memTotal);
	telem.Add("sys.memfree", memFree);
	telem.Add("sys.procs", procs);
	telem.Add("sys.kernel.arch", sys.arch);
	telem.Add("sys.kernel.hostname", sys.hostname);
	telem.Add("sys.kernel.osrelease", sys.osrelease);
	telem.Add("sys.kernel.ostype", sys.ostype);
}

void Monitor::Dispatch()
{
	/*
	//Update uptime
	{
		auto ifs = std::ifstream("/proc/uptime");
		if (ifs.good())
		{
			double seconds;
			ifs >> seconds; 
			uptime = (uint32_t)seconds;
		}
	}

	//Update memory
	{
		auto ifs = std::ifstream("/proc/memory");
		if (ifs.good())
		{
			std::string line, label;
			std::uint64_t value; 
			while(std::getline(ifs, line))
			{		
				std::stringstream ss{line};	
				ss >> label >> value;

				//Get mem stats in MB
				if(label == "MemTotal:")
					memTotal = (uint32_t)(value / 1024);

				if(label == "MemFree:")		
					memFree = (uint32_t)(value / 1024);
			}
		}
	}
	*/

	//Get system info via ProcFS
	{
		Assert(Procfs::GetSysKernel(sys));
	}

	//Get sysinfo
	{
		struct sysinfo info;
		AssertErrNo(::sysinfo(&info));

		uptime = info.uptime;
		memTotal = (uint32_t)(info.totalram / 1024);
		memFree = (uint32_t)(info.freeram / 1024);
		procs = info.procs;
	}
}