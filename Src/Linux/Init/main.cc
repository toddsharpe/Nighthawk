#include "Assert.h"
#include "SysInit.h"
#include "Linux/App.h"
#include "TelemetryTextFile.h"
#include "TelemetryWriter.h"
#include "Nighthawk.h"

#include <cstdarg>
#include <string>
#include <iostream>

using namespace Nighthawk;
using namespace std::literals::chrono_literals;

const std::string Process = "Init";

int main(int argc, char **argv)
{
	std::cout << "Nighthawk - Init\n" << std::endl;
	
	//Telemetry
	TelemetryWriter telem(Process, Nighthawk::TelemIp, Nighthawk::TelemPort);
	telem.Init();

	TelemetryTextFile logTelem(Nighthawk::LogFile, Nighthawk::TelemIp, Nighthawk::TelemPort);

	//Controls
	SysInit init;
	init.Init(telem);

	//App
	App app(telem);
	app.Install("SysInit", { &init, &SysInit::Dispatch }, 1000ms);
	app.Install("Log", { &logTelem, &TelemetryTextFile::Dispatch }, 1000ms);
	app.Run();

	return -1;
}

void Bugcheck(const char *file, const char *line, const char *format, ...)
{
	printf("Init Bugcheck\r\n");
	printf("%s\r\n%s\r\n", file, line);

	va_list args;
	va_start(args, format);
	printf(format, args);
	printf("\r\n");
	va_end(args);

	exit(-1);
}