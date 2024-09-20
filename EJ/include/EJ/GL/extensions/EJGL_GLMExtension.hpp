#ifndef EJGL_GLMEXTENSION_HPP
#define EJGL_GLMEXTENSION_HPP

//
// Tips:
//

#include "../utils/EJGL_Config.hpp"
#include "../utils/EJGL_Utils.hpp"

#include <string>
#include <iostream>
#include <glm/glm.hpp>

EJGL_NAMESPACE_BEGIN

// TODO: constexpr num to string

// vec
template <typename T, ::glm::length_t L, ::glm::qualifier Q>
::std::string toString(const ::glm::vec<L, T, Q>& v_) {
    ::std::string s = "vec" + toString(L) + "(" + toString(v_[0]);
    for (int i = 1; i < L; ++i) {
        s += ", " + toString(v_[i]);
    }
    s += ")";
    return s;
}

// vec
template <typename T, ::glm::qualifier Q>
::std::string toString(const ::glm::qua<T, Q>& q_) {
    ::std::string s = "quat(" + toString(q_.x) + ", " + toString(q_.y) + ", " + toString(q_.z) + ", " + toString(q_.w) + ")";
    return s;
}

template <typename T, ::glm::length_t C, ::glm::length_t R, ::glm::qualifier Q>
::std::string toString(const ::glm::mat<C, R, T, Q>& m_) {
    ::std::string s = "mat" + toString(C) + toString(R) + "(\n";
    for (int c = 0; c < C; ++c) {
        for (int r = 0; r < R; ++r) {
            s += toString(m_[c][r]);
            if (c < C - 1 || r < R - 1)
                s += ", ";
        }
        if (c < C - 1)
            s += '\n';
    }
    s += ")";
    return s;
}

EJGL_NAMESPACE_END

#endif // EJGL_GLMEXTENSION_HPP