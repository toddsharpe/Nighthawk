#include "Hosted/App.h"

#include <stdio.h>
#include <cstdarg>

using namespace Nighthawk;
using namespace std::literals::chrono_literals;

void Run(void* sender)
{
    printf("Run\r\n");
}

int main(int argc, char **argv)
{
    printf("Hello World!\n");

    App app;
    Callback cb;
    cb.Context = nullptr;
    cb.Handler = &Run;
    app.Install(cb, 1000ms);

    app.Run();

    return 0;
}

void Bugcheck(const char* file, const char* line, const char* format, ...)
{
    printf("Kernel Bugcheck\r\n");
    printf("\r\n%s\r\n%s\r\n", file, line);

    va_list args;
    va_start(args, format);
    printf(format, args);
    printf("\r\n");
	va_end(args);

    while (1);
}