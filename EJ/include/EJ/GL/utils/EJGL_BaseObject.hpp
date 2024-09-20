#ifndef EJGL_BASEOBJECT_HPP
#define EJGL_BASEOBJECT_HPP

#include "EJGL_config.hpp"
#include "../../utils/EJ_BaseObject.hpp"

EJGL_NAMESPACE_BEGIN

class EJGLBaseObject: public EJBaseObject {
public:
	EJGLBaseObject() noexcept
	{}
	EJGLBaseObject(const EJGLBaseObject& obj_) noexcept
	{}
	// shallow copy
	EJGLBaseObject(EJGLBaseObject&& obj_) noexcept
	{}
	virtual ~EJGLBaseObject() noexcept
	{}

	EJGLBaseObject& operator=(const EJGLBaseObject& obj_) noexcept
	{}

	virtual std::string toString() const noexcept = 0;

	EJGL_INLINE virtual EJGLBaseObject* clone() const noexcept = 0;

	EJGL_INLINE void swap(EJGLBaseObject& obj_) noexcept
	{}

	EJGL_INLINE friend std::ostream& operator<<(std::ostream& os, const EJGLBaseObject& obj);

private:

};

EJGL_NAMESPACE_END

#include "EJGL_BaseObject.inl"

#endif // EJGL_BASEOBJECT_HPP
