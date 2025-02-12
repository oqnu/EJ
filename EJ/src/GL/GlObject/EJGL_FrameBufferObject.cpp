#include "EJ/GL/GlObject/EJGL_FrameBufferObject.hpp"
#include "EJ/Utils/EJ_Utils.hpp"
#include <string>

EJGL_NAMESPACE_BEGIN

#pragma region FrameBufferObject

class FrameBufferObject::_FrameBufferObjectImpl {
public:
	_FrameBufferObjectImpl()
	{}
	_FrameBufferObjectImpl(default_create) noexcept
	{
		create();
	}
	_FrameBufferObjectImpl(GLuint id_) :
		_frameBufferID(id_)
	{}
	_FrameBufferObjectImpl(const _FrameBufferObjectImpl& obj_) = delete;
	_FrameBufferObjectImpl(_FrameBufferObjectImpl&& obj_) noexcept = delete;
	_FrameBufferObjectImpl& operator=(const _FrameBufferObjectImpl& obj_) = delete;
	_FrameBufferObjectImpl& operator=(_FrameBufferObjectImpl&& obj_) noexcept = delete;
	~_FrameBufferObjectImpl() noexcept {
		deleteFrameBuffer();
	}

	_STD string toStringNoHeader() const noexcept {
		return "{ ID: " + _EJ toString(_frameBufferID) + " }";
	}

	void bind(FrameBufferMode mode_) const noexcept {
		glBindFramebuffer(mode_, _frameBufferID);
	}

	void create() noexcept {
		glGenFramebuffers(1, &_frameBufferID);
	}
	void attachTexture(FrameBufferMode mode_, FrameBufferAttachment attachment_, const Texture2D& texture_, GLint level_) {
		glFramebufferTexture(mode_, attachment_, texture_, level_);
	}
	// attach textureND / RBO

	void deleteFrameBuffer() noexcept {
		glDeleteFramebuffers(1, &_frameBufferID);
		_frameBufferID = 0;
	}

public:
	GLuint _frameBufferID = 0;

public:
	static FrameBufferStatus checkStatus(FrameBufferMode mode_) {
		return static_cast<FrameBufferStatus>(glCheckFramebufferStatus(mode_));
	}
	static void unbind() noexcept {
		glBindFramebuffer(FrameBufferMode::NORMAL, 0);
	}

};

FrameBufferObject::FrameBufferObject() noexcept :
	_impl{ _STD make_shared<_FrameBufferObjectImpl>() }
{}
FrameBufferObject::FrameBufferObject(default_create) noexcept :
	_impl{ _STD make_shared<_FrameBufferObjectImpl>(default_create{}) }
{}
FrameBufferObject::FrameBufferObject(GLuint id_) noexcept :
	_impl{ _STD make_shared<_FrameBufferObjectImpl>(id_) }
{}

_STD string FrameBufferObject::toStringNoHeader() const noexcept {
	return _impl->toStringNoHeader();
}
_STD string FrameBufferObject::toString() const noexcept {
	return _STD string("[EJ][FrameBufferObject]") + _impl->toStringNoHeader();
}

void FrameBufferObject::swap(FrameBufferObject& obj_) noexcept {
	_STD swap(_impl, obj_._impl);
}

FrameBufferObject::operator GLuint() const {
	return _impl->_frameBufferID;
}

bool FrameBufferObject::isValid() const {
	return _impl->_frameBufferID != 0;
}
GLuint FrameBufferObject::getFrameBufferID() const {
	return _impl->_frameBufferID;
}
FrameBufferStatus FrameBufferObject::checkStatus(FrameBufferMode mode_) {
	return _FrameBufferObjectImpl::checkStatus(mode_);
}
void FrameBufferObject::setFrameBufferID(GLuint ID_) noexcept {
	_impl->_frameBufferID = ID_;
}
 
void FrameBufferObject::bind(FrameBufferMode mode_) const noexcept {
	EJ_ASSERT(isValid() && "Have you create()?");
	return _impl->bind(mode_);
}
void FrameBufferObject::unbind() noexcept {
	_FrameBufferObjectImpl::unbind();
}

void FrameBufferObject::create() noexcept {
	return _impl->create();
}
void FrameBufferObject::attachTexture(FrameBufferMode mode_, FrameBufferAttachment attachment_, const Texture2D& texture_, GLint level_) {
	EJ_ASSERT(isValid() && "Have you create()?");
	_impl->attachTexture(mode_, attachment_, texture_, level_);
}

void FrameBufferObject::deleteFrameBuffer() noexcept {
	return _impl->deleteFrameBuffer();
}

EJGL_NAMESPACE_END