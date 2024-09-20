#ifndef EJ_CONFIG_HPP
#define EJ_CONFIG_HPP

#include <cassert>
#include <iostream>

#define EJ_NAMESPACE_BEGIN namespace EJ {
#define EJ_NAMESPACE_END }
#define _EJ EJ::

#define EJ_INLINE inline

#define EJ_ERR_STREAM std::cerr

// -------------------------------------------------
// debug
// -------------------------------------------------
#ifdef _DEBUG
#define EJ_DEBUG
#endif // _DEBUG

// assert
#ifdef EJ_DEBUG
#define EJ_ASSERT(expression) \
	assert(expression)
#else
#define EJ_ASSERT(expression)
#endif // EJGL_DEBUG

#endif // EJ_CONFIG_HPP