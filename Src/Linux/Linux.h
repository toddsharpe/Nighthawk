#pragma once

#include <string>
#include <fstream>
#include "Assert.h"

namespace Linux
{
	inline std::string ReadString(const std::string& file)
	{
		std::ifstream stream(file);
		Assert(stream.is_open());

		std::string line;
		std::getline(stream, line);
		return line;
	}

	inline size_t ReadHex(const std::string& file)
	{
		std::ifstream stream(file);
		Assert(stream.is_open());

		size_t value;
		stream >> std::hex >> value;
		return value;
	}

	inline bool IsSpecialDir(const std::string& dir)
	{
		return dir == "." || dir == "..";
	}
}
