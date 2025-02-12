#ifndef EJGL_FRAMEBUFFEROBJECT_HPP
#define EJGL_FRAMEBUFFEROBJECT_HPP

#include "../Utils/EJGL_config.hpp"
#include "../Utils/EJGL_enum.hpp"
#include "../Utils/EJGL_Traits.hpp"
#include "EJGL_Texture2D.hpp"

#include <memory>

EJGL_NAMESPACE_BEGIN

class FrameBufferObject
{
private:
	class _FrameBufferObjectImpl;

public:
	// construct empty
	FrameBufferObject() noexcept;
	// call create() after construct
	FrameBufferObject(default_create) noexcept;
	// construct by id
	FrameBufferObject(GLuint id_) noexcept;
	FrameBufferObject(const FrameBufferObject& obj_) noexcept = default;
	FrameBufferObject& operator=(const FrameBufferObject& obj_) noexcept = default;
	~FrameBufferObject() noexcept = default;

	_STD string toStringNoHeader() const noexcept;
	_STD string toString() const noexcept;

	void swap(FrameBufferObject& obj_) noexcept;

	operator GLuint() const;
	bool isValid() const;
	GLuint getFrameBufferID() const;

	void setFrameBufferID(GLuint ID_) noexcept;

	void bind(FrameBufferMode mode_ = FrameBufferMode::NORMAL) const noexcept;

	void create() noexcept;
	void attachTexture(FrameBufferMode mode_, FrameBufferAttachment attachment_, const Texture2D& texture_, GLint level_ = 0);
	// attach textureND / RBO

	void deleteFrameBuffer() noexcept;

private:
	_STD shared_ptr<_FrameBufferObjectImpl> _impl;

	// static
public:
	static FrameBufferStatus checkStatus(FrameBufferMode mode_ = FrameBufferMode::NORMAL);
	static void unbind() noexcept;

};

EJGL_NAMESPACE_END

#endif // EJGL_FRAMEBUFFEROBJECT_HPP