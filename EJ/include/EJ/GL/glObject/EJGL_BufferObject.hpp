#ifndef EJGL_BUFFEROBJECT_HPP
#define EJGL_BUFFEROBJECT_HPP

#include "../utils/EJGL_config.hpp"
#include "../../utils/EJ_Macros.hpp"
#include "../utils/EJGL_Utils.hpp"
#include "../utils/EJGL_BaseObject.hpp"
#include "../utils/EJGL_enum.hpp"

#include <memory>
#include <vector>

namespace {
	struct _EJGLBufferObjectElem {
		GLuint _bufferID;
		_EJGL EJGLBufferType _bufferType;
	};
}

EJGL_NAMESPACE_BEGIN

class EJGLBufferObject: public EJGLBaseObject
{
public:
	EJGLBufferObject() noexcept :
		EJGLBufferObject(0, EJGLBufferType::ARRAY)
	{}
	EJGLBufferObject(EJGLBufferType bufferType_) noexcept :
		EJGLBufferObject(0, bufferType_)
	{}
	EJGLBufferObject(GLuint bufferID_, EJGLBufferType bufferType_) noexcept :
		EJGLBaseObject(),
		_dataPtr(std::make_shared<_EJGLBufferObjectElem>(_EJGLBufferObjectElem{ bufferID_, bufferType_ }))
	{}
	EJGLBufferObject(const EJGLBufferObject& obj_) noexcept :
		EJGLBaseObject(obj_),
		_dataPtr(obj_._dataPtr)
	{}
	EJGLBufferObject(EJGLBufferObject&& obj_) noexcept :
		EJGLBaseObject(std::move(obj_)),
		_dataPtr(std::move(obj_._dataPtr))
	{}
	EJGLBufferObject& operator=(const EJGLBufferObject& obj_) noexcept;
	virtual ~EJGLBufferObject() noexcept;

	virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLBufferObject, *this);

	EJGL_INLINE void swap(EJGLBufferObject& obj_) noexcept;

	EJGL_INLINE EJ_M_CONST_GET_FUNC(, operator GLuint, _dataPtr->_bufferID);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(bool, isValid, _dataPtr->_bufferID != 0);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(GLuint, getBufferID, _dataPtr->_bufferID);
	EJGL_INLINE EJ_M_CONST_GET_FUNC(EJGLBufferType, getBufferType, _dataPtr->_bufferType);

	EJGL_INLINE void setBufferID(GLuint ID_) noexcept;
	EJGL_INLINE void setBufferType(EJGLBufferType bufferType_) noexcept;

	EJGL_INLINE void bind() const noexcept;
	EJGL_INLINE void unbind() const noexcept;

	EJGL_INLINE void create(GLsizeiptr size_, const void* data_ = nullptr, EJGLDataUsage usage_ = EJGLDataUsage::STATIC_DRAW) noexcept;
	template<typename _BufferElemType>
	EJGL_INLINE void create(const std::vector<_BufferElemType>& data_, EJGLDataUsage usage_ = EJGLDataUsage::STATIC_DRAW) noexcept;
	EJGL_INLINE void deleteBuffer() noexcept;

	void subData(GLintptr offset_, GLsizeiptr size_, const void* data_) const noexcept;

private:
	std::shared_ptr<_EJGLBufferObjectElem> _dataPtr;

// static
public:
	EJGL_INLINE static void unbind(EJGLBufferType bufferType_) noexcept;

// Debug Helper
#ifdef EJGL_USE_DEBUG_HELPER
public:
	EJGL_INLINE bool isBinding() const noexcept;

public:
	EJGL_INLINE static bool isBinding(EJGLBufferType bufferType_, GLuint bufferID_) noexcept;
	EJGL_INLINE static GLuint getBinding(EJGLBufferType bufferType_) noexcept;
#endif
};

class EJGLArrayBuffer : public EJGLBufferObject
{
public:
	EJGLArrayBuffer() noexcept :
		EJGLBufferObject(EJGLBufferType::ARRAY)
	{}
	EJGLArrayBuffer(const EJGLArrayBuffer& obj_) noexcept :
		EJGLBufferObject(obj_)
	{}
	EJGLArrayBuffer(EJGLArrayBuffer&& obj_) noexcept :
		EJGLBufferObject(std::move(obj_))
	{}
	virtual ~EJGLArrayBuffer() noexcept
	{}

	EJGLArrayBuffer& operator=(const EJGLArrayBuffer& obj_) noexcept;

	EJGL_INLINE virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLArrayBuffer, *this);

	EJGL_INLINE void swap(EJGLArrayBuffer& obj_) noexcept;

private:

public:
	EJGL_INLINE static void unbind() noexcept;

};

class EJGLElementBuffer : public EJGLBufferObject
{
public:
	EJGLElementBuffer() noexcept :
		EJGLBufferObject(EJGLBufferType::ELEMENT)
	{}
	EJGLElementBuffer(const EJGLElementBuffer& obj_) noexcept :
		EJGLBufferObject(obj_)
	{}
	EJGLElementBuffer(EJGLElementBuffer&& obj_) noexcept :
		EJGLBufferObject(std::move(obj_))
	{}
	virtual ~EJGLElementBuffer() noexcept
	{}

	EJGLElementBuffer& operator=(const EJGLElementBuffer& obj_) noexcept;

	EJGL_INLINE virtual std::string toString() const noexcept override;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLElementBuffer, *this);

	EJGL_INLINE void swap(EJGLElementBuffer& obj_) noexcept;

private:

public:
	EJGL_INLINE static void unbind() noexcept;

};

class EJGLUniformBuffer : public EJGLBufferObject
{
public:
	EJGLUniformBuffer(GLuint bindingPoint_ = 0) noexcept :
		EJGLBufferObject(EJGLBufferType::UNIFORM),
		_bindingPoint(bindingPoint_)
	{}
	EJGLUniformBuffer(const EJGLUniformBuffer& obj_) noexcept :
		EJGLBufferObject(obj_),
		_bindingPoint(obj_._bindingPoint)
	{}
	EJGLUniformBuffer(EJGLUniformBuffer&& obj_) noexcept :
		EJGLBufferObject(std::move(obj_)),
		_bindingPoint(std::move(obj_._bindingPoint))
	{}
	virtual ~EJGLUniformBuffer() noexcept
	{}

	EJGLUniformBuffer& operator=(const EJGLUniformBuffer& obj_) noexcept;

	EJGL_INLINE virtual std::string toString() const noexcept override;

	EJGL_INLINE void swap(EJGLUniformBuffer& obj_) noexcept;

	EJGL_INLINE EJ_M_CLONE_FUNC(EJGLBaseObject, EJGLUniformBuffer, *this);

	EJGL_INLINE EJ_M_CONST_GET_FUNC(GLuint, getBindingPoint, _bindingPoint);

	// use glBindBufferBase
	EJGL_INLINE void bindToBindingPoint(GLuint bindingPoint_) noexcept;
	// use glBindBufferRange
	EJGL_INLINE void bindToBindingPoint(GLuint bindingPoint_, GLintptr offset_, GLsizeiptr size_) noexcept;

private:
	GLuint _bindingPoint;

public:
	EJGL_INLINE static void unbind() noexcept;

};

EJGL_NAMESPACE_END

#include "EJGL_BufferObject.inl"

#endif // EJGL_BUFFEROBJECT_HPP