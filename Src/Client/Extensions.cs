using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Client
{
	public static class Extensions
	{
		public static T ToStruct<T>(this byte[] data) where T : struct
		{
			var pData = GCHandle.Alloc(data, GCHandleType.Pinned);
			var result = (T)Marshal.PtrToStructure(pData.AddrOfPinnedObject(), typeof(T));
			pData.Free();
			return result;
		}

		public static byte[] ToArray<T>(this T data) where T : struct
		{
			var result = new byte[Marshal.SizeOf(typeof(T))];
			var pResult = GCHandle.Alloc(result, GCHandleType.Pinned);
			Marshal.StructureToPtr(data, pResult.AddrOfPinnedObject(), true);
			pResult.Free();
			return result;
		}
	}
}