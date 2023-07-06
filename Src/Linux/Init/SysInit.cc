#include "SysInit.h"
#include "Nighthawk.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <fcntl.h>

using namespace Nighthawk;

SysInit::SysInit() :
	_processes()
{

}

void SysInit::Init(TelemetryWriter& telem)
{
	static const std::string File = "dat/Init";
	
	std::cout << "Initialzing runtime" << std::endl;
	std::cout << "\tDir: " << std::filesystem::current_path() << std::endl;
	
	//Launch processes
	{
		std::ifstream file(File);

		std::string affinity;
		std::string process;

		while (file >> affinity >> process)
		{
			std::cout << "\tStarting: " << process << std::endl;
			const pid_t pid = fork();
			Assert(pid != -1);
			_processes.push_back({ process, (uint32_t)pid });

			if (pid == 0)
			{
				//Redirect to runtime log
				int fd = open(Nighthawk::LogFile.c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
				dup2(fd, 1);
				dup2(fd, 2);
				close(fd);

				const std::string path = "./bin/" + process;
				execl(path.c_str(), path.c_str(), (const char*)NULL);
			}
		}
	}

	//Add to telem
	for (const SysInit::process& process : _processes)
	{
		telem.Add(std::string("SysInit." + process.name + ".pid"), process.pid);
		telem.Add(std::string("SysInit." + process.name + ".state"), (uint8_t)process.stats.state);
		telem.Add(std::string("SysInit." + process.name + ".processor"), (uint8_t)process.stats.processor);
		telem.Add(std::string("SysInit." + process.name + ".vsize"), (uint32_t)process.stats.vsize);
		//_telem.Add(std::string("SysInit." + process.name + ".user_time"), process.stats.utime);
		//_telem.Add(std::string("SysInit." + process.name + ".kernel_time"), process.stats.stime);
	}
}

void SysInit::Dispatch()
{
	for (SysInit::process& process : _processes)
	{
		bool ret = Procfs::GetProcStats(process.pid, process.stats);
		if (!ret)
		{
			std::cout << "Process " << process.name << " died" << std::endl;
		}
	}
}