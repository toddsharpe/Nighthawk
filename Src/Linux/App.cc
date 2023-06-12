#include "Linux/App.h"
#include "Assert.h"
#include "Callback.h"

#include <thread>

using namespace std::chrono;

namespace Nighthawk
{
	App::App(TelemetryWriter& telem) :
		m_dispatches(),
		m_telem(telem)
	{
		m_dispatches.reserve(MaxDispatches);

		m_telem.Add("App.Dispatches", m_dispatches.size());
		this->Install("Telem", { &m_telem, &TelemetryWriter::Send }, 1000ms);
	}
	
	void App::Install(const std::string& name, const Callback &callback, const std::chrono::milliseconds period)
	{
		Assert(m_dispatches.size() < MaxDispatches);
		
		m_dispatches.push_back({name, callback, period});

		Dispatch& dispatch = m_dispatches.back();
		m_telem.Add("App." + name + ".Period", dispatch.PeriodCounts);
		m_telem.Add("App." + name + ".Last", dispatch.LastCounts);
	}

	void App::Run()
	{
		while (true)
		{
			// Wake due periodics
			const steady_clock::time_point now = steady_clock::now();
			std::chrono::milliseconds next = std::chrono::milliseconds::max();
			for (Dispatch &dispatch : m_dispatches)
			{
				// Determine next periodic
				if (dispatch.Period < next)
					next = dispatch.Period;

				if (now - dispatch.Last > dispatch.Period)
				{
					Assert(dispatch.Call.IsCallable());
					dispatch.Call.Invoke();
					dispatch.Last = now;
				}

				dispatch.PeriodCounts = dispatch.Period.count();
				dispatch.LastCounts = dispatch.Last.time_since_epoch().count();
			}

			// Sleep
			std::this_thread::sleep_until(now + next);
		}
	}
}
