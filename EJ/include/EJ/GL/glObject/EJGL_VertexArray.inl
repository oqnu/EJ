EJGL_NAMESPACE_BEGIN

// EJGLVertexBufferLayout
EJGL_INLINE unsigned int EJGLVertexBufferLayout::Elem::size() const {
	return count * sizeofGLType(type);
}

EJGL_INLINE void EJGLVertexBufferLayout::Elem::apply(GLuint index_, const void* offset_, GLsizei stride_) const {
	EJGL_CALL(glVertexAttribPointer(index_, count, type, normalized, stride_, offset_));
	EJGL_CALL(glEnableVertexAttribArray(index_));
}

// EJGLVertexArray

EJ_INLINE void EJGLVertexArray::swap(EJGLVertexArray& obj_) noexcept {
	::std::swap(_dataPtr, obj_._dataPtr);
}

EJGL_INLINE void EJGLVertexArray::setVertexArrayID(GLuint ID_) {
	_dataPtr->_vertexArrayID = ID_;
}

EJGL_INLINE void EJGLVertexArray::create() {
	glGenVertexArrays(1, &_dataPtr->_vertexArrayID);
}

EJGL_INLINE void EJGLVertexArray::bind() const {
	EJGL_ASSERT(isValid() && "Have you create()?");
	glBindVertexArray(_dataPtr->_vertexArrayID);
}

EJGL_INLINE void EJGLVertexArray::deleteVertexArray() {
	glDeleteVertexArrays(1, &_dataPtr->_vertexArrayID);
	_dataPtr->_vertexArrayID = 0;
}

// Debug Helper
#ifdef EJGL_USE_DEBUG_HELPER
EJGL_INLINE bool EJGLVertexArray::isBinding() const noexcept {
	return EJGLVertexArray::isBinding(_dataPtr->_vertexArrayID);
}

EJGL_INLINE bool EJGLVertexArray::isBinding(GLuint vertexArrayID_) {
	return getBinding() == vertexArrayID_;
}
EJGL_INLINE GLuint EJGLVertexArray::getBinding() {
	GLuint vao;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, reinterpret_cast<GLint*>(&vao));
	return vao;
}
#endif // EJGL_USE_DEBUG_HELPER

EJGL_NAMESPACE_END