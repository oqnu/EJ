#include "EJ/GL/application/EJGL_Window.hpp"
#include "EJ/GL/camera/EJGL_Camera.hpp"

EJGL_NAMESPACE_BEGIN

EJGLWindow::EJGLWindow(int width_, int height_, const char* name_,
	const glfw::Monitor* monitor_,
	const glfw::Window* share_) :
	::glfw::Window{ width_, height_, name_, monitor_, share_ },
	_lastSize{ width_, height_ }
{
	posEvent.addEvent(onPosEvent);
	sizeEvent.addEvent(onSizeEvent);
	closeEvent.addEvent(onCloseEvent);
	refreshEvent.addEvent(onRefreshEvent);
	focusEvent.addEvent(onFocusEvent);
	iconifyEvent.addEvent(onIconifyEvent);
	maximizeEvent.addEvent(onMaximizeEvent);
	framebufferSizeEvent.addEvent(onFramebufferSizeEvent);
	contentScaleEvent.addEvent(onContentScaleEvent);
	keyEvent.addEvent(onKeyEvent);
	charEvent.addEvent(onCharEvent);
	mouseButtonEvent.addEvent(onMouseEvent);
	cursorPosEvent.addEvent(onCursorPosEvent);
	cursorEnterEvent.addEvent(onCursorEnterEvent);
	scrollEvent.addEvent(onScrollEvent);
	dropEvent.addEvent(onDropEvent);
}

std::string EJGLWindow::toString() const noexcept {
	return std::string("[Window]{ width: ") + std::to_string(getWidth()) +
		", height: " + std::to_string(getHeight()) + " }";
}

EJGLWindow::~EJGLWindow() {
	_deleteCamera();
}

void EJGLWindow::_deleteCamera() {
	delete _camera;
}

EJGLWindow& EJGLWindow::GetWrapperFromHandle(GLFWwindow* handle_) {
	return static_cast<EJGLWindow&>(::glfw::Window::_getWrapperFromHandle(handle_));
}

void EJGLWindow::onPosEvent(Window& window_, int, int) {

}
void EJGLWindow::onSizeEvent(Window& window_, int width_, int height_) {
	EJGLWindow& w = EJGLWindow::GetWrapperFromHandle(window_);
	if (w.isCameraValid()) {
		if (w._camera->getWindowSizeCB())
			w._camera->getWindowSizeCB()(w, width_, height_);
	}
	w._lastSize = glm::ivec2(width_, height_);
}
void EJGLWindow::onCloseEvent(Window&) {

}
void EJGLWindow::onRefreshEvent(Window&) {

}
void EJGLWindow::onFocusEvent(Window& window_, bool) {

}
void EJGLWindow::onIconifyEvent(Window& window_, bool) {

}
void EJGLWindow::onMaximizeEvent(Window& window_, bool) {

}
void EJGLWindow::onFramebufferSizeEvent(Window& window_, int width_, int height_) {
	glViewport(0, 0, width_, height_);
}
void EJGLWindow::onContentScaleEvent(Window& window_, float, float) {

}
void EJGLWindow::onKeyEvent(Window& window_, KeyCode keyCode_, int scancode_, KeyState action_, ModifierKeyBit mods_) {
	EJGLWindow& w = EJGLWindow::GetWrapperFromHandle(window_);
	if (w.isCameraValid()) {
		if (w._camera->getKeyCB())
			w._camera->getKeyCB()(w, keyCode_, scancode_, action_, mods_);
	}
}
void EJGLWindow::onCharEvent(Window& window_, unsigned int) {

}
void EJGLWindow::onMouseEvent(Window& window_, MouseButton button_, MouseButtonState action_, ModifierKeyBit mods_) {
	EJGLWindow& w = EJGLWindow::GetWrapperFromHandle(window_);
	if (w.isCameraValid()) {
		if (w._camera->getMouseButtonCB())
			w._camera->getMouseButtonCB()(w, button_, action_, mods_);
	}
}
void EJGLWindow::onCursorPosEvent(Window& window_, double x_, double y_) {
	EJGLWindow& w = EJGLWindow::GetWrapperFromHandle(window_);
	if (w.isCameraValid()) {
		if (w._camera->getMouseMoveCB())
			w._camera->getMouseMoveCB()(w, x_, y_);
	}
}
void EJGLWindow::onCursorEnterEvent(Window& window_, bool) {

}
void EJGLWindow::onScrollEvent(Window& window_, double x_, double y_) {
	EJGLWindow& w = EJGLWindow::GetWrapperFromHandle(window_);
	if (w.isCameraValid()) {
		if (w._camera->getScrollCB())
			w._camera->getScrollCB()(w, x_, y_);
	}
}
void EJGLWindow::onDropEvent(Window& window_, std::vector<const char*>) {

}

EJGL_NAMESPACE_END