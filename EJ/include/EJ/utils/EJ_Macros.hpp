#ifndef EJ_MACROS_HPP
#define EJ_MACROS_HPP

#include "EJ_config.hpp"

EJ_NAMESPACE_BEGIN

#define EJ_M_GET_FUNC(retT, funcN, retV) \
	retT funcN() noexcept { return retV; }
#define EJ_M_CONST_GET_FUNC(retT, funcN, retV) \
	retT funcN() const noexcept { return retV; }
#define EJ_M_SET_FUNC(valT, funcN, exp) \
	void funcN(valT val_) noexcept { exp; }

#define EJ_M_CLONE_FUNC(baseT, classT, ...) \
	virtual baseT* clone() const noexcept override { return new classT(##__VA_ARGS__); }

EJ_NAMESPACE_END

#endif // EJ_MACROS_HPP
