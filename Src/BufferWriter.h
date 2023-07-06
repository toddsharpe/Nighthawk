#pragma once

#include "Buffer.h"

#include <array>
#include <cstdint>
#include <cstring>
#include <unistd.h>
#include <iostream>

namespace Nighthawk
{
	template <size_t TSize>
	class BufferWriter
	{
	public:
		BufferWriter() :
			m_position(),
			m_buffer()
		{

		}

		template <typename T>
		bool Push(const T& data)
		{
			if (m_position + sizeof(T) > TSize)
				return false;

			std::memcpy(&m_buffer[m_position], (void*)&data, sizeof(T));
			m_position += sizeof(T);
			return true;
		}

		bool Push(const std::string& str)
		{
			if (m_position + str.length() > TSize)
				return false;

			//Push string
			std::memcpy(&m_buffer[m_position], str.c_str(), str.length());
			m_position += str.length();

			//Push null byte
			m_buffer[m_position] = 0;
			m_position++;
			return true;
		}

		bool Push(const int fd, const size_t bytes)
		{
			if (m_position + bytes > TSize)
				return false;

			ssize_t read = ::read(fd, &m_buffer[m_position], bytes);
			if (read == -1)
			{
				if (errno != EAGAIN)
				{
					std::cout << "Error reading file: " << errno << std::endl;
					return false;
				}
				
				return true;
			}

			m_position += read;
			return true;
		}

		size_t GetPosition() const
		{
			return m_position;
		}

		size_t BytesRemaining() const
		{
			return TSize - m_position;
		}

		const ReadOnlyBuffer GetRef() const
		{
			return { &m_buffer[0], m_position };
		}

	private:
		size_t m_position;
		uint8_t m_buffer[TSize];
	};
}