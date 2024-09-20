EJGL_NAMESPACE_BEGIN

EJGL_INLINE glm::vec3& EJGLViewMatrix::getEye() noexcept {
	touch();
	return _eye;
}
EJGL_INLINE glm::quat& EJGLViewMatrix::getRotation() noexcept {
	touch();
	return _rotation;
}
EJGL_INLINE glm::vec3 EJGLViewMatrix::getRotationEuler() noexcept {
	touch();
	return ::glm::eulerAngles(_rotation);
}

EJGL_INLINE void EJGLViewMatrix::setEye(const glm::vec3& eye_) {
	_eye = eye_;
	touch();
}
EJGL_INLINE void EJGLViewMatrix::setRotation(const glm::quat& rotation_) {
	_rotation = rotation_;
	touch();
}
EJGL_INLINE void EJGLViewMatrix::setRotationEuler(const glm::vec3& rotationEuler_) {
	_rotation = glm::quat{ rotationEuler_ };
	touch();
}

EJGL_INLINE void EJGLViewMatrix::touch() noexcept {
	_setHasChange(true);
}

EJGL_INLINE bool EJGLViewMatrix::hasChange() const noexcept {
	bool ret = _getHasChange();
	_setHasChange(false);
	return ret;
}

EJGL_INLINE void EJGLViewMatrix::update() {
	glm::mat4::operator=(glm::mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		-_eye.x, -_eye.y, -_eye.z, 1.0f));
	glm::mat4::operator*=(glm::mat4_cast(glm::inverse(_rotation)));
}

// private
EJGL_INLINE void EJGLViewMatrix::_setHasChange(bool val_) const noexcept {
	_hasChange = val_;
}

EJGL_NAMESPACE_END