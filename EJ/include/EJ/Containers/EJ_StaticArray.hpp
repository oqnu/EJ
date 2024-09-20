#ifndef EJ_STATICARRAY_HPP
#define EJ_STATICARRAY_HPP

//-----------------------------------------------------------------
// 
// It's implemented by std::array
// 
//------------------------------------------------------------------

#include "../utils/EJ_Config.hpp"
#include "../utils/EJ_TypeDefines.hpp"
#include "../utils/EJ_BaseObject.hpp"

#include <array>

EJ_NAMESPACE_BEGIN

template <typename _Type, EJSizeT _Size>
class EJStaticArray: public EJBaseObject {
public:
	using ValT = _Type;
	using SizeT = EJSizeT;
	using PtrT = _Type*;
	using CPtrT = cont _Type*;
	using RefT = _Type&;
	using CRefT = const _Type&;

public:
	EJStaticArray() noexcept:
		_impl()
	{}
	EJStaticArray(std::array<_Type, _Size> arr_):
		_impl(arr_)
	{}
	EJStaticArray(const EJStaticArray& obj_):
		_impl(obj_._impl)
	{}
	EJStaticArray(const EJStaticArray&& obj_) noexcept:
		_impl(std::move(obj_._impl))
	{}
	virtual ~EJStaticArray()
	{}

	virtual EJString toString() const noexcept override;

private:
	std::array<_Type, _Size> _impl;

};

template<typename _Type, EJSizeT _Size>
EJString EJStaticArray<_Type, _Size>::toString() const {
	EJString ret;

}

EJ_NAMESPACE_END

#endif // EJ_STATICARRAY_HPP
