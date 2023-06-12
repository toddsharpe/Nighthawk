#pragma once

#include "Callback.h"
#include "TelemetryWriter.h"

#include <vector>
#include <chrono>
#include <string>

namespace Nighthawk
{
	class App
	{
	public:
		App(TelemetryWriter& telem);
		void Install(const std::string& name, const Callback &callback, const std::chrono::milliseconds period);
		void Run();

	private:
		static constexpr size_t MaxDispatches = 4;
		struct Dispatch
		{
			std::string Name;
			Callback Call;
			std::chrono::milliseconds Period;
			int64_t PeriodCounts;
			std::chrono::steady_clock::time_point Last;
			int64_t LastCounts;
		};

		std::vector<Dispatch> m_dispatches;
		TelemetryWriter& m_telem;
	};
}