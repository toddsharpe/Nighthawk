#pragma once

#include "Telemetry.h"
#include "Network.h"
#include "Assert.h"
#include "BufferWriter.h"

#include <cstdint>
#include <stddef.h>
#include <string>
#include <vector>

namespace Nighthawk
{
	//TODO(tsharpe): Prefix, have binaries default set to process name
	class TelemetryWriter
	{
	public:
		static void Send(void* sender) { ((TelemetryWriter*)sender)->Send(); }

		TelemetryWriter(const std::string& process, const std::string& host, const uint16_t port) :
			m_process(process),
			m_host(host),
			m_port(port),
			m_count(),
			m_entries()
		{
		}

		void Init()
		{
			Add("Telem.Count", m_count);
		}

		template <typename T>
		void Add(const std::string &device, const T &value)
		{
			const std::string deviceName = m_process + "." + device;
			const std::hash<std::string> hasher;
			const Telemetry::hash_t hash = (Telemetry::hash_t)hasher(deviceName);

			//Ensure hash hasn't been used
			for (const Entry& entry : m_entries)
				Assert(entry.Hash != hash);

			//Convert T to DeviceType
			Telemetry::DeviceType type;
			if constexpr (std::is_same<uint8_t, T>::value)
				type = Telemetry::DeviceType::u8;
			else if constexpr (std::is_same<int8_t, T>::value)
				type = Telemetry::DeviceType::s8;
			else if constexpr (std::is_same<uint16_t, T>::value)
				type = Telemetry::DeviceType::u16;
			else if constexpr (std::is_same<int16_t, T>::value)
				type = Telemetry::DeviceType::s16;
			else if constexpr (std::is_same<uint32_t, T>::value)
				type = Telemetry::DeviceType::u32;
			else if constexpr (std::is_same<int32_t, T>::value)
				type = Telemetry::DeviceType::s32;
			else if constexpr (std::is_same<uint64_t, T>::value)
				type = Telemetry::DeviceType::u64;
			else if constexpr (std::is_same<int64_t, T>::value)
				type = Telemetry::DeviceType::s64;
			else if constexpr (std::is_same<std::string, T>::value)
				type = Telemetry::DeviceType::str;
			else
				static_assert(!sizeof(T*), "T is not supported");

			const TelemetryWriter::Entry entry = { deviceName, hash, type, &value };
			m_entries.push_back(entry);
		}

		void Send()
		{
			BufferWriter<Telemetry::MaxPacketSize> buffer;
			const Telemetry::PacketHeader header = { (uint8_t)m_entries.size(), Telemetry::TelemType::Devices };
			buffer.Push(header);
			
			for (Entry& entry : m_entries)
			{
				Assert(buffer.Push(entry.Hash));
				switch (entry.Type)
				{
					case Telemetry::DeviceType::u8:
					case Telemetry::DeviceType::s8:
						Assert(buffer.Push(*(uint8_t*)entry.Ptr));
						break;

					case Telemetry::DeviceType::u16:
					case Telemetry::DeviceType::s16:
						Assert(buffer.Push(*(uint16_t*)entry.Ptr));
						break;
					
					case Telemetry::DeviceType::u32:
					case Telemetry::DeviceType::s32:
						Assert(buffer.Push(*(uint32_t*)entry.Ptr));
						break;

					case Telemetry::DeviceType::u64:
					case Telemetry::DeviceType::s64:
						Assert(buffer.Push(*(uint64_t*)entry.Ptr));
						break;

					case Telemetry::DeviceType::str:
						Assert(buffer.Push(*(std::string*)entry.Ptr));
						break;

					default:
						Assert(false);
				}
			}

			Network::Send(m_host, m_port, buffer.GetRef());
			m_count++;

			if (m_count % 10 == 0)
				SendAnnotations();
		}

	private:
		struct Entry
		{
			std::string Name;
			Telemetry::hash_t Hash;
			Telemetry::DeviceType Type;
			const void *Ptr;
		};

		void SendAnnotations()
		{
			BufferWriter<Telemetry::MaxPacketSize> buffer;
			const Telemetry::PacketHeader header = { (uint8_t)m_entries.size(), Telemetry::TelemType::Annotations };
			buffer.Push(header);

			for (const Entry& entry : m_entries)
			{
				buffer.Push(entry.Hash);
				buffer.Push(entry.Type);
				buffer.Push(entry.Name);
			}

			Network::Send(m_host, m_port, buffer.GetRef());
		}

		const std::string& m_process;
		const std::string& m_host;
		const uint16_t m_port;

		uint32_t m_count;
		std::vector<Entry> m_entries;
	};
}