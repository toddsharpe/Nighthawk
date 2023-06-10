#include "Hosted/App.h"
#include "Assert.h"

#include<thread>

using namespace std::chrono;

namespace Nighthawk
{
    void App::Install(const Callback& callback, const std::chrono::milliseconds period)
    {
        m_dispatches.push_back({ callback, period });
    }
    
    void App::Run()
    {
        while (true)
        {
            //Wake due periodics
            const steady_clock::time_point now = steady_clock::now();
            std::chrono::milliseconds next = std::chrono::milliseconds::max();
            for (Dispatch& dispatch : m_dispatches)
            {
                //Determine next periodic
                if (dispatch.Period < next)
                    next = dispatch.Period;

                if (now - dispatch.Last > dispatch.Period)
                {
                    Assert(dispatch.Call.IsCallable());
                    dispatch.Call.Invoke();
                    dispatch.Last = now;
                }
            }

            //Sleep
            std::this_thread::sleep_until(now + next);
        }
    }
}



