EJGL_NAMESPACE_BEGIN

#pragma region [ProjectionMatrix]

EJGL_INLINE void EJGLProjectionMatrix::touch() noexcept {
	_setHasChange(true);
}

EJGL_INLINE bool EJGLProjectionMatrix::hasChange() const noexcept {
	bool ret = _getHasChange();
	_setHasChange(false);
	return ret;
}

EJGL_INLINE void EJGLProjectionMatrix::update() {

}

// private
EJGL_INLINE void EJGLProjectionMatrix::_setHasChange(bool val_) const noexcept {
	_hasChange = val_;
}

#pragma endregion

#pragma region [PerspectiveMatrix]

EJGL_INLINE float EJGLPerspectiveMatrix::getFov() noexcept {
	touch();
	return _fov;
}
EJGL_INLINE float EJGLPerspectiveMatrix::getAspectRatio() noexcept {
	touch();
	return _aspectRatio;
}
EJGL_INLINE float EJGLPerspectiveMatrix::getNear() noexcept {
	touch();
	return _near;
}
EJGL_INLINE float EJGLPerspectiveMatrix::getFar() noexcept {
	touch();
	return _far;
}

EJGL_INLINE void EJGLPerspectiveMatrix::setFov(float fov_) {
	_fov = fov_;
	touch();
}
EJGL_INLINE void EJGLPerspectiveMatrix::setAspectRatio(float aspectRatio_) {
	_aspectRatio = aspectRatio_;
	touch();
}
EJGL_INLINE void EJGLPerspectiveMatrix::setNear(float near_) {
	_near = near_;
	touch();
}
EJGL_INLINE void EJGLPerspectiveMatrix::setFar(float far_) {
	_far = far_;
	touch();
}

EJGL_INLINE void EJGLPerspectiveMatrix::update() {
	::glm::mat4::operator=(_getMatrix());
	EJGLProjectionMatrix::update();
}

EJGL_INLINE::glm::mat4 EJGLPerspectiveMatrix::s_getMatrix(float fov_, float aspect_, float near_, float far_) {
	return ::glm::perspective(fov_, aspect_, near_, far_);
}

#pragma endregion

#pragma region [EJGLOrthographicMatrix]

EJGL_INLINE float EJGLOrthographicMatrix::getLeft() noexcept {
	touch();
	return _left;
}
EJGL_INLINE float EJGLOrthographicMatrix::getRight() noexcept {
	touch();
	return _right;
}
EJGL_INLINE float EJGLOrthographicMatrix::getBottom() noexcept {
	touch();
	return _bottom;
}
EJGL_INLINE float EJGLOrthographicMatrix::getTop() noexcept {
	touch();
	return _top;
}
EJGL_INLINE float EJGLOrthographicMatrix::getNear() noexcept {
	touch();
	return _near;
}
EJGL_INLINE float EJGLOrthographicMatrix::getFar() noexcept {
	touch();
	return _far;
}

EJGL_INLINE void EJGLOrthographicMatrix::setLeft(float left_) {
	_left = left_;
	touch();
}
EJGL_INLINE void EJGLOrthographicMatrix::setRight(float right_) {
	_right = right_;
	touch();
}
EJGL_INLINE void EJGLOrthographicMatrix::setBottom(float bottom_) {
	_bottom = bottom_;
	touch();
}
EJGL_INLINE void EJGLOrthographicMatrix::setTop(float top_) {
	_top = top_;
	touch();
}
EJGL_INLINE void EJGLOrthographicMatrix::setNear(float near_) {
	_near = near_;
	touch();
}
EJGL_INLINE void EJGLOrthographicMatrix::setFar(float far_) {
	_far = far_;
	touch();
}

EJGL_INLINE void EJGLOrthographicMatrix::update() {
	::glm::mat4::operator=(_getMatrix());
	EJGLProjectionMatrix::update();
}

EJGL_INLINE glm::mat4 EJGLOrthographicMatrix::s_getMatrix(float left_, float right_, float bottom_, float top_, float near_, float far_) {
	return ::glm::ortho(left_, right_, bottom_, top_, near_, far_);
}

#pragma endregion

EJGL_NAMESPACE_END