EJGL_NAMESPACE_BEGIN

EJ_INLINE EJGLBaseObject* EJGLWindow::clone() const noexcept {
	EJGL_ASSERT(false && "You shouldn't clone window");
	return nullptr;
};

EJGL_INLINE void EJGLWindow::swap(EJGLWindow& obj_) noexcept {
	EJGL_ASSERT(false && "You shouldn't swap window");
}

template<typename CameraType, typename... Args>
EJGL_INLINE void EJGLWindow::setCamera(Args&... args_) {
	_deleteCamera();
	_camera = new CameraType(this, args_...);
	//_camera.setEJGLWindow(this);
}

EJGL_INLINE int EJGLWindow::getWidth() const {
	int ret;
	glfwGetWindowSize(*const_cast<EJGLWindow*>(this), &ret, nullptr);
	return ret;
}
EJGL_INLINE int EJGLWindow::getHeight() const {
	int ret;
	glfwGetWindowSize(*const_cast<EJGLWindow*>(this), nullptr, &ret);
	return ret;
}
EJGL_INLINE glm::ivec2 EJGLWindow::getSize() const {
	int w, h;
	glfwGetWindowSize(*const_cast<EJGLWindow*>(this), &w, &h);
	return glm::vec2{ w, h };
}

EJGL_INLINE glm::vec2 EJGLWindow::getCursorPos() const {
	double x, y;
	glfwGetCursorPos(*const_cast<EJGLWindow*>(this), &x, &y);
	return glm::vec2{ x, y };
}
EJGL_INLINE glm::vec2 EJGLWindow::getReverseYCursorPos() const {
	int height = getHeight();
	auto pos = getCursorPos();
	return glm::vec2{ pos.x, height - pos.y };
}
EJGL_INLINE glm::vec2 EJGLWindow::getReverseXCenteredCursorPos() const {
	auto hSize = getSize() / 2;
	auto pos = getCursorPos();
	return glm::vec2{ hSize.x - pos.x, pos.y - hSize.y };
}
EJGL_INLINE glm::vec2 EJGLWindow::getNDCCursorPos() const {
	getNDCCursorPos(std::move(getSize()));
}
EJGL_INLINE glm::vec2 EJGLWindow::getNDCCursorPos(glm::ivec2&& size_) const {
	auto ret = this->getCursorPos();
	return glm::vec2{ ret.x / size_.x, ret.y / size_.y };
}
EJGL_INLINE glm::vec2 EJGLWindow::getReverseYNDCCursorPos() const {
	auto size = getSize();
	auto ret = this->getCursorPos();
	return glm::vec2{ ret.x / size.x, 1.0 - ret.y / size.y };
}


EJGL_INLINE glm::vec2 EJGLWindow::reversePosY(const glm::vec2& pos_) const {
	glm::vec2 ret = pos_;
	int height = getHeight();
	ret.y = height - ret.y;
	return ret;
}

EJGL_NAMESPACE_END