#ifndef EJ_String_HPP
#define EJ_String_HPP

//-----------------------------------------------------------------
// 
// It's implemented by std::string
// 
//------------------------------------------------------------------

#include "../utils/EJ_BaseObject.hpp"
#include "../utils/EJ_TypeDefines.hpp"
#include "../utils/EJ_BaseObject.hpp"
#include "EJ_ContainerBase.hpp"

#include <string>

EJ_NAMESPACE_BEGIN

template<typename _Type>
class EJBasicString : public EJContainerBase<_Type> {
public:
	EJBasicString() noexcept:
		_impl()
	{}
	EJBasicString(std::string str_):
		_impl(str_)
	{}
	EJBasicString(const EJBasicString& obj_):
		_impl(obj_._impl)
	{}
	EJBasicString(const EJBasicString&& obj_) noexcept:
		_impl(std::move(obj_._impl))
	{}
	virtual ~EJBasicString()
	{}

	virtual EJBasicString toString() const noexcept override
	{
		return *this;
	}

private:
	std::basic_string<_Type> _impl;

};

EJ_NAMESPACE_END

#endif // EJ_String_HPP
