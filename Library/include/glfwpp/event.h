#ifndef GLFWPP_EVENT_H
#define GLFWPP_EVENT_H

#include <GLFW/glfw3.h>
#include <functional>
#include <set>

namespace glfw
{
    template<typename... Args>
    class Event
    {
    public:
        using FunctionType = std::function<void(Args...)>;

        struct FunctionComparator {
            bool operator()(const FunctionType& f1, const FunctionType& f2) const {
                return f1.target_type().before(f2.target_type());
            }
        };

    private:
        std::set<FunctionType, FunctionComparator> _functions = std::set<FunctionType, FunctionComparator>();

    public:
        inline const std::set<FunctionType>& functions() const {
            return _functions;
        }
        inline std::set<FunctionType>& functions() {
            return _functions;
        }

        inline bool addEvent(const FunctionType& function_) {
            return _functions.insert(function_).second;
        }
        inline void removeEvent(const FunctionType& function_) {
            _functions.erase(function_);
        }
        
        void operator()(Args... args_) const
        {
            for (const FunctionType& function : _functions)
            {
                function(args_...);
            }
        }
    };

    inline void pollEvents()
    {
        glfwPollEvents();
    }

    inline void waitEvents()
    {
        glfwWaitEvents();
    }
    inline void waitEvents(double timeout_)
    {
        glfwWaitEventsTimeout(timeout_);
    }

    inline void postEmptyEvent()
    {
        glfwPostEmptyEvent();
    }
}  // namespace glfw

#endif  //GLFWPP_EVENT_H
