#ifndef EJGL_ProjectionMatrix_HPP
#define EJGL_ProjectionMatrix_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <bitset>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

EJGL_NAMESPACE_BEGIN

class EJGLProjectionMatrix : public EJGLBaseObject, public ::glm::mat4
{
public:
	EJGLProjectionMatrix(const glm::mat4& mat_ = glm::mat4(1));
	EJGLProjectionMatrix(const EJGLProjectionMatrix&) = default;
	EJGLProjectionMatrix(EJGLProjectionMatrix&&) noexcept = default;
	virtual ~EJGLProjectionMatrix() = default;

	EJGLProjectionMatrix& operator=(const EJGLProjectionMatrix&) = default;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLProjectionMatrix, *this);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(const ::glm::mat4&, toGlm, *this);

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

};

class EJGLPerspectiveMatrix : public EJGLProjectionMatrix {
public:
	EJGLPerspectiveMatrix(float fov_ = 45.f, float aspectRatio_ = 1.f, float near_ = .1f, float far_ = 100.f);
	EJGLPerspectiveMatrix(const EJGLPerspectiveMatrix&) = default;
	EJGLPerspectiveMatrix(EJGLPerspectiveMatrix&&) noexcept = default;
	virtual ~EJGLPerspectiveMatrix() = default;

	EJGLPerspectiveMatrix& operator=(const EJGLPerspectiveMatrix&) = default;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLPerspectiveMatrix, *this);

	EJGL_INLINE float getFov() noexcept;
	EJGL_INLINE float getAspectRatio() noexcept;
	EJGL_INLINE float getNear() noexcept;
	EJGL_INLINE float getFar() noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getFov, _fov);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getAspectRatio, _aspectRatio);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getNear, _near);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getFar, _far);

	virtual EJGL_INLINE void setFov(float fov_);
	virtual EJGL_INLINE void setAspectRatio(float aspectRatio_);
	virtual EJGL_INLINE void setNear(float near_);
	virtual EJGL_INLINE void setFar(float far_);

	virtual EJGL_INLINE void update() override;

private:
	float _fov;
	float _aspectRatio;
	float _near;
	float _far;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(glm::mat4, _getMatrix, s_getMatrix(_fov, _aspectRatio, _near, _far));

private:
	static EJGL_INLINE ::glm::mat4 s_getMatrix(float fov_, float aspect_, float near_, float far_);

};

class EJGLOrthographicMatrix : public EJGLProjectionMatrix {
public:
	EJGLOrthographicMatrix(float left_ = -1, float right_ = 1, float bottom_ = -1, float top_ = 1, float near_ = 0.1, float far_ = 10);
	EJGLOrthographicMatrix(const EJGLOrthographicMatrix&) = default;
	EJGLOrthographicMatrix(EJGLOrthographicMatrix&&) noexcept = default;
	virtual ~EJGLOrthographicMatrix() = default;

	EJGLOrthographicMatrix& operator=(const EJGLOrthographicMatrix&) = default;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLOrthographicMatrix, *this);

	EJGL_INLINE float getLeft() noexcept;
	EJGL_INLINE float getRight() noexcept;
	EJGL_INLINE float getBottom() noexcept;
	EJGL_INLINE float getTop() noexcept;
	EJGL_INLINE float getNear() noexcept;
	EJGL_INLINE float getFar() noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getLeft, _left);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getRight, _right);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getBottom, _bottom);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getTop, _top);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getNear, _near);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(float, getFar, _far);

	virtual EJGL_INLINE void setLeft(float left_);
	virtual EJGL_INLINE void setRight(float right_);
	virtual EJGL_INLINE void setBottom(float bottom_);
	virtual EJGL_INLINE void setTop(float top_);
	virtual EJGL_INLINE void setNear(float near_);
	virtual EJGL_INLINE void setFar(float far_);

	virtual EJGL_INLINE void update() override;

private:
	float _left;
	float _right;
	float _bottom;
	float _top;
	float _near;
	float _far;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(glm::mat4, _getMatrix, s_getMatrix(_left, _right, _bottom, _top, _near, _far));

private:
	static EJGL_INLINE glm::mat4 s_getMatrix(float left_, float right_, float bottom_, float top_, float near_, float far_);

};

EJGL_NAMESPACE_END

#include "EJGL_ProjectionMatrix.inl"

#endif // EJGL_ProjectionMatrix_HPP