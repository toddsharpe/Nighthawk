#pragma once

#include "Buffer.h"

#include <string>
#include <cstdint>

namespace Nighthawk
{
	namespace Network
	{
		void Send(const std::string& host, const uint16_t port, const ReadOnlyBuffer& buffer);
	};
}