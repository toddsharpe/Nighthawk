#include "Procfs.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

namespace Nighthawk
{
	namespace Procfs
	{
		//NOTE(tsharpe): Adapted from https://github.com/Elemnir/proc_stat/blob/master/proc_stat.h.
		//NOTE(tsharpe): Rewrite.
		bool GetProcStats(const pid_t pid, stats& stats)
		{
			const std::string path = "/proc/" + std::to_string(pid) + "/stat";
			//std::cout << "Getting stats for " << path << std::endl;

			// Allocate and initialize the struct, open the file
			FILE *procfp = fopen(path.c_str(), "r");
			if (procfp == NULL)
			{
				return false;
			}

			// Do the read, feel bad about this format string
			int ret = fscanf(procfp,
				"%d %*s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu "
				"%ld %ld %ld %ld %ld %ld %llu %lu %ld %lu "
				"%p %p %p %p %p %lu %lu %lu %lu %p %lu %lu "
				"%d %d %u %u %llu %lu %ld %p %p %p %p %p %p %p %d",
				&stats.pid, /*stats.comm,*/ &stats.state, &stats.ppid, &stats.pgrp, &stats.session, 
				&stats.tty_nr, &stats.tpgid, &stats.flags, &stats.minflt, &stats.cminflt, 
				&stats.majflt, &stats.cmajflt, &stats.utime, &stats.stime, &stats.cutime, 
				&stats.cstime, &stats.priority, &stats.nice, &stats.num_threads, 
				&stats.itrealvalue, &stats.starttime, &stats.vsize, &stats.rss, &stats.rsslim, 
				&stats.startcode, &stats.endcode, &stats.startstack, &stats.kstkesp, 
				&stats.kstkeip, &stats.signal, &stats.blocked, &stats.sigignore, &stats.sigcatch,
				&stats.wchan, &stats.nswap, &stats.cnswap, &stats.exit_signal, &stats.processor, 
				&stats.rt_priority, &stats.policy, &stats.delayacct_blkio_ticks, 
				&stats.guest_time, &stats.cguest_time, &stats.start_data, &stats.end_data, 
				&stats.start_brk, &stats.arg_start, &stats.arg_end, &stats.env_start, 
				&stats.env_end, &stats.exit_code
			);
			//std::cout << "Read " << ret << " items" << std::endl;
			//std::cout << "stuff " << stats.processor << " " << stats.vsize << " " << stats.utime << " " << stats.stime << std::endl;
			fclose(procfp);
			return true;
		}

		bool GetSysKernel(sys_kernel &kernel)
		{
			//Read arch
			{
				std::ifstream ifs = std::ifstream("/proc/sys/kernel/arch");
				if (!ifs.good())
					return false;

				std::getline(ifs, kernel.arch);
			}

			//Read hostname
			{
				std::ifstream ifs = std::ifstream("/proc/sys/kernel/hostname");
				if (!ifs.good())
					return false;

				std::getline(ifs, kernel.hostname);
			}

			//Read osrelease
			{
				std::ifstream ifs = std::ifstream("/proc/sys/kernel/osrelease");
				if (!ifs.good())
					return false;

				std::getline(ifs, kernel.osrelease);
			}
			
			//Read ostype
			{
				auto ifs = std::ifstream("/proc/sys/kernel/ostype");
				if (!ifs.good())
					return false;

				std::getline(ifs, kernel.ostype);
			}

			return true;
		}
	}
}