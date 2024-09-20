EJGL_NAMESPACE_BEGIN

EJGL_INLINE void EJGLCamera::swap(EJGLCamera& obj_) noexcept {
	WindowSizeCBT _windowSizeCB = nullptr;

	::std::swap(_keyCB, obj_._keyCB);
	::std::swap(_mouseButtonCB, obj_._mouseButtonCB);
	::std::swap(_mouseMoveCB, obj_._mouseMoveCB);
	::std::swap(_scrollCB, obj_._scrollCB);

	::std::swap(_window, obj_._window);
	::std::swap(_view, obj_._view);
	::std::swap(_projection, obj_._projection);
}

EJGL_INLINE void EJGLCamera::setWindow(EJGLWindow* window_) {
	_window = window_;
}

template<typename ViewMatrixType, typename... Args>
EJGL_INLINE void EJGLCamera::setViewMatrix(Args... args_) {
	_deleteViewMatrix();
	_view = new ViewMatrixType(args_...);
}
template<typename ProjectionMatrixType, typename... Args>
EJGL_INLINE void EJGLCamera::setProjectionMatrix(Args... args_) {
	_deleteProjectionMatrix();
	_projection = new ProjectionMatrixType(args_...);
}

void EJGLCamera::_deleteViewMatrix() {
	delete _view;
}
void EJGLCamera::_deleteProjectionMatrix() {
	delete _projection;
}

EJGL_NAMESPACE_END