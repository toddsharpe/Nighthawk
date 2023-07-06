#pragma once

namespace Nighthawk
{
	struct Callback
	{
		bool IsCallable()
		{
			return Handler != nullptr;
		}

		void Invoke()
		{
			Handler(Context);
		}

		void *Context;
		void (*Handler)(void *sender);
	};
}