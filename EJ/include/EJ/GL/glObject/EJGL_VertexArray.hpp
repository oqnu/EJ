#ifndef EJGL_VERTEXARRAY_HPP
#define EJGL_VERTEXARRAY_HPP

//
// Tips:
//

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <memory>
#include <vector>

namespace {
	struct _EJGLVertexArrayElem {
		GLuint _vertexArrayID;
		std::vector<GLuint> _bufferAttaching;
	};
}

EJGL_NAMESPACE_BEGIN

class EJGLVertexBufferLayout {
public:
	struct Elem {
		EJGLDataType type;
		int count;
		GLboolean normalized;

		EJGL_INLINE unsigned int size() const;

		EJGL_INLINE void apply(GLuint index_, const void* offset_ = 0, GLsizei stride_ = 0) const;
	};

public:
	EJGLVertexBufferLayout() noexcept :
		_stride(0)
	{}
	EJGLVertexBufferLayout(const EJGLVertexBufferLayout& obj_) noexcept :
		_stride(obj_._stride),
		_elements(obj_._elements)
	{}
	EJGLVertexBufferLayout(EJGLVertexBufferLayout&& obj_) noexcept :
		_stride(std::move(obj_._stride)),
		_elements(std::move(obj_._elements))
	{}
	EJGLVertexBufferLayout& operator=(const EJGLVertexBufferLayout& obj_) noexcept;
	virtual ~EJGLVertexBufferLayout() noexcept
	{}

	EJGL_INLINE EJ_M_CONST_GET_FUNC(GLsizei, getStride, _stride);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(const std::vector<Elem>&, getElements, _elements);
	EJGL_INLINE EJ_M_GET_FUNC(std::vector<Elem>&, getElements, _elements);

	void add(EJGLDataType type_, int count_, GLboolean normalized_ = GL_FALSE);

	void apply() const;

private:
	GLsizei _stride;
	std::vector<Elem> _elements;

};

class EJGLBufferObject;
class EJGLArrayBuffer;
class EJGLElementBuffer;
class EJGLVertexArray : public EJGLBaseObject
{
public:
	EJGLVertexArray(GLuint vertexArrayID_ = 0) :
		EJGLBaseObject(),
		_dataPtr(std::make_shared<_EJGLVertexArrayElem>(_EJGLVertexArrayElem{ vertexArrayID_ }))
	{}
	EJGLVertexArray(const EJGLVertexArray& obj_) noexcept :
		EJGLBaseObject(obj_),
		_dataPtr(obj_._dataPtr)
	{}
	EJGLVertexArray(EJGLVertexArray&& obj_) noexcept :
		EJGLBaseObject(std::move(obj_)),
		_dataPtr(std::move(obj_._dataPtr))
	{}
	EJGLVertexArray& operator=(const EJGLVertexArray& obj_) noexcept;
	virtual ~EJGLVertexArray() noexcept;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLVertexArray, *this);

	EJ_INLINE void swap(EJGLVertexArray& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(, operator GLuint, _dataPtr->_vertexArrayID);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isValid, _dataPtr->_vertexArrayID != 0);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(GLuint, getVertexArrayID, _dataPtr->_vertexArrayID);

	EJGL_INLINE void setVertexArrayID(GLuint ID_);

	EJGL_INLINE void create();

	EJGL_INLINE void bind() const;

	EJGL_INLINE void deleteVertexArray();

	// Description:
	//	Adds a BufferObject(VBO/EBO) to current VAO.
	// Param buffer_:
	//	buffer to be added
	void addBuffer(EJGLBufferObject& buffer_);
	// Description:
	//	Adds a VBO to current VAO with layout.
	// Param buffer_:
	//	buffer to be added
	// Param layout_:
	//	will call layout.apply() for you
	void addBufferLayout(EJGLArrayBuffer& buffer_, const EJGLVertexBufferLayout& layout_);

private:
	std::shared_ptr<_EJGLVertexArrayElem> _dataPtr;

	void _deleteBuffers() const;

// static
public:
	static EJGL_INLINE void unbind() {
		glBindVertexArray(0);
	}

	void drawArray(EJGLDrawOption EJGLDrawOption_, int first_, GLsizei count_);
	void drawElement(EJGLDrawOption EJGLDrawOption_, int first_, GLsizei count_);
	void mulDrawArray(EJGLDrawOption EJGLDrawOption_, const int* first_, const GLsizei* count_, GLsizei drawcount_);
	void mulDrawElement(EJGLDrawOption EJGLDrawOption_, const int* first_, const GLsizei* count_, GLsizei drawcount_);
	void mulDrawArray(EJGLDrawOption EJGLDrawOption_, const std::vector<GLint>& first_, const std::vector<GLsizei>& count_);
	void mulDrawElement(EJGLDrawOption EJGLDrawOption_, const std::vector<GLint>& first_, const std::vector<GLsizei>& count_);

// Debug Helper
#ifdef EJGL_USE_DEBUG_HELPER
public:
	EJGL_INLINE bool isBinding() const noexcept;

public:
	static EJGL_INLINE bool isBinding(GLuint vertexArrayID_);
	static EJGL_INLINE GLuint getBinding();

#endif // EJGL_USE_DEBUG_HELPER

};

EJGL_NAMESPACE_END

#include "EJGL_VertexArray.inl"

#endif // EJGL_VERTEXARRAY_HPP