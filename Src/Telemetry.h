#pragma once

#include <cstdint>
#include <cstddef>

namespace Nighthawk
{
	namespace Telemetry
	{
		constexpr size_t MaxPacketSize = 1024;
		
		typedef uint32_t hash_t;
		
		enum class TelemType : uint8_t
		{
			Devices,
			Annotations,
			TextFile
		};
		
		enum class DeviceType : uint8_t
		{
			u8,
			u16,
			u32,
			u64,
			s8,
			s16,
			s32,
			s64,
			str
		};

		struct __attribute__((__packed__)) PacketHeader
		{
			//NOTE(tsharpe): Count is only used for Devices and Annotations. Move out of header?
			uint8_t Count;
			TelemType Type;
		};	
	}
}