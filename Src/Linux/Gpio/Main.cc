#include "Assert.h"

#include "Linux/Uio.h"

#include <cstdarg>
#include <string>
#include <iostream>
#include <cstdint>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

using namespace Nighthawk;

struct gpio_reg
{
	uint16_t data0;
};

int main(int argc, char **argv)
{
	std::cout << "Nighthawk - gpio\n" << std::endl;

	//Open device.
	UioDevice gpio = UioDevice::FindByName("gpio");
	gpio.Open();

	//Map in.
	std::vector<void*> maps;
	gpio.Map(maps);
	Assert(maps.size() == 1);

	gpio_reg* gpio1 = (gpio_reg*)maps[0];
	while(true)
	{
		gpio1->data0 = (gpio1->data0 + 1) & 0xFF;
		sleep(1);
	}

	gpio.Close();
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
