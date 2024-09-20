#include "EJ/GL/glObject/EJGL_BufferObject.hpp"
#include <string>

EJGL_NAMESPACE_BEGIN

// EJGLBufferObject
EJGLBufferObject& EJGLBufferObject::operator=(const EJGLBufferObject& obj_) noexcept {
	_dataPtr = obj_._dataPtr;
	return *this;
}
EJGLBufferObject::~EJGLBufferObject() noexcept {
	deleteBuffer();
}

void EJGLBufferObject::subData(GLintptr offset_, GLsizeiptr size_, const void* data_) const noexcept  {
	EJGL_ASSERT(_dataPtr->_bufferID != 0);
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	EJGL_CALL(glBufferSubData(_dataPtr->_bufferType, offset_, size_, data_));
}

// EJGLArrayBuffer
EJGLArrayBuffer& EJGLArrayBuffer::operator=(const EJGLArrayBuffer& obj_) noexcept {
	EJGLBufferObject::operator=(obj_);
	return *this;
}

// EJGLElementBuffer
EJGLElementBuffer& EJGLElementBuffer::operator=(const EJGLElementBuffer& obj_) noexcept {
	EJGLBufferObject::operator=(obj_);
	return *this;
}

// EJGLUniformBuffer
EJGLUniformBuffer& EJGLUniformBuffer::operator=(const EJGLUniformBuffer& obj_) noexcept {
	EJGLBufferObject::operator=(obj_);
	_bindingPoint = obj_._bindingPoint;
	return *this;
}

EJGL_NAMESPACE_END