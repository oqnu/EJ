#include "EJ/GL/matrix/EJGL_ViewMatrix.hpp"
#include "EJ/GL/extensions/EJGL_GLMExtension.hpp"

EJGL_NAMESPACE_BEGIN

EJGLViewMatrix::EJGLViewMatrix(const glm::vec3& eye_, const glm::quat& rotation_) :
	_hasChange{ true },
	_eye{ eye_ },
	_rotation{ rotation_ }
{}

std::string EJGLViewMatrix::toString() const noexcept {
	return std::string("[ViewMatrix]{ eye: ") + _EJGL toString(_eye) + ", rotation: " + _EJGL toString(_rotation) + " }";
}

EJGL_NAMESPACE_END