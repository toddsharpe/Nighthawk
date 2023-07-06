#pragma once

#include "Assert.h"
#include "BufferWriter.h"
#include "Telemetry.h"
#include "Network.h"

#include <string>
#include <unistd.h>
#include <fcntl.h>

namespace Nighthawk
{
	class TelemetryTextFile
	{
	public:
		static void Dispatch(void* sender) { ((TelemetryTextFile*)sender)->Dispatch(); }
		
		TelemetryTextFile(const std::string& file, const std::string& host, const uint16_t port) :
			m_file(file),
			m_host(host),
			m_port(port)
		{

		}

		void Dispatch()
		{
			BufferWriter<Telemetry::MaxPacketSize> buffer;
			const Telemetry::PacketHeader header = { 0, Telemetry::TelemType::TextFile };
			Assert(buffer.Push(header));

			//Push file name
			Assert(buffer.Push(m_file));

			//Push file contents
			int fd = open(m_file.c_str(), O_RDONLY | O_NONBLOCK);
			AssertErrNo(fd);
			const size_t pos = buffer.GetPosition();
			Assert(buffer.Push(fd, buffer.BytesRemaining()));
			close(fd);

/*
			std::ifstream ifs(m_file);
			std::string line;
			bool data = false;
			while (std::getline(ifs, line))
			{
				buffer.Push(line + '\n');
				data = true;
			}
*/
			if (pos != buffer.GetPosition())
				Network::Send(m_host, m_port, buffer.GetRef());
		}

	private:
		std::string m_file;
		const std::string& m_host;
		const uint16_t m_port;
	};
}