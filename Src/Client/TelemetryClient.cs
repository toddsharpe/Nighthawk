using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using Client.Telemetry;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Collections.ObjectModel;

using HashType = System.UInt32;
using DeviceTable = System.Collections.Generic.Dictionary<System.UInt32, Client.TelemetryClient.TelemDevice>;

namespace Client
{
	public class TelemetryClient
	{
		public class TelemDevice
		{
			public HashType Hash { get; set; }
			public DateTime LastSeen { get; set; }
			public string Name { get; set; }
			public DeviceType? Type { get; set; }
			public object Value { get; set; }
		}

		public class NodeTelem
		{
			public DateTime LastSeen { get; set; }
			public DeviceTable Devices { get; set; }
			public Dictionary<string, string> Text { get; set; }
		}

		public Dictionary<IPAddress, NodeTelem> Nodes { get;}

		private UdpClient _client;
		private Thread _thread;
		public TelemetryClient()
		{
			Nodes = new Dictionary<IPAddress, NodeTelem>();
			
			_client = new UdpClient(Nighthawk.TelemPort);
			_client.JoinMulticastGroup(IPAddress.Parse(Nighthawk.TelemIp));

			_thread = new Thread(Run);
			_thread.Start();
		}

		private void Run()
		{
			IPEndPoint ipEndPoint = new IPEndPoint(IPAddress.Any, 0);
			while (true)
			{
				byte[] data = _client.Receive(ref ipEndPoint);
				Debug.Assert(data.Length > 0);

				//Create node record if it doesn't exist
				if (!Nodes.ContainsKey(ipEndPoint.Address))
					Nodes.Add(ipEndPoint.Address, new NodeTelem
					{
						LastSeen = DateTime.Now,
						Devices = new DeviceTable(),
						Text = new Dictionary<string, string>()
					});

				//Make node as recent
				NodeTelem node = Nodes[ipEndPoint.Address];
				node.LastSeen = DateTime.Now;

				PacketHeader header = data.ToStruct<PacketHeader>();
				byte[] body = data.Skip(Marshal.SizeOf(typeof(PacketHeader))).ToArray();
				switch (header.Type)
				{
					case TelemType.Devices:
						ParseDevices(node.Devices, header.Count, body);
						break;

					case TelemType.Annotations:
						ParseAnnotations(node.Devices,header.Count, body);
						break;

					case TelemType.Text:
						ParseText(node.Text, body);
						break;

					default:
						Console.WriteLine($"Received {data.Length} bytes from {ipEndPoint.Address}:{ipEndPoint.Port}");
						break;
				}
			}
		}

		private static void ParseDevices(DeviceTable devices, int count, byte[] data)
		{
			BufferReader reader = new BufferReader(data);
			for (int i = 0; i < count; i++)
			{
				HashType hash = reader.Read<HashType>();

				//Cant process packet further
				if (!devices.ContainsKey(hash))
				{
					Console.WriteLine($"Received unknown device hash {hash}");
					reader.Display();
					return;
				}
				
				TelemDevice device = devices[hash];
				switch (device.Type)
				{
					case DeviceType.u8:
						device.Value = reader.Read<byte>();
						break;
					case DeviceType.s8:
						device.Value = reader.Read<sbyte>();
						break;

					case DeviceType.u16:
						device.Value = reader.Read<UInt16>();
						break;
					case DeviceType.s16:
						device.Value = reader.Read<Int16>();
						break;

					case DeviceType.u32:
						device.Value = reader.Read<UInt32>();
						break;
					case DeviceType.s32:
						device.Value = reader.Read<Int32>();
						break;

					case DeviceType.u64:
						device.Value = reader.Read<UInt64>();
						break;
					case DeviceType.s64:
						device.Value = reader.Read<Int64>();
						break;

					case DeviceType.str:
						device.Value = reader.ReadString();
						break;

					default:
						Console.WriteLine($"Received unknown device type {device.Type}");
						return;
				}
				device.LastSeen = DateTime.Now;
			}
		}

		private static void ParseAnnotations(DeviceTable devices, int count, byte[] data)
		{
			BufferReader reader = new BufferReader(data);
			for (int i = 0; i < count; i++)
			{
				HashType hash = reader.Read<HashType>();
				DeviceType type = (DeviceType)reader.Read<byte>();
				string name = reader.ReadString();

				//Ignore if device already exists
				if (devices.ContainsKey(hash))
					continue;

				//Add device
				devices.Add(hash, new TelemDevice
				{
					Hash = hash,
					Name = name,
					Type = type
				});
			}
		}

		private static void ParseText(Dictionary<string, string> text, byte[] data)
		{
			BufferReader reader = new BufferReader(data);
			string file = reader.ReadString();

			if (!text.ContainsKey(file))
				text.Add(file, string.Empty);

			text[file] += reader.ReadString();
		}
	}
}