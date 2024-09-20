#include "EJ/GL/matrix/EJGL_ProjectionMatrix.hpp"
#include "EJ/GL/extensions/EJGL_GLMExtension.hpp"

EJGL_NAMESPACE_BEGIN

// ProjectionMatrix
EJGLProjectionMatrix::EJGLProjectionMatrix(const ::glm::mat4& mat_) :
	::glm::mat4{ mat_ },
	_hasChange{ true }
{}

std::string EJGLProjectionMatrix::toString() const noexcept {
	return std::string("[ProjectionMatrix]{ m: ") + ::_EJGL toString(static_cast<::glm::mat4>(*this)) + " }";
}

// PerspectiveMatrix
EJGLPerspectiveMatrix::EJGLPerspectiveMatrix(float fov_, float aspectRatio_, float near_, float far_) :
	EJGLProjectionMatrix{ s_getMatrix(fov_, aspectRatio_, near_, far_) },
	_fov{ fov_ }, _aspectRatio{ aspectRatio_ }, _near{ near_ }, _far{ far_ }
{}

std::string EJGLPerspectiveMatrix::toString() const noexcept {
	return std::string("[PerspectiveMatrix]{ fov: " + std::to_string(_fov) + ", aspect ratio: " + std::to_string(_aspectRatio) +
		", near: " + std::to_string(_near) + ", far: " + std::to_string(_far) + ", m: ") + ::_EJGL toString(static_cast<::glm::mat4>(*this)) + " }";
}

// EJGLOrthographicMatrix
EJGLOrthographicMatrix::EJGLOrthographicMatrix(float left_, float right_, float bottom_, float top_, float near_, float far_) :
	EJGLProjectionMatrix{ s_getMatrix(left_, right_, bottom_, top_, near_, far_) },
	_left{ left_ }, _right{ right_ },
	_bottom{ bottom_ }, _top{ top_ },
	_near{ near_ }, _far{ far_ }
{}

std::string EJGLOrthographicMatrix::toString() const noexcept {
	return std::string("[OrthographicMatrix]{ left: " + std::to_string(_left) + ", right: " + std::to_string(_right) +
		", bottom: " + std::to_string(_bottom) + ", top: " + std::to_string(_top) +
		", near: " + std::to_string(_near) + ", far: " + std::to_string(_far) + ", m: ") + ::_EJGL toString(static_cast<::glm::mat4>(*this)) + " }";
}

EJGL_NAMESPACE_END