#ifndef EJGL_EXAMPLE_HPP
#define EJGL_EXAMPLE_HPP

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

EJGL_NAMESPACE_BEGIN

class EJGLExample : public EJGLBaseObject {
public:
	EJGLExample() :
		EJGLBaseObject()
	{}
	EJGLExample(const EJGLExample& obj_) :
		EJGLBaseObject(obj_)
	{}
	EJGLExample(EJGLExample&& obj_) :
		EJGLBaseObject(std::move(obj_))
	{}
	virtual ~EJGLExample()
	{}

	EJGLExample& operator=(const EJGLExample& obj_)
	{}

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLExample, *this);

	EJ_INLINE void swap(EJGLBaseObject& obj_) noexcept;

private:

};

EJGL_NAMESPACE_END

#endif // EJGL_EXAMPLE_HPP
