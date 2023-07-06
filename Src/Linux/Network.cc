#include "Network.h"
#include "Assert.h"

#include <string>
#include <cstdint>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

namespace Nighthawk
{
	namespace Network
	{
		void Send(const std::string& host, const uint16_t port, const ReadOnlyBuffer& buffer)
		{
			struct sockaddr_in dest = {};
			dest.sin_family = AF_INET;
			dest.sin_addr.s_addr = inet_addr(host.c_str());
			dest.sin_port = htons(port);

			int fd = socket(AF_INET, SOCK_DGRAM, 0);
			AssertErrNo(fd);
			
			int ret = sendto(fd, buffer.Data, buffer.Length, 0, (const struct sockaddr *)&dest, sizeof(dest));
			AssertErrNo(ret);

			AssertErrNo(close(fd));
		}
	};
}