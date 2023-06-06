namespace Nighthawk
{
    struct Callback
    {
        Callback() : Context(), Handler()
        {

        }

        bool IsCallable()
        {
            return Handler != nullptr;
        }

        void Invoke()
        {
            Handler(Context);
        }

        void* Context;
        void (*Handler)(void* sender);
    };
}