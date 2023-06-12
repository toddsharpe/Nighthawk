#pragma once

#include <cstddef>

namespace Nighthawk
{
	struct ReadOnlyBuffer
	{
		const void* Data;
		size_t Length;
	};

	struct Buffer
	{
		void* Data;
		size_t Length;
	};
}