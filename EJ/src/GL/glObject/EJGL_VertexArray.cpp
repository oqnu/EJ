#include "EJ/GL/GlObject/EJGL_VertexArray.hpp"
#include "EJ/GL/GlObject/EJGL_BufferObject.hpp"

#include <ranges>

EJGL_NAMESPACE_BEGIN

#pragma region VertexBufferLayout

void VertexBufferLayout::add(DataType type_, int count_, GLboolean normalized_, int divisor_) {
	EJ_ASSERT(count_ != 0);
	_elements.push_back({ type_, count_, normalized_, divisor_ });
	_stride += _elements.back().size();
}

void VertexBufferLayout::apply(int startFrom_) const {
	const auto& stride = getStride();
	const auto& elements = getElements();
	unsigned long long offset = 0;
	for (int i = 0; i < elements.size(); ++i) {
		const auto& element = elements[i];
		element.apply(i + startFrom_, (void*)(offset), stride);
		offset += element.size();
	}
}

#pragma endregion

#pragma region VertexArray

class VertexArray::_VertexArrayImpl {
public:
	// construct empty
	_VertexArrayImpl() noexcept
	{}
	// call create() after construct
	_VertexArrayImpl(default_create) noexcept
	{
		create();
	}
	// construct by id
	_VertexArrayImpl(GLuint id_) :
		_vertexArrayID(id_)
	{}
	_VertexArrayImpl(const _VertexArrayImpl& obj_) = delete;
	_VertexArrayImpl& operator=(const _VertexArrayImpl& obj_) = delete;
	~_VertexArrayImpl() noexcept {
		deleteVertexArray();
	}

	_STD string toStringNoHeader() const noexcept {
		return _STD string("{ ID: ") + _EJ toString(_vertexArrayID) + " }";
	}

	void create() {
		glGenVertexArrays(1, &_vertexArrayID);
	}

	void bind() const {
		glBindVertexArray(_vertexArrayID);
	}

	void addBuffer(const BufferObject& buffer_) {
		buffer_.bind();
		_bindingBuffers.push_back(buffer_);
	}
	void addBufferLayout(const ArrayBuffer& buffer_, const VertexBufferLayout& layout_, int startFrom_) {
		buffer_.bind();
		layout_.apply(startFrom_);
		buffer_.unbind();
		_bindingBuffers.push_back(buffer_);
	}

	void deleteVertexArray() {
		glDeleteVertexArrays(1, &_vertexArrayID);
		_vertexArrayID = 0;
	}

public:
	GLuint _vertexArrayID;
	_STD vector<BufferObject> _bindingBuffers;

public:
	static void unbind() {
		glBindVertexArray(0);
	}

};

// construct empty
VertexArray::VertexArray() noexcept :
	_impl{ _STD make_shared<_VertexArrayImpl>() }
{}
// call create() after construct
VertexArray::VertexArray(default_create) noexcept :
	_impl{ _STD make_shared<_VertexArrayImpl>(default_create{}) }
{}
// construct by id
VertexArray::VertexArray(GLuint id_) :
	_impl{ _STD make_shared<_VertexArrayImpl>(id_) }
{}

_STD string VertexArray::toStringNoHeader() const noexcept {
	return _impl->toStringNoHeader();
}
_STD string VertexArray::toString() const noexcept {
	return _STD string("[EJ][VertexArray]") + _impl->toStringNoHeader();
}

void VertexArray::swap(VertexArray& obj_) noexcept {
	_STD swap(_impl, obj_._impl);
}

VertexArray::operator GLuint() const {
	return _impl->_vertexArrayID;
}
bool VertexArray::isValid() const {
	return _impl->_vertexArrayID != 0;
}
GLuint VertexArray::getVertexArrayID() const {
	return _impl->_vertexArrayID;
}

void VertexArray::setVertexArrayID(GLuint ID_) noexcept {
	_impl->_vertexArrayID = ID_;
}

void VertexArray::create() {
	return _impl->create();
}

void VertexArray::bind() const {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->bind();
}

// Description:
//	Adds a BufferObject(VBO/EBO) to current VAO.
// Param buffer_:
//	buffer to be added
void VertexArray::addBuffer(const BufferObject& buffer_) {
	EJ_ASSERT(isValid() && "Have you create()?");
	EJ_ASSERT(buffer_.getBufferType() == BufferType::ARRAY || buffer_.getBufferType() == BufferType::ELEMENT && "You can only add VBO/EBO");
	return _impl->addBuffer(buffer_);
}
// Description:
//	Adds a VBO to current VAO with layout.
// Param buffer_:
//	buffer to be added
// Param layout_:
//	will call layout.apply() for you
void VertexArray::addBufferLayout(const ArrayBuffer& buffer_, const VertexBufferLayout& layout_, int startFrom_) {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->addBufferLayout(buffer_, layout_, startFrom_);
}

void VertexArray::deleteVertexArray() {
	return _impl->deleteVertexArray();
}

// static functions
void VertexArray::unbind() {
	_VertexArrayImpl::unbind();
}

void VertexArray::drawArray(DrawOption drawOption_, GLint first_, GLsizei count_) {
	glDrawArrays(drawOption_, first_, count_);
}
void VertexArray::drawElement(DrawOption drawOption_, GLint first_, GLsizei count_, DataType valType_) {
	glDrawElements(drawOption_, count_, valType_, (void*)(sizeofGLType(valType_) * first_));
}
void VertexArray::drawArrayInstanced(DrawOption drawOption_, GLint first_, GLsizei count_, GLsizei numInstances_) {
	glDrawArraysInstanced(drawOption_, first_, count_, numInstances_);
}
void VertexArray::drawElementInstanced(DrawOption drawOption_, GLint first_, GLsizei count_, GLsizei numInstances_, DataType valType_) {
	glDrawElementsInstanced(drawOption_, count_, valType_, (void*)(sizeofGLType(valType_) * first_), numInstances_);
}
void VertexArray::mulDrawArray(DrawOption drawOption_, _STD span<GLint> first_, _STD span<GLsizei> count_) {
	EJ_ASSERT(first_.size() == count_.size() && "offsets's and counts's size must equal to drawcount");
	glMultiDrawArrays(drawOption_, first_.data(), count_.data(), first_.size());
}
void VertexArray::mulDrawElement(DrawOption drawOption_, _STD span<GLint> first_, _STD span<GLsizei> count_, DataType valType_) {
	auto offs = first_ | _STD views::transform([valType_](GLint v_) { return (void*)(v_ * sizeofGLType(valType_)); });
	_STD vector<const void*> offsets{ offs.begin(), offs.end() };
	glMultiDrawElements(drawOption_, count_.data(), valType_, offsets.data(), offsets.size());
}

#pragma endregion

EJGL_NAMESPACE_END