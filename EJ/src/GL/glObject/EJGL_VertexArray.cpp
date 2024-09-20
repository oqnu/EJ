#include "EJ/GL/glObject/EJGL_VertexArray.hpp"
#include "EJ/GL/glObject/EJGL_BufferObject.hpp"

EJGL_NAMESPACE_BEGIN

// EJGLVertexBufferLayout
EJGLVertexBufferLayout& EJGLVertexBufferLayout::operator=(const EJGLVertexBufferLayout& obj_) noexcept {
	_stride = obj_._stride;
	_elements = obj_._elements;
	return *this;
}

void EJGLVertexBufferLayout::add(EJGLDataType type_, int count_, GLboolean normalized_) {
	EJGL_ASSERT(count_ != 0);
	_elements.push_back({ type_, count_, normalized_ });
	_stride += _elements.back().size();
}

void EJGLVertexBufferLayout::apply() const {
	const auto& stride = getStride();
	const auto& elements = getElements();
	unsigned long long offset = 0;
	for (int i = 0; i < elements.size(); ++i) {
		const auto& element = elements[i];
		element.apply(i, (void*)(offset), stride);
		offset += element.size();
	}
}

// EJGLVertexArray
EJGLVertexArray& EJGLVertexArray::operator=(const EJGLVertexArray& obj_) noexcept {
	_dataPtr = obj_._dataPtr;
	return *this;
}
EJGLVertexArray::~EJGLVertexArray() {
	deleteVertexArray();
	_deleteBuffers();
}

std::string EJGLVertexArray::toString() const noexcept {
	return std::string("[VertexArray]{ ID: ") + std::to_string(_dataPtr->_vertexArrayID) + " }";
}

void EJGLVertexArray::addBuffer(EJGLBufferObject& buffer_) {
	EJGL_ASSERT(isValid() && "Have you create()?");

	EJGL_ASSERT(buffer_.getBufferType() == EJGLBufferType::ARRAY || buffer_.getBufferType() == EJGLBufferType::ELEMENT && "You can only add VBO/EBO");

#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER

	buffer_.bind();
	_dataPtr->_bufferAttaching.push_back(buffer_.getBufferID());
}
void EJGLVertexArray::addBufferLayout(EJGLArrayBuffer& buffer_, const EJGLVertexBufferLayout& layout_) {
	EJGL_ASSERT(isValid() && "Have you create()?");

#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER

	buffer_.bind();
	layout_.apply();
	_dataPtr->_bufferAttaching.push_back(buffer_.getBufferID());
}

void EJGLVertexArray::_deleteBuffers() const {
	//glDeleteBuffers(_bufferToDelete.size(), _bufferToDelete.data());
}

// static functions
void EJGLVertexArray::drawArray(EJGLDrawOption EJGLDrawOption_, int first_, GLsizei count_) {
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	EJGL_CALL(glDrawArrays(EJGLDrawOption_, first_, count_));
}
void EJGLVertexArray::drawElement(EJGLDrawOption EJGLDrawOption_, int first_, GLsizei count_) {
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	EJGL_CALL(glDrawElements(EJGLDrawOption_, count_, EJGLDataType::UNSIGNED_INT, (void*)(sizeof(GLuint) * first_)));
}
void EJGLVertexArray::mulDrawArray(EJGLDrawOption EJGLDrawOption_, const int* first_, const GLsizei* count_, GLsizei drawcount_) {
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	EJGL_CALL(glMultiDrawArrays(EJGLDrawOption_, first_, count_, drawcount_));
}
void EJGLVertexArray::mulDrawElement(EJGLDrawOption EJGLDrawOption_, const int* first_, const GLsizei* count_, GLsizei drawcount_) {
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	std::vector<const void*> offsets;
	offsets.reserve(drawcount_);
	for (int i = 0; i < drawcount_; ++i) {
		offsets.push_back((void*)(first_[i] * sizeof(GLuint)));
	}
	EJGL_CALL(glMultiDrawElements(EJGLDrawOption_, count_, EJGLDataType::UNSIGNED_INT, offsets.data(), drawcount_));
}
void EJGLVertexArray::mulDrawArray(EJGLDrawOption EJGLDrawOption_, const std::vector<GLint>& first_, const std::vector<GLsizei>& count_) {
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(first_.size() == count_.size());
	mulDrawArray(EJGLDrawOption_, first_.data(), count_.data(), static_cast<GLsizei>(first_.size()));
}
void EJGLVertexArray::mulDrawElement(EJGLDrawOption EJGLDrawOption_, const std::vector<GLint>& first_, const std::vector<GLsizei>& count_) {
#ifdef EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(isBinding() && "Have you bind()?");
#endif // EJGL_USE_DEBUG_HELPER
	EJGL_ASSERT(first_.size() == count_.size());
	mulDrawElement(EJGLDrawOption_, first_.data(), count_.data(), static_cast<GLsizei>(first_.size()));
}

EJGL_NAMESPACE_END