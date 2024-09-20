#ifndef EJGL_ViewMatrix_HPP
#define EJGL_ViewMatrix_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <bitset>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

EJGL_NAMESPACE_BEGIN

class EJGLViewMatrix : public EJGLBaseObject, public ::glm::mat4
{
public:
	EJGLViewMatrix(const glm::vec3& eye_ = { 0, 0, 1 }, const glm::quat& rotation_ = { 1, 0, 0, 0 });
	EJGLViewMatrix(const EJGLViewMatrix&) = default;
	EJGLViewMatrix(EJGLViewMatrix&&) noexcept = default;
	~EJGLViewMatrix() = default;

	EJGLViewMatrix& operator=(const EJGLViewMatrix&) = default;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLViewMatrix, *this);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const ::glm::mat4&, toGlm, *this);

	// about view
	EJGL_INLINE glm::vec3& getEye() noexcept;
	EJGL_INLINE glm::quat& getRotation() noexcept;
	EJGL_INLINE glm::vec3 getRotationEuler() noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const glm::vec3&, getEye, _eye);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const glm::quat&, getRotation, _rotation);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const glm::vec3, getRotationEuler, ::glm::eulerAngles(_rotation));

	EJGL_INLINE void setEye(const glm::vec3& eye_);
	EJGL_INLINE void setRotation(const glm::quat& rotation_);
	EJGL_INLINE void setRotationEuler(const glm::vec3& rotationEuler_);

	EJGL_INLINE void touch() noexcept;
	// when call set to false
	// which means you need to call update to get correct value
	EJGL_INLINE bool hasChange() const noexcept;
	virtual EJGL_INLINE void update();

protected:
	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, _getHasChange, _hasChange);
	EJGL_INLINE void _setHasChange(bool val_) const noexcept;

private:
	mutable bool _hasChange = false;
	glm::vec3 _eye;
	glm::quat _rotation;

};

EJGL_NAMESPACE_END

#include "EJGL_ViewMatrix.inl"

#endif // EJGL_ViewMatrix_HPP