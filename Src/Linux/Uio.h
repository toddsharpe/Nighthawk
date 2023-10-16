#pragma once

#include "Linux/Linux.h"
#include "Assert.h"

#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

namespace Nighthawk
{
	class UioDevice
	{
	public:
		struct DeviceMap
		{
			void* Address;
			size_t Size;
		};

		static void ListDevices(std::vector<UioDevice> &devices)
		{
			DIR *dir = opendir("/sys/class/uio");
			if (!dir)
				return;

			struct dirent *ent;
			while((ent = readdir(dir)) != NULL)
			{
				if (ent->d_type != DT_LNK)
					continue;

				UioDevice device(ent->d_name);
				device.Discover();
				devices.push_back(device);
			}
			closedir(dir);
		}

		static UioDevice FindByName(const std::string& name)
		{
			std::vector<UioDevice> devices;
			ListDevices(devices);

			for(auto device : devices)
			{
				if (device.Name == name)
					return device;
			}

			Assert(false);
			return UioDevice();
		}

		UioDevice(const std::string &device)
			: Device(device),
			Name(),
			Maps(),
			m_fd(-1)
		{
			
		}

		void Open()
		{
			Assert(!IsOpen());

			const std::string path = "/dev/" + Device;
			m_fd = open(path.c_str(), O_RDWR | O_SYNC);
			AssertErrNo(m_fd);
		}

		void Map(std::vector<void*> &addresses)
		{
			Assert(IsOpen());

			const int pageSize = getpagesize();
			for (size_t i = 0; i < Maps.size(); i++)
			{
				void* address = mmap(NULL, Maps[i].Size, PROT_READ|PROT_WRITE, MAP_SHARED, m_fd, i * pageSize);
				Assert(address);
				addresses.push_back(address);
			}
		}

		void Close()
		{
			close(m_fd);
			m_fd = -1;
		}

		bool IsOpen()
		{
			return m_fd != -1;
		}

		std::string Device;
		std::string Name;
		std::vector<DeviceMap> Maps;

	private:
		UioDevice()
			: Device(),
			Name(),
			Maps(),
			m_fd(-1)
		{
			
		}

		void Discover()
		{
			Assert(!IsOpen());

			//Read name.
			const std::string fullPath = "/sys/class/uio/" + Device;
			Name = Linux::ReadString(fullPath + "/name");

			//Read maps.
			const std::string mapsDir = fullPath + "/maps";
			DIR *maps = opendir(mapsDir.c_str());
			if (maps)
			{
				struct dirent *ent;
				while((ent = readdir(maps)) != NULL)
				{
					if (Linux::IsSpecialDir(ent->d_name))
						continue;

					const std::string mapFile = mapsDir + "/" + ent->d_name;

					DeviceMap map;
					map.Address = (void*)Linux::ReadHex(mapFile + "/addr");
					map.Size = (size_t)Linux::ReadHex(mapFile + "/size");
					Maps.push_back(map);
				}
				closedir(maps);
			}
		}

		int m_fd;
	};
}
