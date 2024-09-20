EJGL_NAMESPACE_BEGIN

EJ_INLINE void EJGLShader::swap(EJGLShader& obj_) noexcept {
	::std::swap(_dataPtr, obj_._dataPtr);
}

EJGL_INLINE void EJGLShader::setShaderID(GLuint ID_) {
	_dataPtr->_shaderID = ID_;
}

EJGL_NAMESPACE_END