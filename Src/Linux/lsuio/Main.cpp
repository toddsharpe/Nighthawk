#include "Linux/Uio.h"
#include <iostream>
#include <stdarg.h>

using namespace Nighthawk;

int main(int argc, char** argv)
{
	std::vector<UioDevice> devices;
	UioDevice::ListDevices(devices);

	for(auto device : devices)
	{
		std::cout << device.Device << " : " << device.Name << std::endl;
		std::cout << "Maps: " << device.Maps.size() << std::endl;
		for(auto map : device.Maps)
		{
			std::cout << "  " << std::hex << map.Address << " : " << map.Size << std::endl;
		}
	}

	return 0;
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
