#ifndef EJGL_UTILS_HPP
#define EJGL_UTILS_HPP

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <string>

EJGL_NAMESPACE_BEGIN

template <typename T>
typename ::std::enable_if<::std::is_integral<T>::value, ::std::string>::type
toString(T v_) {
    return ::std::to_string(v_);
}

template <typename T>
typename ::std::enable_if<::std::is_floating_point<T>::value, ::std::string>::type
toString(T v_) {
    const auto len = static_cast<size_t>(::_scprintf("%4.2f", v_));
    ::std::string s(len, '\0');
    ::sprintf_s(&s[0], len + 1, "%4.2f", v_);
    return s;
}

EJGL_NAMESPACE_END

#endif // EJGL_UTILS_HPP
