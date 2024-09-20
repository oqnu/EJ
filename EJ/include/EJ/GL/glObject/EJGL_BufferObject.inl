EJGL_NAMESPACE_BEGIN

// EJGLBufferObject
EJGL_INLINE::std::string EJGLBufferObject::toString() const noexcept {
	return ::std::string("[BufferObject]{ ID: ") + :: _EJGL toString(_dataPtr->_bufferID) + " }";
}

EJGL_INLINE void EJGLBufferObject::swap(EJGLBufferObject& obj_) noexcept {
	::std::swap(_dataPtr, obj_._dataPtr);
}

EJGL_INLINE void EJGLBufferObject::setBufferID(GLuint ID_) noexcept {
	_dataPtr->_bufferID = ID_;
}
EJGL_INLINE void EJGLBufferObject::setBufferType(EJGLBufferType bufferType_) noexcept {
	_dataPtr->_bufferType = bufferType_;
}

EJGL_INLINE void EJGLBufferObject::bind() const noexcept {
	EJGL_ASSERT(isValid() && "Have you create()?");
	glBindBuffer(_dataPtr->_bufferType, _dataPtr->_bufferID);
}
EJGL_INLINE void EJGLBufferObject::unbind() const noexcept {
	EJGLBufferObject::unbind(_dataPtr->_bufferType);
}

EJGL_INLINE void EJGLBufferObject::create(GLsizeiptr size_, const void* data_, EJGLDataUsage usage_) noexcept {
	glGenBuffers(1, &_dataPtr->_bufferID);
	bind();
	EJGL_CALL(glBufferData(_dataPtr->_bufferType, size_, data_, usage_));
}
template<typename _BufferElemType>
EJGL_INLINE void EJGLBufferObject::create(const std::vector<_BufferElemType>& data_, EJGLDataUsage usage_) noexcept {
	create(data_.size() * sizeof(_BufferElemType), data_.data(), usage_);
}

EJGL_INLINE void EJGLBufferObject::deleteBuffer() noexcept {
	glDeleteBuffers(1, &_dataPtr->_bufferID);
	_dataPtr->_bufferID = 0;
}

EJGL_INLINE void EJGLBufferObject::unbind(EJGLBufferType bufferType_) noexcept {
	glBindBuffer(bufferType_, 0);
}


#ifdef EJGL_USE_DEBUG_HELPER
EJGL_INLINE bool EJGLBufferObject::isBinding() const noexcept {
	return EJGLBufferObject::isBinding(_dataPtr->_bufferType, _dataPtr->_bufferID);
}

EJGL_INLINE bool EJGLBufferObject::isBinding(EJGLBufferType bufferType_, GLuint bufferID_) noexcept {
	return getBinding(bufferType_) == bufferID_;
}
EJGL_INLINE GLuint EJGLBufferObject::getBinding(EJGLBufferType bufferType_) noexcept {
	GLuint bo;
	GLenum param = GL_ARRAY_BUFFER_BINDING;
	switch (bufferType_)
	{
	//case EJGLBufferType::ARRAY:
	//	param = GL_ARRAY_BUFFER_BINDING;
	//	break;
	case EJGLBufferType::ELEMENT:
		param = GL_ELEMENT_ARRAY_BUFFER_BINDING;
		break;
	case EJGLBufferType::UNIFORM:
		param = GL_UNIFORM_BUFFER_BINDING;
		break;
	}
	glGetIntegerv(param, reinterpret_cast<GLint*>(&bo));
	return bo;
}
#endif

// EJGLArrayBuffer
EJGL_INLINE std::string EJGLArrayBuffer::toString() const noexcept {
	return "[ArrayBuffer]" + EJGLBufferObject::toString();
}

EJGL_INLINE void EJGLArrayBuffer::swap(EJGLArrayBuffer& obj_) noexcept {
	EJGLBufferObject::swap(obj_);
}

EJGL_INLINE void EJGLArrayBuffer::unbind() noexcept {
	EJGLBufferObject::unbind(EJGLBufferType::ARRAY);
}

// EJGLElementBuffer
EJGL_INLINE std::string EJGLElementBuffer::toString() const noexcept {
	return "[ElementBuffer]" + EJGLBufferObject::toString();
}

EJGL_INLINE void EJGLElementBuffer::swap(EJGLElementBuffer& obj_) noexcept {
	EJGLBufferObject::swap(obj_);
}

EJGL_INLINE void EJGLElementBuffer::unbind() noexcept {
	EJGLBufferObject::unbind(EJGLBufferType::ELEMENT);
}

// EJGLUniformBuffer
EJGL_INLINE std::string EJGLUniformBuffer::toString() const noexcept {
	return "[UniformBuffer]" + EJGLBufferObject::toString();
}

EJGL_INLINE void EJGLUniformBuffer::swap(EJGLUniformBuffer& obj_) noexcept {
	EJGLBufferObject::swap(obj_);
	::std::swap(_bindingPoint, obj_._bindingPoint);
}

EJGL_INLINE void EJGLUniformBuffer::bindToBindingPoint(GLuint bindingPoint_) noexcept {
	EJGL_ASSERT(isValid() && "Have you create()?");
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	_bindingPoint = bindingPoint_;
	glBindBufferBase(EJGLBufferType::UNIFORM, bindingPoint_, getBufferID());
}
EJGL_INLINE void EJGLUniformBuffer::bindToBindingPoint(GLuint bindingPoint_, GLintptr offset_, GLsizeiptr size_) noexcept {
	EJGL_ASSERT(isValid() && "Have you create()?");
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	_bindingPoint = bindingPoint_;
	glBindBufferRange(EJGLBufferType::UNIFORM, bindingPoint_, getBufferID(), offset_, size_);
}

EJGL_INLINE void EJGLUniformBuffer::unbind() noexcept {
	EJGLBufferObject::unbind(EJGLBufferType::UNIFORM);
}

EJGL_NAMESPACE_END