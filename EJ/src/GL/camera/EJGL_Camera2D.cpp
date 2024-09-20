#include "EJ/GL/camera/EJGL_Camera2D.hpp"
#include "EJ/GL/application/EJGL_Window.hpp"

#include "EJ/GL/extensions/EJGL_GLMExtension.hpp"

EJGL_NAMESPACE_BEGIN

EJGLCamera2D::EJGLCamera2D(EJGLWindow* window_) :
	EJGLCamera{ window_ }
{
	EJGL_ASSERT(window_ != nullptr);
	auto size = window_->getSize() / 2;
	setProjectionMatrix<EJGLOrthographicMatrix>(static_cast<float>(-size.x), static_cast<float>(size.x), static_cast<float>(-size.y), static_cast<float>(size.y));
	setViewMatrix<EJGLViewMatrix>();

	_windowSizeCB = s_windowSizeCB;

	_mouseButtonCB = s_mouseButtonCB;
	_mouseMoveCB = s_mouseMoveCB;
	_scrollCB = s_scrollCB;
}

std::string EJGLCamera2D::toString() const noexcept {
	return EJGLCamera::toString();
}

// static
void EJGLCamera2D::s_windowSizeCB(EJGLWindow& window_, int width_, int height_) {
	EJGLCamera2D* cam = window_.getCamera<EJGLCamera2D>();
	glm::ivec2 tmp = window_.getLastSize();
	auto ortho = cam->getProjectionMatrix<EJGLOrthographicMatrix>();
	float hW = (width_ >> 1) * cam->_invScale, hH = (height_ >> 1) * cam->_invScale;
	ortho->setLeft(-hW);
	ortho->setRight(hW);
	ortho->setTop(hH);
	ortho->setBottom(-hH);
	ortho->update();
}

void EJGLCamera2D::s_mouseButtonCB(EJGLWindow& window_, MouseButton button_, MouseButtonState action_, ModifierKeyBit mods_) {
	EJGLCamera2D* cam = window_.getCamera<EJGLCamera2D>();
	if (button_ == glfw::MouseButton::Right) {
		if (action_ == glfw::MouseButtonState::Press) {
			cam->_isMoving = true;
			cam->_startMovePos = window_.getReverseYCursorPos();
		}
		else if (action_ == glfw::MouseButtonState::Release) {
			cam->_isMoving = false;
		}
	}
}

void EJGLCamera2D::s_mouseMoveCB(EJGLWindow& window_, double x_, double y_) {
	EJGLCamera2D* cam = window_.getCamera<EJGLCamera2D>();
	if (!cam->_isMoving)
		return;
	glm::vec2 pos = window_.reversePosY({ x_, y_ });
	glm::vec3 eye = cam->getViewMatrix()->getEye();
	eye += glm::vec3{ glm::vec2{ cam->_startMovePos - pos } * cam->_invScale, 0 };
	cam->getViewMatrix()->setEye(eye);
	cam->_startMovePos = glm::vec2{ pos };

	// move eye to make it like we resize at mouse pos
	auto mouse = window_.getReverseXCenteredCursorPos() * cam->_invScale;
	auto eyeScreenPos = ::glm::vec2(cam->getViewMatrix()->getEye());

	std::cout << ::_EJGL toString(mouse) << '\t' << ::_EJGL toString(eyeScreenPos) << '\n';
}

void EJGLCamera2D::s_scrollCB(EJGLWindow& window_, double x_, double y_) {
	EJGLCamera2D* cam = window_.getCamera<EJGLCamera2D>();
	auto ortho = cam->getProjectionMatrix<EJGLOrthographicMatrix>();
	auto view = cam->getViewMatrix();

	// resize
	constexpr float _OffsetScale = 0.1f;
	float y = _OffsetScale * static_cast<float>(y_);
	float scale = 1 - y;
	ortho->setLeft(ortho->getLeft() * scale);
	ortho->setRight(ortho->getRight() * scale);
	ortho->setTop(ortho->getTop() * scale);
	ortho->setBottom(ortho->getBottom() * scale);
	ortho->update();

	// move eye to make it like we resize at mouse pos
	auto mouse = window_.getReverseXCenteredCursorPos() * cam->_invScale;
	auto eyeScreenPos = ::glm::vec2(view->getEye());

	std::cout << ::_EJGL toString(mouse) << '\t' << ::_EJGL toString(eyeScreenPos) << '\n';

	// y == 1 - scale
	view->setEye(::glm::vec3((eyeScreenPos - mouse) * y + eyeScreenPos, 1));

	cam->_invScale *= scale;
}

EJGL_NAMESPACE_END