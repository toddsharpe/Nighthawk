using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Client
{
	public class BufferReader
	{
		private int _position;
		private byte[] _buffer;

		public BufferReader(byte[] buffer)
		{
			_position = 0;
			_buffer = buffer;
		}

		public T Read<T>() where T : struct
		{
			int size = Marshal.SizeOf(typeof(T));
			ReadOnlySpan<byte> span = new ReadOnlySpan<byte>(_buffer, _position, size);
			T ret = MemoryMarshal.Read<T>(span);
			_position += size;
			return ret;
		}

		public string ReadString()
		{
			int size = 0;
			while ((_position + size < _buffer.Length) && (_buffer[_position + size] != '\0'))
				size++;

			ReadOnlySpan<byte> span = new ReadOnlySpan<byte>(_buffer, _position, size);
			string ret = System.Text.Encoding.ASCII.GetString(span);
			_position += size + 1;
			return ret;
		}

		public void Display()
		{
			Console.WriteLine($"BufferReader: {_buffer.Length} bytes");
			Console.WriteLine($"Position: {_position}");
			Console.WriteLine($"Remaining: {_buffer.Length - _position}");
		}
	}
}