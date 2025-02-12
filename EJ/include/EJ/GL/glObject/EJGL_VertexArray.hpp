#ifndef EJGL_VERTEXARRAY_HPP
#define EJGL_VERTEXARRAY_HPP

//
// Tips:
//

#include "../Utils/EJGL_config.hpp"
#include "../../Utils/EJ_Macros.hpp"
#include "../Utils/EJGL_enum.hpp"
#include "../Utils/EJGL_Traits.hpp"

#include <span>
#include <memory>
#include <vector>
#include <string>

EJGL_NAMESPACE_BEGIN

class VertexBufferLayout {
public:
	struct Elem {
		DataType type;
		int count;
		GLboolean normalized;
		int divisor;

		unsigned int size() const {
			return count * sizeofGLType(type);
		}

		void apply(GLuint index_, const void* offset_ = 0, GLsizei stride_ = 0) const {
			glVertexAttribPointer(index_, count, type, normalized, stride_, offset_);
			glEnableVertexAttribArray(index_);
			if (divisor != 0)
				glVertexAttribDivisor(index_, divisor);
		}
	};

public:
	VertexBufferLayout() noexcept = default;
	VertexBufferLayout(const VertexBufferLayout& obj_) noexcept = default;
	VertexBufferLayout& operator=(const VertexBufferLayout& obj_) noexcept = default;
	virtual ~VertexBufferLayout() noexcept = default;

	EJ_M_GET_FUNC(GLsizei&, stride, _stride);
	EJ_M_GET_FUNC(_STD vector<Elem>&, elements, _elements);
	EJ_M_CONST_GET_FUNC(GLsizei, getStride, _stride);
	EJ_M_CONST_GET_FUNC(const _STD vector<Elem>&, getElements, _elements);

	void add(DataType type_, int count_, GLboolean normalized_ = GL_FALSE, int divisor_ = 0);

	void apply(int startFrom_ = 0) const;

private:
	GLsizei _stride = 0;
	_STD vector<Elem> _elements;

};

class BufferObject;
class ArrayBuffer;
class ElementBuffer;
class VertexArray
{
public:
	class _VertexArrayImpl;

public:
	// construct empty
	VertexArray() noexcept;
	// call create() after construct
	VertexArray(default_create) noexcept;
	// construct by id
	VertexArray(GLuint id_);
	VertexArray(const VertexArray& obj_) noexcept = default;
	VertexArray& operator=(const VertexArray& obj_) noexcept = default;
	virtual ~VertexArray() noexcept = default;

	_STD string toStringNoHeader() const noexcept;
	_STD string toString() const noexcept;

	void swap(VertexArray& obj_) noexcept;

	operator GLuint() const;
	bool isValid() const;
	GLuint getVertexArrayID() const;

	void setVertexArrayID(GLuint ID_) noexcept;

	void create();

	void bind() const;

	// Description:
	//	Adds a BufferObject(VBO/EBO) to current VAO.
	// Param buffer_:
	//	buffer to be added
	void addBuffer(const BufferObject& buffer_);
	// Description:
	//	Adds a VBO to current VAO with layout.
	// Param buffer_:
	//	buffer to be added
	// Param layout_:
	//	will call layout.apply() for you
	void addBufferLayout(const ArrayBuffer& buffer_, const VertexBufferLayout& layout_, int startFrom_ = 0);

	void deleteVertexArray();

private:
	_STD shared_ptr<_VertexArrayImpl> _impl;

// static
public:
	static void unbind();

	void drawArray(DrawOption drawOption_, GLint first_, GLsizei count_);
	void drawElement(DrawOption drawOption_, GLint first_, GLsizei count_, DataType valType_ = DataType::UNSIGNED_INT);
	void drawArrayInstanced(DrawOption drawOption_, GLint first_, GLsizei count_, GLsizei numInstances_);
	void drawElementInstanced(DrawOption drawOption_, GLint first_, GLsizei count_, GLsizei numInstances_, DataType valType_ = DataType::UNSIGNED_INT);
	void mulDrawArray(DrawOption drawOption_, _STD span<GLint> first_, _STD span<GLsizei> count_);
	void mulDrawElement(DrawOption drawOption_, _STD span<GLint> first_, _STD span<GLsizei> count_, DataType valType_ = DataType::UNSIGNED_INT);

};

EJGL_NAMESPACE_END

#endif // EJGL_VERTEXARRAY_HPP