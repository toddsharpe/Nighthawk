#include "Assert.h"

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

struct gpio_reg
{
	uint16_t data0;
	uint16_t mask0;
	uint32_t reserved[(0x00000040 / sizeof(uint32_t)) - 1];
	uint32_t output1;
};
const uintptr_t GPIO1_ADDR = (uintptr_t)0x41210000;

int main(int argc, char **argv)
{
	std::cout << "Nighthawk - gpio\n" << std::endl;

	int fd = open("/dev/uio2", O_RDWR | O_SYNC);
	AssertErrNo(fd);
	gpio_reg* gpio1 = (gpio_reg *)mmap(NULL, (1 << 12), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	while(true)
	{
		//gpio1->output1 = 0x00000001;
		gpio1->data0 = 0x00000001;
		sleep(1);
		//gpio1->output1 = 0x00000004;
		gpio1->data0 = 0x00000004;
		sleep(1);
	}

	close(fd);

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