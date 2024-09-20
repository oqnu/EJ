#ifndef EJ_BASEOBJECT_HPP
#define EJ_BASEOBJECT_HPP

#include "EJ_Config.hpp"
#include <string>

EJ_NAMESPACE_BEGIN

class EJBaseObject {
public:
	EJBaseObject() noexcept
	{}
	EJBaseObject(const EJBaseObject& obj_) noexcept
	{}
	// move ctor
	EJBaseObject(EJBaseObject&& obj_) noexcept
	{}
	virtual ~EJBaseObject() noexcept 
	{}

	EJBaseObject& operator=(const EJBaseObject& obj_) noexcept
	{}

	virtual std::string toString() const noexcept = 0;

	// use new to create and return and copy of this object
	EJ_INLINE virtual EJBaseObject* clone() const noexcept = 0;

	EJ_INLINE friend std::ostream& operator<<(std::ostream& os, const EJBaseObject& obj);

private:

};

EJ_NAMESPACE_END

#include "EJ_BaseObject.inl"

#endif // EJ_BASEOBJECT_HPP
