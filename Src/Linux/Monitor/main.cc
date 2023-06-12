#include "Linux/App.h"
#include "Monitor.h"
#include "TelemetryTextFile.h"
#include "TelemetryWriter.h"
#include "Nighthawk.h"

#include <stdio.h>
#include <cstdarg>
#include <iostream>

using namespace Nighthawk;
using namespace std::literals::chrono_literals;

const std::string Process = "Monitor";

int main(int argc, char **argv)
{
	std::cout << "Nighthawk - Monitor\n" << std::endl;

	//Telemetry
	TelemetryWriter telem(Process, Nighthawk::TelemIp, Nighthawk::TelemPort);
	telem.Init();

	//Controls
	Monitor monitor;
	monitor.Init(telem);

	//App
	App app(telem);
	app.Install("Monitor", { &monitor, &Monitor::Dispatch }, 1000ms);
	app.Run();

	return 0;
}

void Bugcheck(const char *file, const char *line, const char *format, ...)
{
	printf("Monitor Bugcheck\r\n");
	printf("%s\r\n%s\r\n", file, line);

	va_list args;
	va_start(args, format);
	printf(format, args);
	printf("\r\n");
	va_end(args);

	exit(-1);
}