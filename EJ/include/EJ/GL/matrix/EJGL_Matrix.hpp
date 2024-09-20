#ifndef EJGL_MATRIX_HPP
#define EJGL_MATRIX_HPP

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

EJGL_NAMESPACE_BEGIN

class EJGLMatrix : public EJGLBaseObject, public ::glm::mat4 {
public:
	EJGLMatrix(::glm::mat4 mat_ = ::glm::mat4()) :
		EJGLBaseObject(),
		::glm::mat4(mat_)
	{}
	EJGLMatrix(const EJGLMatrix& obj_) :
		EJGLBaseObject(obj_),
		::glm::mat4(obj_)
	{}
	EJGLMatrix(EJGLMatrix&& obj_) noexcept :
		EJGLBaseObject(std::move(obj_)),
		::glm::mat4(std::move(obj_))
	{}
	virtual ~EJGLMatrix()
	{}

	EJGLMatrix& operator=(const EJGLMatrix& obj_);

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLMatrix, *this);

	EJ_INLINE void swap(EJGLBaseObject& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const ::glm::mat4&, toGlm, *this);

	EJ_M_CONST_GET_FUNC(const float*, data, ::glm::value_ptr(toGlm()));

private:

};

EJGL_NAMESPACE_END

#endif // EJGL_MATRIX_HPP
