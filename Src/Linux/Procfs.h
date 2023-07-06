#pragma once

#include <sys/types.h>
#include <string>

namespace Nighthawk
{
	namespace Procfs
	{
		struct stats
		{
			int pid;
			char *comm, state;
			int ppid, pgrp, session, tty_nr, tpgid;
			unsigned int flags;
			unsigned long int minflt, cminflt, majflt, cmajflt, utime, stime;
			long int cutime, cstime, priority, nice, num_threads, itrealvalue;
			unsigned long long int starttime;
			unsigned long int vsize;
			long int rss;
			unsigned long int rsslim;
			void *startcode, *endcode, *startstack, *kstkesp, *kstkeip;
			unsigned long int signal, blocked, sigignore, sigcatch;
			void *wchan;
			unsigned long int nswap, cnswap;
			int exit_signal, processor;
			unsigned int rt_priority, policy;
			unsigned long long int delayacct_blkio_ticks;
			unsigned long int guest_time;
			long int cguest_time;
			void *start_data, *end_data, *start_brk, *arg_start, *arg_end;
			void *env_start, *env_end;
			int exit_code;
		};

		struct sys_kernel
		{
			std::string arch;
			std::string hostname;
			std::string osrelease;
			std::string ostype;
		};

		bool GetProcStats(const pid_t pid, stats &stats);
		bool GetSysKernel(sys_kernel &kernel);
	}
}