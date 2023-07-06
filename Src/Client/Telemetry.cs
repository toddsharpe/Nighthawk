using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Client.Telemetry
{
	using HashType = UInt32;
	
	public enum TelemType : byte
	{
		Devices,
		Annotations,
		Text
	};

	[StructLayout(LayoutKind.Sequential, Pack = 1)]
	public struct PacketHeader
	{
		public byte Count;
		public TelemType Type;
	};

	public enum DeviceType : byte
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
}