#include "Callback.h"

#include <vector>
#include <chrono>

namespace Nighthawk
{
    class App
    {
    public:
        void Install(const Callback& callback, const std::chrono::milliseconds period);
        void Run();

    private:
        struct Dispatch
        {
            Callback Callback;
            std::chrono::milliseconds Period;
            std::chrono::steady_clock::time_point Last;
        };

        std::vector<Dispatch> m_dispatches;
    };
}