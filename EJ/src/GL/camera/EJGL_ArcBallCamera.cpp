#include "EJ/GL/camera/EJGL_ArcBallCamera.hpp"
#include "EJ/GL/application/EJGL_Window.hpp"

#include "EJ/GL/extensions/EJGL_GLMExtension.hpp"

#include <glm/gtx/quaternion.hpp>

EJGL_NAMESPACE_BEGIN

EJGLArcBallCamera::EJGLArcBallCamera(EJGLWindow* window_) :
	EJGLCamera{ window_ }
{
	EJGL_ASSERT(window_ != nullptr);
	//auto size = window_->getSize() / 2;
	setProjectionMatrix<EJGLPerspectiveMatrix>();
	setViewMatrix<EJGLViewMatrix>(::glm::vec3{0, 0, 10});

	_mouseButtonCB = s_mouseButtonCB;
	_mouseMoveCB = s_mouseMoveCB;
	_scrollCB = s_scrollCB;
}

std::string EJGLArcBallCamera::toString() const noexcept {
	return EJGLCamera::toString();
}

glm::vec3 EJGLArcBallCamera::_screenToArcball(const glm::vec2& point) const {
	glm::ivec2 wSize = getWindow()->getSize();
	glm::vec2 p = point / glm::vec2(wSize.x, wSize.y) * 2.0f - glm::vec2(1.0f);
	float dist = glm::dot(p, p);
	if (dist <= 1.0f) {
		// point in ball
		return glm::vec3(p, sqrt(1.0f - dist));
	}
	else {
		// point out ball
		return glm::normalize(glm::vec3(p, 0.0f));
	}
}

// static
void EJGLArcBallCamera::s_mouseButtonCB(EJGLWindow& window_, MouseButton button_, MouseButtonState action_, ModifierKeyBit mods_) {
	EJGLArcBallCamera* cam = window_.getCamera<EJGLArcBallCamera>();
	if (button_ == glfw::MouseButton::Right) {
		if (action_ == glfw::MouseButtonState::Press) {
			cam->_isMoving = true;
			cam->_lastMouse = window_.getReverseYCursorPos();
		}
		else if (action_ == glfw::MouseButtonState::Release) {
			cam->_isMoving = false;
		}
	}
}

void EJGLArcBallCamera::s_mouseMoveCB(EJGLWindow& window_, double x_, double y_) {
	EJGLArcBallCamera* cam = window_.getCamera<EJGLArcBallCamera>();
	if (!cam->_isMoving)
		return;

	glm::vec2 pos = window_.reversePosY({ x_, y_ });
	if (window_.getKey(::glfw::KeyCode::LeftAlt) || window_.getKey(::glfw::KeyCode::RightAlt)) {
		// pan
		glm::vec3 eye = cam->getViewMatrix()->getEye();
		cam->getViewMatrix()->setEye(eye + eye.z * 0.001f * ::glm::vec3(cam->_lastMouse - pos, 0.0f));
	}
	else {
		// rotate
		glm::vec3 ballPos = cam->_screenToArcball(pos);

		glm::quat rotation = cam->getViewMatrix()->getRotation();
		glm::quat deltaQuat = glm::rotation(ballPos, cam->_screenToArcball(cam->_lastMouse));
		cam->getViewMatrix()->setRotation(rotation * deltaQuat);
	}
	cam->_lastMouse = pos;
}

void EJGLArcBallCamera::s_scrollCB(EJGLWindow& window_, double x_, double y_) {
	EJGLArcBallCamera* cam = window_.getCamera<EJGLArcBallCamera>();
	glm::vec3 eye = cam->getViewMatrix()->getEye();
	float scale = 1.f - 0.1f * static_cast<float>(y_);
	eye.z *= scale;
	if (eye.z < 0.01f) {
		eye.z = 0.01f;
	}
	cam->getViewMatrix()->setEye(eye);
}

EJGL_NAMESPACE_END