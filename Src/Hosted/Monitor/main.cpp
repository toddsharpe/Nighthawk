#include <stdio.h>

#include "Hosted/App.h"

using namespace Nighthawk;

void Run(void* sender)
{
    printf("Run\r\n");
}

int main(int argc, char **argv)
{
    printf("Hello World!\n");

    App app;
    app.Install({ nullptr, &Run }, 1000ms);

    app.Run();

    return 0;
}